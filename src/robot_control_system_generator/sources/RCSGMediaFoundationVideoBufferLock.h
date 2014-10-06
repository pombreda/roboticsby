/*
Copyright (C) 2013-2014, Sergey Gerasuto <contacts@robotics.by>

http://www.robotics.by/

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

- Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
- Neither the name of the RCSG Developers nor the names of its
contributors may be used to endorse or promote products derived from this
software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
`AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef VIDEOBUFFERLOCK_H_
#define VIDEOBUFFERLOCK_H_

#include <windows.h>
#include <mfapi.h>

class RCSGMediaFoundationVideoBufferLock
{   
public:
    RCSGMediaFoundationVideoBufferLock(IMFMediaBuffer *buffer) : iMF2DBuffer(NULL), isLocked(FALSE)
    {
        iMFMediaBuffer = buffer;
        iMFMediaBuffer->AddRef();
        iMFMediaBuffer->QueryInterface(IID_PPV_ARGS(&iMF2DBuffer));
    }

    ~RCSGMediaFoundationVideoBufferLock()
    {
        UnlockBuffer();
        safeRelease(&iMFMediaBuffer);
        safeRelease(&iMF2DBuffer);
    }

    HRESULT LockBuffer(LONG lDefaultStride, DWORD dwHeightInPixels, BYTE  **ppbScanLine0, LONG *plStride)
    {
        HRESULT hr = S_OK;

        if (iMF2DBuffer)
        {
            hr = iMF2DBuffer->Lock2D(ppbScanLine0, plStride);
        }
        else
        {
            BYTE *pData = NULL;
            hr = iMFMediaBuffer->Lock(&pData, NULL, NULL);
			if (SUCCEEDED(hr))
			{
				*plStride = lDefaultStride;
				if (lDefaultStride < 0)
				{
					*ppbScanLine0 = pData + abs(lDefaultStride) * (dwHeightInPixels-1);
				}
				else
				{
					*ppbScanLine0 = pData;
				}
			}
        }

		isLocked = (SUCCEEDED(hr));
        return hr;
    }

    void UnlockBuffer()
    {
        if (isLocked)
        {
            if (iMF2DBuffer)
            {
                (void)iMF2DBuffer->Unlock2D();
            }
            else
            {
                (void)iMFMediaBuffer->Unlock();
            }
            isLocked = FALSE;
        }
    }

private:
    IMFMediaBuffer  *iMFMediaBuffer;
    IMF2DBuffer     *iMF2DBuffer;
    BOOL            isLocked;

	template <class T> void safeRelease(T **ppT)
	{
		if (ppT != NULL)
		{
			if (*ppT)
			{
				(*ppT)->Release();
				*ppT = NULL;
			}
		}
	}
};

#endif //VIDEOBUFFERLOCK_H_