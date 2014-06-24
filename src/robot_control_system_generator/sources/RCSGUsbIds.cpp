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

#include "RCSGUsbIds.h"


	RCSGUsbIds::RCSGUsbIds()
	{
		InitManufacturesUsbIdsHash();
		InitManufacturesProductsUsbIdsHash();
	};

	QString RCSGUsbIds::Manufacture(WORD manufactureId)
	{
		QString result("");
		result.append(mh.value(manufactureId));
		return result;
	};

	QString RCSGUsbIds::Product(WORD manufactureId, WORD productId)
	{
		QString result("");
		result.append((mph.value(manufactureId)).value(productId));
		return result;
	};

	void RCSGUsbIds::InitManufacturesUsbIdsHash()
	{
		DWORD mid[] = {
		0x0001,0x0002,0x0003,0x0004,0x0011,0x0053,0x0079,0x0105,0x0145,0x017c,0x0200,0x0204,0x0218,0x02ad,0x0300,0x0324,0x0325,0x0386,0x03d9,0x03da,
		0x03e8,0x03e9,0x03ea,0x03eb,0x03ec,0x03ed,0x03ee,0x03f0,0x03f1,0x03f2,0x03f3,0x03f4,0x03f5,0x03f8,0x03f9,0x03fb,0x03fc,0x03fd,0x03fe,0x0400,
		0x0401,0x0402,0x0403,0x0404,0x0405,0x0406,0x0407,0x0408,0x0409,0x040a,0x040b,0x040c,0x040d,0x040e,0x040f,0x0411,0x0412,0x0413,0x0414,0x0416,
		0x0417,0x0418,0x0419,0x041a,0x041b,0x041d,0x041e,0x041f,0x0420,0x0421,0x0422,0x0423,0x0424,0x0425,0x0426,0x0427,0x0428,0x0429,0x042a,0x042b,
		0x042c,0x042d,0x042e,0x042f,0x0430,0x0431,0x0432,0x0433,0x0434,0x0435,0x0436,0x0437,0x0438,0x0439,0x043d,0x043e,0x043f,0x0440,0x0441,0x0442,
		0x0443,0x0445,0x0446,0x0447,0x044a,0x044b,0x044c,0x044d,0x044e,0x044f,0x0450,0x0451,0x0452,0x0453,0x0454,0x0455,0x0456,0x0457,0x0458,0x0459,
		0x045a,0x045b,0x045d,0x045e,0x0460,0x0461,0x0463,0x0464,0x0467,0x0468,0x046a,0x046b,0x046c,0x046d,0x046e,0x046f,0x0471,0x0472,0x0473,0x0474,
		0x0475,0x0476,0x0477,0x0478,0x0479,0x047a,0x047b,0x047c,0x047d,0x047e,0x047f,0x0480,0x0481,0x0482,0x0483,0x0484,0x0485,0x0486,0x0487,0x0488,
		0x0489,0x048a,0x048c,0x048d,0x048f,0x0490,0x0491,0x0492,0x0493,0x0495,0x0496,0x0497,0x0498,0x0499,0x049a,0x049b,0x049c,0x049d,0x049f,0x04a0,
		0x04a1,0x04a2,0x04a3,0x04a4,0x04a5,0x04a6,0x04a7,0x04a8,0x04a9,0x04aa,0x04ab,0x04ac,0x04ad,0x04af,0x04b0,0x04b1,0x04b3,0x04b4,0x04b5,0x04b6,
		0x04b7,0x04b8,0x04b9,0x04ba,0x04bb,0x04bd,0x04be,0x04bf,0x04c1,0x04c2,0x04c3,0x04c4,0x04c5,0x04c6,0x04c7,0x04c8,0x04ca,0x04cb,0x04cc,0x04cd,
		0x04ce,0x04cf,0x04d0,0x04d1,0x04d2,0x04d3,0x04d4,0x04d5,0x04d6,0x04d7,0x04d8,0x04d9,0x04da,0x04db,0x04dc,0x04dd,0x04de,0x04df,0x04e1,0x04e2,
		0x04e3,0x04e4,0x04e5,0x04e6,0x04e7,0x04e8,0x04e9,0x04ea,0x04eb,0x04ec,0x04ed,0x04ef,0x04f0,0x04f1,0x04f2,0x04f3,0x04f4,0x04f5,0x04f6,0x04f7,
		0x04f8,0x04f9,0x04fa,0x04fb,0x04fc,0x04fd,0x04fe,0x04ff,0x0500,0x0501,0x0502,0x0503,0x0504,0x0506,0x0507,0x0508,0x0509,0x050a,0x050b,0x050c,
		0x050d,0x050e,0x050f,0x0510,0x0511,0x0512,0x0513,0x0514,0x0515,0x0516,0x0517,0x0518,0x0519,0x051a,0x051b,0x051c,0x051d,0x051e,0x051f,0x0520,
		0x0521,0x0522,0x0523,0x0524,0x0525,0x0526,0x0527,0x0528,0x0529,0x052a,0x052b,0x052c,0x052d,0x052e,0x052f,0x0530,0x0531,0x0532,0x0533,0x0534,
		0x0535,0x0536,0x0537,0x0538,0x0539,0x053a,0x053b,0x053c,0x053d,0x053e,0x053f,0x0540,0x0541,0x0543,0x0544,0x0545,0x0546,0x0547,0x0548,0x0549,
		0x054a,0x054b,0x054c,0x054d,0x054e,0x054f,0x0550,0x0551,0x0552,0x0553,0x0554,0x0555,0x0556,0x0557,0x0558,0x0559,0x055a,0x055b,0x055c,0x055d,
		0x055e,0x055f,0x0560,0x0561,0x0562,0x0563,0x0564,0x0565,0x0566,0x0567,0x0568,0x0569,0x056a,0x056b,0x056c,0x056d,0x056e,0x056f,0x0570,0x0571,
		0x0572,0x0573,0x0574,0x0575,0x0576,0x0577,0x0578,0x0579,0x057a,0x057b,0x057c,0x057d,0x057e,0x057f,0x0580,0x0581,0x0582,0x0583,0x0584,0x0585,
		0x0586,0x0587,0x0588,0x0589,0x058a,0x058b,0x058c,0x058d,0x058e,0x058f,0x0590,0x0591,0x0592,0x0593,0x0594,0x0595,0x0596,0x0597,0x0598,0x0599,
		0x059a,0x059b,0x059c,0x059d,0x059e,0x059f,0x05a0,0x05a1,0x05a2,0x05a3,0x05a4,0x05a5,0x05a6,0x05a7,0x05a8,0x05a9,0x05aa,0x05ab,0x05ac,0x05ad,
		0x05ae,0x05af,0x05b0,0x05b1,0x05b4,0x05b5,0x05b6,0x05b7,0x05b8,0x05b9,0x05ba,0x05bb,0x05bc,0x05bd,0x05be,0x05bf,0x05c0,0x05c1,0x05c2,0x05c5,
		0x05c6,0x05c7,0x05c8,0x05c9,0x05ca,0x05cb,0x05cc,0x05cd,0x05ce,0x05cf,0x05d0,0x05d1,0x05d2,0x05d3,0x05d5,0x05d6,0x05d7,0x05d8,0x05d9,0x05da,
		0x05db,0x05dc,0x05dd,0x05df,0x05e0,0x05e1,0x05e2,0x05e3,0x05e4,0x05e5,0x05e6,0x05e8,0x05e9,0x05eb,0x05ec,0x05ee,0x05ef,0x05f0,0x05f1,0x05f2,
		0x05f3,0x05f5,0x05f6,0x05f7,0x05f9,0x05fa,0x05fc,0x05fd,0x05fe,0x05ff,0x0600,0x0601,0x0602,0x0603,0x0604,0x0605,0x0606,0x0607,0x0608,0x0609,
		0x060a,0x060b,0x060c,0x060d,0x060e,0x060f,0x0610,0x0611,0x0613,0x0614,0x0615,0x0616,0x0617,0x0618,0x0619,0x061a,0x061b,0x061c,0x061d,0x061e,
		0x0620,0x0621,0x0622,0x0623,0x0624,0x0625,0x0626,0x0627,0x0628,0x0629,0x062a,0x062b,0x062c,0x062d,0x062e,0x062f,0x0631,0x0633,0x0634,0x0635,
		0x0636,0x0638,0x0639,0x063a,0x063b,0x063c,0x063d,0x063e,0x063f,0x0640,0x0641,0x0642,0x0644,0x0645,0x0646,0x0647,0x0648,0x0649,0x064b,0x064c,
		0x064d,0x064e,0x064f,0x0650,0x0651,0x0652,0x0653,0x0654,0x0655,0x0656,0x0657,0x0658,0x0659,0x065a,0x065b,0x065e,0x065f,0x0660,0x0661,0x0662,
		0x0663,0x0664,0x0665,0x0667,0x0668,0x0669,0x066a,0x066b,0x066d,0x066e,0x066f,0x0670,0x0672,0x0673,0x0674,0x0675,0x0676,0x0677,0x0678,0x067b,
		0x067c,0x067d,0x067e,0x067f,0x0680,0x0681,0x0682,0x0684,0x0685,0x0686,0x068a,0x068b,0x068e,0x0690,0x0693,0x0694,0x0698,0x0699,0x069a,0x069b,
		0x069d,0x069e,0x069f,0x06a2,0x06a3,0x06a4,0x06a5,0x06a7,0x06a8,0x06a9,0x06aa,0x06ac,0x06ad,0x06ae,0x06af,0x06b8,0x06b9,0x06ba,0x06bb,0x06bc,
		0x06bd,0x06be,0x06bf,0x06c2,0x06c4,0x06c5,0x06c6,0x06c8,0x06c9,0x06ca,0x06cb,0x06cc,0x06cd,0x06ce,0x06cf,0x06d0,0x06d1,0x06d3,0x06d4,0x06d5,
		0x06d6,0x06d7,0x06d8,0x06da,0x06db,0x06dc,0x06de,0x06e0,0x06e1,0x06e4,0x06e6,0x06ea,0x06eb,0x06ef,0x06f0,0x06f1,0x06f2,0x06f6,0x06f7,0x06f8,
		0x06f9,0x06fa,0x06fc,0x06fd,0x06fe,0x0701,0x0703,0x0705,0x0706,0x0707,0x0708,0x0709,0x070a,0x070d,0x070e,0x0710,0x0711,0x0713,0x0714,0x0717,
		0x0718,0x0719,0x071b,0x071c,0x071d,0x071e,0x0723,0x0726,0x0729,0x072e,0x072f,0x0731,0x0732,0x0733,0x0734,0x0735,0x0736,0x0738,0x073a,0x073b,
		0x073c,0x073d,0x073e,0x0745,0x0746,0x0747,0x0748,0x0749,0x074a,0x074b,0x074c,0x074d,0x074e,0x0755,0x0757,0x075b,0x0763,0x0764,0x0765,0x0766,
		0x0767,0x0768,0x0769,0x076a,0x076b,0x076c,0x076d,0x076e,0x076f,0x0770,0x0771,0x0772,0x0774,0x0775,0x0776,0x0777,0x0778,0x0779,0x077a,0x077b,
		0x077c,0x077d,0x077f,0x0780,0x0781,0x0782,0x0783,0x0784,0x0785,0x0789,0x078b,0x078c,0x078e,0x0790,0x0791,0x0792,0x0793,0x0794,0x0795,0x0796,
		0x0797,0x0798,0x0799,0x079b,0x079d,0x07a1,0x07a2,0x07a3,0x07a4,0x07a6,0x07aa,0x07ab,0x07af,0x07b0,0x07b1,0x07b2,0x07b3,0x07b4,0x07b5,0x07b6,
		0x07b7,0x07b8,0x07bc,0x07bd,0x07be,0x07c0,0x07c1,0x07c4,0x07c5,0x07c6,0x07c7,0x07c8,0x07c9,0x07ca,0x07cb,0x07cc,0x07cd,0x07cf,0x07d0,0x07d1,
		0x07d2,0x07d3,0x07d5,0x07d7,0x07da,0x07de,0x07df,0x07e1,0x07e2,0x07e3,0x07e4,0x07e5,0x07e6,0x07e7,0x07e8,0x07ea,0x07eb,0x07ec,0x07ee,0x07ef,
		0x07f2,0x07f6,0x07f7,0x07f9,0x07fa,0x07fd,0x07ff,0x0801,0x0802,0x0803,0x0809,0x080a,0x080b,0x080c,0x080d,0x0810,0x0813,0x0819,0x081a,0x081b,
		0x081c,0x081e,0x0822,0x0825,0x0826,0x0827,0x0828,0x0829,0x082d,0x0830,0x0832,0x0833,0x0835,0x0836,0x0839,0x083a,0x083f,0x0840,0x0841,0x0844,
		0x0846,0x084d,0x084e,0x084f,0x0850,0x0851,0x0852,0x0853,0x0854,0x0856,0x0858,0x0859,0x085a,0x085c,0x0862,0x0863,0x0864,0x0867,0x086a,0x086c,
		0x086e,0x086f,0x0870,0x0871,0x0873,0x0874,0x0879,0x087c,0x087d,0x087e,0x087f,0x0880,0x0883,0x0885,0x0886,0x0887,0x088a,0x088b,0x088c,0x088e,
		0x0892,0x0894,0x0897,0x089c,0x089d,0x089e,0x089f,0x08a5,0x08a6,0x08a8,0x08a9,0x08ae,0x08b0,0x08b4,0x08b7,0x08b8,0x08b9,0x08bb,0x08bd,0x08c3,
		0x08c4,0x08c7,0x08c8,0x08c9,0x08ca,0x08cd,0x08ce,0x08cf,0x08d1,0x08d3,0x08d4,0x08d8,0x08d9,0x08dd,0x08de,0x08df,0x08e3,0x08e4,0x08e5,0x08e6,
		0x08e7,0x08e8,0x08e9,0x08ea,0x08ec,0x08ed,0x08ee,0x08f0,0x08f1,0x08f2,0x08f5,0x08f6,0x08f7,0x08f8,0x08f9,0x08fa,0x08fb,0x08fc,0x08fd,0x08ff,
		0x0900,0x0901,0x0906,0x0908,0x0909,0x090a,0x090b,0x090c,0x090d,0x090e,0x090f,0x0910,0x0911,0x0912,0x0915,0x0917,0x0919,0x091e,0x0920,0x0921,
		0x0922,0x0923,0x0924,0x0925,0x0927,0x0928,0x0929,0x092a,0x092b,0x092f,0x0930,0x0931,0x0932,0x0933,0x0934,0x0936,0x0939,0x093a,0x093b,0x093c,
		0x093d,0x093e,0x093f,0x0940,0x0941,0x0942,0x0943,0x0944,0x0945,0x0948,0x094b,0x094d,0x094f,0x0951,0x0954,0x0955,0x0956,0x0957,0x0958,0x0959,
		0x095a,0x095b,0x095c,0x095d,0x0967,0x0968,0x096e,0x0971,0x0973,0x0974,0x0975,0x0976,0x0977,0x0978,0x0979,0x097a,0x097b,0x097c,0x097d,0x097e,
		0x097f,0x0981,0x0984,0x0985,0x0986,0x098c,0x098d,0x098e,0x098f,0x0993,0x0996,0x099a,0x09a3,0x09a4,0x09a5,0x09a6,0x09a7,0x09a8,0x09a9,0x09aa,
		0x09ab,0x09ae,0x09b2,0x09b3,0x09b4,0x09b5,0x09bc,0x09be,0x09bf,0x09c0,0x09c1,0x09c2,0x09c3,0x09c4,0x09c5,0x09cc,0x09cd,0x09ce,0x09cf,0x09d1,
		0x09d2,0x09d3,0x09d7,0x09d9,0x09da,0x09db,0x09dc,0x09dd,0x09df,0x09e1,0x09e5,0x09e6,0x09e7,0x09e8,0x09e9,0x09eb,0x09ef,0x09f3,0x09f5,0x09f6,
		0x09f7,0x09f8,0x09f9,0x09fa,0x09fb,0x09ff,0x0a00,0x0a01,0x0a05,0x0a07,0x0a0b,0x0a0d,0x0a11,0x0a12,0x0a13,0x0a14,0x0a15,0x0a16,0x0a17,0x0a18,
		0x0a19,0x0a21,0x0a22,0x0a27,0x0a2c,0x0a34,0x0a35,0x0a39,0x0a3a,0x0a3c,0x0a3d,0x0a3f,0x0a43,0x0a46,0x0a47,0x0a48,0x0a4a,0x0a4b,0x0a4c,0x0a4d,
		0x0a4e,0x0a4f,0x0a50,0x0a51,0x0a52,0x0a53,0x0a5a,0x0a5b,0x0a5c,0x0a5d,0x0a5f,0x0a62,0x0a66,0x0a67,0x0a68,0x0a69,0x0a6b,0x0a6c,0x0a6d,0x0a6e,
		0x0a6f,0x0a70,0x0a71,0x0a72,0x0a73,0x0a7d,0x0a7e,0x0a80,0x0a81,0x0a82,0x0a83,0x0a84,0x0a85,0x0a86,0x0a8d,0x0a8e,0x0a90,0x0a91,0x0a92,0x0a93,
		0x0a94,0x0aa3,0x0aa4,0x0aa5,0x0aa6,0x0aa7,0x0aa8,0x0aa9,0x0aaa,0x0aab,0x0aac,0x0aad,0x0aae,0x0aaf,0x0ab0,0x0ab1,0x0aba,0x0abe,0x0abf,0x0ac3,
		0x0ac4,0x0ac5,0x0ac6,0x0ac7,0x0ac8,0x0ac9,0x0aca,0x0acc,0x0acd,0x0ace,0x0acf,0x0ad0,0x0ad1,0x0ad2,0x0ada,0x0ae3,0x0ae4,0x0ae7,0x0ae8,0x0ae9,
		0x0aea,0x0aeb,0x0aec,0x0af0,0x0af6,0x0af7,0x0af9,0x0afa,0x0afc,0x0afd,0x0afe,0x0aff,0x0b00,0x0b05,0x0b0b,0x0b0c,0x0b0d,0x0b0e,0x0b0f,0x0b10,
		0x0b11,0x0b1e,0x0b1f,0x0b20,0x0b21,0x0b22,0x0b23,0x0b24,0x0b27,0x0b28,0x0b2c,0x0b30,0x0b33,0x0b37,0x0b38,0x0b39,0x0b3a,0x0b3b,0x0b3c,0x0b3e,
		0x0b41,0x0b43,0x0b47,0x0b48,0x0b49,0x0b4b,0x0b4d,0x0b4e,0x0b50,0x0b51,0x0b52,0x0b54,0x0b56,0x0b57,0x0b59,0x0b5a,0x0b5f,0x0b60,0x0b61,0x0b62,
		0x0b63,0x0b64,0x0b65,0x0b66,0x0b67,0x0b69,0x0b6a,0x0b6f,0x0b70,0x0b71,0x0b72,0x0b73,0x0b75,0x0b79,0x0b7a,0x0b7b,0x0b7c,0x0b7d,0x0b81,0x0b84,
		0x0b85,0x0b86,0x0b87,0x0b88,0x0b89,0x0b8c,0x0b95,0x0b96,0x0b97,0x0b98,0x0b99,0x0b9b,0x0b9d,0x0b9f,0x0baf,0x0bb0,0x0bb1,0x0bb2,0x0bb3,0x0bb4,
		0x0bb5,0x0bb6,0x0bb7,0x0bb8,0x0bb9,0x0bba,0x0bbb,0x0bbc,0x0bbd,0x0bc0,0x0bc1,0x0bc2,0x0bc3,0x0bc4,0x0bc5,0x0bc6,0x0bc7,0x0bc8,0x0bc9,0x0bca,
		0x0bcb,0x0bd7,0x0bda,0x0bdb,0x0bdc,0x0bdd,0x0be2,0x0be3,0x0be4,0x0be5,0x0be6,0x0bed,0x0bee,0x0bef,0x0bf0,0x0bf1,0x0bf2,0x0bf6,0x0bf7,0x0bf8,
		0x0bfd,0x0c04,0x0c05,0x0c06,0x0c07,0x0c08,0x0c09,0x0c0a,0x0c0b,0x0c12,0x0c15,0x0c16,0x0c17,0x0c18,0x0c19,0x0c1a,0x0c1b,0x0c1c,0x0c22,0x0c23,
		0x0c24,0x0c25,0x0c26,0x0c27,0x0c2e,0x0c35,0x0c36,0x0c37,0x0c38,0x0c39,0x0c3a,0x0c3b,0x0c3c,0x0c3d,0x0c3e,0x0c44,0x0c45,0x0c46,0x0c4a,0x0c4b,
		0x0c4c,0x0c52,0x0c53,0x0c54,0x0c55,0x0c56,0x0c57,0x0c58,0x0c59,0x0c5a,0x0c5e,0x0c60,0x0c62,0x0c63,0x0c64,0x0c65,0x0c66,0x0c67,0x0c6a,0x0c6c,
		0x0c70,0x0c72,0x0c74,0x0c76,0x0c77,0x0c78,0x0c79,0x0c7a,0x0c86,0x0c88,0x0c89,0x0c8a,0x0c8b,0x0c8c,0x0c8d,0x0c8e,0x0c8f,0x0c94,0x0c98,0x0c99,
		0x0c9a,0x0c9b,0x0c9d,0x0ca2,0x0ca3,0x0ca4,0x0ca5,0x0ca6,0x0ca7,0x0cad,0x0cae,0x0caf,0x0cb0,0x0cb1,0x0cb6,0x0cb7,0x0cb8,0x0cba,0x0cbb,0x0cbc,
		0x0cbd,0x0cbe,0x0cbf,0x0cc0,0x0cc1,0x0cc2,0x0cc3,0x0cc4,0x0cc5,0x0cc6,0x0cc7,0x0cc8,0x0cc9,0x0cca,0x0ccb,0x0ccc,0x0ccd,0x0cd4,0x0cd5,0x0cd7,
		0x0cd8,0x0cd9,0x0cde,0x0ce5,0x0ce9,0x0cf1,0x0cf2,0x0cf3,0x0cf4,0x0cf5,0x0cf6,0x0cf7,0x0cf8,0x0cf9,0x0cfa,0x0cfc,0x0cff,0x0d06,0x0d08,0x0d0b,
		0x0d0c,0x0d0d,0x0d0e,0x0d0f,0x0d10,0x0d11,0x0d12,0x0d13,0x0d14,0x0d15,0x0d16,0x0d17,0x0d18,0x0d19,0x0d28,0x0d32,0x0d33,0x0d34,0x0d35,0x0d3a,
		0x0d3c,0x0d3d,0x0d3e,0x0d3f,0x0d40,0x0d41,0x0d42,0x0d46,0x0d48,0x0d49,0x0d4a,0x0d4b,0x0d4c,0x0d4d,0x0d4e,0x0d4f,0x0d50,0x0d51,0x0d53,0x0d54,
		0x0d55,0x0d56,0x0d57,0x0d5c,0x0d5e,0x0d5f,0x0d60,0x0d61,0x0d62,0x0d63,0x0d64,0x0d65,0x0d66,0x0d67,0x0d68,0x0d69,0x0d6a,0x0d6b,0x0d70,0x0d71,
		0x0d72,0x0d73,0x0d76,0x0d77,0x0d78,0x0d7a,0x0d7b,0x0d7c,0x0d7d,0x0d7e,0x0d7f,0x0d80,0x0d81,0x0d83,0x0d87,0x0d89,0x0d8a,0x0d8b,0x0d8c,0x0d8d,
		0x0d8e,0x0d8f,0x0d90,0x0d96,0x0d97,0x0d98,0x0d99,0x0d9a,0x0d9b,0x0d9c,0x0d9d,0x0d9e,0x0d9f,0x0da0,0x0da1,0x0da2,0x0da3,0x0da4,0x0da7,0x0da8,
		0x0dab,0x0dad,0x0db0,0x0db1,0x0db2,0x0db3,0x0db4,0x0db7,0x0dba,0x0dbc,0x0dbe,0x0dbf,0x0dc0,0x0dc1,0x0dc3,0x0dc4,0x0dc5,0x0dc6,0x0dc7,0x0dcd,
		0x0dd0,0x0dd1,0x0dd2,0x0dd3,0x0dd4,0x0dd5,0x0dd7,0x0dd8,0x0dd9,0x0dda,0x0ddb,0x0ddd,0x0dde,0x0de0,0x0de7,0x0dea,0x0ded,0x0dee,0x0def,0x0df4,
		0x0df6,0x0df7,0x0dfa,0x0dfc,0x0e03,0x0e08,0x0e0b,0x0e0c,0x0e0f,0x0e16,0x0e17,0x0e1a,0x0e1b,0x0e20,0x0e21,0x0e22,0x0e23,0x0e25,0x0e26,0x0e30,
		0x0e34,0x0e35,0x0e36,0x0e38,0x0e39,0x0e3a,0x0e3b,0x0e41,0x0e44,0x0e48,0x0e4a,0x0e4c,0x0e50,0x0e55,0x0e56,0x0e5a,0x0e5b,0x0e5c,0x0e5d,0x0e5e,
		0x0e66,0x0e67,0x0e6a,0x0e6f,0x0e70,0x0e72,0x0e75,0x0e79,0x0e7b,0x0e7e,0x0e82,0x0e83,0x0e8c,0x0e8d,0x0e8f,0x0e90,0x0e91,0x0e92,0x0e93,0x0e95,
		0x0e96,0x0e97,0x0e98,0x0e99,0x0e9a,0x0e9b,0x0e9c,0x0e9f,0x0ea0,0x0ea6,0x0ea7,0x0ea8,0x0ead,0x0eb0,0x0eb1,0x0eb2,0x0eb3,0x0eb7,0x0eb8,0x0ebb,
		0x0ebe,0x0ebf,0x0ec0,0x0ec1,0x0ec2,0x0ec3,0x0ec4,0x0ec5,0x0ec6,0x0ec7,0x0ecd,0x0ece,0x0ecf,0x0ed1,0x0ed2,0x0ed3,0x0ed5,0x0eda,0x0edf,0x0ee0,
		0x0ee1,0x0ee2,0x0ee3,0x0ee4,0x0eee,0x0eef,0x0ef0,0x0ef1,0x0ef2,0x0ef3,0x0ef4,0x0ef5,0x0ef6,0x0ef7,0x0efd,0x0efe,0x0f03,0x0f06,0x0f08,0x0f0c,
		0x0f0d,0x0f0e,0x0f11,0x0f12,0x0f13,0x0f14,0x0f18,0x0f19,0x0f1b,0x0f1c,0x0f1d,0x0f21,0x0f22,0x0f23,0x0f24,0x0f2d,0x0f2e,0x0f2f,0x0f30,0x0f31,
		0x0f32,0x0f37,0x0f38,0x0f39,0x0f3d,0x0f41,0x0f42,0x0f44,0x0f4b,0x0f4c,0x0f4d,0x0f4e,0x0f52,0x0f53,0x0f54,0x0f55,0x0f5c,0x0f5d,0x0f5f,0x0f60,
		0x0f61,0x0f62,0x0f63,0x0f68,0x0f69,0x0f6a,0x0f6e,0x0f73,0x0f78,0x0f7c,0x0f7d,0x0f7e,0x0f88,0x0f8b,0x0f8c,0x0f8d,0x0f8e,0x0f8f,0x0f97,0x0f98,
		0x0f9c,0x0f9e,0x0fa3,0x0fa4,0x0fa5,0x0fa7,0x0fa8,0x0faf,0x0fb0,0x0fb1,0x0fb2,0x0fb6,0x0fb8,0x0fb9,0x0fba,0x0fbb,0x0fc1,0x0fc2,0x0fc5,0x0fc6,
		0x0fca,0x0fce,0x0fcf,0x0fd0,0x0fd1,0x0fd2,0x0fd4,0x0fd5,0x0fd9,0x0fda,0x0fdc,0x0fde,0x0fe0,0x0fe4,0x0fe5,0x0fe6,0x0fe9,0x0fea,0x0feb,0x0fec,
		0x0fed,0x0fee,0x0fef,0x0ff6,0x0ff7,0x0ffc,0x0ffd,0x0fff,0x1000,0x1001,0x1003,0x1004,0x1005,0x1006,0x1009,0x100a,0x100b,0x100d,0x1010,0x1011,
		0x1012,0x1013,0x1014,0x1015,0x1016,0x1017,0x1019,0x1020,0x1022,0x1025,0x1026,0x1027,0x1028,0x1029,0x102a,0x102b,0x102c,0x102d,0x1031,0x1032,
		0x1033,0x1038,0x1039,0x103d,0x1043,0x1044,0x1046,0x1048,0x104b,0x104c,0x104d,0x104f,0x1050,0x1053,0x1054,0x1055,0x1056,0x1057,0x1058,0x1059,
		0x105c,0x105d,0x105e,0x105f,0x1060,0x1063,0x1065,0x106a,0x106c,0x106d,0x106e,0x106f,0x1076,0x107b,0x107d,0x107e,0x107f,0x1082,0x1083,0x1084,
		0x108a,0x108b,0x108c,0x108e,0x1099,0x109a,0x109b,0x109f,0x10a0,0x10a3,0x10a9,0x10aa,0x10ab,0x10ac,0x10ae,0x10af,0x10b5,0x10b8,0x10bb,0x10bc,
		0x10bd,0x10bf,0x10c3,0x10c4,0x10c5,0x10c6,0x10cb,0x10cc,0x10cd,0x10ce,0x10cf,0x10d1,0x10d4,0x10d5,0x10d6,0x10de,0x10df,0x10e0,0x10e1,0x10e2,
		0x10ec,0x10f0,0x10f1,0x10f5,0x10fb,0x10fd,0x10fe,0x1100,0x1101,0x1108,0x110a,0x1110,0x1111,0x1112,0x1113,0x111e,0x112a,0x112e,0x112f,0x1130,
		0x1131,0x1132,0x1136,0x113c,0x113d,0x1141,0x1142,0x1145,0x1146,0x1147,0x114b,0x114c,0x114d,0x114f,0x115b,0x1162,0x1163,0x1164,0x1165,0x1166,
		0x1167,0x1168,0x116e,0x116f,0x1175,0x117d,0x117e,0x1182,0x1183,0x1184,0x1188,0x1189,0x118f,0x1190,0x1191,0x1196,0x1197,0x1198,0x1199,0x119a,
		0x119b,0x11a0,0x11a3,0x11aa,0x11ab,0x11ac,0x11b0,0x11be,0x11c5,0x11ca,0x11db,0x11e6,0x11f5,0x11f6,0x11f7,0x1203,0x1209,0x120e,0x120f,0x1210,
		0x121e,0x1223,0x1228,0x1230,0x1233,0x1234,0x1235,0x1241,0x124a,0x124b,0x124c,0x125c,0x125f,0x1260,0x1264,0x1266,0x1267,0x126c,0x126d,0x126e,
		0x126f,0x1274,0x1275,0x1278,0x1283,0x1286,0x1291,0x1292,0x1293,0x1294,0x129b,0x12a7,0x12ab,0x12b8,0x12b9,0x12ba,0x12c4,0x12cf,0x12d1,0x12d2,
		0x12d6,0x12d7,0x12d8,0x12e6,0x12ef,0x12f5,0x12f7,0x12fd,0x12ff,0x1307,0x1308,0x1310,0x1312,0x1313,0x131d,0x132a,0x132b,0x1342,0x1343,0x1345,
		0x1347,0x1348,0x134c,0x134e,0x1357,0x1366,0x136b,0x1370,0x1371,0x1376,0x137b,0x1385,0x138a,0x138e,0x1390,0x1391,0x1395,0x1397,0x1398,0x13ad,
		0x13b0,0x13b1,0x13b2,0x13b3,0x13ba,0x13be,0x13ca,0x13cf,0x13d0,0x13d1,0x13d2,0x13d3,0x13dc,0x13dd,0x13e1,0x13e5,0x13e6,0x13ea,0x13ec,0x13ee,
		0x13fd,0x13fe,0x1400,0x1402,0x1403,0x1409,0x140e,0x1410,0x1415,0x1419,0x1421,0x1429,0x142a,0x142b,0x1430,0x1431,0x1435,0x1436,0x143c,0x1443,
		0x1446,0x1453,0x1456,0x1457,0x145f,0x1460,0x1461,0x1462,0x1472,0x147a,0x147e,0x147f,0x1482,0x1484,0x1485,0x1487,0x148e,0x148f,0x1491,0x1493,
		0x1497,0x1498,0x149a,0x14aa,0x14ad,0x14ae,0x14af,0x14b0,0x14b2,0x14c0,0x14c2,0x14c8,0x14cd,0x14d8,0x14dd,0x14e0,0x14e1,0x14e4,0x14e5,0x14ea,
		0x14ed,0x14f7,0x1500,0x1501,0x1509,0x1513,0x1514,0x1516,0x1518,0x1519,0x1520,0x1524,0x1527,0x1529,0x152a,0x152d,0x152e,0x1532,0x153b,0x1546,
		0x1547,0x154a,0x154b,0x154d,0x154e,0x154f,0x1554,0x1557,0x1568,0x156f,0x1570,0x157b,0x157e,0x1582,0x1587,0x158d,0x158e,0x1598,0x15a2,0x15a4,
		0x15a8,0x15a9,0x15aa,0x15ad,0x15ba,0x15c0,0x15c2,0x15c5,0x15c6,0x15c8,0x15c9,0x15ca,0x15d5,0x15d9,0x15dc,0x15e0,0x15e1,0x15e4,0x15e8,0x15e9,
		0x15ec,0x15f4,0x1604,0x1606,0x1608,0x160a,0x160e,0x1614,0x1619,0x1621,0x1628,0x162a,0x162f,0x1630,0x1631,0x1645,0x1649,0x164a,0x164c,0x1657,
		0x165b,0x165c,0x1660,0x1668,0x1669,0x166a,0x1677,0x1679,0x1680,0x1681,0x1682,0x1684,0x1685,0x1686,0x1687,0x1688,0x1689,0x168c,0x1690,0x1696,
		0x1697,0x16a5,0x16a6,0x16ab,0x16ac,0x16b4,0x16b5,0x16c0,0x16ca,0x16cc,0x16d0,0x16d1,0x16d3,0x16d5,0x16d6,0x16d8,0x16dc,0x16df,0x16f0,0x16f5,
		0x1706,0x1707,0x170b,0x170d,0x1711,0x1724,0x1725,0x1726,0x172f,0x1733,0x1736,0x1737,0x173d,0x1740,0x1743,0x1748,0x174c,0x174f,0x1753,0x1756,
		0x1759,0x1761,0x1772,0x1776,0x177f,0x1781,0x1782,0x1784,0x1787,0x1788,0x1796,0x1797,0x1799,0x179d,0x17a0,0x17a4,0x17a5,0x17a7,0x17a8,0x17b3,
		0x17b5,0x17ba,0x17c3,0x17cc,0x17cf,0x17d0,0x17d3,0x17e9,0x17eb,0x17ef,0x17f4,0x17f5,0x17f6,0x1809,0x1822,0x1831,0x1832,0x183d,0x1843,0x1849,
		0x1852,0x1854,0x185b,0x1861,0x1862,0x1870,0x1871,0x1873,0x187c,0x187f,0x1892,0x1894,0x1897,0x189f,0x18a4,0x18a5,0x18b1,0x18b4,0x18b6,0x18b7,
		0x18c5,0x18cd,0x18d1,0x18d5,0x18d9,0x18dc,0x18dd,0x18e3,0x18e8,0x18ea,0x18ec,0x18fd,0x1908,0x190d,0x1914,0x1915,0x1923,0x1926,0x192f,0x1930,
		0x1931,0x1934,0x1941,0x1943,0x1949,0x194f,0x1951,0x1953,0x1954,0x195d,0x1965,0x1967,0x196b,0x1970,0x1975,0x1976,0x1977,0x197d,0x1989,0x198f,
		0x1990,0x1995,0x199b,0x199e,0x199f,0x19a8,0x19ab,0x19af,0x19b2,0x19b4,0x19b5,0x19b6,0x19b9,0x19c2,0x19ca,0x19cf,0x19d2,0x19db,0x19e1,0x19e8,
		0x19ef,0x19f7,0x19fa,0x19ff,0x1a08,0x1a0a,0x1a12,0x1a1d,0x1a25,0x1a2a,0x1a2c,0x1a32,0x1a34,0x1a36,0x1a40,0x1a41,0x1a44,0x1a4a,0x1a4b,0x1a5a,
		0x1a61,0x1a6a,0x1a6d,0x1a6e,0x1a6f,0x1a72,0x1a79,0x1a7b,0x1a7c,0x1a81,0x1a86,0x1a89,0x1a8b,0x1a8d,0x1a98,0x1aa4,0x1aa5,0x1aa6,0x1aad,0x1ab1,
		0x1acb,0x1acc,0x1ad1,0x1ad4,0x1adb,0x1ae4,0x1ae7,0x1aed,0x1aef,0x1af1,0x1afe,0x1b04,0x1b0e,0x1b1c,0x1b20,0x1b22,0x1b26,0x1b27,0x1b28,0x1b32,
		0x1b36,0x1b3b,0x1b3f,0x1b47,0x1b48,0x1b52,0x1b59,0x1b5a,0x1b65,0x1b71,0x1b72,0x1b73,0x1b75,0x1b76,0x1b80,0x1b86,0x1b88,0x1b8c,0x1b8d,0x1b8e,
		0x1b8f,0x1b96,0x1b98,0x1b99,0x1ba1,0x1ba2,0x1ba4,0x1ba6,0x1ba8,0x1bad,0x1bae,0x1bbb,0x1bc4,0x1bc5,0x1bc7,0x1bce,0x1bcf,0x1bd0,0x1bd5,0x1bde,
		0x1bef,0x1bf0,0x1bf5,0x1bf6,0x1bfd,0x1c02,0x1c04,0x1c0c,0x1c0d,0x1c10,0x1c13,0x1c1a,0x1c1b,0x1c1f,0x1c20,0x1c21,0x1c22,0x1c26,0x1c27,0x1c31,
		0x1c34,0x1c37,0x1c3d,0x1c3e,0x1c40,0x1c49,0x1c4f,0x1c6b,0x1c6c,0x1c73,0x1c77,0x1c78,0x1c79,0x1c7a,0x1c7b,0x1c83,0x1c87,0x1c88,0x1c89,0x1c8e,
		0x1c98,0x1c9e,0x1ca0,0x1ca1,0x1cac,0x1cb3,0x1cb4,0x1cb6,0x1cbe,0x1cbf,0x1cc0,0x1cca,0x1ccd,0x1cd4,0x1cd5,0x1cd6,0x1cde,0x1cdf,0x1ce0,0x1ce1,
		0x1cf1,0x1cfc,0x1cfd,0x1d03,0x1d07,0x1d08,0x1d09,0x1d0a,0x1d0b,0x1d0f,0x1d14,0x1d17,0x1d19,0x1d1f,0x1d20,0x1d27,0x1d34,0x1d45,0x1d4d,0x1d50,
		0x1d57,0x1d5b,0x1d6b,0x1d90,0x1de1,0x1e0e,0x1e10,0x1e17,0x1e1d,0x1e1f,0x1e29,0x1e3d,0x1e41,0x1e4e,0x1e54,0x1e68,0x1e71,0x1e74,0x1e7d,0x1ebb,
		0x1eda,0x1edb,0x1ee8,0x1ef6,0x1f28,0x1f3a,0x1f44,0x1f48,0x1f4d,0x1f6f,0x1f75,0x1f82,0x1f84,0x1f87,0x1f9b,0x1fab,0x1fbd,0x1fc9,0x1fde,0x1fe7,
		0x1ff7,0x1fff,0x2001,0x2002,0x200c,0x2013,0x2019,0x2040,0x2047,0x2080,0x2087,0x20a0,0x20b1,0x20b3,0x20b7,0x20df,0x20f4,0x2101,0x2149,0x2162,
		0x2184,0x21a1,0x21d6,0x2222,0x2227,0x2232,0x2233,0x2237,0x228d,0x22a6,0x22b8,0x22b9,0x22ba,0x2304,0x2318,0x2341,0x2373,0x2375,0x2406,0x2443,
		0x2478,0x2632,0x2650,0x2659,0x2730,0x2735,0x2770,0x2821,0x2899,0x2c02,0x2c1a,0x2fb2,0x3125,0x3176,0x3275,0x3334,0x3340,0x3504,0x3538,0x3579,
		0x3636,0x3838,0x3923,0x40bb,0x4101,0x4102,0x413c,0x4146,0x4242,0x4317,0x4348,0x4572,0x4586,0x4670,0x4752,0x4757,0x4766,0x4855,0x4971,0x4d46,
		0x5032,0x5041,0x50c2,0x5173,0x5219,0x5345,0x544d,0x5543,0x5555,0x55aa,0x5656,0x595a,0x5986,0x5a57,0x6000,0x601a,0x6189,0x6253,0x636c,0x6472,
		0x6547,0x6615,0x6666,0x6677,0x6891,0x695c,0x6993,0x6a75,0x7104,0x726c,0x734c,0x7392,0x8086,0x8087,0x80ee,0x8282,0x8341,0x9016,0x9022,0x9148,
		0x9710,0x99fa,0x9ac4,0xa128,0xa168,0xa600,0xa727,0xabcd,0xc251,0xcace,0xd209,0xe4e4,0xeb03,0xeb1a,0xeb2a,0xf003,0xf4ec};


		char* mids[] = {
		"Fry's Electronics","Ingram","Club Mac","Nebraska Furniture Mart","Unknown",
		"Planex","DragonRise Inc.","Trust International B.V.","Unknown","MLK",
		"TP-Link","Chipsbank Microelectronics Co., Ltd","Hangzhou Worlde","HUMAX Co., Ltd.","MM300 eBook Reader",
		"OCZ Technology Inc","OCZ Technology Inc","LTS","Shenzhen Sinote Tech-Electron Co., Ltd","Bernd Walter Computer Technology",
		"EndPoints, Inc.","Thesys Microelectronics","Data Broadcasting Corp.","Atmel Corp.","Iwatsu America, Inc.",
		"Mitel Corp.","Mitsumi","Hewlett-Packard","Genoa Technology","Oak Technology, Inc.",
		"Adaptec, Inc.","Diebold, Inc.","Siemens Electromechanical","Epson Imaging Technology Center","KeyTronic Corp.",
		"OPTi, Inc.","Elitegroup Computer Systems","Xilinx, Inc.","Farallon Comunications","National Semiconductor Corp.",
		"National Registry, Inc.","ALi Corp.","Future Technology Devices International, Ltd","NCR Corp.","Synopsys, Inc.",
		"Fujitsu-ICL Computers","Fujitsu Personal Systems, Inc.","Quanta Computer, Inc.","NEC Corp.","Kodak Co.",
		"Weltrend Semiconductor","VTech Computers, Ltd","VIA Technologies, Inc.","MCCI","Echo Speech Corp.",
		"BUFFALO INC. (formerly MelCo., Inc.)","Award Software International","Leadtek Research, Inc.","Giga-Byte Technology Co., Ltd","Winbond Electronics Corp.",
		"Symbios Logic","AST Research","Samsung Info. Systems America, Inc.","Phoenix Technologies, Ltd","d'TV",
		"S3, Inc.","Creative Technology, Ltd","LCS Telegraphics","Chips and Technologies","Nokia Mobile Phones",
		"ADI Systems, Inc.","Computer Access Technology Corp.","Standard Microsystems Corp.","Motorola Semiconductors HK, Ltd","Integrated Device Technology, Inc.",
		"Motorola Electronics Taiwan, Ltd","Advanced Gravis Computer Tech, Ltd","Cirrus Logic","Ericsson Austrian, AG","Intel Corp.",
		"Innovative Semiconductors, Inc.","Micronics","Acer, Inc.","Molex, Inc.","Sun Microsystems, Inc.",
		"Itac Systems, Inc.","Unisys Corp.","Alps Electric, Inc.","Samsung Info. Systems America, Inc.","Hyundai Electronics America",
		"Taugagreining HF","Framatome Connectors USA","Advanced Micro Devices, Inc.","Voice Technologies Group","Lexmark International, Inc.",
		"LG Electronics USA, Inc.","RadiSys Corp.","Eizo Nanao Corp.","Winbond Systems Lab.","Ericsson, Inc.",
		"Gateway, Inc.","Lucent Technologies, Inc.","NMB Technologies Corp.","Momentum Microsystems","Shamrock Tech. Co., Ltd",
		"WSI","CCL/ITRI","Siemens Nixdorf AG","Alps Electric Co., Ltd","ThrustMaster, Inc.",
		"DFI, Inc.","Texas Instruments, Inc.","Mitsubishi Electronics America, Inc.","CMD Technology","Vobis Microcomputer AG",
		"Telematics International, Inc.","Analog Devices, Inc.","Silicon Integrated Systems Corp.","KYE Systems Corp. (Mouse Systems)","Adobe Systems, Inc.",
		"SONICblue, Inc.","Hitachi, Ltd","Nortel Networks, Ltd","Microsoft Corp.","Ace Cad Enterprise Co., Ltd",
		"Primax Electronics, Ltd","MGE UPS Systems","AMP/Tycoelectronics Corp.","AT&T Paradyne","Wieson Technologies Co., Ltd",
		"Cherry GmbH","American Megatrends, Inc.","Toshiba Corp., Digital Media Equipment","Logitech, Inc.","Behavior Tech. Computer Corp.",
		"Crystal Semiconductor","Philips (or NXP)","Chicony Electronics Co., Ltd","Sanyo Information Business Co., Ltd","Sanyo Electric Co., Ltd",
		"Relisys/Teco Information System","AESP","Seagate Technology, Inc.","Connectix Corp.","Advanced Peripheral Laboratories",
		"Semtech Corp.","Silitek Corp.","Dell Computer Corp.","Kensington","Agere Systems, Inc. (Lucent)",
		"Plantronics, Inc.","Toshiba America Info. Systems, Inc.","Zenith Data Systems","Kyocera Corp.","STMicroelectronics",
		"Specialix","Nokia Monitors","ASUS Computers, Inc.","Stewart Connector","Cirque Corp.",
		"Foxconn / Hon Hai","S-MOS Systems, Inc.","Alps Electric Ireland, Ltd","Integrated Technology Express, Inc.","Eicon Tech.",
		"United Microelectronics Corp.","Capetronic","Samsung SemiConductor, Inc.","MAG Technology Co., Ltd","ESS Technology, Inc.",
		"Micron Electronics","Smile International","Capetronic (Kaohsiung) Corp.","Yamaha Corp.","Gandalf Technologies, Ltd",
		"Curtis Computer Products","Acer Advanced Labs, Inc.","VLSI Technology","Compaq Computer Corp.","Digital Equipment Corp.",
		"SystemSoft Corp.","FirePower Systems","Trident Microsystems, Inc.","Hitachi, Ltd","Acer Peripherals Inc. (now BenQ Corp.)",
		"Nokia Display Products","Visioneer","Multivideo Labs, Inc.","Canon, Inc.","DaeWoo Telecom, Ltd",
		"Chromatic Research","Micro Audiometrics Corp.","Dooin Electronics","Winnov L.P.","Nikon Corp.",
		"Pan International","IBM Corp.","Cypress Semiconductor Corp.","ROHM LSI Systems USA, LLC","Hint Corp.",
		"Compal Electronics, Inc.","Seiko Epson Corp.","Rainbow Technologies, Inc.","Toucan Systems, Ltd","I-O Data Device, Inc.",
		"Toshiba Electronics Taiwan Corp.","Telia Research AB","TDK Corp.","U.S. Robotics (3Com)","Methode Electronics Far East PTE, Ltd",
		"Maxi Switch, Inc.","Lockheed Martin Energy Research","Fujitsu, Ltd","Toshiba America Electronic Components","Micro Macro Technologies",
		"Konica Corp.","Lite-On Technology Corp.","Fuji Photo Film Co., Ltd","ST-Ericsson","Tatung Co. Of America",
		"ScanLogic Corp.","Myson Century, Inc.","Digi International","ITT Canon","Altec Lansing Technologies",
		"VidUS, Inc.","LSI Logic, Inc.","Forte Technologies, Inc.","Mentor Graphics","Oki Semiconductor",
		"Microchip Technology, Inc.","Holtek Semiconductor, Inc.","Panasonic (Matsushita)","Hypertec Pty, Ltd","Huan Hsin Holdings, Ltd",
		"Sharp Corp.","MindShare, Inc.","Interlink Electronics","Iiyama North America, Inc.","Exar Corp.",
		"Zilog, Inc.","ACC Microelectronics","Promise Technology","SCM Microsystems, Inc.","Elo TouchSystems",
		"Samsung Electronics Co., Ltd","PC-Tel, Inc.","Brooktree Corp.","Northstar Systems, Inc.","Tokyo Electron Device, Ltd",
		"Annabooks","Pacific Electronic International, Inc.","Daewoo Electronics Co., Ltd","Victor Company of Japan, Ltd","Chicony Electronics Co., Ltd",
		"Elan Microelectronics Corp.","Harting Elektronik, Inc.","Fujitsu-ICL Systems, Inc.","Norand Corp.","Newnex Technology Corp.",
		"FuturePlus Systems","Brother Industries, Ltd","Dallas Semiconductor","Biostar Microtech International Corp.","Sunplus Technology Co., Ltd",
		"Soliton Systems, K.K.","PFU, Ltd","E-CMOS Corp.","Siam United Hi-Tech","Fujikura DDK, Ltd",
		"Acer, Inc.","Hitachi America, Ltd","Hayes Microcomputer Products","3Com Corp.","Hosiden Corp.",
		"Clarion Co., Ltd","Aztech Systems, Ltd","Cinch Connectors","Cable System International","InnoMedia, Inc.",
		"Belkin Components","Neon Technology, Inc.","KC Technology, Inc.","Sejin Electron, Inc.","N'Able (DataBook) Technologies, Inc.",
		"Hualon Microelectronics Corp.","digital-X, Inc.","FCI Electronics","ACTC","Longwell Electronics",
		"Butterfly Communications","EzKEY Corp.","Star Micronics Co., Ltd","WYSE Technology","Silicon Graphics",
		"Shuttle, Inc.","American Power Conversion","Scientific Atlanta, Inc.","IO Systems (Elite Electronics), Inc.","Taiwan Semiconductor Manufacturing Co.",
		"Airborn Connectors","Advanced Connectek, Inc.","ATEN GmbH","Sola Electronics","Netchip Technology, Inc.",
		"Temic MHS S.A.","ALTRA","ATI Technologies, Inc.","Aladdin Knowledge Systems","Crescent Heart Software",
		"Tekom Technologies, Inc.","Canon Information Systems, Inc.","Avid Electronics Corp.","Standard Microsystems Corp.","Unicore Software, Inc.",
		"American Microsystems, Inc.","Wacom Technology Corp.","Systech Corp.","Alcatel Mobile Phones","Motorola, Inc.",
		"LIH TZU Electric Co., Ltd","Hand Held Products (Welch Allyn, Inc.)","Inventec Corp.","Caldera International, Inc. (SCO)","Shyh Shiun Terminals Co., Ltd",
		"PrehKeyTec GmbH","Global Village Communication","Institut of Microelectronic & Mechatronic Systems","Silicon Architect","Mobility Electronics",
		"Synopsys, Inc.","UniAccess AB","Sirf Technology, Inc.","ViewSonic Corp.","Cristie Electronics, Ltd",
		"Xirlink, Inc.","Polaroid Corp.","Anchor Chips, Inc.","Tyan Computer Corp.","Pixera Corp.",
		"Fujitsu Microelectronics, Inc.","New Media Corp.","Sony Corp.","Try Corp.","Proside Corp.",
		"WYSE Technology Taiwan","Fuji Xerox Co., Ltd","CompuTrend Systems, Inc.","Philips Monitors","STMicroelectronics Imaging Division (VLSI Vision)",
		"Dictaphone Corp.","ANAM S&T Co., Ltd","Asahi Kasei Microsystems Co., Ltd","ATEN International Co., Ltd","Truevision, Inc.",
		"Cadence Design Systems, Inc.","Kenwood USA","KnowledgeTek, Inc.","Proton Electronic Ind.","Samsung Electro-Mechanics Co.",
		"CTX Opto-Electronics Corp.","Mustek Systems, Inc.","Interface Corp.","Oasis Design, Inc.","Telex Communications, Inc.",
		"Immersion Corp.","Kodak Digital Product Center, Japan Ltd. (formerly Chinon Industries Inc.)","Peracom Networks, Inc.","Monterey International Corp.","Xyratex International, Ltd",
		"Quartz Ingenierie","SegaSoft","Wacom Co., Ltd","Decicon, Inc.","eTEK Labs",
		"EIZO Corp.","Elecom Co., Ltd","Korea Data Systems Co., Ltd","Epson America","Interex, Inc.",
		"Conexant Systems (Rockwell), Inc.","Zoran Co. Personal Media Division (Nogatech)","City University of Hong Kong","Philips Creative Display Solutions","BAFO/Quality Computer Accessories",
		"ELSA","Intrinsix Corp.","GVC Corp.","Samsung Electronics America","Y-E Data, Inc.",
		"AVM GmbH","Shark Multimedia, Inc.","Nintendo Co., Ltd","QuickShot, Ltd","Denron, Inc.",
		"Racal Data Group","Roland Corp.","Padix Co., Ltd (Rockfire)","RATOC System, Inc.","FlashPoint Technology, Inc.",
		"ZyXEL Communications Corp.","America Kotobuki Electronics Industries, Inc.","Sapien Design","Victron","Nohau Corp.",
		"Infineon Technologies","In Focus Systems","Micrel Semiconductor","Tripath Technology, Inc.","Alcor Micro Corp.",
		"Omron Corp.","Questra Consulting","Powerware Corp.","Incite","Princeton Graphic Systems",
		"Zoran Microelectronics, Ltd","MicroTouch Systems, Inc.","Trisignal Communications","Niigata Canotec Co., Inc.","Brilliance Semiconductor, Inc.",
		"Spectrum Signal Processing, Inc.","Iomega Corp.","A-Trend Technology Co., Ltd","Advanced Input Devices","Intelligent Instrumentation",
		"LaCie, Ltd","Vetronix Corp.","USC Corp.","Fuji Film Microdevices Co., Ltd","ARC International",
		"Ortek Technology, Inc.","Sampo Technology Corp.","Cisco Systems, Inc.","Bose Corp.","Spacetec IMC Corp.",
		"OmniVision Technologies, Inc.","Utilux South China, Ltd","In-System Design","Apple, Inc.","Y.C. Cable U.S.A., Inc.",
		"Synopsys, Inc.","Jing-Mold Enterprise Co., Ltd","Fountain Technologies, Inc.","First International Computer, Inc.","LG Semicon Co., Ltd",
		"Dialogic Corp.","Proxima Corp.","Medianix Semiconductor, Inc.","Agiler, Inc.","Philips Research Laboratories",
		"DigitalPersona, Inc.","Grey Cell Systems","3G Green Green Globe Co., Ltd","RAFI GmbH & Co. KG","Tyco Electronics (Raychem)",
		"S & S Research","Keil Software","Kawasaki Microelectronics, Inc.","Media Phonics (Suisse) S.A.","Digi International, Inc.",
		"Qualcomm, Inc.","Qtronix Corp.","Cheng Uei Precision Industry Co., Ltd (Foxlink)","Semtech Corp.","Ricoh Co., Ltd",
		"PowerVision Technologies, Inc.","ELSA AG","Silicom, Ltd","sci-worx GmbH","Sung Forn Co., Ltd",
		"GE Medical Systems Lunar","Brainboxes, Ltd","Wave Systems Corp.","Tohoku Ricoh Co., Ltd","Super Gate Technology Co., Ltd",
		"Philips Semiconductors, CICT","Thomas & Betts Corp.","Ultima Electronics Corp.","Axiohm Transaction Solutions","Microtek International, Inc.",
		"Sun Corp. (Suntac?)","Lexar Media, Inc.","Delta Electronics, Inc.","Silicon Vision, Inc.","Symbol Technologies",
		"Syntek Semiconductor Co., Ltd","ElecVision, Inc.","Genesys Logic, Inc.","Red Wing Corp.","Fuji Electric Co., Ltd",
		"Keithley Instruments","ICC, Inc.","Kawasaki LSI","FFC, Ltd","COM21, Inc.",
		"Cytechinfo Inc.","AVB, Inc. [anko?]","Canopus Co., Ltd","Compass Communications","Dexin Corp., Ltd",
		"PI Engineering, Inc.","Unixtar Technology, Inc.","AOC International","RFC Distribution(s) PTE, Ltd","PSC Scanning, Inc.",
		"Siemens Telecommunications Systems, Ltd","Harman Multimedia","InterAct, Inc.","Chic Technology Corp.","LeCroy Corp.",
		"Barco Display Systems","Jazz Hipster Corp.","Vista Imaging, Inc.","Novatek Microelectronics Corp.","Jean Co., Ltd",
		"Anchor C&C Co., Ltd","Royal Information Electronics Co., Ltd","Bridge Information Co., Ltd","Genrad Ads","SMK Manufacturing, Inc.",
		"Worthington Data Solutions, Inc.","Solid Year","EEH Datalink GmbH","Auctor Corp.","Transmonde Technologies, Inc.",
		"Joinsoon Electronics Mfg. Co., Ltd","Costar Electronics, Inc.","Totoku Electric Co., Ltd","TransAct Technologies, Inc.","Bio-Rad Laboratories",
		"Quabbin Wire & Cable Co., Inc.","Future Techno Designs PVT, Ltd","Swiss Federal Insitute of Technology","MacAlly","Seiko Instruments, Inc.",
		"Veridicom International, Inc.","Promptus Communications, Inc.","Act Labs, Ltd","Quatech, Inc.","Nissei Electric Co.",
		"Alaris, Inc.","ODU-Steckverbindungssysteme GmbH & Co. KG","Iotech, Inc.","Littelfuse, Inc.","Avocent Corp.",
		"TiMedia Technology Co., Ltd","Nippon Systems Development Co., Ltd","Adomax Technology Co., Ltd","Tasking Software, Inc.","Zida Technologies, Ltd",
		"Creative Labs","Greatlink Electronics Taiwan, Ltd","Institute for Information Industry","Taiwan Tai-Hao Enterprises Co., Ltd","Mainsuper Enterprises Co., Ltd",
		"Sin Sheng Terminal & Machine, Inc.","JUJO Electronics Corp.","Cyrix Corp.","Micron Technology, Inc.","Methode Electronics, Inc.",
		"Sierra Imaging, Inc.","Avision, Inc.","Chrontel, Inc.","Techwin Corp.","Taugagreining HF",
		"Yamaichi Electronics Co., Ltd (Sakura)","Fong Kai Industrial Co., Ltd","RealMedia Technology, Inc.","New Technology Cable, Ltd","Hitex Development Tools",
		"Woods Industries, Inc.","VIA Medical Corp.","TEAC Corp.","Who? Vision Systems, Inc.","UMAX",
		"Acton Research Corp.","Inside Out Networks","Weli Science Co., Ltd","Analog Devices, Inc. (White Mountain DSP)","Ji-Haw Industrial Co., Ltd",
		"TriTech Microelectronics, Ltd","Suyin Corp.","WIBU-Systems AG","Dynapro Systems","Likom Technology Sdn. Bhd.",
		"Stargate Solutions, Inc.","CNF, Inc.","Granite Microsystems, Inc.","Space Shuttle Hi-Tech Co., Ltd","Glory Mark Electronic, Ltd",
		"Tekcon Electronics Corp.","Sigma Designs, Inc.","Aethra","Optoelectronics Co., Ltd","Tracewell Systems",
		"Silicon Graphics","Good Way Technology Co., Ltd & GWC technology Inc.","TSAY-E (BVI) International, Inc.","Hamamatsu Photonics K.K.","Kansai Electric Co., Ltd",
		"Topmax Electronic Co., Ltd","ET&T Technology Co., Ltd.","Cypress Semiconductor","Aiwa Co., Ltd","WordWand",
		"Oce' Printing Systems GmbH","Total Technologies, Ltd","Linksys, Inc.","Entrega, Inc.","Acer Semiconductor America, Inc.",
		"SigmaTel, Inc.","Sequel Imaging","Labtec, Inc.","HCL","Key Mouse Electronic Enterprise Co., Ltd",
		"DrayTek Corp.","Teles AG","Aiwa Co., Ltd","ACard Technology Corp.","Prolific Technology, Inc.",
		"Efficient Networks, Inc.","Hohner Corp.","Intermec Technologies Corp.","Virata, Ltd","Realtek Semiconductor Corp., CPP Div. (Avance Logic)",
		"Siemens Information and Communication Products","Victor Company of Japan, Ltd","Actiontec Electronics, Inc.","ZD Incorporated","Minolta Co., Ltd",
		"Pertech, Inc.","Potrans International, Inc.","CH Products, Inc.","Golden Bridge Electech, Inc.","Hagiwara Sys-Com Co., Ltd",
		"Lego Group","Chuntex (CTX)","Tektronix, Inc.","Askey Computer Corp.","Thomson, Inc.",
		"Hughes Network Systems (HNS)","Welcat Inc.","Allied Data Technologies BV","Topro Technology, Inc.","Saitek PLC",
		"Xiamen Doowell Electron Co., Ltd","Divio","MicroStore, Inc.","Topaz Systems, Inc.","Westell",
		"Sysgration, Ltd","Fujitsu Laboratories of America, Inc.","Greatland Electronics Taiwan, Ltd","Professional Multimedia Testing Centre","Harting, Inc. of North America",
		"Pixela Corp.","Alcatel Telecom","Smooth Cord & Connector Co., Ltd","EDA, Inc.","Oki Data Corp.",
		"AGFA-Gevaert NV","AME Optimedia Technology Co., Ltd","Leoco Corp.","Phidgets Inc. (formerly GLAB)","Bizlink International Corp.",
		"Hagenuk, GmbH","Infowave Software, Inc.","SIIG, Inc.","Taxan (Europe), Ltd","Newer Technology, Inc.",
		"Synaptics, Inc.","Terayon Communication Systems","Keyspan","Contec","SpheronVR AG",
		"LapLink, Inc.","Daewoo Electronics Co., Ltd","Mitsubishi Electric Corp.","Cisco Systems","Toshiba",
		"Aashima Technology B.V.","Network Computing Devices (NCD)","Technical Marketing Research, Inc.","Phoenixtec Power Co., Ltd","Paradyne",
		"Foxlink Image Technology Co., Ltd","Heisei Electronics Co., Ltd","Multi-Tech Systems, Inc.","ADS Technologies, Inc.","Alcatel Microelectronics",
		"Tiger Jet Network, Inc.","Sirius Technologies","PC Expert Tech. Co., Ltd","I.A.C. Geometrische Ingenieurs B.V.","T.N.C Industrial Co., Ltd",
		"Opcode Systems, Inc.","Emine Technology Co.","Wintrend Technology Co., Ltd","Wailly Technology Ltd","Guillemot Corp.",
		"ASYST electronic d.o.o.","HSD S.r.L","Motorola Semiconductor Products Sector","Boston Acoustics","Gallant Computer, Inc.",
		"Supercomal Wire & Cable SDN. BHD.","Bvtech Industry, Inc.","NKK Corp.","Ariel Corp.","Standard Microsystems Corp.",
		"Putercom Co., Ltd","Silicon Systems, Ltd (SSL)","Oki Electric Industry Co., Ltd","Comoss Electronic Co., Ltd","Excel Cell Electronic Co., Ltd",
		"Connect Tech, Inc.","Magic Control Technology Corp.","Interval Research Corp.","NewMotion, Inc.","ZNK Corp.",
		"Imation Corp.","Tremon Enterprises Co., Ltd","Domain Technologies, Inc.","Xionics Document Technologies, Inc.","Eicon Networks Corp.",
		"Ariston Technologies","Centillium Communications Corp.","Vanguard International Semiconductor-America","Amitm","Sunix Co., Ltd",
		"Advanced Card Systems, Ltd","Susteen, Inc.","Goldfull Electronics & Telecommunications Corp.","ViewQuest Technologies, Inc.","Lasat Communications A/S",
		"Asuscom Network","Lorom Industrial Co., Ltd","Mad Catz, Inc.","Chaplet Systems, Inc.","Suncom Technologies",
		"Industrial Electronic Engineers, Inc.","Eutron S.p.a.","NEC, Inc.","Syntech Information Co., Ltd","Onkyo Corp.",
		"Labway Corp.","Strong Man Enterprise Co., Ltd","EVer Electronics Corp.","Ming Fortune Industry Co., Ltd","Polestar Tech. Corp.",
		"C-C-C Group PLC","Micronas GmbH","Digital Stream Corp.","Aureal Semiconductor","Network Technologies, Inc.",
		"Sophisticated Circuits, Inc.","Midiman","Cyber Power System, Inc.","X-Rite, Inc.","Jess-Link Products Co., Ltd",
		"Tokheim Corp.","Camtel Technology Corp.","Surecom Technology Corp.","Smart Technology Enablers, Inc.","OmniKey AG",
		"Partner Tech","Denso Corp.","Kuan Tech Enterprise Co., Ltd","Jhen Vei Electronic Co., Ltd","Welch Allyn, Inc - Medical Division",
		"Observator Instruments BV","Your data Our Care","AmTRAN Technology Co., Ltd","Longshine Electronics Corp.","Inalways Corp.",
		"Comda Enterprise Corp.","Volex, Inc.","Fairchild Semiconductor","Sankyo Seiki Mfg. Co., Ltd","Linksys",
		"Forward Electronics Co., Ltd","Griffin Technology","Well Excellent & Most Corp.","Sagem Monetel GmbH","SanDisk Corp.",
		"Trackerball","C3PO","Vivitar, Inc.","NTT-ME","Logitec Corp.",
		"Happ Controls, Inc.","GTCO/CalComp","Brincom, Inc.","Pro-Image Manufacturing Co., Ltd","Copartner Wire and Cable Mfg. Corp.",
		"Axis Communications AB","Wha Yu Industrial Co., Ltd","ABL Electronics Corp.","RealChip, Inc.","Certicom Corp.",
		"Grandtech Semiconductor Corp.","Optelec","Altera","Sagem","Alfadata Computer Corp.",
		"Digicom S.p.A.","National Technical Systems","Onnto Corp.","Be, Inc.","ADMtek, Inc.",
		"Corega K.K.","Freecom Technologies","Microtech","Trust Technologies","IMP, Inc.",
		"Motorola BCS, Inc.","Plustek, Inc.","Olympus Optical Co., Ltd","Mega World International, Ltd","Marubun Corp.",
		"TIME Interconnect, Ltd","AboCom Systems Inc","Canon Computer Systems, Inc.","Webgear, Inc.","Veridicom",
		"Code Mercenaries Hard- und Software GmbH","Keisokugiken","Datafab Systems, Inc.","APG Cash Drawer","ShareWave, Inc.",
		"Powertech Industrial Co., Ltd","B.U.G., Inc.","Allied Telesyn International","AVerMedia Technologies, Inc.","Kingmax Technology, Inc.",
		"Carry Computer Eng., Co., Ltd","Elektor","Casio Computer Co., Ltd","Dazzle","D-Link System",
		"Aptio Products, Inc.","Cyberdata Corp.","Radiant Systems","GCC Technologies, Inc.","Arasan Chip Systems",
		"Diamond Multimedia","David Electronics Co., Ltd","Ambient Technologies, Inc.","Elmeg GmbH & Co., Ltd","Planex Communications, Inc.",
		"Movado Enterprise Co., Ltd","QPS, Inc.","Allied Cable Corp.","Mirvo Toys, Inc.","Labsystems",
		"Iwatsu Electric Co., Ltd","Double-H Technology Co., Ltd","Taiyo Electric Wire & Cable Co., Ltd","Torex Retail (formerly Logware)","STSN",
		"Microcomputer Applications, Inc.","Circuit Assembly Corp.","Century Corp.","Dotop Technology, Inc.","DrayTek Corp.",
		"Mark of the Unicorn","Unknown","MagTek","Mako Technologies, LLC","Zoom Telephonics, Inc.",
		"Genicom Technology, Inc.","Evermuch Technology Co., Ltd","Cross Match Technologies","Datalogic S.p.A.","Teco Image Systems Co., Ltd",
		"Personal Communication Systems, Inc.","Mattel, Inc.","eLicenser","MG Logic","Indigita Corp.",
		"Mipsys","AlphaSmart, Inc.","Reudo Corp.","GC Protronics","Data Transit",
		"BroadLogic, Inc.","Sato Corp.","DirecTV Broadband, Inc. (Telocity)","Handspring","Palm, Inc.",
		"Kouwell Electronics Corp.","Sourcenext Corp.","Action Star Enterprise Co., Ltd","TrekStor","Samsung Techwin Co., Ltd",
		"Accton Technology Corp.","Global Village","Argosy Research, Inc.","Rioport.com, Inc.","Welland Industrial Co., Ltd",
		"NetGear, Inc.","Minton Optic Industry Co., Inc.","KB Gear","Empeg","Fast Point Technologies, Inc.",
		"Macronix International Co., Ltd","CSEM","Topre Corporation","ActiveWire, Inc.","B&B Electronics",
		"Hitachi Maxell, Ltd","Minolta Systems Laboratory, Inc.","Xircom","ColorVision, Inc.","Teletrol Systems, Inc.",
		"Filanet Corp.","NetGear, Inc.","Data Translation, Inc.","Emagic Soft- und Hardware GmbH","DeTeWe - Deutsche Telephonwerke AG & Co.",
		"System TALKS, Inc.","MEC IMEX, Inc.","Metricom","SanDisk, Inc.","Xpeed, Inc.",
		"A-Tec Subsystem, Inc.","Comtrol Corp.","Adesso/Kbtek America, Inc.","Jaton Corp.","Fujitsu Computer Products of America",
		"QualCore Logic Inc.","APT Technologies, Inc.","Recording Industry Association of America (RIAA)","Boca Research, Inc.","XAC Automation Corp.",
		"Hannstar Electronics Corp.","TechTools","MassWorks, Inc.","Swecoin AB","iLok",
		"DioGraphy, Inc.","TSI Incorporated","Lauterbach","United Technologies Research Cntr.","Icron Technologies Corp.",
		"NST Co., Ltd","Primex Aerospace Co.","e9, Inc.","Toshiba TEC","Andrea Electronics",
		"CWAV Inc.","Macally (Mace Group, Inc.)","Metrohm","Sorenson Vision, Inc.","NATSU",
		"J. Gordon Electronic Design, Inc.","RadioShack Corp. (Tandy)","Texas Instruments","Citizen Watch Co., Ltd","Precise Biometrics",
		"Proxim, Inc.","Key Nice Enterprise Co., Ltd","2Wire, Inc.","Nippon Telegraph and Telephone Corp.","Aiptek International, Inc.",
		"Jue Hsun Ind. Corp.","Long Well Electronics Corp.","Productivity Enhancement Products","smartBridges, Inc.","Virtual Ink",
		"Fujitsu Siemens Computers","IXXAT Automation GmbH","Increment P Corp.","Billionton Systems, Inc.","???",
		"Spyrus, Inc.","Olitec, Inc.","Pioneer Corp.","Litronic","Gemalto (was Gemplus)",
		"Pan-International Wire & Cable","Integrated Memory Logic","Extended Systems, Inc.","Ericsson, Inc., Blue Ridge Labs","M-Systems Flash Disk Pioneers",
		"MediaTek Inc.","CCSI/Hesso","Corex Technologies","CTI Electronics Corp.","Gotop Information Inc.",
		"SysTec Co., Ltd","Logic 3 International, Ltd","Vernier","Keen Top International Enterprise Co., Ltd","Wipro Technologies",
		"Caere","Socket Communications","Sicon Cable Technology Co., Ltd","Digianswer A/S","AuthenTec, Inc.",
		"Pinnacle Systems, Inc.","VST Technologies","Faraday Technology Corp.","Siemens AG","Audio-Technica Corp.",
		"Trumpion Microelectronics, Inc.","Neurosmith","Silicon Motion, Inc. - Taiwan (formerly Feiya Technology Corp.)","Multiport Computer Vertriebs GmbH","Shining Technology, Inc.",
		"Fujitsu Devices, Inc.","Alation Systems, Inc.","Philips Speech Processing","Voquette, Inc.","GlobeSpan, Inc.",
		"SmartDisk Corp.","Tiger Electronics","Garmin International","Echelon Co.","GoHubs, Inc.",
		"Dymo-CoStar Corp.","IC Media Corp.","Xerox","Lakeview Research","Summus, Ltd",
		"PLX Technology, Inc. (formerly Oxford Semiconductor, Ltd)","American Biometric Co.","Toshiba Information & Industrial Sys. And Services","Sena Technologies, Inc.","Northern Embedded Science/CAVNEX",
		"Toshiba Corp.","Harmonic Data Systems, Ltd","Crescentec Corp.","Quantum Corp.","Spirent Communications",
		"NuTesla","Lumberg, Inc.","Pixart Imaging, Inc.","Plextor Corp.","Intrepid Control Systems, Inc.",
		"InnoSync, Inc.","J.S.T. Mfg. Co., Ltd","Olympia Telecom Vertriebs GmbH","Japan Storage Battery Co., Ltd","Photobit Corp.",
		"i2Go.com, LLC","HCL Technologies India Private, Ltd","KORG, Inc.","Pasco Scientific","Kronauer music in digital",
		"Linkup Systems Corp.","Cable Television Laboratories","Yano","Kingston Technology","RPM Systems Corp.",
		"NVidia Corp.","BSquare Corp.","Agilent Technologies, Inc.","CompuLink Research, Inc.","Cologne Chip AG",
		"Portsmith","Medialogic Corp.","K-Tec Electronics","Polycom, Inc.","Acer NeWeb Corp.",
		"Catalyst Enterprises, Inc.","Feitian Technologies, Inc.","Gretag-Macbeth AG","Schlumberger","Datagraphix, a business unit of Anacomp",
		"OL'E Communications, Inc.","Adirondack Wire & Cable","Lightsurf Technologies","Beckhoff GmbH","Jeilin Technology Corp., Ltd",
		"Minds At Work LLC","Knudsen Engineering, Ltd","Marunix Co., Ltd","Rosun Technologies, Inc.","Biopac Systems Inc.",
		"Barun Electronics Co., Ltd","Oak Technology, Ltd","Apricorn","cab Produkttechnik GmbH & Co KG","Matsushita Electric Works, Ltd.",
		"Vitana Corp.","INDesign","Integrated Intellectual Property, Inc.","Kenwood TMI Corp.","Gemstar eBook Group, Ltd",
		"Integrated Telecom Express, Inc.","Zippy Technology Corp.","PairGain Technologies","Contech Research, Inc.","VCON Telecommunications",
		"Poinchips","Data Transmission Network Corp.","Lin Shiung Enterprise Co., Ltd","Smart Card Technologies Co., Ltd","Intersil Corp.",
		"Japan Cash Machine Co., Ltd.","Tripp Lite","Franklin Electronic Publishers, Inc.","Altius Solutions, Inc.","MDS Telephone Systems",
		"Celltrix Technology Co., Ltd","Grundig","MySmart.Com","Auerswald GmbH & Co. KG","Genpix Electronics, LLC",
		"Arris Interactive LLC","Nisca Corp.","ActivCard, Inc.","ACTiSYS Corp.","Memory Corp.",
		"Workbit Corp.","Psion Dacom Home Networks, Ltd","City Electronics, Ltd","Electronics Testing Center, Taiwan","NeoMagic, Inc.",
		"Vreelin Engineering, Inc.","Com One","Novatel Wireless","KRF Tech, Ltd","A4 Tech Co., Ltd",
		"Measurement Computing Corp.","Aimex Corp.","Fellowes, Inc.","Addonics Technologies Corp.","Intellon Corp.",
		"Jo-Dan International, Inc.","Silutia, Inc.","Real 3D, Inc.","AKAI  Professional M.I. Corp.","Chen-Source, Inc.",
		"IM Networks, Inc.","Xitel","GoFlight, Inc.","AresCom","RocketChips, Inc.",
		"Edu-Science (H.K.), Ltd","SoftConnex Technologies, Inc.","Bay Associates","Mtek Vision","Altera",
		"Gain Technology Corp.","Liquid Audio","ViA, Inc.","Unknown Manufacturer","Ontrak Control Systems Inc.",
		"Cybex Computer Products Co.","Servergy, Inc","Xentec, Inc.","Cambridge Silicon Radio, Ltd","Telebyte, Inc.",
		"Spacelabs Medical, Inc.","Scalar Corp.","Trek Technology (S) PTE, Ltd","Pentax Corp.","Heidelberger Druckmaschinen AG",
		"Hua Geng Technologies, Inc.","Medtronic Physio Control Corp.","Century Semiconductor USA, Inc.","Datacard Group","AK-Modul-Bus Computer GmbH",
		"TG3 Electronics, Inc.","Radikal Technologies","Gilat Satellite Networks, Ltd","PentaMedia Co., Ltd","NTT DoCoMo, Inc.",
		"Varo Vision","Swissonic AG","Boca Systems, Inc.","Davicom Semiconductor, Inc.","Hirose Electric",
		"I/O Interconnect","Ploytec GmbH","Fujitsu Media Devices, Ltd","Computex Co., Ltd","Evolution Electronics, Ltd",
		"Steinberg Soft-und Hardware GmbH","Litton Systems, Inc.","Mimaki Engineering Co., Ltd","Sony Electronics, Inc.","Jebsee Electronics Co., Ltd",
		"Portable Peripheral Co., Ltd","Electronics For Imaging, Inc.","EAsics NV","Broadcom Corp.","Diatrend Corp.",
		"Zebra","MPMan","ClearCube Technology","Medeli Electronics Co., Ltd","Comaide Corp.",
		"Chroma ate, Inc.","Green House Co., Ltd","Integrated Circuit Systems, Inc.","UPS Manufacturing","Benwin",
		"Core Technology, Inc.","International Game Technology","VIPColor Technologies USA, Inc.","Sanwa Denshi","Mackie Designs",
		"NSTL, Inc.","Octagon Systems Corp.","Rexon Technology Corp., Ltd","Chesen Electronics Corp.","Syscan",
		"NextComm, Inc.","Maui Innovative Peripherals","Idexx Labs","NITGen Co., Ltd","Picturetel",
		"Japan Aviation Electronics Industry, Ltd","Candy Technology Co., Ltd","Globlink Technology, Inc.","EGO SYStems, Inc.","C Technologies AB",
		"Intersense","Lava Computer Mfg., Inc.","Develco Elektronik","First International Digital","Perception Digital, Ltd",
		"Wincor Nixdorf International GmbH","TriGem Computer, Inc.","Baromtec Co.","Japan CBM Corp.","Vision Shape Europe SA",
		"iCompression, Inc.","Rohde & Schwarz GmbH & Co. KG","NEC infrontia Corp. (Nitsuko)","Digitalway Co., Ltd","Arrow Strong Electronics Co., Ltd",
		"FEIG ELECTRONIC GmbH","Ellisys","Stereo-Link","Diolan","Sanyo Semiconductor Company Micro",
		"Leco Corp.","I & C Corp.","Singing Electrons, Inc.","Panwest Corp.","Z-Star Microelectronics Corp.",
		"Micro Solutions, Inc.","OPEN Networks Ltd","Koga Electronics Co.","ID Tech","ZyDAS",
		"Intoto, Inc.","Intellix Corp.","Remotec Technology, Ltd","Service & Quality Technology Co., Ltd","Data Encryption Systems Ltd.",
		"Allion Computer, Inc.","Taito Corp.","Neodym Systems, Inc.","System Support Co., Ltd","North Shore Circuit Design L.L.P.",
		"SciEssence, LLC","TTP Communications, Ltd","Neodio Technologies Corp.","Option","Silver I Co., Ltd",
		"B2C2, Inc.","Hama, Inc.","DMC Co., Ltd.","Zaptronix Ltd","Tateno Dennou, Inc.",
		"Cummins Engine Co.","Jump Zone Network Products, Inc.","INGENICO","ASUSTek Computer, Inc.","Datamax-O'Neil",
		"Todos AB","ProjectLab","GN Netcom","AVID Technology","Pcally",
		"I Tech Solutions Co., Ltd","Electronic Warfare Assoc., Inc. (EWA)","Insyde Software Corp.","TransDimension, Inc.","Yokogawa Electric Corp.",
		"Japan System Development Co., Ltd","Pan-Asia Electronics Co., Ltd","Link Evolution Corp.","Ritek Corp.","Kenwood Corp.",
		"Village Center, Inc.","PNY Technologies, Inc.","Contour Design, Inc.","Hitachi ULSI Systems Co., Ltd","Gear Head",
		"Omnidirectional Control Technology, Inc.","IPaxess","Tekram Technology Co., Ltd","Olivetti Techcenter","Kikusui Electronics Corp.",
		"Hal Corp.","Play.com, Inc.","Sportbug.com, Inc.","TechnoTrend AG","ASCII Corp.",
		"Pine Corp. Ltd.","Graphtec America, Inc.","Musical Electronics, Ltd","Dumpries Co., Ltd","Comfort Keyboard Co.",
		"Colorado MicroDisplay, Inc.","Sinbon Electronics Co., Ltd","TYI Systems, Ltd","Beijing HanwangTechnology Co., Ltd","Lake Communications, Ltd",
		"Corel Corp.","Green Electronics Co., Ltd","Nsine, Ltd","NEC Viewtechnology, Ltd","Orange Micro, Inc.",
		"ADLink Technology, Inc.","Wonderful Wire Cable Co., Ltd","Expert Magnetics Corp.","Cybiko Inc.","Fairbanks Scales",
		"CacheVision","Maxim Integrated Products","Nagano Japan Radio Co., Ltd","PortalPlayer, Inc.","SHIN-EI Sangyo Co., Ltd",
		"Embedded Wireless Technology Co., Ltd","Computone Corp.","Roland DG Corp.","Sunrise Telecom, Inc.","Zeevo, Inc.",
		"Taiko Denki Co., Ltd","ITRAN Communications, Ltd","Astrodesign, Inc.","id3 Semiconductors","Rextron Technology, Inc.",
		"Elkat Electronics, Sdn., Bhd.","Exputer Systems, Inc.","Plus-One I & T, Inc.","Sigma Koki Co., Ltd, Technology Center","Advanced Digital Broadcast, Ltd",
		"SMART Technologies Inc.","ASIX Electronics Corp.","Sewon Telecom","O2 Micro, Inc.","Playmates Toys, Inc.",
		"Audio International, Inc.","Dipl.-Ing. Stefan Kunde","Softprotec Co.","Chippo Technologies","U.S. Robotics",
		"Concord Camera Corp.","Infinilink Corp.","Ambit Microsystems Corp.","Ofuji Technology","HTC (High Tech Computer Corp.)",
		"Murata Manufacturing Co., Ltd","Network Alchemy","Joytech Computer Co., Ltd","Hitachi Semiconductor and Devices Sales Co., Ltd","Eiger M&C Co., Ltd",
		"ZAccess Systems","General Meters Corp.","Assistive Technology, Inc.","System Connection, Inc.","Knilink Technology, Inc.",
		"Fuw Yng Electronics Co., Ltd","Seagate RSS LLC","IPWireless, Inc.","Microcube Corp.","JCN Co., Ltd",
		"ExWAY, Inc.","X10 Wireless Technology, Inc.","Telmax Communications","ECI Telecom, Ltd","Startek Engineering, Inc.",
		"Perfect Technic Enterprise Co., Ltd","Andrew Pargeter & Associates","Realtek Semiconductor Corp.","Ericsson Business Mobile Networks BV","Y Media Corp.",
		"Orange PCS","Kanda Tsushin Kogyo Co., Ltd","TOYO Corp.","Elka International, Ltd","DOME imaging systems, Inc.",
		"Dong Guan Humen Wonderful Wire Cable Factory","MEI","LTK Industries, Ltd","Way2Call Communications","Pace Micro Technology PLC",
		"Intracom S.A.","Konexx","Addonics Technologies, Inc.","Sunny Giken, Inc.","Fujitsu Siemens Computers",
		"Kvaser AB","MOTO Development Group, Inc.","Appian Graphics","Hasbro Games, Inc.","Infinite Data Storage, Ltd",
		"Agate","Comjet Information System","Highpoint Technologies, Inc.","Dura Micro, Inc. (Acomdata)","Zeroplus",
		"Iris Graphics","Gyration, Inc.","Cyberboard A/S","SynerTek Korea, Inc.","cyberPIXIE, Inc.",
		"Silicon Motion, Inc.","MIPS Technologies","Hang Zhou Silan Electronics Co., Ltd","Tally Printer Corp.","Lernout + Hauspie",
		"Taiyo Yuden","Sampo Corp.","Prolific Technology Inc.","RFIDeas, Inc","Metrologic Instruments",
		"Eagletron, Inc.","E Ink Corp.","e.Digital","Der An Electric Wire & Cable Co., Ltd","IFR",
		"Furui Precise Component (Kunshan) Co., Ltd","Komatsu, Ltd","Radius Co., Ltd","Innocom, Inc.","Nextcell, Inc.",
		"Motorola iDEN","Microdia","WaveRider Communications, Inc.","ALGE-TIMING GmbH","Reiner SCT Kartensysteme GmbH",
		"Needham's Electronics","Sealevel Systems, Inc.","ViewPLUS, Inc.","Glory, Ltd","Spectrum Digital, Inc.",
		"Billion Bright, Ltd","Imaginative Design Operation Co., Ltd","Vidar Systems Corp.","Dong Guan Shinko Wire Co., Ltd","TRS International Mfg., Inc.",
		"Xytronix Research & Design","Apogee Electronics Corp.","Chant Sincere Co., Ltd","Toko, Inc.","Signality System Engineering Co., Ltd",
		"Eminence Enterprise Co., Ltd","Rexon Electronics Corp.","Concept Telecom, Ltd","ACS","JETI Technische Instrumente GmbH",
		"MCT Elektronikladen","PEAK System","Optronic Laboratories Inc.","JMTek, LLC.","Sipix Group, Ltd",
		"Detto Corp.","NuConnex Technologies Pte., Ltd","Wing-Span Enterprise Co., Ltd","NDA Technologies, Inc.","Kyocera Wireless Corp.",
		"Honda Tsushin Kogyo Co., Ltd","Pathway Connectivity, Inc.","Wavefly Corp.","Coactive Networks","Tempo",
		"Cesscom Co., Ltd","Applied Microsystems","Cryptera","Berkshire Products, Inc.","Innochips Co., Ltd",
		"Hanwool Robotics Corp.","Jobin Yvon, Inc.","SemTek","Zyfer","Sega Corp.",
		"ST&T Instrument Corp.","BAE Systems Canada, Inc.","Castles Technology Co., Ltd","Information Systems Laboratories","Motorola CGISS",
		"Ascom Business Systems, Ltd","Buslink","Flying Pig Systems","Innovonics, Inc.","Celestix Networks, Pte., Ltd",
		"Singatron Enterprise Co., Ltd","Opticis Co., Ltd","Trust Electronic (Shanghai) Co., Ltd","Shanghai Darong Electronics Co., Ltd","Palmax Technology Co., Ltd",
		"Pentel Co., Ltd (Electronics Equipment Div.)","Keryx Technologies, Inc.","Union Genius Computer Co., Ltd","Kuon Yi Industrial Corp.","Given Imaging, Ltd",
		"Timex Corp.","Rimage Corp.","emsys GmbH","Sendo","Intermagic Corp.",
		"Kontron Medical AG","Technotools Corp.","BroadMAX Technologies, Inc.","Amphenol","SKNet Co., Ltd",
		"Domex Technology Corp.","TerraTec Electronic GmbH","Bang Olufsen","LabJack Corporation","NewChip S.r.l.",
		"JS Digitech, Inc.","Hitachi Shin Din Cable, Ltd","Z-Com","Validation Technologies International","pico Technology",
		"e-Conn Electronic Co., Ltd","ENE Technology, Inc.","Atheros Communications, Inc.","Fomtex Corp.","Cellink Co., Ltd",
		"Compucable Corp.","ishoni Networks","Clarisys, Inc.","Central System Research Co., Ltd","Inviso, Inc.",
		"Minolta-QMS, Inc.","SAFA MEDIA Co., Ltd.","telos EDV Systementwicklung GmbH","UTStarcom","Contemporary Controls",
		"Astron Electronics Co., Ltd","MKNet Corp.","Hybrid Networks, Inc.","Feng Shin Cable Co., Ltd","Elastic Networks",
		"Maspro Denkoh Corp.","Hansol Electronics, Inc.","BMF Corp.","Array Comm, Inc.","OnStream b.v.",
		"Hi-Touch Imaging Technologies Co., Ltd","NALTEC, Inc.","coaXmedia","Hank Connection Industrial Co., Ltd","NXP",
		"Leo Hui Electric Wire & Cable Co., Ltd","AirSpeak, Inc.","Rearden Steel Technologies","Dah Kun Co., Ltd","Posiflex Technologies, Inc.",
		"Sri Cable Technology, Ltd","Tangtop Technology Co., Ltd","Fitcom, inc.","MTS Systems Corp.","Ascor, Inc.",
		"Ta Yun Terminals Industrial Co., Ltd","Full Der Co., Ltd","Kobil Systems GmbH","Promethean Limited","Maxtor",
		"NF Corp.","Grape Systems, Inc.","Tedas AG","Coherent, Inc.","Agere Systems Netherland BV",
		"EADS Airbus France","Cleware GmbH","Volex (Asia) Pte., Ltd","HMI Co., Ltd","Holon Corp.",
		"ASKA Technologies, Inc.","AVLAB Technology, Inc.","Solomon Microtech, Ltd","SMC Networks, Inc.","Myacom, Ltd",
		"CSI, Inc.","IVL Technologies, Ltd","Meilu Electronics (Shenzhen) Co., Ltd","Darfon Electronics Corp.","Fritz Gegauf AG",
		"DXG Technology Corp.","KMJP Co., Ltd","TMT","Advanet, Inc.","Super Link Electronics Co., Ltd",
		"NSI","Megapower International Corp.","And-Or Logic","Try Computer Co., Ltd","Hirakawa Hewtech Corp.",
		"Winmate Communication, Inc.","Hit's Communications, Inc.","MFP Korea, Inc.","Power Sentry/Newpoint","Japan Distributor Corp.",
		"MARX Datentechnik GmbH","Wellco Technology Co., Ltd","Taiwan Line Tek Electronic Co., Ltd","Phison Electronics Corp.","American Computer & Digital Components",
		"Essential Reality LLC","H.R. Silvine Electronics, Inc.","TechnoVision","Think Outside, Inc.","Dolby Laboratories Inc.",
		"Oz Software","King Jim Co., Ltd","Ascom Telecommunications, Ltd","C-Media Electronics, Inc.","Promotion & Display Technology, Ltd",
		"Global Sun Technology, Inc.","Pitney Bowes","Sure-Fire Electrical Corp.","Skanhex Technology, Inc.","Santa Barbara Instrument Group",
		"Mars Semiconductor Corp.","Trazer Technologies, Inc.","RTX Telecom AS","Tat Shing Electrical Co.","Chee Chen Hi-Technology Co., Ltd",
		"Sanwa Supply, Inc.","Avaya","Powercom Co., Ltd","Danger Research","Suzhou Peter's Precise Industrial Co., Ltd",
		"Land Instruments International, Ltd","Nippon Electro-Sensory Devices Corp.","Polar Electro OY","IOGear, Inc.","softDSP Co., Ltd",
		"Cubig Group","Westover Scientific","Micro Star International","Wen Te Electronics Co., Ltd","Shian Hwi Plug Parts, Plastic Factory",
		"Tekram Technology Co., Ltd","Chung Fu Chen Yeh Enterprise Corp.","ELCON Systemtechnik","Digidesign","A&D Medical",
		"Jiuh Shiuh Precision Industry Co., Ltd","Jess-Link International","G7 Solutions (formerly Great Notions)","Tamagawa Seiki Co., Ltd","Athena Smartcard Solutions, Inc.",
		"Macpower Peripherals, Ltd","SDK Co., Ltd","Precision Squared Technology Corp.","First Cable Line, Inc.","NetworkFab Corp.",
		"Access Solutions","Contek Electronics Co., Ltd","Power Quotient International Co., Ltd","MediaQ","Custom Engineering SPA",
		"California Micro Devices","Kocom Co., Ltd","Netac Technology Co., Ltd","HighSpeed Surfing","Integrated Circuit Solution, Inc.",
		"Tamarack, Inc.","Datelink Technology Co., Ltd","Ubicom, Inc.","BD Consumer Healthcare","USBmicro",
		"UTECH Electronic (D.G.) Co., Ltd.","Novasonics","Lifetime Memory Products","Full Rise Electronic Co., Ltd","NET&SYS",
		"Sitecom Europe B.V.","Mobile Action Technology, Inc.","Toyo Communication Equipment Co., Ltd","GeneralTouch Technology Co., Ltd","Nippon Systemware Co., Ltd",
		"Winbest Technology Co., Ltd","Amigo Technology Inc.","Gesytec","VMware, Inc.","JMTek, LLC",
		"Walex Electronic, Ltd","Unisys","Crewave","Pegasus Technologies Ltd.","Cowon Systems, Inc.",
		"Symbian Ltd.","Liou Yuane Enterprise Co., Ltd","VinChip Systems, Inc.","J-Phone East Co., Ltd","HeartMath LLC",
		"Micro Computer Control Corp.","3Pea Technologies, Inc.","TiePie engineering","Stratitec, Inc.","Smart Modular Technologies, Inc.",
		"Neostar Technology Co., Ltd","Mansella, Ltd","Line6, Inc.","Sun-Riseful Technology Co., Ltd.","Julia Corp., Ltd",
		"Shenzhen Bao Hing Electric Wire & Cable Mfr. Co.","Radica Games, Ltd","TechnoData Interware","Speed Dragon Multimedia, Ltd","Kingston Technology Company, Inc.",
		"Active Co., Ltd","Union Power Information Industrial Co., Ltd","Bitland Information Technology Co., Ltd","Neltron Industrial Co., Ltd","Conwise Technology Co., Ltd.",
		"Hawking Technologies","Fossil, Inc.","Megawin Technology Co., Ltd","Logic3","Tokyo Electronic Industry Co., Ltd",
		"Hsi-Chin Electronics Co., Ltd","TVS Electronics, Ltd","Archos, Inc.","On-Tech Industry Co., Ltd","Gmate, Inc.",
		"Ching Tai Electric Wire & Cable Co., Ltd","Shin An Wire & Cable Co.","Well Force Electronic Co., Ltd","MediaTek Inc.","GreenAsia Inc.",
		"WiebeTech, LLC","VTech Engineering Canada, Ltd","C's Glory Enterprise Co., Ltd","eM Technics Co., Ltd","Future Technology Co., Ltd",
		"Aplux Communications, Ltd","Fingerworks, Inc.","Advanced Analogic Technologies, Inc.","Parallel Dice Co., Ltd","TA HSING Industries, Ltd",
		"ADTEC Corp.","Streamzap, Inc.","Tamura Corp.","Ours Technology, Inc.","Nihon Computer Co., Ltd",
		"MSL Enterprises Corp.","CenDyne, Inc.","Humax Co., Ltd","NovaTech","WIS Technologies, Inc.",
		"Y-S Electronic Co., Ltd","Saint Technology Corp.","Endor AG","Mettler Toledo","Thermo Fisher Scientific",
		"VWeb Corp.","Omega Technology of Taiwan, Inc.","LHI Technology (China) Co., Ltd","Abit Computer Corp.","Sweetray Industrial, Ltd",
		"Axell Co., Ltd","Ballracing Developments, Ltd","GT Information System Co., Ltd","InnoVISION Multimedia, Ltd","Theta Link Corp.",
		"Lite-On IT Corp.","TaiSol Electronics Co., Ltd","Phogenix Imaging, LLC","WinMaxGroup","Kyoto Micro Computer Co., Ltd",
		"Wing-Tech Enterprise Co., Ltd","Fiberbyte","Noriake Itron Corp.","e-MDT Co., Ltd","Shima Seiki Mfg., Ltd",
		"Sarotech Co., Ltd","AMI Semiconductor, Inc.","ComTrue Technology Corp.","Sunrich Technology, Ltd","Digital Stream Technology, Inc.",
		"D-WAV Scientific Co., Ltd","Hitachi Cable, Ltd","Aichi Micro Intelligent Corp.","I/O Magic Corp.","Lynn Products, Inc.",
		"DSI Datotech","PointChips","Yield Microelectronics Corp.","SM Tech Co., Ltd (Tulip)","Oasis Semiconductor",
		"Wem Technology, Inc.","Unitek UPS Systems","Visual Frontier Enterprise Co., Ltd","CSL Wire & Plug (Shen Zhen) Co.","CAS Corp.",
		"Hori Co., Ltd","Energy Full Corp.","LD Didactic GmbH","Mars Engineering Corp.","Acetek Technology Co., Ltd",
		"Ingenico","Finger Lakes Instrumentation","Oracom Co., Ltd","Onset Computer Corp.","Funai Electric Co., Ltd",
		"Iwill Corp.","IOI Technology Corp.","Senior Industries, Inc.","Leader Tech Manufacturer Co., Ltd","Flex-P Industries, Snd., Bhd.",
		"ViPower, Inc.","Geniality Maple Technology Co., Ltd","Priva Design Services","Jess Technology Co., Ltd","Chrysalis Development",
		"YFC-BonEagle Electric Co., Ltd","Kokuyo Co., Ltd","Nien-Yi Industrial Corp.","TG3 Electronics","Airprime, Incorporated",
		"RDC Semiconductor Co., Ltd","Nital Consulting Services, Inc.","Polhemus","St. John Technology Co., Ltd","WorldWide Cable Opto Corp.",
		"Microtune, Inc.","Freedom Scientific","Wing Key Electrical Co., Ltd","Dongguan White Horse Cable Factory, Ltd","Kawai Musical Instruments Mfg. Co., Ltd",
		"AmbiCom, Inc.","Prairiecomm, Inc.","NewAge International, LLC","Key Technology Corp.","NTK, Ltd",
		"Varian, Inc.","Acrox Technologies Co., Ltd","LeapFrog Enterprises","Kobe Steel, Ltd","Dionex Corp.",
		"Vibren Technologies, Inc.","INTELLIGENT SYSTEMS","DFI","Guntermann & Drunck GmbH","DQ Technology, Inc.",
		"NetBotz, Inc.","Fluke Corp.","VTech Holdings, Ltd","Yazaki Corp.","Young Generation International Corp.",
		"Uniwill Computer Corp.","Kingnet Technology Co., Ltd","Soma Networks","CviLux Corp.","CyberBank Corp.",
		"Hyun Won, Inc.","Lucent Technologies","Starconn Electronic Co., Ltd","ATL Technology","Sotec Co., Ltd",
		"Epox Computer Co., Ltd","Logic Controls, Inc.","Winpoint Electronic Corp.","Haurtian Wire & Cable Co., Ltd","Inclose Design, Inc.",
		"Juan-Chern Industrial Co., Ltd","Heber Ltd","Wistron Corp.","AACom Corp.","San Shing Electronics Co., Ltd",
		"Bitwise Systems, Inc.","Mitac Internatinal Corp.","Plug and Jack Industrial, Inc.","Delcom Engineering","Dataplus Supplies, Inc.",
		"Research In Motion, Ltd.","Sony Ericsson Mobile Communications AB","Dynastream Innovations, Inc.","Tulip Computers B.V.","Giant Electronics Ltd.",
		"Seac Banche","Tenovis GmbH & Co., KG","Direct Access Technology, Inc.","Elgato Systems GmbH","Quantec Networks GmbH",
		"Micro Plus","Oregon Scientific","Osterhout Design Group","IN-Tech Electronics, Ltd","Greenconn (U.S.A.), Inc.",
		"Kontron (Industrial Computer Source / ICS Advent)","DVICO","United Computer Accessories","CRS Electronic Co., Ltd","UMC Electronics Co., Ltd",
		"Access Co., Ltd","Xsido Corp.","MJ Research, Inc.","Core Valley Co., Ltd","CHI SHING Computer Accessories Co., Ltd",
		"Clavia DMI AB","EarlySense","Aopen, Inc.","Speed Tech Corp.","Ritronics Components (S) Pte., Ltd",
		"Sigma Corp.","LG Electronics, Inc.","Apacer Technology, Inc.","iRiver, Ltd.","Emuzed, Inc.",
		"AV Chaseway, Ltd","Chou Chin Industrial Co., Ltd","Netopia, Inc.","Fukuda Denshi Co., Ltd","Mobile Media Tech.",
		"SDKM Fibres, Wires & Cables Berhad","TST-Touchless Sensor Technology AG","Densitron Technologies PLC","Softronics Pty., Ltd","Xiamen Hung's Enterprise Co., Ltd",
		"Speedy Industrial Supplies, Pte., Ltd","Elitegroup Computer Systems (ECS)","Labtec","Shinko Shoji Co., Ltd","Hyper-Paltek",
		"Newly Corp.","Time Domain","Inovys Corp.","Atlantic Coast Telesys","Ramos Technology Co., Ltd",
		"Infotronic America, Inc.","Etoms Electronics Corp.","Winic Corp.","Comax Technology, Inc.","C-One Technology Corp.",
		"Nucam Corp.","SteelSeries ApS","devolo AG","Stanton","iCreate Technologies Corp.",
		"Chu Yuen Enterprise Co., Ltd","Winbond Electronics Corp. [hex]","Targus Group International","Mylex / Buslogic","AMCO TEC International, Inc.",
		"Newport Corporation","WB Electronics","Yubico.com","Immanuel Electronics Co., Ltd","BMS International Beheer N.V.",
		"Complex Micro Interconnection Co., Ltd","Hsin Chen Ent Co., Ltd","ON Semiconductor","Western Digital Technologies, Inc.","Giesecke & Devrient GmbH",
		"Hong Ji Electric Wire & Cable (Dongguan) Co., Ltd","Delkin Devices, Inc.","Valence Semiconductor Design, Ltd","Chin Shong Enterprise Co., Ltd","Easthome Industrial Co., Ltd",
		"Motorola Electronics Taiwan, Ltd [hex]","CCYU Technology","Loyal Legend, Ltd","Curitel Communications, Inc.","San Chieh Manufacturing, Ltd",
		"ConectL","Money Controls","GCT Semiconductor, Inc.","Gateway, Inc.","Arlec Australia, Ltd",
		"Midoriya Electric Co., Ltd","KidzMouse, Inc.","Shin-Etsukaken Co., Ltd","Canon Electronics, Inc.","Pantech Co., Ltd",
		"Chloride Power Protection","Grand-tek Technology Co., Ltd","Robert Bosch GmbH","Lotes Co., Ltd.","Surface Optics Corp.",
		"DATASOFT Systems GmbH","Hisense","eSOL Co., Ltd","Hirotech, Inc.","Mitsubishi Materials Corp.",
		"SK Teletech Co., Ltd","Cables To Go","USI Co., Ltd","Honeywell, Inc.","Princeton Technology Corp.",
		"Liebert Corp.","Comodo (PLX?)","DiBcom","TM Technology, Inc.","Dinging Technology Co., Ltd",
		"TMT Technology, Inc.","SmartHome","Universal Laser Systems, Inc.","Cygnal Integrated Products, Inc.","Sanei Electric, Inc.",
		"Intec, Inc.","Eratech","GBM Connector Co., Ltd","Kycon, Inc.","Silicon Labs",
		"Velleman Components, Inc.","Hottinger Baldwin Measurement","Man Boon Manufactory, Ltd","Uni Class Technology Co., Ltd","Actions Semiconductor Co., Ltd",
		"Authenex, Inc.","In-Win Development, Inc.","Post-Op Video, Inc.","CablePlus, Ltd","Nada Electronics, Ltd",
		"Vast Technologies, Inc.","Nexio Co., Ltd","Importek","Turtle Beach","Pictos Technologies, Inc.",
		"Anubis Electronics, Ltd","Thrane & Thrane","VirTouch, Ltd","EasyPass Industrial Co., Ltd","Brightcom Technologies, Ltd",
		"Moxa Technologies Co., Ltd.","Analog Devices Canada, Ltd (Allied Telesyn)","Pandora International Ltd.","YM ELECTRIC CO., Ltd","Medion AG",
		"VSO Electric Co., Ltd","RedRat","Master Hill Electric Wire and Cable Co., Ltd","Cellon International, Inc.","Tenx Technology, Inc.",
		"Integrated System Solution Corp.","Toshiba Corp., Digital Media Equipment [hex]","CTS Electronincs","Arin Tech Co., Ltd","Mapower Electronics Co., Ltd",
		"V One Multimedia, Pte., Ltd","CyberScan Technologies, Inc.","Japan Radio Company","Shimane SANYO Electric Co., Ltd.","Ever Great Electric Wire and Cable Co., Ltd",
		"Sphairon Access Systems GmbH","Tinius Olsen Testing Machine Co., Inc.","Alpha Imaging Technology Corp.","Wavecom","Salix Technology Co., Ltd.",
		"Secugen Corp.","DeLorme Publishing, Inc.","YUAN High-Tech Development Co., Ltd","Telson Electronics Co., Ltd","Bantam Interactive Technologies",
		"Salient Systems Corp.","BizConn International Corp.","Gigastorage Corp.","Silicon 10 Technology Corp.","Shengyih Steel Mold Co., Ltd",
		"Santa Electronic, Inc.","JNC, Inc.","Venture Corp., Ltd","Compaq Computer Corp. [hex] (Digital Dream ??)","Kyocera Elco Corp.",
		"Bloomberg L.P.","Acer Communications & Multimedia","You Yang Technology Co., Ltd","Tripace","Loyalty Founder Enterprise Co., Ltd",
		"Yankee Robotics, LLC","Technoimagia Co., Ltd","StarShine Technology Corp.","Sierra Wireless, Inc.","ZHAN QI Technology Co., Ltd",
		"ruwido austria GmbH","Chipcon AS","Technovas Co., Ltd","GlobalMedia Group, LLC","Exito Electronics Co., Ltd",
		"Nike","ATECH FLASH TECHNOLOGY","R&D International NV","Inmax","VeriFone Inc",
		"Topfield Co., Ltd.","K.I. Technology Co. Ltd.","Siemens AG","Prolific","Alcatel (?)",
		"TSC Auto ID Technology Co., Ltd","InterBiometrics","Hudson Soft Co., Ltd","Magellan","DigiTech",
		"Jungsoft Co., Ltd","SKYCABLE ENTERPRISE. CO., LTD.","Datapaq Limited","Chipidea-Microelectronica, S.A.","Denver Electronics",
		"Brain Actuated Technologies","Focusrite-Novation","Belkin","AirVast","Nyko (Honey Bee)",
		"MXI - Memory Experts International, Inc.","Apogee Inc.","A-DATA Technology Co., Ltd.","Standard Microsystems Corp.","Covidien Energy-based Devices",
		"Pirelli Broadband Solutions","Logic3 / SpectraVideo plc","Aristocrat Technologies","Bel Stewart","Strobe Data, Inc.",
		"TwinMOS","Ensoniq","Xaxero Marine Software Engineering, Ltd.","Starlight Xpress","zebris Medical GmbH",
		"Marvell Semiconductor, Inc.","Qualcomm Flarion Technologies, Inc. / Leadtek Research, Inc.","Innomedia","Belkin Components [hex]","RISO KAGAKU CORP.",
		"CyberTAN Technology","Trendchip Technologies Corp.","Honey Bee Electronic International Ltd.","Zhejiang Xinya Electronic Technology Co., Ltd.","E28",
		"Licensed by Sony Computer Entertainment America","Autocue Group Ltd","DEXIN","Huawei Technologies Co., Ltd.","LINE TECH INDUSTRIAL CO., LTD.",
		"EMS Dr. Thomas Wuensche","BETTER WIRE FACTORY CO., LTD.","Araneus Information Systems Oy","Waldorf Music GmbH","Tapwave, Inc.",
		"Dynamic System Electronics Corp.","Memorex Products, Inc.","AIN Comm. Technology Co., Ltd","Fascinating Electronics, Inc.","Transcend Information, Inc.",
		"Shuttle, Inc.","Roper","ICS Electronics","ThorLabs","Natural Point",
		"Envara Inc.","Konica Minolta","Mobility","Citizen Systems","Sino Lite Technology Corp.",
		"Moravian Instruments","Katsuragawa Electric Co., Ltd.","PanJit International Inc.","Digby's Bitpile, Inc. DBA D Bit","P&E Microcomputer Systems",
		"SEGGER","STEC","Swissbit","CNet Technology Inc.","Vimtron Electronics Co., Ltd.",
		"SCAPS GmbH","Netgear, Inc","Validity Sensors, Inc.","Jungo LTD","TOMTOM B.V.",
		"IdealTEK, Inc.","Sennheiser Communications","BEHRINGER International GmbH","Q-tec","Baltech",
		"PerkinElmer Optoelectronics","Linksys","Alesis","Nippon Dics Co., Ltd.","PCPlay",
		"Ricoh Printing Systems, Ltd.","JyeTai Precision Industrial Co., Ltd.","Wisair Ltd.","Techsan Electronics Co., Ltd.","A-Max Technology Macao Commercial Offshore Co. Ltd.",
		"Shark Multimedia","IMC Networks","ALEREON, INC.","i.Tech Dynamic Limited","Kaibo Wire & Cable (Shenzhen) Co., Ltd.",
		"Rane","TechnoScope Co., Ltd.","Hengstler","Zydacron","MosArt",
		"Initio Corporation","Kingston Technology Company Inc.","Axxion Group Corp.","Bowe Bell & Howell","Sitronix",
		"IDS Imaging Development Systems GmbH","Telechips, Inc.","Novatel Wireless","Nam Tai E&E Products Ltd. or OmniVision Technologies, Inc.","ABILITY ENTERPRISE CO., LTD.",
		"Sensor Technology","Vega Technologies Industrial (Austria) Co.","Thales E-Transactions","Arbiter Systems, Inc.","RedOctane",
		"Pertech Resources, Inc.","Wistron NeWeb","Denali Software, Inc.","Altek Corporation","Digilent",
		"X.J.GROUP","Radio Shack","Extending Wire & Cable Co., Ltd.","First International Computer, Inc.","Trust",
		"Tatung Co.","Staccato Communications","Micro Star International","Huawei-3Com","Formosa Industrial Computing, Inc.",
		"Upek","Hama GmbH & Co., KG","Vaillant","Elsa AG [hex]","Silicom",
		"DSP Group, Ltd.","EVATRONIX SA","Ralink Technology, Corp.","Futronic Technology Co. Ltd.","Suunto",
		"Panstrong Company Ltd.","Microtek International Inc.","Imagination Technologies","WideView Technology Inc.","CTK Corporation",
		"Printronix Inc.","ATP Electronics Inc.","StarTech.com Ltd.","Ralink Technology, Corp.","Rockwell Automation, Inc.",
		"Gemlight Computer, Ltd","Zytronic","Super Top","JAMER INDUSTRIES CO., LTD.","Raritan Computer, Inc.",
		"WiNRADiO Communications","Dialogue Technology Corp.","Broadcom Corp.","SAIN Information & Communications Co., Ltd.","Planex Communications",
		"Shure Inc.","TechniSat Digital GmbH","Ellisys","Pine-Tum Enterprise Co., Ltd.","First International Computer, Inc.",
		"medMobile","Actel","CompUSA","Cheshire Engineering Corp.","Comneon",
		"Bitwire Corp.","ENE Technology Inc","Silicon Portals","UBIQUAM Co., Ltd.","Thesycon Systemsoftware & Consulting GmbH",
		"JMicron Technology Corp. / JMicron USA Technology Corp.","LG (HLDS)","Razer USA, Ltd","TerraTec Electronic GmbH","U-Blox AG",
		"SG Intec Ltd & Co KG","Celectronic GmbH","PNY","ConnectCounty Holdings Berhad","D&M Holdings, Inc. (Denon/Marantz)",
		"SNBC CO., Ltd","Prolink Microsystems Corp.","OQO","Sunf Pu Technology Co., Ltd","Quantum Corporation",
		"ALLTOP TECHNOLOGY CO., LTD.","Ketron SRL","TRENDnet","Fiberline","SMA Technologie AG",
		"Oakley Inc.","JDS Uniphase Corporation (JDSU)","Kunshan Guoji Electronics Co., Ltd.","Freescale Semiconductor, Inc.","Afatech Technologies, Inc.",
		"Teams Power Limited","Gemtek","Gearway Electronics (Dong Guan) Co., Ltd.","VMware Inc.","Olimex Ltd.",
		"XL Imaging","SoundGraph Inc.","Advance Multimedia Internet Technology Inc. (AMIT)","Laboratoires MXM","KTF Technologies",
		"D-Box Technologies","Textech International Ltd.","Coulomb Electronics Ltd.","Trust International B.V.","Hynix Semiconductor Inc.",
		"Seong Ji Industrial Co., Ltd.","RSA","Numark","SohoWare","Pacific Digital Corp.",
		"Belcarra Technologies Corp.","HanfTek","Tascam","Umax","Inside Out Networks [hex]",
		"VIA Technologies, Inc.","INRO","Amoi Electronics","L & K Precision Technology Co., Ltd.","Wionics Research",
		"Stonestreet One, Inc.","Airgo Networks Inc.","WiQuest Communications, Inc.","2Wire, Inc.","Good Way Technology",
		"Cross Match Technologies GmbH","SofTec Microsystems","ChipX","Matrix Vision GmbH","Struck Innovative Systeme GmbH",
		"Frontier Design Group","Kondo Kagaku","Creatix Polymedia GmbH","Actiontec Electronics, Inc. [hex]","PiKRON Ltd. [hex]",
		"Clipsal","China Huada Integrated Circuit Design (Group) Co., Ltd. (CIDC Group)","Total Phase","Golden Bridge Electech Inc.","Prevo Technologies, Inc.",
		"Maxwise Production Enterprise Ltd.","Godspeed Computer Corp.","Delock","ZOOM Corporation","Kingmax Digital Inc.",
		"Saab AB","Razer USA, Ltd","Atheros Communications","Askey Computer Corp. [hex]","Hitachi Video and Information System, Inc.",
		"VTec Test, Inc.","Shenzhen Zhengerya Cable Co., Ltd.","Unigraf","Global Sun Technology","Dongguan ChingLung Wire & Cable Co., Ltd.",
		"iStation","Persentec, Inc.","Van Ooijen Technische Informatica","Wireless Cables, Inc.","silex technology, Inc.",
		"MCS","Suprema Inc.","Frontline Test Equipment, Inc.","AnyDATA Corporation","JABLOCOM s.r.o.",
		"CMOTECH Co., Ltd.","Wiener, Plein & Baus","King Billion Electronics Co., Ltd.","GN ReSound A/S","Futurelogic Inc.",
		"BlueView Technologies, Inc.","ARTIMI","Swissonic","Avnera","Leica Microsystems",
		"Meyer Instruments (MIS)","Vitesse Semiconductor","Axesstel, Inc.","Waltop International Corp.","Cellink Technology Co., Ltd",
		"CANON IMAGING SYSTEM TECHNOLOGIES INC.","Linksys","QSENN","Senao","General Atomics",
		"MQP Electronics","ASMedia Technology Inc.","Syntek","GERTEC Telecomunicacoes Ltda.","ENENSYS Technologies",
		"LucidPort Technology, Inc.","ASUSTek Computer, Inc. (wrong ID)","System Level Solutions, Inc.","Arowana","Sweex",
		"Multiple Vendors","Spreadtrum Communications Inc.","TopSeed Technology Corp.","ATI AIB","ShenZhen Litkconn Technology Co., Ltd.",
		"Printrex, Inc.","JALCO CO., LTD.","Thales Norway A/S","Ricavision International, Inc.","Samson Technologies Corp.",
		"Concept2","Advanced Connection Technology Inc.","MICOMSOFT CO., LTD.","Kamstrup A/S","Grey Innovation",
		"Lunatone","SAURIS GmbH","Singim International Corp.","Native Instruments","Hip Hing Cable & Plug Mfy. Ltd.",
		"Sanford L.P.","Korea Techtron Co., Ltd.","DisplayLink","Cornice, Inc.","Lenovo",
		"WaveSense","K.K. Rocky","Unicomp, Inc","Advantech","Twinhan",
		"Gwo Jinn Industries Co., Ltd.","Huizhou Shenghua Industrial Co., Ltd.","VIVOphone","Vaisala","ASRock Incorporation",
		"GYROCOM C&C Co., LTD","Memory Devices Ltd.","Compro","Tech Technology Industrial Company","Teridian Semiconductor Corp.",
		"Nexio Co., Ltd","Aveo Technology Corp.","Navilock","Alienware Corporation","Siano Mobile Silicon",
		"Vast Technologies, Inc.","Topseed","Evertop Wire Cable Co.","3Shape A/S","CSSN",
		"Verbatim, Ltd","Petalynx","e3C Technologies","Mikkon Technology Limited","Zotek Electronic Co., Ltd.",
		"AMIT Technology, Inc.","Ecamm","Google Inc.","Starline International Group Limited","Kaba",
		"LKC Technologies, Inc.","Planon System Solutions Inc.","Fitipower Integrated Technology Inc","Qcom","Matrox Graphics, Inc.",
		"Arkmicro Technologies Inc.","FineArch Inc.","GEMBIRD","Motorola GSG","Alco Digital Devices Limited",
		"Nordic Semiconductor ASA","FitLinxx","NextWindow","Avago Technologies, Pte.","Shenzhen Xianhe Technology Co., Ltd.",
		"Ningbo Broad Telecommunication Co., Ltd.","Feature Integration Technology Inc. (Fintek)","Dream Link","Sensoray Co., Inc.","Lab126, Inc.",
		"PreSonus Audio Electronics, Inc.","Hyperstone AG","Ironkey Inc.","Radiient Technologies","Itron Technology iONE",
		"Uniden Corporation","CASIO HITACHI Mobile Communications Co., Ltd.","Wispro Technology Inc.","Dane-Elec Corp. USA","Dongguan Guneetal Wire & Cable Co., Ltd.",
		"Chipsbrand Microelectronics (HK) Co., Ltd.","T-Logic","Leuze electronic","Nuconn Technology Corp.","Beceem Communications Inc.",
		"Acron Precision Industrial Co., Ltd.","Trillium Technology Pty. Ltd.","MicroStrain, Inc.","The Imaging Source Europe GmbH","Benica Corporation",
		"Biforst Technology Inc.","Bodelin","S Life","Batronix","Celestron",
		"B & W Group","Infotech Logistic, LLC","Data Robotics","Futuba","Mindtribe",
		"Parrot SA","ZTE WCDMA Technologies MSM","KFI Printers","WeiDuan Electronic Accessory (S.Z.) Co., Ltd.","Industrial Technology Research Institute",
		"Pak Heng Technology (Shenzhen) Co., Ltd.","RODE Microphones","Gampaq Co.Ltd","Dynex","Bellwood International, Inc.",
		"USB-IF non-workshop","KES Co., Ltd.","Veho","Amphenol East Asia Ltd.","Seagate Branded Solutions",
		"China Resource Semico Co., Ltd","Quanta Microsystems, Inc.","ACRUX","Biwin Technology Ltd.","Terminus Technology Inc.",
		"Action Electronics Co., Ltd.","VASCO Data Security International","Silicon Image","SafeBoot International B.V.","Tandberg Data",
		"Abbott Diabetes Care","Spansion Inc.","SamYoung Electronics Co., Ltd","Global Unichip Corp.","Sagem Orga GmbH",
		"Physik Instrumente","Bayer Health Care LLC","Lumberg Connect  GmbH & Co. KG","Evoluent","Holtek Semiconductor, Inc.",
		"QinHeng Electronics","Dynalith Systems Co., Ltd.","SGS Taiwan Ltd.","BandRich, Inc.","Leica Camera AG",
		"Data Drive Thru, Inc.","UBeacon Technologies, Inc.","eFortune Technology Corp.","KeeTouch","Rigol Technologies",
		"Salcomp Plc","Midiplus Co, Ltd.","Desay Wire Co., Ltd.","APS","SEL C662 Serial Cable",
		"ic-design Reinhard Gottinger GmbH","X-TENSIONS","High Top Precision Electronic Co., Ltd.","Conntech Electronic (Suzhou) Corporation","Connect One Ltd.",
		"A. Eberle GmbH & Co. KG","Meilhaus Electronic GmbH","BLUTRONICS S.r.l.","Corsair","MStar Semiconductor, Inc.",
		"WiLinx Corp.","Cellex Power Products, Inc.","Current Electronics Inc.","NAVIsis Inc.","Ugobe Life Forms, Inc.",
		"ViXS Systems, Inc.","iPassion Technology Inc.","Generalplus Technology Inc.","Energizer Holdings, Inc.","Plastron Precision Co., Ltd.",
		"ARH Inc.","K.S. Terminals Inc.","Chao Zhou Kai Yuan Electric Co., Ltd.","The Hong Kong Standards and Testing Centre Ltd.","Fushicai",
		"ATERGI TECHNOLOGY CO., LTD.","Fresco Logic","Ovislink Corp.","Legend Silicon Corp.","Afatech",
		"Dongguan Guanshang Electronics Co., Ltd.","ShenMing Electron (Dong Guan) Co., Ltd.","Altium Limited","e-MOVE Technology Co., Ltd.","Amlogic, Inc.",
		"MA LABS, Inc.","N-Trig","YMax Communications Corp.","Shenzhen Yuanchuan Electronic","JINQ CHERN ENTERPRISE CO., LTD.",
		"Lite Metals & Plastic (Shenzhen) Co., Ltd.","Ember Corporation","Abilis Systems","China Telecommunication Technology Labs","Harmonix Music",
		"Vuzix Corporation","T & A Mobile Phones","Ford Motor Co.","AVIXE Technology (China) Ltd.","Telit Wireless Solutions",
		"Contac Cable Industrial Limited","Sunplus Innovation Technology Inc.","Hangzhou Riyue Electronic Co., Ltd.","BG Systems, Inc.","P-TWO INDUSTRIES, INC.",
		"Shenzhen Tongyuan Network-Communication Cables Co., Ltd","RealVision Inc.","Extranet Systems Inc.","Orient Semiconductor Electronics, Ltd.","TouchPack",
		"Kreton Corporation","QNAP System Inc.","Ionics EMS, Inc.","Relm Wireless","Lanterra Industrial Co., Ltd.",
		"ALECTRONIC LIMITED","Datel Electronics Ltd.","Volkswagen of America, Inc.","Goldvish S.A.","Fuji Electric Device Technology Co., Ltd.",
		"ADDMM LLC","ZHONGSHAN CHIANG YU ELECTRIC CO., LTD.","Shanghai Haiying Electronics Co., Ltd.","HuiYang D & S Cable Co., Ltd.","LS Cable Ltd.",
		"SpringCard","Authorizer Technologies, Inc.","NONIN MEDICAL INC.","Wep Peripherals","EZPrototypes",
		"Cherng Weei Technology Corp.","SiGma Micro","Philips & Lite-ON Digital Solutions Corporation","Skydigital Inc.","AMT",
		"Kaetat Industrial Co., Ltd.","Datascope Corp.","Unigen Corporation","LighTuning Technology Inc.","LUXSHARE PRECISION INDUSTRY (SHENZHEN) CO., LTD.",
		"Schomaecker GmbH","2N TELEKOMUNIKACE a.s.","Somagic, Inc.","HONGKONG WEIDIDA ELECTRON LIMITED","ASTRON INTERNATIONAL CORP.",
		"ALPINE ELECTRONICS, INC.","OMEGA TECHNOLOGY","ACCARIO Inc.","Symwave","Kinstone",
		"Aces Electronic Co., Ltd.","OPEX CORPORATION","IdeaCom Technology Inc.","Luminary Micro Inc.","FORTAT SKYMARK INDUSTRIAL COMPANY",
		"PlantSense","NextWave Broadband Inc.","Bodatong Technology (Shenzhen) Co., Ltd.","adp corporation","Firecomms Ltd.",
		"Antonio Precise Products Manufactory Ltd.","Telecommunications Technology Association (TTA)","WonTen Technology Co., Ltd.","EDIMAX TECHNOLOGY CO., LTD.","Amphenol KAE",
		"Dresden Elektronik","ANDES TECHNOLOGY CORPORATION","Flextronics Digital Design Japan, LTD.","iCON","Solid-Motion",
		"NINGBO HENTEK DRAGON ELECTRONICS CO., LTD.","TechFaith Wireless Technology Limited","Johnson Controls, Inc. The Automotive Business Unit","HAN HUA CABLE & WIRE TECHNOLOGY (J.X.) CO., LTD.","Sonix Technology Co., Ltd.",
		"ALPHA-SAT TECHNOLOGY LIMITED","C-Thru Music Ltd.","Dexatek Technology Ltd.","Diostech Co., Ltd.","SAMTACK INC.",
		"ASUS","Dream Cheeky","Touch","PEGATRON CORPORATION","OpenMoko, Inc.",
		"Xenta","Smartronix, Inc.","Linux Foundation","Citizen","Actions Microelectronics Co.",
		"Qualcomm / Option","Point Grey Research, Inc.","Mirion Technologies Dosimetry Services Division","Lumension Security","INVIA",
		"Festo AG & Co. KG","Chipsbank Microelectronics Co., Ltd","Cleverscope","Cubeternet","TypeMatrix",
		"TrekStor GmbH & Co. KG","NZXT","Coby Electronics Corporation","ROCCAT","NuCORE Technology, Inc.",
		"AirTies Wireless Networks","Blackmagic design","ONDA COMMUNICATION S.p.a.","EADS Deutschland GmbH","Cal-Comp",
		"Onda (unverified)","The Neat Company","H-TRONIC GmbH","G-Tek Electronics Group","Aliph",
		"Innostor Technology Corporation","TANDBERG","Alere, Inc.","Stantum","Ubiquiti Networks, Inc.",
		"Samsung Opto-Electroncs Co., Ltd.","Delphin Technology AG","NXP Semiconductors","ILX Lightwave Corporation","Vertex Wireless Co., Ltd.",
		"CVT Electronics.Co.,Ltd","Ideofy Inc.","D-Link Corp.","DAP Technologies","Reloop",
		"PCTV Systems","PLANEX","Hauppauge","Texas Instruments","Barnes & Noble",
		"Cando","Clay Logic","XMOS Ltd","Hanvon","Qi Hardware",
		"Simtec Electronics","TRENDnet","ActionStar","Advanced Silicon S.A.","Creative (?)",
		"GW Instek","Emotiv Systems Pty. Ltd.","Agecodagis SARL","MacAlly","SAMWOO Enterprise",
		"Silicon Motion","RadioShack Corporation","Kobo Inc.","8D Technologies inc.","Pie Digital, Inc.",
		"Motorola PCS","eTurboTouch Technology, Inc.","Technology Innovation Holdings, Ltd","Pinnacle Systems, Inc.","Shining Technologies, Inc. [hex]",
		"Arduino SA","Pumatronix Ltda","Digit@lway, Inc.","SANHO Digital Electronics Co., Ltd.","Aessent Technology Ltd",
		"Tripp-Lite","TwinMOS","Electronics For Imaging, Inc. [hex]","Sundtek","Citizen",
		"DigitalWay","NHJ, Ltd","ASUSTek Computer Inc.","Toptronic Industrial Co., Ltd","Planex Communications",
		"Dolphin Peripherals","Fujitsu, Ltd","Eagletron","Whanam Electronics Co., Ltd","VidzMedia Pte Ltd",
		"AEI","Yakumo","Micro Star","Power Quotient International Co., Ltd","DIVA",
		"InVibro","WEM","National Instruments Corp.","I-O Data","i-rocks",
		"iRiver, Ltd.","Dell Computer Corp.","USBest Technology","USB Design by Example","Broadcom Corp.",
		"WinChipHead","Shuttle, Inc.","Panram","EMS Production","Miditech",
		"GW Instek","Aceeca","Memorex","SimpleTech","Musical Fidelity",
		"Grandtec","Linksys (?)","Averatec (?)","Sweex","I-Tetra",
		"Owon","Transmeta Corp.","UC-Logic Technology Corp.","Epiphan Systems Inc.","OnSpec Electronic, Inc.",
		"Uni-Trend Group Limited","IRTOUCHSYSTEMS Co. Ltd.","Acer, Inc","Zinwell","Beholder International Ltd.",
		"Ingenic Semiconductor Ltd.","Sitecom","TwinHan Technology Co., Ltd","CoreLogic, Inc.","Unknown (Sony?)",
		"Arkmicro Technologies Inc.","IRTOUCHSYSTEMS Co. Ltd.","Prototype product Vendor ID","WiseGroup, Ltd.","3Com",
		"Opera1","Yealink Network Technology Co., Ltd.","Shanghai Jujo Electronics Co., Ltd","CME (Central Music Co.)","StackFoundry LLC",
		"TBS Technologies China","Edimax Technology Co., Ltd","Intel Corp.","Intel Corp.","VirtualBox",
		"Keio","EGO Systems, Inc.","Sitecom","TeVii Technology Ltd.","GeoLab, Ltd",
		"MosChip Semiconductor","Grandtec","J. Westhues","AnMo Electronics Corp. / Dino-Lite (?)","AnMo Electronics Corporation",
		"Asix","3Com","Unknown","Keil Software, Inc.","CACE Technologies Inc.",
		"Ultimarc","Xorcom Ltd.","MakingThings","eMPIA Technology, Inc.","KWorld",
		"Hewlett Packard","Atten Electronics / Siglent Technologies"};

	InsertVendors(mid, mids, ARRAYSIZE(mid));
	};

	void RCSGUsbIds::InitManufacturesProductsUsbIdsHash()
	{

	{
		DWORD mid[] = {0x142b,0x7778};
		char* mids[] = {"Arbiter Systems, Inc.","Counterfeit flash drive [Kingston]"};
		InsertProducts(0x0001, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7788};
		char* mids[] = {"Flash mass storage drive"};
		InsertProducts(0x0011, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5301};
		char* mids[] = {"GW-US54ZGL 802.11bg"};
		InsertProducts(0x0053, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0006,0x0011};
		char* mids[] = {"PC TWIN SHOCK Gamepad","Gamepad"};
		InsertProducts(0x0079, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x145f};
		char* mids[] = {"NW-3100 802.11b/g 54Mbps Wireless Network Adapter [zd1211]"};
		InsertProducts(0x0105, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0112};
		char* mids[] = {"Card Reader"};
		InsertProducts(0x0145, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x145f};
		char* mids[] = {"Trust Deskset"};
		InsertProducts(0x017c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0201};
		char* mids[] = {"MA180 UMTS Modem"};
		InsertProducts(0x0200, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6025,0x6026};
		char* mids[] = {"CBM2080 / CBM2090 Flash drive controller","CBM1180 Flash drive controller"};
		InsertProducts(0x0204, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0301};
		char* mids[] = {"MIDI Port"};
		InsertProducts(0x0218, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x138c};
		char* mids[] = {"PVR Mass Storage"};
		InsertProducts(0x02ad, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xbc06,0xbc08};
		char* mids[] = {"OCZ ATV USB 2.0 Flash Drive","OCZ Rally2/ATV USB 2.0 Flash Drive"};
		InsertProducts(0x0324, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xac02};
		char* mids[] = {"ATV Turbo / Rally2 Dual Channel USB 2.0 Flash Drive"};
		InsertProducts(0x0325, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"PSX for USB Converter"};
		InsertProducts(0x0386, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0499};
		char* mids[] = {"SE340D PC Remote Control"};
		InsertProducts(0x03d9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"HD44780 LCD interface"};
		InsertProducts(0x03da, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004,0x0008,0x0015,0x2123,0x8004};
		char* mids[] = {"SE401 Webcam","101 Ethernet [klsi]","ATAPI Enclosure","SiPix StyleCam Deluxe","Aox 99001"
		};
		InsertProducts(0x03e8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0902,0x2002,0x2015,0x2018,0x2019,0x201c,0x201d,0x2022,0x2040,0x2041,0x2042,0x2043,0x2044,0x2045,0x2046,0x2047,0x2048,0x2049,0x204a,0x204b,
		0x204c,0x204d,0x204e,0x204f,0x2060,0x2061,0x2062,0x2063,0x2064,0x2065,0x2066,0x2068,0x2069,0x2103,0x2104,0x2105,0x2106,0x2107,0x2109,0x210d,
		0x2110,0x2122,0x2141,0x2310,0x2fe4,0x2ff0,0x2ffa,0x2ffb,0x2ffd,0x2fff,0x3301,0x3312,0x4102,0x5601,0x5603,0x6119,0x6124,0x6127,0x6129,0x6200,
		0x7603,0x7604,0x7605,0x7606,0x7611,0x7613,0x7614,0x7615,0x7617,0x7800,0xff07};
		char* mids[] = {"4-Port Hub","Mass Storage Device","at90usbkey sample firmware (HID keyboard)","at90usbkey sample firmware (CDC ACM)","stk525 sample firmware (microphone)",
		"at90usbkey sample firmware (HID mouse)","at90usbkey sample firmware (HID generic)","at90usbkey sample firmware (composite device)","LUFA Test PID","LUFA Mouse Demo Application",
		"LUFA Keyboard Demo Application","LUFA Joystick Demo Application","LUFA CDC Demo Application","LUFA Mass Storage Demo Application","LUFA Audio Output Demo Application",
		"LUFA Audio Input Demo Application","LUFA MIDI Demo Application","Stripe Snoop Magnetic Stripe Reader","LUFA CDC Class Bootloader","LUFA USB to Serial Adapter Project",
		"LUFA RNDIS Demo Application","LUFA Combined Mouse and Keyboard Demo Application","LUFA Dual CDC Demo Application","LUFA Generic HID Demo Application","Benito Programmer Project",
		"LUFA Combined Mass Storage and Keyboard Demo Application","LUFA Combined CDC and Mouse Demo Application","LUFA Datalogger Device","Interfaceless Control-Only LUFA Devices","LUFA Test and Measurement Demo Application",
		"LUFA Multiple Report HID Demo","LUFA Virtual Serial/Mass Storage Demo","LUFA Webserver Project","JTAG ICE mkII","AVR ISP mkII",
		"AVRONE!","STK600 development board","AVR Dragon","STK541 ZigBee Development Board","XPLAIN evaluation kit (CDC ACM)",
		"AVR JTAGICE3 Debugger and Programmer","XMEGA-A1 Explained evaluation kit","ICE debugger","EVK11xx evaluation board","ATxmega32A4U DFU bootloader",
		"atmega32u2 DFU bootloader","at90usb162 DFU bootloader","at90usb AVR DFU bootloader","at89c5130/c5131 DFU bootloader","at89c5132/c51snd1c DFU bootloader",
		"at43301 4-Port Hub","4-Port Hub","AirVast W-Buddie WN210","at76c510 Prism-II 802.11b Access Point","Cisco 7920 WiFi IP Phone",
		"AT91SAM CDC Demo Application","at91sam SAMBA bootloader","AT91SAM HID Keyboard Demo Application","AT91SAM Mass Storage Demo Application","AT91SAM HID Mouse Demo Application",
		"D-Link DWL-120 802.11b Wireless Adapter [Atmel at76c503a]","at76c503a 802.11b Adapter","at76c503a 802.11b Adapter","at76c505 802.11b Adapter","at76c510 rfmd2948 802.11b Access Point",
		"WL-1130 USB","AT76c505a Wireless Adapter","AT76C505AMX Wireless Adapter","AT76C505AS Wireless Adapter","Mini Album",
		"Tux Droid fish dongle"};
		InsertProducts(0x03eb, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x2501,0x2502,0x5609,0x641f,0x6438,0x6440,0x6901,0x6902,0x7500,0xffff};
		char* mids[] = {"CD-R/RW Drive","eHome Infrared Receiver","eHome Infrared Receiver","Japanese Keyboard","WIF-0402C Bluetooth Adapter",
		"Bluetooth Device","WML-C52APR Bluetooth Adapter","SmartDisk FDD","Floppy Disk Drive","CD-R/RW",
		"Dongle with BlueCore in DFU mode"};
		InsertProducts(0x03ee, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004,0x0011,0x0012,0x0024,0x002a,0x0101,0x0102,0x0104,0x0105,0x0107,0x010c,0x0111,0x0117,0x011c,0x011d,0x0121,0x0122,0x0139,0x0201,0x0202,
		0x0204,0x0205,0x0207,0x020c,0x0211,0x0212,0x0217,0x0218,0x0304,0x0305,0x0307,0x0311,0x0312,0x0314,0x0317,0x0324,0x0401,0x0404,0x0405,0x0411,
		0x0412,0x0417,0x0423,0x042a,0x0441,0x0504,0x0505,0x0507,0x050c,0x0511,0x0512,0x0517,0x051d,0x0601,0x0604,0x0605,0x0611,0x0612,0x0624,0x0701,
		0x0704,0x0705,0x0711,0x0712,0x0714,0x0801,0x0804,0x0805,0x0811,0x0817,0x0901,0x0904,0x0912,0x0917,0x0924,0x094a,0x0a01,0x0a17,0x0b01,0x0b0c,
		0x0b17,0x0c17,0x0c24,0x0d12,0x0d17,0x0e17,0x0f0c,0x0f11,0x0f12,0x0f17,0x1001,0x1002,0x1004,0x1005,0x1011,0x1016,0x1017,0x1024,0x1027,0x1102,
		0x1104,0x1105,0x1111,0x1116,0x1117,0x1151,0x1202,0x1204,0x1205,0x1211,0x1217,0x1302,0x1305,0x1311,0x1312,0x1317,0x1327,0x1405,0x1411,0x1424,
		0x1502,0x1504,0x150c,0x1511,0x1512,0x1517,0x1524,0x1539,0x1602,0x1604,0x1605,0x1611,0x1617,0x161d,0x1624,0x1702,0x1704,0x1705,0x1711,0x1712,
		0x1717,0x171d,0x1801,0x1802,0x1804,0x1805,0x1811,0x1812,0x1817,0x181d,0x1902,0x1904,0x1911,0x1917,0x1a02,0x1a11,0x1a17,0x1b02,0x1b04,0x1b05,
		0x1b07,0x1c02,0x1c17,0x1d02,0x1d17,0x1d24,0x1e02,0x1e11,0x1e17,0x1f02,0x1f11,0x1f12,0x1f17,0x1f1d,0x2001,0x2002,0x2004,0x2005,0x2012,0x201d,
		0x2039,0x2102,0x2104,0x2112,0x211d,0x2202,0x2205,0x2212,0x2217,0x2302,0x2304,0x2305,0x2311,0x2312,0x2317,0x231d,0x2402,0x2404,0x2405,0x2417,
		0x241d,0x2424,0x2502,0x2504,0x2505,0x2512,0x2514,0x2517,0x251d,0x2524,0x2602,0x2605,0x2611,0x2617,0x2624,0x2702,0x2704,0x2717,0x2724,0x2811,
		0x2817,0x2902,0x2911,0x2917,0x2a11,0x2a17,0x2b11,0x2b17,0x2c12,0x2c17,0x2c24,0x2d05,0x2d11,0x2d17,0x2e11,0x2e17,0x2e24,0x2f11,0x2f17,0x2f24,
		0x3002,0x3004,0x3005,0x3011,0x3017,0x3102,0x3104,0x3111,0x3117,0x311d,0x3202,0x3207,0x3211,0x3217,0x3302,0x3304,0x3312,0x3317,0x3402,0x3404,
		0x3417,0x3502,0x3504,0x3511,0x3517,0x3602,0x3611,0x3617,0x3711,0x3717,0x3724,0x3802,0x3807,0x3817,0x3902,0x3a02,0x3a11,0x3a17,0x3b02,0x3b05,
		0x3b11,0x3b17,0x3c02,0x3c05,0x3c11,0x3c17,0x3d02,0x3d11,0x3d17,0x3e02,0x3e17,0x3f02,0x3f11,0x4002,0x4004,0x4102,0x4105,0x4111,0x4117,0x4202,
		0x4205,0x4211,0x4217,0x4302,0x4305,0x4311,0x4317,0x4402,0x4417,0x4502,0x4505,0x4507,0x4511,0x4512,0x4517,0x4605,0x4611,0x4717,0x4811,0x4911,
		0x4b11,0x4c11,0x4c17,0x4d11,0x4d17,0x4e11,0x4f11,0x4f17,0x5004,0x5011,0x5017,0x5111,0x5211,0x5307,0x5311,0x5312,0x5411,0x5511,0x5611,0x5617,
		0x5711,0x5717,0x5811,0x5817,0x5911,0x5912,0x5a11,0x5b11,0x5c11,0x5c12,0x5c17,0x5d11,0x5e11,0x6004,0x6102,0x6104,0x6117,0x6202,0x6204,0x6217,
		0x6302,0x6317,0x6402,0x6411,0x6417,0x6502,0x6511,0x6602,0x6611,0x6617,0x6702,0x6717,0x6802,0x6811,0x6817,0x6911,0x6917,0x6a02,0x6a11,0x6a17,
		0x6b02,0x6b11,0x6c11,0x6c17,0x6f17,0x7004,0x7102,0x7104,0x7117,0x7202,0x7204,0x7217,0x7302,0x7304,0x7311,0x7317,0x7404,0x7417,0x7504,0x7517,
		0x7604,0x7611,0x7617,0x7702,0x7704,0x7717,0x7804,0x7817,0x7917,0x7a02,0x7a04,0x7a17,0x7b02,0x7b17,0x7c17,0x7d04,0x7d17,0x7e04,0x8017,0x8104,
		0x8117,0x811c,0x8204,0x8207,0x8217,0x8317,0x8404,0x8417,0x8504,0x8604,0x8607,0x8704,0x8711,0x8804,0x8904,0x8c07,0x8c11,0x9002,0x9102,0x9302,
		0x9402,0x9502,0x9602,0x9702,0x9802,0x9902,0x9a02,0x9b02,0x9b07,0x9c02,0xa004,0xa011,0xb002,0xb102,0xb107,0xb116,0xb202,0xb302,0xb402,0xb502,
		0xb602,0xb702,0xb802,0xb902,0xba02,0xbb02,0xbc02,0xbd02,0xbef4,0xc002,0xc102,0xc202,0xc302,0xc402,0xc502,0xc602,0xc702,0xc802,0xd104,0xefbe,
		0xf0be,0xf1be};
		char* mids[] = {"DeskJet 895c","OfficeJet G55","DeskJet 1125C Printer Port","KU-0316 Keyboard","LaserJet P1102",
		"ScanJet 4100c","PhotoSmart S20","DeskJet 880c/970c","ScanJet 4200c","CD-Writer Plus",
		"Multimedia Keyboard Hub","G55xi Printer/Scanner/Copier","LaserJet 3200","hn210w 802.11b Adapter","Bluetooth 1.2 Interface [Broadcom BCM2035]",
		"HP49g+ Calculator","HID Internet Keyboard","Barcode Scanner 4430","ScanJet 6200c","PhotoSmart S20",
		"DeskJet 815c","ScanJet 3300c","CD-Writer Plus 8200e","Multimedia Keyboard","OfficeJet G85",
		"DeskJet 1220C","LaserJet 2200","APOLLO P2500/2600","DeskJet 810c/812c","ScanJet 4300c",
		"CD-Writer+ CD-4e","OfficeJet G85xi","Color Inkjet CP1700","designjet 30/130 series","LaserJet 1200",
		"SK-2885 keyboard","ScanJet 5200c","DeskJet 830c/832c","ScanJet 3400cse","OfficeJet G95",
		"Printing Support","LaserJet 1200 series","HS-COMBO Cardreader","LaserJet M1132 MFP","HP Prime Calculator",
		"DeskJet 885c","ScanJet 2100c","DVD+RW","5219 Wireless Keyboard","OfficeJet K60",
		"DeckJet 450","LaserJet 1000","Bluetooth Interface","ScanJet 6300c","DeskJet 840c",
		"ScanJet 2200c","OfficeJet K60xi","business inkjet 3000","Bluetooth Dongle","ScanJet 5300c/5370c",
		"DeskJet 825c","ScanJet 4400c","OfficeJet K80","DeskJet 1180c","Printing Support",
		"ScanJet 7400c","DeskJet 816c","HP4470C","OfficeJet K80xi","LaserJet 3300",
		"ScanJet 2300c","DeskJet 845c","Printing Support","LaserJet 3330","Modular Smartcard Keyboard",
		"Optical Mouse [672662-001]","ScanJet 2400c","color LaserJet 3700","ScanJet 82x0C","Wireless Keyboard and Optical Mouse receiver",
		"LaserJet 2300d","LaserJet 1010","Bluetooth Dongle","OfficeJet 9100 series","LaserJet 1012",
		"LaserJet 1015","Wireless Keyboard and Optical Mouse receiver","OfficeJet V40","Printing Support","LaserJet 1150",
		"Photo Scanner 1000","PhotoSmart 140 series","DeskJet 970c/970cse","ScanJet 5400c","OfficeJet V40xi",
		"Jornada 548 / iPAQ HW6515 Pocket PC","LaserJet 1300","Smart Card Keyboard","Virtual keyboard and mouse","PhotoSmart 240 series",
		"DeskJet 959c","ScanJet 5470c/5490c","OfficeJet v60","Jornada 568 Pocket PC","LaserJet 1300n",
		"PSC-750xi Printer/Scanner/Copier","PhotoSmart 320 series","DeskJet 930c","ScanJet 4500C/5550C","OfficeJet v60xi",
		"LaserJet 2300L","PhotoSmart 370 series","ScanJet 4570c","OfficeJet V30","DeskJet 460",
		"LaserJet 1005","iLO Virtual Hub","ScanJet 3670","PSC 750","f2105 Monitor Hub",
		"PhotoSmart 420 series","DeskJet 920c","Mood Lighting (Microchip Technology Inc.)","PSC 750xi","Printing Support",
		"color LaserJet 3500","Smart Card Keyboard - KR","Mini Magnetic Stripe Reader","PhotoSmart 330 series","DeskJet 940c",
		"ScanJet 5530C PhotoSmart","psc 780","LaserJet 3015","Wireless Rechargeable Optical Mouse (HID)","Smart Card Keyboard - JP",
		"PhotoSmart 380 series","DeskJet 948C","ScanJet 5590","psc 780xi","Printing Support",
		"LaserJet 3020","Bluetooth 2.0 Interface [Broadcom BCM2045]","Inkjet P-2000U","PhotoSmart 470 series","DeskJet 916C",
		"ScanJet 7650","PSC 720","OfficeJet Pro K550","LaserJet 3030","Bluetooth 2.0 Interface",
		"PhotoSmart A430 series","DeskJet 3820","OfficeJet V45","LaserJet 3380","PhotoSmart A510 series",
		"OfficeJet 5100 series","color LaserJet 4650","PhotoSmart A610 series","DeskJet 3810","ScanJet 4850C/4890C",
		"Premium Starter Webcam","PhotoSmart A710 series","Color LaserJet 2550l","PhotoSmart A310 series","LaserJet 1320",
		"Barcode scanner","PhotoSmart A320 Printer series","PSC-950","LaserJet 1160 series","PhotoSmart A440 Printer series",
		"PSC 920","OfficeJet Pro K5300","color LaserJet 5550","un2400 Gobi Wireless Modem","Floppy",
		"Hub","DeskJet 640c","ScanJet 3570c","OfficeJet Pro K5400","un2400 Gobi Wireless Modem (QDL mode)",
		"Cashdrawer","PhotoSmart 7345","DeskJet 630c","OfficeJet Pro L7500","Sierra MC5725 [ev2210]",
		"PhotoSmart 7600 series","ScanJet 3500c","OfficeJet Pro L7600","color LaserJet 9500 MFP","PhotoSmart 7600 series",
		"DeskJet 656c","ScanJet 3970c","OfficeJet d series","OfficeJet Pro L7700","LaserJet 4350",
		"Broadcom 2070 Bluetooth Combo","PhotoSmart 7700 series","Deskjet F2280 series","ScanJet 4070 PhotoSmart","LaserJet 4250",
		"Gobi 2000 Wireless Modem (QDL mode)","LP1965 19\" Monitor Hub","PhotoSmart 7700 series","DeskJet F4200 series","ScanJet 3770",
		"OfficeJet Pro L7300 / Compaq LA2405 series monitor","4-port hub","LaserJet 2410","Gobi 2000 Wireless Modem","LP3065 30\" Monitor Hub",
		"PhotoSmart A520 series","ScanJet 3800c","OfficeJet 7100 series","Color LaserJet 2820 series","Pole Display (HP522 2 x 20 Line Display)",
		"PhotoSmart A620 series","DeskJet 915","Color LaserJet 2830","Magnetic Stripe Reader IDRA-334133-HP","PSC-2100",
		"Color LaserJet 2840","PhotoSmart A820 series","PSC 2200","LaserJet 2420","PSC 2150 series",
		"LaserJet 2430","PSC 2170 series","LaserJet 1020","Officejet J4680","LaserJet 1022",
		"Logitech M-UAL-96 Mouse","Scanjet 7000","OfficeJet 6110","Printing Support","PSC 1000",
		"LaserJet 2600n","LP2275w Monitor Hub","PSC 1200","EWS 2605dn","LP2475w Monitor Hub",
		"PhotoSmart P1000","DeskJet 980c","ScanJet 4670v","PSC 1100 series","Printing Support",
		"PhotoSmart P1100 Printer w/ Card Reader","DeskJet 960c","OfficeJet 4100 series","EWS 2605dtn","Atheros AR9285 Malbec Bluetooth Adapter",
		"PhotoSmart 1215","4 GB flash drive","OfficeJet 4105 series","LaserJet 3050","PhotoSmart 1218",
		"DeskJet 990c","OfficeJet J6410","LaserJet 3052","PhotoSmart 1115","DeskJet 6122",
		"LaserJet 3055","PhotoSmart 230","DeskJet 6127c","PSC 2300","LaserJet 3390",
		"PhotoSmart 1315","PSC 2410 PhotoSmart","Color LaserJet 2605","PSC 2500","EWS UPD",
		"Webcam","PhotoSmart 100","c485w Flash Drive","LaserJet P2015 series","PhotoSmart 130",
		"PhotoSmart 7150","OfficeJet 5500 series","Printing Support","PhotoSmart 7150~","Scanjet N8460",
		"PSC 1300 series","LaserJet M1005 MFP","PhotoSmart 7350","Scanjet Professional 1000 Mobile Scanner","PSC 1358",
		"EWS UPD","PhotoSmart 7350~","OfficeJet 4215","LaserJet P1005","PhotoSmart 7550",
		"LaserJet P1006","PhotoSmart 7550~","PSC-1315/PSC-1317","PhotoSmart 635/715/720/735/935 (storage)","cp1160",
		"PhotoSmart 618","ScanJet 4370","OfficeJet 7200 series","LaserJet 1018","PhotoSmart 812",
		"ScanJet G3010","OfficeJet 7300 series","EWS CM1015","PhotoSmart 850 (ptp)","ScanJet G3110",
		"OfficeJet 7400 series","Color LaserJet CM1017","PhotoSmart 935 (ptp)","EWS UPD","PhotoSmart 945 (PTP mode)",
		"ScanJet G4010","External HDD","PhotoSmart 2600","E709n [Officejet 6500 Wireless]","EWS UPD",
		"ScanJet G4050","PhotoSmart 2700","Color LaserJet CP1215","PSC 1600","PSC 2350",
		"OfficeJet 6200","PSC 1500 series","EWS UPD","PSC 1400","EWS UPD",
		"PhotoSmart 2570 series","OfficeJet 5600 (USBHUB)","Color LaserJet CM1312 MFP","DeskJet 995c","PhotoSmart 3100 series",
		"EWS UPD","PhotoSmart 3200 series","PhotoSmart 3300 series","v165w Stick","OfficeJet 6300",
		"Officejet Pro 8500A","OfficeJet 4300","DeskJet F300 series","PhotoSmart C3180","LaserJet M1120 MFP",
		"PhotoSmart C4100 series","LaserJet M1120n MFP","PhotoSmart C5100 series","LaserJet M1319f MFP","PhotoSmart C6180",
		"Officejet Pro 8600","PhotoSmart C7100 series","OfficeJet J2100 series","PhotoSmart C4200 Printer series","OfficeJet 6700",
		"LaserJet P2055 series","PhotoSmart C5200 series","PhotoSmart D7400 series","DeskJet 5550","Hewlett Packard Digital Camera",
		"DeskJet 5650c","color LaserJet 3550","PhotoSmart 215","DeskJet 5150c","Color LaserJet 4700",
		"PhotoSmart 318/612","Color LaserJet 4730mfp","PhotoSmart 715 (ptp)","PhotoSmart C8100 series","LaserJet 5200",
		"PhotoSmart 120 (ptp)","PhotoSmart C7200 series","PhotoSmart 320","PhotoSmart C4380 series","LaserJet 5200L",
		"PhotoSmart 720 (ptp)","Color LaserJet 3000","PhotoSmart 620 (ptp)","PhotoSmart D5300 series","Color LaserJet 3800",
		"PhotoSmart D7200 series","Color LaserJet 3600","PhotoSmart 735 (ptp)","PhotoSmart C6200 series","LaserJet 4240",
		"PhotoSmart R707 (PTP mode)","Photosmart C4500 series","Photosmart C4480","Color LaserJet 4610","Color LaserJet CP6015 series",
		"DeskJet 3320c","PhotoSmart 635 (PTP mode)","DeskJet 3420c","CM8060 Color MFP with Edgeline Technology","PhotoSmart 43x (ptp)",
		"DeskJet 36xx","LaserJet M5035 MFP","PhotoSmart M307 (PTP mode)","DeskJet 35xx","Photosmart Premium C309",
		"LaserJet P3005","Printing Support","LaserJet M4345 MFP","Printing Support","LaserJet M3035 MFP",
		"DeskJet 3940","DeskJet F2492 All-in-One","LaserJet P3004","PhotoSmart R817 (PTP mode)","DeskJet D4100",
		"CM8050 Color MFP with Edgeline Technology","DeskJet D1360","Color LaserJet CP3505","LaserJet M5025 MFP","PhotoSmart M415 (PTP mode)",
		"DeskJet D2460","LaserJet M3027 MFP","PhotoSmart M23 (PTP mode)","Color LaserJet CP4005","Color LaserJet CM6040 series",
		"DeskJet F2100 Printer series","Color LaserJet CM4730 MFP","DeskJet F4100 Printer series","LaserJet P4515","Printing Support",
		"LaserJet P4015","Ethernet HN210E","Printing Support","FHA-3510 2.4GHz Wireless Optical Mobile Mouse","LaserJet P4014",
		"LaserJet M9050 MFP","DeskJet 6800 series","LaserJet M9040 MFP","DeskJet 6600 series","DeskJet 5440",
		"Optical Mobile Mouse","DeskJet 5940","Deskjet 2050 J510","DeskJet 6980 series","DeskJet 6940 series",
		"Digital Stereo Headset","Deskjet F4500 series","PhotoSmart M437","PhotoSmart M537","PhotoSmart R930 series",
		"PhotoSmart R837","PhotoSmart R840 series","PhotoSmart M730 series","PhotoSmart R740 series","PhotoSmart Mz60 series",
		"PhotoSmart M630 series","PhotoSmart E330 series","PhotoSmart M540 series","Portable Drive","PhotoSmart M440 series",
		"DeskJet 5850c","Deskjet 3050A","PhotoSmart 7200 series","PhotoSmart 7200 series","v255w/c310w Flash Drive",
		"Webcam","PhotoSmart 7600 series","PhotoSmart 7600 series","PhotoSmart 7700 series","PhotoSmart 7700 series",
		"PhotoSmart 7900 series","PhotoSmart 7900 series","PhotoSmart 7400 series","PhotoSmart 7800 series","PhotoSmart 8100 series",
		"PhotoSmart 8400 series","PhotoSmart 8700 series","PhotoSmart Pro B9100 series","NEC Picty760","PhotoSmart 7800 series",
		"PhotoSmart 8000 series","PhotoSmart 8200 series","DeskJet D2300","PhotoSmart D5100 series","PhotoSmart D6100 series",
		"PhotoSmart D7100 series","PhotoSmart D7300 series","PhotoSmart D5060 Printer","Bluetooth Dongle","NEC Picty900",
		"NEC Picty920","NEC Picty800"};
		InsertProducts(0x03f0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0020,0x0080,0x0083,0x0087,0x0088,0x008b,0x008c,0x0094,0x009b,0x2000,0x2001,0x2002,0x2003,0x4000,0xadcc};
		char* mids[] = {"AWN-8020 WLAN [Intersil PRISM 2.5]","AVC-1100 Audio Capture","AVC-2200 Device","AVC-2210 Loader","AVC-2210 Device",
		"AVC-2310 Loader","AVC-2310 Device","eHome Infrared Receiver","AVC-1410 GameBridge TV NTSC","USBXchange",
		"USBXchange Adapter","USB2-Xchange","USB2-Xchange Adapter","4-port hub","Composite Device Support"
		};
		InsertProducts(0x03f3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0101,0x0102};
		char* mids[] = {"KT-2001 Keyboard","Keyboard","Keyboard Mouse"};
		InsertProducts(0x03f9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0008};
		char* mids[] = {"Platform Cable USB II"};
		InsertProducts(0x03fd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x05dc,0x0807,0x080a,0x09c4,0x1000,0x1001,0x1237,0xa000,0xc359,0xc35b,0xc55d};
		char* mids[] = {"Rigol Technologies DS1000USB Oscilloscope","Bluetooth Dongle","Bluetooth Device","Rigol Technologies DG1022 Arbitrary Waveform Generator","Mustek BearPaw 1200 Scanner",
		"Mustek BearPaw 2400 Scanner","Hub","Smart Display Reference Device","Logitech Harmony","Printing Support",
		"Rigol Technologies DS5000USB Oscilloscope"};
		InsertProducts(0x0400, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5462,0x5602,0x5603,0x5606,0x5621,0x5623,0x5627,0x5632,0x5635,0x5636,0x5637,0x5661,0x5667,0x9665};
		char* mids[] = {"M5462 IDE Controller","M5602 Video Camera Controller","M5603 Video Camera Controller","M5606 Video Camera Controller [UVC]","M5621 High-Speed IDE Controller",
		"M5623 Scanner Controller","Welland ME-740PS USB2 3.5\" Power Saving Enclosure","M5632 Host-to-Host Link","M5635 Flash Card Reader","USB 2.0 Storage Device",
		"M5637 IDE Controller","M5661 MP3 player","M5667 MP3 player","Gateway Webcam"};
		InsertProducts(0x0402, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0232,0x1060,0x1234,0x6001,0x6002,0x6007,0x6008,0x6009,0x6010,0x6011,0x6014,0x6015,0x8028,0x8040,0x8070,0x8140,0x8210,0x8370,0x8371,
		0x8372,0x8a28,0x8a98,0x8b28,0x8b29,0x8b2a,0x8b2b,0x8b2c,0x9132,0x9133,0x9135,0x9136,0x9e90,0x9f80,0xa6d0,0xa951,0xabb8,0xb810,0xb811,0xb812,
		0xb9b0,0xbaf8,0xbcd8,0xbcd9,0xbcda,0xbdc8,0xbfd8,0xbfd9,0xbfda,0xbfdb,0xbfdc,0xc630,0xc631,0xc632,0xc633,0xc634,0xc7d0,0xc8b8,0xc8b9,0xc8ba,
		0xc8bb,0xc8bc,0xc8bd,0xc8be,0xc8bf,0xcc48,0xcc49,0xcc4a,0xcff8,0xd010,0xd011,0xd012,0xd013,0xd491,0xd578,0xd6f8,0xd738,0xd739,0xd9a9,0xd9aa,
		0xe0d0,0xe521,0xe6c8,0xe700,0xe729,0xe888,0xe889,0xe88a,0xe88b,0xe88c,0xe8d8,0xe8dc,0xea90,0xed71,0xed72,0xed73,0xed74,0xef10,0xf070,0xf0e9,
		0xf1a0,0xf208,0xf3c0,0xf608,0xf60b,0xf680,0xf758,0xf7c0,0xf850,0xf918,0xfa00,0xfa01,0xfa02,0xfa03,0xfa04,0xfa20,0xfc08,0xfc09,0xfc0b,0xfc0c,
		0xfc0d,0xfc82,0xfd48,0xfd49,0xff08,0xff18,0xff19,0xff1a,0xff1b,0xff1c,0xff1d,0xff1e,0xff1f};
		char* mids[] = {"H4SMK 7 Port Hub","Serial Converter","JTAG adapter","IronLogic RFID Adapter [Z-2 USB]","FT232 USB-Serial (UART) IC",
		"Lumel PD12","Serial Converter","Serial Converter","Serial Converter","FT2232C Dual USB-UART/FIFO IC",
		"FT4232H Quad HS USB-UART/FIFO IC","FT232H Single HS USB-UART/FIFO IC","Bridge(I2C/SPI/UART/FIFO)","Dev board JTAG (FT232H based)","4 Port Hub",
		"7 Port Hub","Vehicle Explorer Interface","MGTimer - MGCC (Vic) Timing System","7 Port Hub","PS/2 Keyboard And Mouse",
		"FT8U100AX Serial Port","Rainforest Automation ZigBee Controller","TIAO Multi-Protocol Adapter","Alpermann+Velte TCI70","Alpermann+Velte TC60 CLS",
		"Alpermann+Velte Rubidium Q1","Alpermann+Velte TCD","Alpermann+Velte TCC70","LCD and Temperature Interface","CallerID",
		"Rotary Pub alarm","Pulsecounter","Marvell OpenRD Base/Client","Ewert Energy Systems CANdapter","Texas Instruments XDS100v2 JTAG / BeagleBone A3",
		"HCP HIT GSM/GPRS modem [Cinterion MC55i]","Lego Mindstorms NXTCam","US Interface Navigator (CAT and 2nd PTT lines)","US Interface Navigator (WKEY and FSK lines)","US Interface Navigator (RS232 and CONFIG lines)",
		"Fujitsu SK-16FX-100PMC V1.1","Amontec JTAGkey","Stellaris Development Board","Stellaris Evaluation Board","Stellaris ICDI Board",
		"Egnite GmbH - JTAG/RS-232 adapter","OpenDCC","OpenDCC (Sniffer)","OpenDCC (Throttle)","OpenDCC (Gateway)",
		"OpenDCC (GBM)","lcd2usb interface","i2c-tiny-usb interface","xu1541 c64 floppy drive interface","TinyCrypt dongle",
		"glcd2usb interface","RR-CirKits LocoBuffer-USB","Alpermann+Velte MTD TCU","Alpermann+Velte MTD TCU 1HE","Alpermann+Velte Rubidium H1",
		"Alpermann+Velte Rubidium H3","Alpermann+Velte Rubidium S1","Alpermann+Velte Rubidium T1","Alpermann+Velte Rubidium D1","Alpermann+Velte TC60 RLV",
		"Tactrix OpenPort 1.3 Mitsubishi","Tactrix OpenPort 1.3 Subaru","Tactrix OpenPort 1.3 Universal","Amontec JTAGkey","SCS PTC-IIusb",
		"SCS Position-Tracker/TNC","SCS DRAGON 1","SCS DRAGON 1","Zolix Omni 1509 monochromator","Accesio USB-COM-4SM",
		"UNI Black BOX","Propox JTAGcable II","Propox ISPcable III","Actisense USG-1 NMEA Serial Gateway","Actisense NGT-1 NMEA2000 PC Interface",
		"Total Phase Aardvark I2C/SPI Host Adapter","EVER Sinline XL Series UPS","PYRAMID Computer GmbH LCD","Elster Unicom III Optical Probe","Segway Robotic Mobility Platforms 200",
		"Expert ISDN Control USB","USB-RS232 OptoBridge","Expert mouseCLOCK USB II","Precision Clock MSF USB","Expert mouseCLOCK USB II HBG",
		"Aaronia AG Spectran Spectrum Analyzer","Aaronia AG UBBV Preamplifier","Eclo 1-Wire Adapter","HAMEG HO870 Serial Port","HAMEG HO720 Serial Port",
		"HAMEG HO730 Serial Port","HAMEG HO820 Serial Port","FT1245BL","Serial Converter 422/485 [Vardaan VEUSB422R3]","Tagsys L-P101",
		"Asix PRESTO Programmer","Papenmeier Braille-Display","4N-GALAXY Serial Converter","CTI USB-485-Mini","CTI USB-Nano-485",
		"Suunto Sports Instrument","GW Instek GDS-8x0 Oscilloscope","ZeitControl Cardsystems TagTracer MIFARE","USB-UIRT (Universal Infrared Receiver+Transmitter)","Ant8 Logic Probe",
		"Matrix Orbital USB Serial","Matrix Orbital MX2 or MX3","Matrix Orbital MX4 or MX5","Matrix Orbital VK/LK202 Family","Matrix Orbital VK/LK204 Family",
		"Ross-Tech HEX-USB","Crystalfontz CFA-632 USB LCD","Crystalfontz CFA-634 USB LCD","Crystalfontz CFA-633 USB LCD","Crystalfontz CFA-631 USB LCD",
		"Crystalfontz CFA-635 USB LCD","SEMC DSS-20/DSS-25 SyncStation","ShipModul MiniPlex-4xUSB NMEA Multiplexer","ShipModul MiniPlex-4xUSB-AIS NMEA Multiplexer","ToolHouse LoopBack Adapter",
		"ScienceScope Logbook ML","Logbook Bus","Logbook Bus","Logbook Bus","ScienceScope Logbook LS",
		"ScienceScope Logbook HS","Logbook Bus","Logbook Bus"};
		InsertProducts(0x0403, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0202,0x0203,0x0310,0x0311,0x0312,0x0320,0x0321,0x0322,0x0323,0x0324,0x0325,0x0328,0x0329,0x032a,0x032b};
		char* mids[] = {"78XX Scanner","78XX Scanner - Embedded System","K590 Printer, Self-Service","7167 Printer, Receipt/Slip","7197 Printer Receipt",
		"5932-USB Keyboard","5953-USB Dynakey","5932-USB Enhanced Keyboard","5932-USB Enhanced Keyboard, Flash-Recovery/Download","5953-USB Enhanced Dynakey",
		"5953-USB Enhanced Dynakey Flash-Recovery/Download","K016: USB-MSR ISO 3-track MSR: POS Standard (See HID pages)","K018: USB-MSR JIS 2-Track MSR: POS Standard","K016: USB-MSR ISO 3-Track MSR: HID Keyboard Mode","K016/K018: USB-MSR Flash-Recovery/Download"
		};
		InsertProducts(0x0404, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0103,0x030c,0x03b2,0x1030,0x3000,0x3001};
		char* mids[] = {"FV TouchCam N1 (Audio)","HP Webcam","HP Webcam","FV TouchCam N1 (Video)","Optical dual-touch panel",
		"Optical Touch Screen"};
		InsertProducts(0x0408, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0011,0x0012,0x0014,0x0019,0x001a,0x0025,0x0027,0x002c,0x0034,0x003f,0x0040,0x004e,0x004f,0x0050,0x0058,0x0059,0x005a,0x006a,0x007d,0x007e,
		0x0081,0x0082,0x0094,0x0095,0x00a9,0x00aa,0x00ab,0x00ac,0x00ae,0x00af,0x00b0,0x00b2,0x00c0,0x00f7,0x011d,0x0203,0x021d,0x0248,0x0249,0x02b4,
		0x02b6,0x0300,0x0301,0x55aa,0x55ab,0x8010,0x8011,0xefbe,0xf0be};
		char* mids[] = {"PC98 Series Layout Keyboard Mouse","ATerm IT75DSU ISDN TA","Japanese Keyboard","109 Japanese Keyboard with Bus-Powered Hub","PC98 Series Layout Keyboard with Bus-Powered Hub",
		"Mini Keyboard with Bus-Powered Hub","MultiSync Monitor","Clik!-USB Drive","109 Japanese Keyboard with One-touch start buttons","Wireless Keyboard with One-touch start buttons",
		"Floppy","SuperScript 1400 Series","Wireless Keyboard with One-touch start buttons","7-port hub","HighSpeed Hub",
		"HighSpeed Hub","HighSpeed Hub","Conceptronic USB Harddisk Box","MINICUBE2","PG-FP5 Flash Memory Programmer",
		"SuperScript 1400 Series","SuperScript 1400 Series","Japanese Keyboard with One-touch start buttons","Japanese Keyboard","AtermIT21L 128K Support Standard",
		"AtermITX72 128K Support Standard","AtermITX62 128K Support Standard","AtermIT42 128K Support Standard","INSMATEV70G-MAX Standard","AtermITX70 128K Support Standard",
		"AtermITX80 128K Support Standard","AtermITX80D 128K Support Standard","Wireless Remocon","Smart Display PK-SD10","e228 Mobile Phone",
		"HID Audio Controls","Aterm WL54SU2 802.11g Wireless Adapter [Atheros AR5523]","Aterm PA-WL54GU","Aterm WL300NU-G","Aterm WL300NU-AG",
		"Aterm WL300NU-GS 802.11n Wireless Adapter","LifeTouch Note","LifeTouch Note (debug mode)","Hub","Hub [iMac/iTouch kbd]",
		"Intellibase Hub","Intellibase Hub","P!cty 900 [HP DJ]","P!cty 920 [HP DJ 812c]"};
		InsertProducts(0x0409, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0100,0x0110,0x0111,0x0112,0x0120,0x0121,0x0130,0x0131,0x0132,0x0140,0x0160,0x0170,0x0200,0x0300,0x0400,0x0402,0x0403,0x0500,
		0x0510,0x0525,0x0530,0x0535,0x0540,0x0550,0x0555,0x0560,0x0565,0x0566,0x0567,0x0568,0x0569,0x0570,0x0571,0x0572,0x0573,0x0574,0x0575,0x0576,
		0x0577,0x0578,0x0579,0x057a,0x057b,0x057c,0x057d,0x057e,0x057f,0x0580,0x0581,0x0582,0x0583,0x0584,0x0585,0x0586,0x0587,0x0588,0x0589,0x058a,
		0x058b,0x058c,0x058d,0x058e,0x058f,0x0590,0x0591,0x0592,0x0593,0x0594,0x0595,0x0596,0x0597,0x0598,0x0599,0x059a,0x059b,0x059c,0x059d,0x059e,
		0x059f,0x05a0,0x05a1,0x05a2,0x05a3,0x05a4,0x05a5,0x05a6,0x05a7,0x05a8,0x05a9,0x05aa,0x05ab,0x05ac,0x05ad,0x05ae,0x05af,0x05b0,0x05b1,0x05b2,
		0x05b3,0x05b4,0x05b5,0x05b6,0x05b7,0x05b8,0x05b9,0x05ba,0x05bb,0x05bc,0x05bd,0x05be,0x05bf,0x05c0,0x05c1,0x05c2,0x05c3,0x05c4,0x05c5,0x05c8,
		0x05d3,0x05d4,0x1001,0x4000,0x4021,0x4022,0x402b,0x402e,0x4034,0x4056,0x4109,0x410d,0x5010,0x5012,0x6001,0x6002,0x6003,0x6004,0x6005};
		char* mids[] = {"DVC-323","DVC-325","DC-220","DC-260","DC-265",
		"DC-290","DC-240","DC-240 (PTP firmware)","DC-280","DC-5000",
		"DC-3400","DC-4800","DC4800","DX3900","Digital Camera",
		"EZ-200","MC3","Digital Camera","Z7590","DX3500",
		"DX3600","DX3215","DX3700","EasyShare CX4230 Camera","LS420",
		"DX4900","DX4330","CX4200","CX4210","CX4300",
		"LS753","LS443","LS663","DX6340","CX6330",
		"DX6440","CX6230","CX6200","DX6490","DX4530",
		"DX7630","CX7300/CX7310","CX7220","CX7330","CX7430",
		"CX7530","DX7440","C300","DX7590","Z730",
		"Digital Camera","Digital Camera","Digital Camera","CX6445","Digital Camera",
		"CX7525","Digital Camera","Digital Camera","EasyShare C360","C310",
		"Digital Camera","C330","C340","V530","V550",
		"Digital Camera","Digital Camera","Digital Camera","Digital Camera","Digital Camera",
		"Digital Camera","Digital Camera","Digital Camera","EASYSHARE M1033 digital camera","Digital Camera",
		"Digital Camera","Digital Camera","Digital Camera","Digital Camera","Digital Camera",
		"Digital Camera","Digital Camera","Digital Camera","Digital Camera","Digital Camera",
		"Digital Camera","Digital Camera","Digital Camera","Digital Camera","Digital Camera",
		"Digital Camera","Digital Camera","Digital Camera","Digital Camera","Digital Camera",
		"Digital Camera","Digital Camera","Digital Camera","Digital Camera","Digital Camera",
		"EasyShare Z710 Camera","Digital Camera","Digital Camera","Digital Camera","Digital Camera",
		"Digital Camera","Digital Camera","Digital Camera","Digital Camera","Digital Camera",
		"Digital Camera","Digital Camera","Digital Camera","Digital Camera","Digital Camera",
		"Digital Camera","Digital Camera","Digital Camera","Digital Camera","EASYSHARE Z1485 IS Digital Camera",
		"EasyShare M320 Camera","EasyShare C180 Digital Camera","EasyShare SV811 Digital Picture Frame","InkJet Color Printer","Photo Printer 6800",
		"1400 Digital Photo Printer","Photo Printer 6850","605 Photo Printer","805 Photo Printer","ESP 7200 Series AiO",
		"EasyShare Printer Dock Series 3","EasyShare G600 Printer Dock","Wireless Adapter","DBT-220 Bluetooth Adapter","i30",
		"i40","i50","i60","i80"};
		InsertProducts(0x040a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0a68,0x6510,0x6520,0x6533,0x6543};
		char* mids[] = {"Func MS-3 gaming mouse [WT6573F MCU]","Weltrend Bar Code Reader","XBOX Xploder","Speed-Link Competition Pro","Manhattan Magnetic Card Strip Reader"
		};
		InsertProducts(0x040b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3184,0x6205};
		char* mids[] = {"VNT VT6656 USB-802.11 Wireless LAN Adapter","USB 2.0 Card Reader"};
		InsertProducts(0x040d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0005,0x0006,0x0009,0x000b,0x000d,0x0012,0x0013,0x0016,0x0018,0x001c,0x0027,0x002a,0x003d,0x0044,0x004b,0x004d,0x0050,0x005e,0x0065,
		0x0066,0x0067,0x006e,0x0089,0x008b,0x0091,0x0092,0x0097,0x00a9,0x00aa,0x00b3,0x00bc,0x00ca,0x00cb,0x00d8,0x00d9,0x00da,0x00db,0x00e8,0x0105,
		0x012e,0x0148,0x0150,0x0157,0x0158,0x015d,0x016f,0x017f,0x019e,0x01a1,0x01a2,0x01dc,0x01de,0x01ee,0x01f1,0x01fd};
		char* mids[] = {"LUA-TX Ethernet [pegasus]","LUA-TX Ethernet","WLI-USB-L11 Wireless LAN Adapter","LUA2-TX Ethernet","WLI-USB-L11G-WR Wireless LAN Adapter",
		"WLI-USB-L11G Wireless LAN Adapter","LUA-KTX Ethernet","USB2-IDE Adapter","WLI-USB-S11 802.11b Adapter","USB2-IDE Adapter",
		"USB-IDE Bridge: DUB-PxxG","WLI-USB-KS11G 802.11b Adapter","SMSC USB97C202 \"HD-HB300V2-EU\"","LUA-U2-KTX Ethernet","WLI-USB-KB11 Wireless LAN Adapter",
		"WLI-USB-G54 802.11g Adapter [Broadcom 4320 USB]","WLI-USB-B11 Wireless LAN Adapter","WLI2-USB2-G54 Wireless LAN Adapter","WLI-U2-KG54-YB WLAN","Python2 WDM Encoder",
		"WLI-U2-KG54 WLAN","WLI-U2-KG54-AI WLAN","LUA-U2-GT 10/100/1000 Ethernet Adapter","RUF-C/U2 Flash Drive","Nintendo Wi-Fi",
		"WLI-U2-KAMG54 Wireless LAN Adapter","WLI-U2-KAMG54 Bootloader","WLI-U2-KG54-BB","WLI-U2-AMG54HP Wireless LAN Adapter","WLI-U2-AMG54HP Bootloader",
		"PC-OP-RS1 RemoteStation","WLI-U2-KG125S 802.11g Adapter [Broadcom 4320 USB]","802.11n Network Adapter","WLI-U2-G300N 802.11n Adapter","WLI-U2-SG54HP",
		"WLI-U2-G54HP","WLI-U2-KG54L 802.11bg [ZyDAS ZD1211B]","External Hard Drive HD-PF32OU2 [Buffalo Ministation]","WLI-UC-G300N Wireless LAN Adapter [Ralink RT2870]","External Hard Drive HD-CEU2 [Drive Station]",
		"WLI-UC-AG300N Wireless LAN Adapter","WLI-UC-G300HP Wireless LAN Adapter","WLP-UC-AG300 Wireless LAN Adapter","External Hard Drive HD-PEU2","WLI-UC-GNHP Wireless LAN Adapter",
		"WLI-UC-GN Wireless LAN Adapter [Ralink RT3070]","WLI-UC-G301N Wireless LAN Adapter [Ralink RT3072]","Sony UWA-BR100 802.11abgn Wireless Adapter [Atheros AR7010+AR9280]","WLI-UC-GNP Wireless LAN Adapter","MiniStation Metro",
		"WLI-UC-GNM Wireless LAN Adapter [Ralink RT8070]","Ultra-Slim Portable DVD Writer (DVSM-PC58U2V)","External Hard Drive HD-PCTU3 [Buffalo MiniStation]","WLI-UC-GNM2 Wireless LAN Adapter [Ralink RT3070]","SATA Adapter [HD-LBU3]",
		"WLI-UC-G450 Wireless LAN Adapter"};
		InsertProducts(0x0411, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1310,0x1311,0x1312,0x1313,0x1314,0x1315,0x1316,0x1317,0x1318,0x1319,0x131a,0x131b,0x131c,0x131d,0x131e,0x1320,0x1321,0x1322,0x1323,0x1324,
		0x1325,0x1326,0x1327,0x1328,0x1329,0x132a,0x132b,0x132c,0x132d,0x132e,0x6023,0x6024,0x6025,0x6026,0x6029,0x6125,0x6126,0x6a03,0x6f00};
		char* mids[] = {"WinFast TV - NTSC + FM","WinFast TV - NTSC + MTS + FM","WinFast TV - PAL BG + FM","WinFast TV - PAL BG+TXT + FM","WinFast TV Audio - PHP PAL I",
		"WinFast TV Audio - PHP PAL I+TXT","WinFast TV Audio - PHP PAL DK","WinFast TV Audio - PHP PAL DK+TXT","WinFast TV - PAL I/DK + FM","WinFast TV - PAL N + FM",
		"WinFast TV Audio - PHP SECAM LL","WinFast TV Audio - PHP SECAM LL+TXT","WinFast TV Audio - PHP SECAM DK","WinFast TV - SECAM DK + TXT + FM","WinFast TV - NTSC Japan + FM",
		"WinFast TV - NTSC","WinFast TV - NTSC + MTS","WinFast TV - PAL BG","WinFast TV - PAL BG+TXT","WinFast TV Audio - PHP PAL I",
		"WinFast TV Audio - PHP PAL I+TXT","WinFast TV Audio - PHP PAL DK","WinFast TV Audio - PHP PAL DK+TXT","WinFast TV - PAL I/DK","WinFast TV - PAL N",
		"WinFast TV Audio - PHP SECAM LL","WinFast TV Audio - PHP SECAM LL+TXT","WinFast TV Audio - PHP SECAM DK","WinFast TV - SECAM DK + TXT","WinFast TV - NTSC Japan",
		"EMP Audio Device","WinFast PalmTop/Novo TV Video","WinFast DTV Dongle (cold state)","WinFast DTV Dongle (warm state)","WinFast DTV Dongle Gold",
		"WinFast DTV Dongle","WinFast DTV Dongle BDA Driver","RTL2832 [WinFast DTV Dongle Mini]","WinFast DTV Dongle (STK7700P based)"};
		InsertProducts(0x0413, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0035,0x0101,0x0961,0x3810,0x3811,0x3812,0x3813,0x5011,0x5518,0x551a,0x551b,0x551c,0x551d,0x551e,0x551f,0x5521,0x6481,0x7721,0x7722,0x7723
		};
		char* mids[] = {"W89C35 802.11bg WLAN Adapter","Hub","AVL Flash Card Reader","Smart Card Controller","Generic Controller - Single interface",
		"Smart Card Controller_2Interface","Panel Display","Virtual Com Port","4-Port Hub","PC Sync Keypad",
		"PC Async Keypad","Sync Tenkey","Async Tenkey","Keyboard","Keyboard w/ Sys and Media",
		"Keyboard","16-bit Scanner","Memory Stick Reader/Writer","Memory Stick Reader/Writer","SD Card Reader"
		};
		InsertProducts(0x0416, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0600,0x3001,0x3003,0x3201,0x3404,0x3406,0x3407,0x3601,0x3602,0x4602,0x8001,0x8002,0xaa03};
		char* mids[] = {"IrDA Remote Controller / Creative Cordless Mouse","Desktop Wireless 6000","Xerox P1202 Laser Printer","Olivetti PG L12L","Docuprint P8ex",
		"SCX-5x12 series","MFP 830 series","ML-912","InkJet Color Printer","InkJet Color Printer",
		"Remote NDIS Network Device","Hub","SyncMaster HID Monitor Control","SDAS-3 MP3 Player"};
		InsertProducts(0x0419, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1002,0x1003,0x1050,0x1053,0x200c,0x2020,0x2029,0x2801,0x3000,0x3002,0x3010,0x3014,0x3015,0x3020,0x3030,0x3040,0x3060,0x3061,0x3090,0x30d3,
		0x3121,0x3220,0x3f00,0x3f02,0x3f04,0x3f07,0x4003,0x4004,0x4005,0x4007,0x400a,0x400b,0x400c,0x400d,0x400f,0x4011,0x4012,0x4013,0x4015,0x4016,
		0x4017,0x4018,0x4019,0x401a,0x401c,0x401d,0x401e,0x401f,0x4020,0x4021,0x4022,0x4028,0x4029,0x402f,0x4034,0x4035,0x4036,0x4037,0x4038,0x4039,
		0x403a,0x403b,0x403c,0x403d,0x403e,0x4041,0x4043,0x4045,0x4049,0x4051,0x4052,0x4053,0x4054,0x4055,0x4056,0x4057,0x4058,0x405f,0x4061,0x4063,
		0x4068,0x406c,0x4083,0x4087,0x4088,0x4100,0x4101,0x4102,0x4106,0x4107,0x4108,0x4109,0x410b,0x410c,0x410f,0x4110,0x4111,0x4116,0x4117,0x411b,
		0x411c,0x411d,0x411e,0x4120,0x4123,0x4124,0x4126,0x4127,0x4128,0x412b,0x412f,0x4130,0x4131,0x4133,0x4134,0x4136,0x4137,0x4139,0x413c,0x4150,
		0x4151,0x4152,0x4153,0x4154,0x4155,0x4157,0x500f,0x5015,0xffff};
		char* mids[] = {"Nomad II","Blaster GamePad Cobra","GamePad Cobra","Mouse Gamer HD7600L","MuVo V100",
		"Zen X-Fi 2","ZiiO","Prodikeys PC-MIDI multifunction keyboard","SoundBlaster Extigy","SB External Composite Device",
		"SoundBlaster MP3+","SB External Composite Device","Sound Blaster Digital Music LX","SoundBlaster Audigy 2 NX","SB External Composite Device",
		"SoundBlaster Live! 24-bit External SB0490","Sound Blaster Audigy 2 ZS External","SoundBlaster Audigy 2 ZS Video Editor","Sound Blaster Digital Music SX","Sound Blaster Play!",
		"WoW tap chat","Sound Blaster Tactic(3D) Sigma sound card","E-Mu Xboard 25 MIDI Controller","E-Mu 0202","E-Mu 0404",
		"E-Mu Xmidi 1x1","VideoBlaster Webcam Go Plus [W9967CF]","Nomad II MG","Webcam Blaster Go ES","Go Mini",
		"PC-Cam 300","PC-Cam 600","Webcam 5 [pwc]","Webcam PD1001","PC-CAM 550 (Composite)",
		"Webcam PRO eX","PC-CAM350","PC-Cam 750","CardCam Value","CardCam",
		"Webcam Mobile [PD1090]","Webcam Vista [PD1100]","Audio Device","Webcam Vista [PD1100]","Webcam NX [PD1110]",
		"Webcam NX Ultra","Webcam NX Pro","Webcam Notebook [PD1171]","Webcam NX","Webcam NX Ultra",
		"Webcam NX Pro","Vista Plus cam [VF0090]","Webcam Live!","DC-CAM 3000Z","Webcam Instant",
		"Webcam Instant","Webcam Live!/Live! Pro","Webcam Live!","ORITE CCD Webcam [PC370R]","Webcam Live! Effects",
		"Webcam NX Pro 2","Creative Webcam Vista [VF0010]","Webcam Live! Ultra","Webcam Notebook Ultra","Webcam Vista Plus",
		"Webcam Live! Motion","Vibra Plus Webcam","Live! Cam Voice","Live! Cam Voice","Live! Cam Notebook Pro [VF0250]",
		"Live! Cam Vista IM","Live! Cam Video IM","Live! Cam Video IM","Live! Cam Video IM Pro","Live! Cam Video IM Pro",
		"Live! Cam Optia","Live! Cam Optia AF","WebCam Vista (VF0330)","Live! Cam Notebook Pro [VF0400]","Live! Cam Video IM Pro",
		"Live! Cam Notebook [VF0470]","Live! Cam Sync [VF0520]","Live! Cam Socialize [VF0640]","Live! Cam Socialize HD 1080 [VF0680]","Live! Cam Chat HD [VF0700]",
		"Nomad Jukebox 2","Nomad Jukebox 3","NOMAD MuVo^2","Nomad MuVo","NOMAD MuVo",
		"Nomad Jukebox Zen","Nomad Jukebox Zen NX","Nomad Jukebox Zen USB 2.0","Nomad MuVo NX","NOMAD MuVo^2 (Flash)",
		"Nomad Jukebox Zen Xtra","Dell Digital Jukebox","MuVo^2","Nomad MuVo TX","Zen Touch",
		"Nomad MuVo USB 2.0","Zen","Zen Micro","Nomad MuVo TX FM","Zen Portable Media Center",
		"MuVo^2 FM (uHDD)","Dell DJ (2nd gen)","Dell DJ","NOMAD Jukebox Zen Xtra (mtp)","MuVo N200 with FM radio",
		"Dell Digital Jukebox 2.Gen","Zen Micro (mtp)","DAP-HD0014 [Zen Touch] (MTP)","Mass Storage Device","Zen Neeon",
		"Zen Sleek","Zen Sleek (mtp)","Zen Nano Plus","Zen MicroPhoto","Zen V (MTP)",
		"Zen Vision:M (mtp)","Zen V Plus","Zen Vision W","Zen Stone","Zen Stone plus",
		"Zen (MTP)","Broadband Blaster 8012U-V","TECOM Bluetooth Device","Webcam Live! Ultra"};
		InsertProducts(0x041e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1307};
		char* mids[] = {"Celly SIM Card Reader"};
		InsertProducts(0x0420, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0018,0x0019,0x001a,0x0024,0x0025,0x0028,0x002d,0x002e,0x002f,0x0042,0x0064,0x006b,0x006c,0x006d,0x006e,0x006f,0x0070,0x0096,0x00aa,
		0x00ab,0x00e4,0x0103,0x0104,0x0105,0x0106,0x0154,0x0155,0x0156,0x0157,0x0199,0x019a,0x019b,0x01b0,0x01b1,0x01b2,0x01c7,0x01c8,0x0228,0x023a,
		0x026a,0x026b,0x026c,0x026d,0x0295,0x0297,0x02e1,0x02e2,0x02e3,0x02e4,0x0360,0x03a4,0x03c0,0x03d1,0x0400,0x0401,0x0402,0x0404,0x0405,0x0407,
		0x040b,0x040d,0x040e,0x040f,0x0410,0x0411,0x0413,0x0414,0x0415,0x0416,0x0417,0x0418,0x0419,0x041a,0x041b,0x041c,0x041d,0x041e,0x041f,0x0421,
		0x0422,0x0423,0x0428,0x0429,0x0431,0x0432,0x0435,0x0436,0x0437,0x043a,0x043b,0x043c,0x043d,0x0443,0x0444,0x044c,0x044d,0x044e,0x044f,0x0453,
		0x0456,0x0457,0x045a,0x045d,0x046e,0x0471,0x0485,0x04b9,0x04bc,0x04bd,0x04be,0x04c3,0x04ce,0x04cf,0x04f0,0x04f9,0x0508,0x0509,0x0518,0x0600,
		0x0610,0x0661,0x0800,0x0801,0x0802};
		char* mids[] = {"E61i (PC Suite mode)","6288 GSM Smartphone","6288 GSM Smartphone (imaging mode)","6288 GSM Smartphone (file transfer mode)","5610 XpressMusic (Storage mode)",
		"5610 XpressMusic (PC Suite mode)","5610 XpressMusic (Imaging mode)","6120 Phone (Mass storage mode)","6120 Phone (Media-Player mode)","6120 Phone (PC-Suite mode)",
		"E51 (PC Suite mode)","3109c GSM Phone","5310 Xpress Music (PC Suite mode)","5310 Xpress music (Storage mode)","N95 (Storage mode)",
		"N95 (Multimedia mode)","N95 (Printing mode)","N95 (PC Suite mode)","N810 Internet Tablet","E71 (Mass storage mode)",
		"E71 (PC Suite mode)","E71 (Media transfer mode)","ADL Flashing Engine AVALON Parent","ADL Re-Flashing Engine Parent","Nokia Firmware Upgrade Mode",
		"ROM Parent","5800 XpressMusic (PC Suite mode)","5800 XpressMusic (Multimedia mode)","5800 XpressMusic (Storage mode)","5800 XpressMusic (Imaging mode)",
		"6700 Classic (msc)","6700 Classic (PC Suite)","6700 Classic (mtp)","6303 classic Phone (PC Suite mode)","6303 classic Phone (Mass storage mode)",
		"6303 classic Phone (Printing and media mode)","N900 (Storage Mode)","N900 (PC-Suite Mode)","5530 XpressMusic","6730 Classic",
		"N97 (mass storage)","N97 (Multimedia)","N97 (PC Suite)","N97 (Pictures)","660i/6600i Slide Phone (Mass Storage)",
		"660i/6600i Slide Phone (Still Image)","5230 (Storage mode)","5230 (Multimedia mode)","5230 (PC-Suite mode)","5230 (Imaging mode)",
		"C1-01 Ovi Suite Mode","C5 (Storage mode)","C7-00","N950","7600 Phone Parent",
		"6650 GSM Phone","6255 Phone Parent","5510","9500 GSM Communicator","Music Player HDR-1(tm)",
		"N-Gage GSM Phone","6620 Phone Parent","6651 Phone Parent","6230 GSM Phone","6630 Imaging Smartphone",
		"7610 Phone Parent","6260 Phone Parent","7370","9300 GSM Smartphone","6170 Phone Parent",
		"7270 Phone Parent","E70 (PC Suite mode)","E60 (PC Suite mode)","9500 GSM Communicator (RNDIS)","9300 GSM Smartphone (RNDIS)",
		"7710 Phone Parent","6670 Phone Parent","6680","6235 Phone Parent","3230 Phone Parent",
		"6681 Phone Parent","6682 Phone Parent","6230i Modem","6230i MultiMedia Card","770 Internet Tablet",
		"N90 Phone Parent","E70 (IP Passthrough/RNDIS mode)","E60 (IP Passthrough/RNDIS mode)","6265 Phone Parent","N70 USB Phone Parent",
		"3155 Phone Parent","6155 Phone Parent","6270 Phone Parent","N70 Phone Parent","N91",
		"NM850iG Phone Parent","E61 (PC Suite mode)","E61 (Data Exchange mode)","E61 (IP Passthrough/RNDIS mode)","9300 Phone Parent",
		"6111 Phone Parent","6111 Phone (Printing mode)","6280 Phone Parent","6282 Phone Parent","6110 Navigator",
		"6110 Navigator","MTP Device","5300","5200 (Nokia mode)","5200 (Storage mode)",
		"5200 (MTP mode)","N800 Internet Tablet","E90 Communicator (PC Suite mode)","E90 Communicator (Storage mode)","Nokia N95 (PC Suite mode)",
		"6300 (PC Suite mode)","E65 (PC Suite mode)","E65 (Storage mode)","N9 Phone","Digital Pen SU-1B",
		"CS-15 (Internet Stick 3G modem)","Lumia 920","Connectivity Cable DKU-5","Data Cable DKU-6","CA-42 Phone Parent"
		};
		InsertProducts(0x0421, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000a,0x000c,0x000d,0x0100,0x0101,0x0200,0x020a,0x0300,0x0301,0x030a,0x1237};
		char* mids[] = {"NetMate Ethernet","NetMate2 Ethernet","USB Chief Analyzer","Generic Universal Protocol Analyzer","UPA USBTracer",
		"Generic 10K Universal Protocol Analyzer","PETracer ML","Generic Universal Protocol Analyzer","2500H Tracer Trainer","PETracer x1",
		"Andromeda Hub"};
		InsertProducts(0x0423, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0acd,0x0fdc,0x10cd,0x2020,0x20cd,0x20fc,0x2228,0x223a,0x2503,0x2504,0x2507,0x2512,0x2513,0x2514,0x2517,0x2524,0x2602,0x2640,0x4060,
		0x4064,0x7500,0x9512,0x9514,0xa700,0xec00};
		char* mids[] = {"Integrated Hub","Sitecom Internal Multi Memory reader/writer MD-005","Floppy","Sitecom Internal Multi Memory reader/writer MD-005","USB Hub",
		"Sitecom Internal Multi Memory reader/writer MD-005","6-in-1 Card Reader","9-in-2 Card Reader","8-in-1 Card Reader","USB 2.0 Hub",
		"USB 2.0 Hub","hub","USB 2.0 Hub","2.0 Hub","USB 2.0 Hub",
		"Hub","USB MultiSwitch Hub","USB 2.0 Hub","USB 2.0 Hub","Ultra Fast Media Reader",
		"Ultra Fast Media Reader","LAN7500 Ethernet 10/100/1000 Adapter","SMC9512/9514 USB Hub","SMC9514 Hub","2 Port Hub",
		"SMSC9512/9514 Fast Ethernet Adapter"};
		InsertProducts(0x0424, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0xf102};
		char* mids[] = {"G-Tech Wireless Mouse & Keyboard","G-Tech U+P Wireless Mouse"};
		InsertProducts(0x0425, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0426};
		char* mids[] = {"WDM Driver"};
		InsertProducts(0x0426, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4001};
		char* mids[] = {"GamePad Pro"};
		InsertProducts(0x0428, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x9316};
		char* mids[] = {"8x931Hx Customer Hub"};
		InsertProducts(0x042b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0380};
		char* mids[] = {"MP3 Player"};
		InsertProducts(0x042e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0005,0x000a,0x000b,0x0082,0x0083,0x00a2,0x0100,0x100e,0x36ba,0xa101,0xa102,0xa103,0xa4a2,0xcdab};
		char* mids[] = {"109 Keyboard","Type 6 Keyboard","109 Japanese Keyboard","109 Japanese Keyboard","109 Japanese Keyboard",
		"109 Japanese Keyboard","Type 7 Keyboard","3-button Mouse","24.1\" LCD Monitor v4 / FID-638 Mouse","Bus Powered Hub",
		"remote key/mouse for P3 chip","remote key/mouse/storage for P3 chip","remote storage for P3 chip","Ethernet (RNDIS and CDC ethernet)","Raritan KVM dongle"
		};
		InsertProducts(0x0430, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100};
		char* mids[] = {"Mouse-Trak 3-button Track Ball"};
		InsertProducts(0x0431, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1101,0xabab};
		char* mids[] = {"IBM Game Controller","Keyboard"};
		InsertProducts(0x0433, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005};
		char* mids[] = {"CameraMate (DPCM_USB)"};
		InsertProducts(0x0436, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0009,0x000a,0x000b,0x000c,0x000d,0x000e,0x000f,0x0010,0x0011,0x0012,0x0013,0x0014,
		0x0015,0x0016,0x0017,0x0018,0x0019,0x001a,0x001b,0x001c,0x001d,0x001e,0x001f,0x0020,0x0021,0x0022,0x0023,0x0024,0x0025,0x0026,0x0027,0x0028,
		0x0029,0x002a,0x002b,0x002c,0x002d,0x002e,0x002f,0x0030,0x0031,0x0032,0x0033,0x0034,0x0035,0x0036,0x0037,0x0038,0x0039,0x003a,0x003b,0x003c,
		0x003d,0x003e,0x003f,0x0040,0x0041,0x0042,0x0043,0x0044,0x0045,0x0046,0x0047,0x0048,0x0049,0x004a,0x004b,0x004c,0x004d,0x004e,0x004f,0x0050,
		0x0051,0x0052,0x0053,0x0054,0x0057,0x0058,0x005a,0x005c,0x0060,0x0061,0x0065,0x0069,0x006d,0x006e,0x0072,0x0073,0x0078,0x0079,0x007a,0x007b,
		0x007c,0x007d,0x008a,0x008b,0x008c,0x008e,0x008f,0x0093,0x0095,0x0096,0x0097,0x0098,0x009e,0x009f,0x00a9,0x00ab,0x00b2,0x00b8,0x00b9,0x00ba,
		0x00bb,0x00bd,0x00be,0x00bf,0x00c0,0x00c1,0x00c7,0x00c8,0x00c9,0x00cb,0x00cc,0x00d0,0x00d3,0x00d4,0x00d5,0x00d6,0x00e8,0x00e9,0x00f6,0x00f7,
		0x00ff,0x010b,0x010d,0x010f,0x0142,0x01fa,0x4303};
		char* mids[] = {"Laser Printer","Optra E310 Printer","Laser Printer","Laser Printer","Laser Printer",
		"Laser Printer","Laser Printer","Inkjet Color Printer","Optra S2450 Printer","Laser Printer",
		"Inkjet Color Printer","Optra E312 Printer","Laser Printer","Laser Printer","Laser Printer",
		"Laser Printer","Laser Printer","Inkjet Color Printer","Inkjet Color Printer","InkJet Color Printer",
		"InkJet Color Printer","Z12 Color Jetprinter","Z32 printer","Z52 Printer","Forms Printer",
		"Z65 Printer","InkJet Photo Printer","Kodak Personal Picture Maker 200 Printer","InkJet Color Printer","InkJet Photo Printer",
		"Kodak Personal Picture Maker 200 Card Reader","Z51 Printer","Z33 Printer","InkJet Color Printer","Laser Printer",
		"Laser Printer","InkJet Color Printer","InkJet Color Printer","InkJet Color Printer","InkJet Color Printer",
		"Scan Print Copy","Scan Print Copy","Scan Print Copy","Scan Print Copy","X70/X73 Scan/Print/Copy",
		"Scan Print Copy","Scan Print Copy","Scan Print Copy","Scan Print Copy","Scan Print Copy",
		"Scan Print Copy","Scan Print Copy","Scan Print Copy","Scan Print Copy","Scan Print Copy",
		"Scan Print Copy","Scan Print Copy","Scan Print Copy","Scan Print Copy","Scan Print Copy",
		"X83 Scan/Print/Copy","Scan Print Copy","Scan Print Copy","Scan Print Copy","Scan Print Copy",
		"Scan Print Copy","Scan Print Copy","Scan Print Copy","Scan Print Copy","Scan Print Copy",
		"Scan Print Copy","Scan Print Copy","Scan Print Copy","Scan Print Copy","Scan Print Copy",
		"Scan Print Copy","Laser Printer","Laser Printer","InkJet Color Printer","InkJet Color Printer",
		"Laser Printer","Laser Printer","InkJet Color Printer","InkJet Color Printer","Z35 Printer",
		"Laser Printer","X63","InkJet Color Printer","X74/X75 Scanner","X74 Hub",
		"X5130","X74/X75 Printer","X125","C510","X6170 Printer",
		"InkJet Color Printer","InkJet Color Printer","InkJet Color Printer","Generic Hub","InkJet Color Printer",
		"X1110/X1130/X1140/X1150/X1170/X1180/X1185","Photo 3150","4200 series","InkJet Color Printer","to CF/SM/SD/MS Card Reader",
		"InkJet Color Printer","X422","X5250","E220 Printer","2200 series",
		"P6250","7100 series","P910 series Human Interface Device","InkJet Color Printer","IBM Infoprint 1410 MFP",
		"InkJet Color Printer","3300 series","7300 series","8300 series","InkJet Color Printer",
		"2300 series","Printing Support","Printing Support","Printing Support","6300 series",
		"4300 series","Printing Support","Printing Support","Printing Support","Printing Support",
		"E120(n)","9300 series","X340 Scanner","X342n Scanner","Printing Support",
		"X340 Scanner","X642e","2400 series","3400 series","InkJet Color Printer",
		"InkJet Color Printer","2500 series","3500-4500 series","6500 series","X3650 (Printer, Scanner, Copier)",
		"S310 series","Xerox WorkCentre Pro 412"};
		InsertProducts(0x043d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3001,0x42bd,0x4a4d,0x7001,0x7013,0x70d7,0x70f5,0x8484,0x8585,0x8888,0x9800,0x9803,0x9804,0x9c01};
		char* mids[] = {"AN-WF100 802.11abgn Wireless Adapter [Broadcom BCM4323]","Flatron 795FT Plus Monitor","Flatron 915FT Plus Monitor","MF-PD100 Soul Digital MP3 Player","MP3 Player",
		"Mouse Scanner LSM-150 [LG Smart Scan Mouse]","External HDD","LPC-U30 Webcam II","LPC-UC35 Webcam","Electronics VCS Camera II(LPC-U20)",
		"Remote Control Receiver_iMON","eHome Infrared Receiver","DMB Receiver Control","LGE Sync"};
		InsertProducts(0x043e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1456};
		char* mids[] = {"Hub"};
		InsertProducts(0x0441, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xabba};
		char* mids[] = {"Bluetooth Device"};
		InsertProducts(0x0442, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000e,0x002e};
		char* mids[] = {"Multimedia Keyboard","Millennium Keyboard"};
		InsertProducts(0x0443, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6781,0x6782};
		char* mids[] = {"Keyboard with PS/2 Mouse Port","Keyboard"};
		InsertProducts(0x0446, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1104,0x2002,0x2014,0x3001,0x3002,0x3003,0x3004,0x3005,0x3006,0x3007,0x300c,0x300d,0x3010,0x3017,0xffff};
		char* mids[] = {"Japanese Keyboard","MD-5500 Printer","Bluetooth Device","UGTZ4 Bluetooth","Bluetooth Device",
		"Bluetooth Device","Bluetooth Adapter","Integrated Bluetooth Device","Bluetooth Adapter","Bluetooth Controller (ALPS/UGX)",
		"Bluetooth Controller (ALPS/UGPZ6)","Bluetooth Controller (ALPS/UGPZ6)","Bluetooth Adapter","BCM2046 Bluetooth Device","Compaq Bluetooth Multiport Module"
		};
		InsertProducts(0x044e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0400,0x044f,0xa003,0xa01b,0xa0a0,0xa0a1,0xa0a3,0xa201,0xb108,0xb10a,0xb203,0xb300,0xb303,0xb304,0xb307,0xb30b,0xb315,0xb323,0xb324,0xb603,
		0xb605,0xb651,0xb653,0xb654,0xb700};
		char* mids[] = {"HOTAS Cougar","GP XID","Rage 3D Game Pad","PK-GP301 Driving Wheel","Top Gun Joystick",
		"Top Gun Joystick (rev2)","Fusion Digital GamePad","PK-GP201 PlayStick","T-Flight Hotas X Flight Stick","T.16000M Joystick",
		"360 Modena Pro Wheel","Firestorm Dual Power","FireStorm Dual Analog 2","Firestorm Dual Power","vibrating Upad",
		"Wireless VibrationPad","Firestorm Dual Analog 3","Dual Trigger 3-in-1 (PC Mode)","Dual Trigger 3-in-1 (PS3 Mode)","force feedback Wheel",
		"force feedback Racing Wheel","Ferrari GT Rumble Force Wheel","RGT Force Feedback Clutch Racing Wheel","Ferrari GT Force Feedback Wheel","Tacticalboard"
		};
		InsertProducts(0x044f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1234,0x1428,0x1446,0x16a6,0x2036,0x2046,0x2077,0x2f90,0x3410,0x3f00,0x3f02,0x5409,0x6000,0x6001,0x6060,0x6070,0x625f,0x8042,0xdbc0,0xe001,
		0xe003,0xe004,0xe008,0xe012,0xf430,0xf432,0xffff};
		char* mids[] = {"Bluetooth Device","Hub","TUSB2040/2070 Hub","BM-USBD1 BlueRobin RF heart rate sensor receiver","TUSB2036 Hub",
		"TUSB2046 Hub","TUSB2077 Hub","SM-USB-DIG","TUSB3410 Microcontroller","OMAP1610",
		"SMC WSKP100 Wi-Fi Phone","Frontier Labs NEX IA+ Digital Audio Player","AU5 ADSL Modem (pre-reenum)","AU5 ADSL Modem","RNDIS/BeWAN ADSL2+",
		"RNDIS/BeWAN ADSL2+","TUSB6250 ATA Bridge","Hub","Device Bay Controller","GraphLink [SilverLink]",
		"TI-84 Plus Calculator","TI-89 Titanium Calculator","TI-84 Plus Silver Calculator","TI-Nspire Calculator","MSP-FET430UIF JTAG Tool",
		"eZ430 Development Tool","Bluetooth Device"};
		InsertProducts(0x0451, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0021,0x0050,0x0051};
		char* mids[] = {"HID Monitor Controls","Diamond Pro 900u CRT Monitor","Integrated Hub"};
		InsertProducts(0x0452, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6781,0x6783};
		char* mids[] = {"NMB Keyboard","Chicony Composite Keyboard"};
		InsertProducts(0x0453, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xf000,0xf001};
		char* mids[] = {"FT2232 JTAG ICE [gnICE]","FT2232H Hi-Speed JTAG ICE [gnICE+]"};
		InsertProducts(0x0456, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0150,0x0151,0x0162,0x0163,0x0817,0x5401};
		char* mids[] = {"Super Talent 1GB Flash Drive","Super Flash 1GB / GXT  64MB Flash Drive","SiS162 usb Wireless LAN Adapter","802.11 Wireless LAN Adapter","SiS-184-ASUS-4352.17 touch panel",
		"Wireless Adapter RO80211GS-USB"};
		InsertProducts(0x0457, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0006,0x000b,0x000c,0x000e,0x0013,0x001a,0x0036,0x0039,0x003a,0x004c,0x0056,0x0057,0x0059,0x005a,0x005b,0x005c,0x005d,
		0x0061,0x0066,0x0072,0x0083,0x0087,0x00ca,0x0100,0x0101,0x011b,0x1001,0x1002,0x1003,0x1004,0x100a,0x2001,0x2004,0x2005,0x2007,0x2008,0x2009,
		0x2011,0x2012,0x2013,0x2014,0x2015,0x2016,0x2017,0x2018,0x2019,0x201a,0x201b,0x201c,0x201d,0x201e,0x201f,0x2020,0x2021,0x3017,0x3018,0x3019,
		0x301a,0x301d,0x400f,0x4012,0x5003,0x5004,0x505e,0x6001,0x7004,0x7006,0x7007,0x7009,0x700c,0x700d,0x700f,0x7012,0x7014,0x701c,0x7020,0x7025,
		0x7029,0x702f,0x7035,0x7045,0x704c,0x704d,0x7055,0x705a,0x705c,0x7061,0x7066,0x7067,0x7068,0x706d,0x7076,0x7079,0x707f,0x7088,0x7089,0x708c
		};
		char* mids[] = {"Mouse","Genius NetMouse Pro","Genius NetScroll+","Easy Mouse+","NetMouse Wheel(P+U)",
		"TACOMA Fingerprint V1.06.01","VideoCAM Web","TACOMA Fingerprint Mouse V1.06.01","Genius WebScroll+","Pocket Mouse LE",
		"NetScroll+ Superior","NetScroll+ Mini Traveler / Genius NetScroll 120","Slimstar Pro Keyboard","Ergo 300 Mouse","Enhanced Gaming Device",
		"Enhanced Laser Device","Enhanced Device","Enhanced Device","Enhanced Laser Gaming Device","Enhanced Device",
		"Bluetooth Dongle","Genius Traveler 1000 Wireless Mouse","Navigator 335","Bluetooth Dongle","Ergo 525V Laser Mouse",
		"Pen Mouse","EasyPen Tablet","CueCat","NetScroll T220","Joystick",
		"Game Pad","Genius VideoCam","Flight2000 F-23 Joystick","Aashima Technology Trust Sight Fighter Vibration Feedback Joystick","ColorPage-Vivid Pro Scanner",
		"ColorPage-HR6 V1 Scanner","ColorPage-HR6/Vivid3","ColorPage-HR6 V2 Scanner","ColorPage-HR6 V2 Scanner","ColorPage-HR6A Scanner",
		"ColorPage-Vivid3x Scanner","Plustek Scanner","ColorPage-HR7 Scanner","ColorPage-Vivid4","ColorPage-HR7LE Scanner",
		"ColorPage-HR6X Scanner","ColorPage-Vivid3xe","ColorPage-HR7X","ColorPage-HR6X Slim","ColorPage-Vivid4xe",
		"ColorPage-Vivid4x","ColorPage-HR8","ColorPage-Vivid 1200 X","ColorPage-Slim 1200","ColorPage-Vivid 1200 XE",
		"ColorPage-Slim 1200 USB2","ColorPage-SF600","SPEED WHEEL 3 Vibration","Wireless 2.4Ghz Game Pad","10-Button USB Joystick with Vibration",
		"MaxFire G-12U Vibration","Genius MaxFire MiniPad","Genius TVGo DVB-T02Q MCE","TVGo DVB-T03 [AF9015]","G-pen 560 Tablet",
		"G-pen Tablet","Genius iSlim 330","GF3000F Ethernet Adapter","VideoCAM Express V2","Dsc 1.3 Smart Camera Device",
		"VideoCAM Web","G-Shot G312 Still Camera Device","VideoCAM Web V3","G-Shot G511 Composite Device","VideoCAM Web",
		"WebCAM USB2.0","VideoCAM Live V3","G-Shot G512 Still Camera","Sim 321C","Eye 311Q Camera",
		"Genius Look 320s (SN9C201 + HV7131R)","Genius Slim 322","i-Look 325T Camera","Genius Look 1320 V2","Genius i-Look 1321",
		"Slim 1322AF","Slim 2020AF camera","Asus USB2.0 Webcam","Genius iSlim 1300AF","Genius iLook 1321 V2",
		"Acer Crystal Eye Webcam","Genius iSlim 1300AF V2","Genius eFace 1325R","Genius iSlim 2000AF V2","Genius FaceCam 312",
		"FaceCam 2025R","TVGo DVB-T03 [RTL2832]","WideCam 1050","Genius FaceCam 320","Genius WideCam F100"
		};
		InsertProducts(0x0458, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x07da,0x0b4a,0x0b68,0x5001,0x5002,0x5003,0x5005,0x5006,0x5007,0x5008,0x5009,0x500d,0x500e,0x500f,0x5010,0x501c,0x501d,0x501e,0x501f,0x503f,
		0x5202,0x5210,0x5220,0x5221};
		char* mids[] = {"Supra Express 56K modem","SupraMax 2890 56K Modem [Lucent Atlas]","SupraMax 56K Modem","Rio 600 MP3 Player","Rio 800 MP3 Player",
		"Nike Psa/Play MP3 Player","Rio S10 MP3 Player","Rio S50 MP3 Player","Rio S35 MP3 Player","Rio 900 MP3 Player",
		"Rio S30 MP3 Player","Fuse MP3 Player","Chiba MP3 Player","Cali MP3 Player","Rio S11 MP3 Player",
		"Virgin MPF-1000","Rio Fuse","Rio Chiba","Rio Cali","Cali256 MP3 Player",
		"Rio Riot MP3 Player","Rio Karma Music Player","Rio Nitrus MP3 Player","Rio Eigen"};
		InsertProducts(0x045a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0053};
		char* mids[] = {"RX610 RX-Stick"};
		InsertProducts(0x045b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0007,0x0008,0x0009,0x000b,0x000e,0x0014,0x001a,0x001b,0x001c,0x001d,0x001e,0x0023,0x0024,0x0025,0x0026,0x0027,0x0028,0x0029,0x002b,0x002d,
		0x002f,0x0033,0x0034,0x0038,0x0039,0x003b,0x003c,0x0040,0x0047,0x0048,0x0053,0x0059,0x005c,0x005f,0x0061,0x0063,0x0065,0x006a,0x006d,0x006e,
		0x006f,0x0070,0x0071,0x0072,0x0073,0x0079,0x007a,0x007d,0x007e,0x0080,0x0083,0x0084,0x008a,0x008b,0x008c,0x0095,0x009c,0x009d,0x00a0,0x00a4,
		0x00b0,0x00b4,0x00b9,0x00bb,0x00bc,0x00bd,0x00c2,0x00c9,0x00ca,0x00cb,0x00ce,0x00d1,0x00da,0x00db,0x00dd,0x00e1,0x00f4,0x00f5,0x00f6,0x00f7,
		0x00f8,0x00f9,0x0202,0x0280,0x0283,0x0284,0x0285,0x0288,0x0289,0x028b,0x028d,0x028e,0x028f,0x0290,0x0291,0x0292,0x029c,0x029d,0x029e,0x02a0,
		0x02a1,0x02a8,0x02ad,0x02ae,0x02b0,0x02b6,0x02be,0x02bf,0x02c2,0x0400,0x0401,0x0402,0x0403,0x0404,0x0405,0x0406,0x0407,0x0408,0x0409,0x040a,
		0x040b,0x040c,0x040d,0x040e,0x040f,0x0410,0x0411,0x0412,0x0413,0x0414,0x0415,0x0416,0x0417,0x0432,0x0433,0x0434,0x0435,0x0436,0x0437,0x0438,
		0x0439,0x043a,0x043b,0x043c,0x043d,0x043e,0x043f,0x0440,0x0441,0x0442,0x0443,0x0444,0x0445,0x0446,0x0447,0x0448,0x0449,0x044a,0x044b,0x044c,
		0x044d,0x044e,0x044f,0x0450,0x0451,0x0452,0x0453,0x0454,0x0455,0x0456,0x0457,0x0458,0x0459,0x045a,0x045b,0x045c,0x045d,0x045e,0x045f,0x0460,
		0x0461,0x0462,0x0463,0x0464,0x0465,0x0466,0x0467,0x0468,0x0469,0x046a,0x046b,0x046c,0x046d,0x046e,0x046f,0x0470,0x0471,0x0472,0x0473,0x0474,
		0x0475,0x0476,0x0477,0x0478,0x0479,0x047a,0x047b,0x04c8,0x04c9,0x04ca,0x04cb,0x04cc,0x04cd,0x04ce,0x04d7,0x04d8,0x04d9,0x04da,0x04db,0x04dc,
		0x04dd,0x04de,0x04df,0x04e0,0x04e1,0x04e2,0x04e3,0x04e4,0x04e5,0x04e6,0x04e7,0x04e8,0x04e9,0x04ea,0x04ec,0x063e,0x0640,0x0641,0x0642,0x0707,
		0x0708,0x070a,0x0710,0x0713,0x0719,0x071f,0x0721,0x0723,0x0724,0x0730,0x0734,0x0736,0x0737,0x0745,0x0750,0x0752,0x075d,0x0766,0x0768,0x076c,
		0x076d,0x0772,0x0779,0x0780,0x0797,0x930a,0xffca,0xfff8,0xffff};
		char* mids[] = {"SideWinder Game Pad","SideWinder Precision Pro","IntelliMouse","Natural Keyboard Elite","SideWinderÂ® Freestyle Pro",
		"Digital Sound System 80","SideWinder Precision Racing Wheel","SideWinder Force Feedback 2 Joystick","Internet Keyboard Pro","Natural Keyboard Pro",
		"IntelliMouse Explorer","Trackball Optical","Trackball Explorer","IntelliEye Mouse","SideWinder GamePad Pro",
		"SideWinder PnP GamePad","SideWinder Dual Strike","IntelliMouse Optical","Internet Keyboard Pro","Internet Keyboard",
		"Integrated Hub","Sidewinder Strategic Commander","SideWinder Force Feedback Wheel","SideWinder Precision 2","IntelliMouse Optical",
		"SideWinder Game Voice","SideWinder Joystick","Wheel Mouse Optical","IntelliMouse Explorer 3.0","Office Keyboard 1.0A",
		"Optical Mouse","Wireless IntelliMouse Explorer","Office Keyboard (106/109)","Wireless MultiMedia Keyboard","Wireless MultiMedia Keyboard (106/109)",
		"Wireless Natural MultiMedia Keyboard","Wireless Natural MultiMedia Keyboard (106/109)","Wireless Optical Mouse (IntelliPoint)","eHome Remote Control Keyboard keys","MN-510 802.11b Wireless Adapter [Intersil ISL3873B]",
		"Smart Display Reference Device","Wireless MultiMedia Keyboard","Wireless MultiMedia Keyboard (106/109)","Wireless Natural MultiMedia Keyboard","Wireless Natural MultiMedia Keyboard (106/109)",
		"IXI Ogo CT-17 handheld device","10/100 USB NIC","Notebook Optical Mouse","Wireless Transceiver for Bluetooth","Digital Media Pro Keyboard",
		"Basic Optical Mouse","Basic Optical Mouse","Wireless Keyboard and Mouse","Dual Receiver Wireless Mouse (IntelliPoint)","Wireless Intellimouse Explorer 2.0",
		"IntelliMouse Explorer 4.0 (IntelliPoint)","Wireless Transceiver for Bluetooth 2.0","Wireless Optical Desktop 3.0","eHome Infrared Receiver","Compact Optical Mouse, model 1016",
		"Digital Media Pro Keyboard","Digital Media Keyboard 1.0A","Wireless Optical Mouse 3.0","Fingerprint Reader","Fingerprint Reader",
		"Fingerprint Reader","MN-710 802.11g Wireless Adapter [Intersil ISL3886]","MTP Device","Fingerprint Reader","Basic Optical Mouse v2.0",
		"Generic PPC Flash device","Optical Mouse with Tilt Wheel","eHome Infrared Receiver","Natural Ergonomic Keyboard 4000 V1.0","Comfort Curve Keyboard 2000 V1.0",
		"Wireless Laser Mouse 6000 Reciever","LifeCam VX-6000 (SN9C20x + OV9650)","LifeCam VX-3000","Comfort Optical Mouse 1000","LifeCam VX-1000",
		"LifeCam NX-6000","Wireless Desktop Receiver 3.1","Xbox Controller","XBox Device","Xbox Communicator",
		"Xbox DVD Playback Kit","Xbox Controller S","Xbox Controller S Hub","Xbox Controller S","Xbox360 DVD Emulator",
		"Xbox360 Memory Unit 64MB","Xbox360 Controller","Xbox360 Wireless Controller","Xbox360 Performance Pipe (PIX)","Xbox 360 Wireless Receiver for Windows",
		"Xbox360 Wireless Networking Adapter","Xbox360 HD-DVD Drive","Xbox360 HD-DVD Drive","Xbox360 HD-DVD Memory Unit","Xbox360 Big Button IR",
		"Xbox 360 Wireless Receiver for Windows","Xbox360 Wireless N Networking Adapter [Atheros AR7010+AR9280]","Xbox NUI Audio","Xbox NUI Camera","Xbox NUI Motor",
		"Xbox 360 / Bluetooth Wireless Headset","Kinect for Windows NUI Audio","Kinect for Windows NUI Camera","Kinect for Windows NUI Motor","Windows Powered Pocket PC 2002",
		"Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002",
		"Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002",
		"Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002",
		"Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002",
		"Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2002","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003",
		"Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003",
		"Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Becker Traffic Assist Highspeed 7934",
		"Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003",
		"Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003",
		"Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003",
		"Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003",
		"Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003",
		"Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003",
		"Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003",
		"Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003",
		"Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003",
		"Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003",
		"Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003",
		"Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003",
		"Windows Powered Pocket PC 2003","Windows Powered Pocket PC 2003","Windows Powered Smartphone 2002","Windows Powered Smartphone 2002","Windows Powered Smartphone 2002",
		"Windows Powered Smartphone 2002","Windows Powered Smartphone 2002","Windows Powered Smartphone 2002","Windows Powered Smartphone 2002","Windows Powered Smartphone 2003",
		"Windows Powered Smartphone 2003","Windows Powered Smartphone 2003","Windows Powered Smartphone 2003","Windows Powered Smartphone 2003","Windows Powered Smartphone 2003",
		"Windows Powered Smartphone 2003","Windows Powered Smartphone 2003","Windows Powered Smartphone 2003","Windows Powered Smartphone 2003","Windows Powered Smartphone 2003",
		"Windows Powered Smartphone 2003","Windows Powered Smartphone 2003","Windows Powered Smartphone 2003","Windows Powered Smartphone 2003","Windows Powered Smartphone 2003",
		"Windows Powered Smartphone 2003","Windows Powered Smartphone 2003","Windows Powered Smartphone 2003","Windows Powered Smartphone 2003","Windows Phone (Zune)",
		"Zune HD Media Player","KIN Phone","KIN Phone","KIN Phone","Wireless Laser Mouse 8000",
		"Transceiver v 3.0 for Bluetooth","Charon Bluetooth Dongle (DFU)","Zune Media Player","Wireless Presenter Mouse 8000","Xbox 360 Wireless Adapter",
		"Mouse/Keyboard 2.4GHz Transceiver V2.0","LifeCam NX-3000 (UVC-compliant)","LifeCam VX-7000 (UVC-compliant)","SideWinder Mouse","Digital Media Keyboard 3000",
		"Wireless Optical Desktop 700","Sidewinder X5 Mouse","Compact Optical Mouse 500","Nano Transceiver v1.0 for Bluetooth","Wired Keyboard 600",
		"Wired Keyboard 400","LifeCam Cinema","LifeCam VX-800","Sidewinder X4","Comfort Mouse 4500",
		"LifeCam HD-5000","LifeCam Studio","LifeCam HD-3000","Comfort Curve Keyboard 3000","Optical Mouse 200",
		"ISOUSB.SYS Intel 82930 Isochronous IO Test Board","Catalina","Keyboard","Windows CE Mass Storage"};
		InsertProducts(0x045e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004,0x0006,0x0008};
		char* mids[] = {"Tablet (5x3.75)","LCD Tablet (12x9)","Tablet (3x2.25)"};
		InsertProducts(0x0460, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010,0x0300,0x0301,0x0302,0x0303,0x0340,0x0341,0x0345,0x0346,0x0347,0x0360,0x0361,0x0363,0x0364,0x0365,0x0366,0x0367,0x0371,0x0374,0x0375,
		0x0377,0x0378,0x037b,0x037c,0x0380,0x0381,0x0382,0x0383,0x038a,0x038b,0x038c,0x0392,0x03a8,0x0813,0x0815,0x0819,0x081a,0x081c,0x081d,0x0a00,
		0x4d01,0x4d02,0x4d03,0x4d04,0x4d06,0x4d0f,0x4d15,0x4d17,0x4d20,0x4d2a,0x4d2b,0x4d2c,0x4d2e,0x4d51,0x4d62,0x4d75,0x4d81,0x4de7};
		char* mids[] = {"HP Keyboard","G2-300 Scanner","G2E-300 Scanner","G2-300 #2 Scanner","G2E-300 #2 Scanner",
		"Colorado 9600 Scanner","Colorado 600u Scanner","Visioneer 6200 Scanner","Memorex Maxx 6136u Scanner","Primascan Colorado 2600u/Visioneer 4400 Scanner",
		"Colorado 19200 Scanner","Colorado 1200u Scanner","VistaScan Astra 3600(ENG)","LG Electronics Scanworks 600U Scanner","VistaScan Astra 3600(ENG)",
		"6400","VistaScan Astra 3600(ENG)","Visioneer Onetouch 8920 Scanner","UMAX Astra 2500","VistaScan Astra 3600(ENG)",
		"Medion MD 5345 Scanner","VistaScan Astra 3600(ENG)","Medion MD 6190 Scanner","VistaScan Astra 3600(ENG)","G2-600 Scanner",
		"ReadyScan 636i Scanner","G2-600 #2 Scanner","G2E-600 Scanner","UMAX Astra 3000/3600","Xerox 2400 Onetouch",
		"UMAX Astra 4100","Medion/Lifetec/Tevion/Cytron MD 6190","9420M","IBM UltraPort Camera","Micro Innovations IC200 Webcam",
		"Fujifilm IX-30 Camera [webcam mode]","Fujifilm IX-30 Camera [storage mode]","Elitegroup ECS-C11 Camera","Elitegroup ECS-C11 Storage","Micro Innovations Web Cam 320",
		"Comfort Keyboard","Mouse-in-a-Box","Kensington Mouse-in-a-box","Mouse","Balless Mouse (HID)",
		"HP Optical Mouse","Dell Optical Mouse","Optical Mouse","HP Optical Mouse","PoPo Elixir Mouse (HID)",
		"Wireless Laser Mini Mouse (HID)","PoPo Mini Pointer Mouse (HID)","Optical Mobile Mouse (HID)","0Y357C PMX-MMOCZUL (B) [Dell Laser Mouse]","HP Laser Mobile Mini Mouse",
		"Rocketfish RF-FLBTAD Bluetooth Adapter","Dell N889 Optical Mouse","webcam"};
		InsertProducts(0x0461, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0xffff};
		char* mids[] = {"UPS","UPS"};
		InsertProducts(0x0463, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0003,0x0004,0x0005,0x0008,0x0010,0x0011,0x0021,0x0023,0x0027,0x002a,0x002d,0x003e,0x0041,0x0080,0x0081,0x0106};
		char* mids[] = {"Keyboard","My3000 Hub","CyBoard Keyboard","XX33 SmartCard Reader Keyboard","Wireless Keyboard and Mouse",
		"SmartBoard XX44","G83 (RS 6000) Keyboard","CyMotion Expert Combo","CyMotion Master Linux Keyboard G230","CyMotion Master Solar Keyboard",
		"Wireless Mouse & Keyboard","SmartTerminal XX44","SmartTerminal ST-2xxx","G86 6240 Keyboard","eHealth Terminal ST 1503",
		"eHealth Keyboard G87 1504","R-300 Wireless Mouse Receiver"};
		InsertProducts(0x046a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0101,0x0301,0x0500,0xff10};
		char* mids[] = {"Keyboard","PS/2 Keyboard, Mouse & Joystick Ports","USB 1.0 Hub","Serial & Parallel Ports","Virtual Keyboard and Mouse"
		};
		InsertProducts(0x046b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0082,0x0200,0x0203,0x0301,0x0401,0x0402,0x040f,0x0430,0x0801,0x0802,0x0804,0x0805,0x0807,0x0808,0x0809,0x080a,0x080f,0x0810,0x0819,0x081b,
		0x081d,0x0820,0x0821,0x0825,0x0828,0x082d,0x0830,0x0840,0x0843,0x0850,0x0870,0x0890,0x0892,0x0894,0x0895,0x0896,0x0897,0x0899,0x089d,0x08a0,
		0x08a1,0x08a2,0x08a3,0x08a6,0x08a7,0x08a9,0x08aa,0x08ac,0x08ad,0x08ae,0x08af,0x08b0,0x08b1,0x08b2,0x08b3,0x08b4,0x08b5,0x08b9,0x08bd,0x08c0,
		0x08c1,0x08c2,0x08c3,0x08c5,0x08c6,0x08c7,0x08c9,0x08ca,0x08cb,0x08cc,0x08ce,0x08cf,0x08d0,0x08d7,0x08d8,0x08d9,0x08da,0x08dd,0x08e0,0x08e1,
		0x08f0,0x08f1,0x08f2,0x08f3,0x08f4,0x08f5,0x08f6,0x0900,0x0901,0x0903,0x0905,0x0910,0x0920,0x0921,0x0922,0x0928,0x0929,0x092a,0x092b,0x092c,
		0x092d,0x092e,0x092f,0x0950,0x0960,0x0970,0x0990,0x0991,0x0992,0x0994,0x09a1,0x09a2,0x09a4,0x09a5,0x09a6,0x09b0,0x09b2,0x09c0,0x09c1,0x0a01,
		0x0a02,0x0a03,0x0a04,0x0a07,0x0a0b,0x0a0c,0x0a13,0x0a17,0x0a1f,0x0a29,0x0a38,0x0a4d,0x0b02,0x8801,0xb305,0xbfe4,0xc000,0xc001,0xc002,0xc003,
		0xc004,0xc005,0xc00b,0xc00c,0xc00d,0xc00e,0xc00f,0xc011,0xc012,0xc014,0xc015,0xc016,0xc018,0xc019,0xc01a,0xc01b,0xc01c,0xc01d,0xc01e,0xc024,
		0xc025,0xc030,0xc031,0xc032,0xc033,0xc034,0xc035,0xc036,0xc037,0xc038,0xc03d,0xc03e,0xc03f,0xc040,0xc041,0xc042,0xc043,0xc044,0xc045,0xc046,
		0xc047,0xc048,0xc049,0xc050,0xc051,0xc053,0xc054,0xc058,0xc05a,0xc05b,0xc05d,0xc05f,0xc061,0xc062,0xc063,0xc064,0xc066,0xc068,0xc069,0xc06a,
		0xc06b,0xc06c,0xc077,0xc101,0xc110,0xc111,0xc112,0xc11f,0xc121,0xc122,0xc124,0xc125,0xc126,0xc12b,0xc201,0xc202,0xc207,0xc208,0xc209,0xc20a,
		0xc20b,0xc20c,0xc20d,0xc20e,0xc211,0xc212,0xc213,0xc214,0xc215,0xc216,0xc218,0xc219,0xc21a,0xc21c,0xc21d,0xc21e,0xc21f,0xc221,0xc222,0xc223,
		0xc225,0xc226,0xc227,0xc228,0xc229,0xc22a,0xc22b,0xc22d,0xc22e,0xc245,0xc246,0xc248,0xc24a,0xc24d,0xc24e,0xc281,0xc283,0xc285,0xc286,0xc287,
		0xc291,0xc293,0xc294,0xc295,0xc298,0xc299,0xc29b,0xc29c,0xc2a0,0xc2a1,0xc301,0xc302,0xc303,0xc305,0xc307,0xc308,0xc309,0xc30a,0xc30b,0xc30c,
		0xc30d,0xc30e,0xc30f,0xc311,0xc312,0xc313,0xc315,0xc316,0xc317,0xc318,0xc31a,0xc31b,0xc31c,0xc31d,0xc401,0xc402,0xc403,0xc404,0xc408,0xc501,
		0xc502,0xc503,0xc504,0xc505,0xc506,0xc508,0xc509,0xc50a,0xc50b,0xc50c,0xc50d,0xc50e,0xc510,0xc512,0xc513,0xc514,0xc515,0xc517,0xc518,0xc51a,
		0xc51b,0xc521,0xc525,0xc526,0xc529,0xc52b,0xc52d,0xc52e,0xc52f,0xc532,0xc603,0xc605,0xc606,0xc621,0xc623,0xc625,0xc626,0xc627,0xc628,0xc629,
		0xc62b,0xc640,0xc702,0xc703,0xc704,0xc705,0xc707,0xc708,0xc709,0xc70a,0xc70b,0xc70c,0xc70d,0xc70e,0xc70f,0xc712,0xc714,0xc715,0xc71a,0xc71d,
		0xc71f,0xc720,0xca03,0xca04,0xcab1,0xd001};
		char* mids[] = {"Acer Aspire 5672 Webcam","WingMan Extreme Joystick","M2452 Keyboard","M4848 Mouse","HP PageScan",
		"NEC PageScan","Logitech/Storm PageScan","Mic (Cordless)","QuickCam Home","Webcam C200",
		"Webcam C250","Webcam C300","Webcam B500","Webcam C600","Webcam Pro 9000",
		"Portable Webcam C905","Webcam C120","QuickCam Pro","Webcam C210","Webcam C310",
		"HD Webcam C510","QuickCam VC","HD Webcam C910","Webcam C270","HD Webcam B990",
		"HD Pro Webcam C920","QuickClip","QuickCam Express","Webcam C930e","QuickCam Web",
		"QuickCam Express","QuickCam Traveler","OrbiCam","CrystalCam","QuickCam for Dell Notebooks",
		"OrbiCam","QuickCam for Dell Notebooks","QuickCam for Dell Notebooks","QuickCam E2500 series","QuickCam IM",
		"QuickCam IM with sound","Labtec Webcam Pro","QuickCam QuickCam Chat","QuickCam IM","QuickCam Image",
		"Notebook Deluxe","Labtec Notebooks","QuickCam Cool","QuickCam Communicate STX","QuickCam for Notebooks",
		"QuickCam Easy/Cool","QuickCam 3000 Pro [pwc]","QuickCam Notebook Pro","QuickCam Pro 4000","QuickCam Zoom",
		"QuickCam Zoom","QuickCam Sphere","QuickCam IM","Microphone (Pro 4000)","QuickCam Pro 3000",
		"QuickCam Fusion","QuickCam PTZ","Camera (Notebooks Pro)","QuickCam Pro 5000","QuickCam for DELL Notebooks",
		"QuickCam OEM Cisco VT Camera II","QuickCam Ultra Vision","Mic (Fusion)","Mic (Notebooks Pro)","Mic (PTZ)",
		"QuickCam Pro 5000","QuickCam UpdateMe","QuickCam Express","QuickCam Communicate STX","QuickCam for Notebook Deluxe",
		"QuickCam IM/Connect","QuickCam Messanger","QuickCam for Notebooks","QuickCam Express","Labtec Webcam",
		"QuickCam Messenger","QuickCam Express","Microphone (Messenger)","QuickCam Express","Labtec Webcam",
		"QuickCam Messenger Communicate","QuickCam Messenger Plus","ClickSmart 310","ClickSmart 510","ClickSmart 820",
		"ClickSmart 820","QuickCam Cordless","QuickCam Express","Labtec Webcam","QuickCam Live",
		"QuickCam Express","Labtec Webcam Pro","QuickCam for Notebooks","Labtec Webcam Plus","QuickCam Chat",
		"QuickCam Express / Go","QuickCam Chat","QuickCam Express Plus","Pocket Camera","ClickSmart 420",
		"Pocket750","QuickCam Pro 9000","QuickCam Pro for Notebooks","QuickCam Communicate Deluxe","QuickCam Orbit/Sphere AF",
		"QuickCam Communicate MP/S5500","QuickCam Communicate Deluxe/S7500","QuickCam E 3500","Quickcam 3000 For Business","QuickCam Vision Pro",
		"Acer OrbiCam","Fujitsu Webcam","QuickCam for Dell Notebooks Mic","QuickCam Deluxe for Notebooks","USB Headset",
		"Premium Stereo USB Headset 350","Logitech USB Microphone","V20 portable speakers (USB powered)","Z-10 Speakers","ClearChat Pro USB",
		"Clear Chat Comfort USB Headset","Z-5 Speakers","G330 Headset","G930","H600 [Wireless Headset]",
		"Headset H340","G430 Surround Sound Gaming Headset","C-UV35 [Bluetooth Mini-Receiver] (HID proxy mode)","Video Camera","BT Mini-Receiver",
		"Premium Optical Wheel Mouse","N43 [Pilot Mouse]","N48/M-BB48 [FirstMouse Plus]","M-BA47 [MouseMan Plus]","MouseMan",
		"WingMan Gaming Mouse","WingMan Gaming Wheel Mouse","MouseMan Wheel","Optical Wheel Mouse","MouseMan Wheel+",
		"M-BJ58/M-BJ69 Optical Wheel Mouse","MouseMan Traveler/Mobile","Optical MouseMan","Mouseman Dual Optical","Corded Workstation Mouse",
		"Corded Workstation Mouse","Optical Wheel Mouse","Optical Wheel Mouse","Optical Tilt Wheel Mouse","M-BQ85 Optical Wheel Mouse",
		"MX310 Optical Mouse","Optical Mouse","MX510 Optical Mouse","MX518 Optical Mouse","MX300 Optical Mouse",
		"MX500 Optical Mouse","iFeel Mouse","iFeel Mouse+","MouseMan iFeel","iFeel MouseMan+",
		"MouseMan Optical","Mouse","Mouse","Mouse","Mouse",
		"M-BT96a Pilot Optical Mouse","Premium Optical Wheel Mouse (M-BT58)","M-BT85 [UltraX Optical Mouse]","Corded Tilt-Wheel Mouse","G5 Laser Mouse",
		"G3 Laser Mouse","MX320/MX400 Laser Mouse","LX3 Optical Mouse","Optical Mouse","RX1000 Laser Mouse",
		"Laser Mouse M-UAL120","G9 Laser Mouse","G5 Laser Mouse","RX 250 Optical Mouse","G3 (MX518) Optical Mouse",
		"Laser Mouse","Bluetooth mini-receiver","M115 Mouse","M90/M100 Optical Mouse","M-U0004 810-001317 [B110 Optical USB Mouse]",
		"Optical Mouse","M115 Optical Mouse","RX1500 Laser Mouse","M-UAS144 [LS1 Laser Mouse]","DELL Laser Mouse",
		"M110 corded optical mouse (M-B0001)","G9x Laser Mouse","G500 Laser Mouse","M500 Laser Mouse","USB Optical Mouse",
		"G700 Wireless Gaming Mouse","Optical Mouse","M105 Optical Mouse","UltraX Media Remote","Harmony 785/885 Remote",
		"Harmony 525 Remote","Harmony 890 Remote","Harmony 900/1100 Remote","Harmony One Remote","Harmony 650/700 Remote",
		"Harmony 300 Remote","Harmony 200 Remote","Harmony Link","Harmony Touch Remote","WingMan Extreme Joystick with Throttle",
		"WingMan Formula","WingMan Extreme Digital 3D","WingMan Gamepad Extreme","WingMan Gamepad","WingMan RumblePad",
		"WingMan Action Pad","WingMan Precision","WingMan Attack 2","WingMan Formula GP","iTouch Cordless Reciever",
		"WingMan Extreme Digital 3D","J-UH16 (Freedom 2.4 Cordless Joystick)","ATK3 (Attack III Joystick)","Extreme 3D Pro","Dual Action Gamepad",
		"Logitech RumblePad 2 USB","Cordless RumblePad 2","Precision Gamepad","G13 Advanced Gameboard","F310 Gamepad [XInput Mode]",
		"F510 Gamepad [XInput Mode]","F710 Wireless Gamepad [XInput Mode]","G11/G15 Keyboard / Keyboard","G15 Keyboard / LCD","G11/G15 Keyboard / USB Hub",
		"G11/G15 Keyboard / G keys","G15 Refresh Keyboard","G15 Refresh Keyboard","G19 Gaming Keyboard","G19 Gaming Keyboard Macro Interface",
		"Gaming Keyboard G110","Gaming Keyboard G110 G-keys","G510 Gaming Keyboard","G510 Gaming Keyboard onboard audio","G400 Optical Mouse",
		"Gaming Mouse G300","G105 Gaming Keyboard","G600 Gaming Mouse","G710 Gaming Keyboard","G500s Laser Gaming Mouse",
		"WingMan Force","WingMan Force 3D","WingMan Strike Force 3D","Force 3D Pro","Flight System G940",
		"WingMan Formula Force","WingMan Formula Force GP","Driving Force","Momo Force Steering Wheel","Driving Force Pro",
		"G25 Racing Wheel","G27 Racing Wheel","Speed Force Wireless Wheel for Wii","Wingman Force Feedback Mouse","WingMan Force Feedback Mouse",
		"iTouch Keyboard","iTouch Pro Keyboard","iTouch Keyboard","Internet Keyboard","Internet Keyboard",
		"Internet Navigator Keyboard","Internet Keyboard","iTouch Composite","NetPlay Keyboard","Internet Keys (X)",
		"Internet Keys","UltraX Keyboard (Y-BL49)","Logicool HID-Compliant Keyboard (106 key)","Y-UF49 [Internet Pro Keyboard]","DeLuxe 250 Keyboard",
		"Internet 350 Keyboard","Classic Keyboard 200","HID-Compliant Keyboard","Wave Corded Keyboard","Illuminated Keyboard",
		"Comfort Wave 450","Compact Keyboard K300","Keyboard K120","Media Keyboard K200","TrackMan Marble Wheel",
		"Marble Mouse (2-button)","Turbo TrackMan Marble FX","TrackMan Wheel","Marble Mouse (4-button)","Cordless Mouse Receiver",
		"Cordless Mouse & iTouch Keys","Cordless Mouse+Keyboard Receiver","Cordless Mouse+Keyboard Receiver","Cordless Mouse+Keyboard Receiver","MX700 Cordless Mouse Receiver",
		"Cordless Trackball","Cordless Keyboard & Mouse","Cordless Mouse","Cordless Desktop Optical","Cordless Desktop S510",
		"Cordless Mouse","Cordless Mouse Receiver","Cordless Mouse","LX-700 Cordless Desktop Receiver","MX3000 Cordless Desktop Receiver",
		"Cordless Mouse","Cordless 2.4 GHz Presenter Presentation remote control","LX710 Cordless Desktop Laser","MX610 Laser Cordless Mouse","MX Revolution/G7 Cordless Mouse",
		"V220 Cordless Optical Mouse for Notebooks","Cordless Mouse Receiver","MX Revolution Cordless Mouse","Nano Receiver","Logitech Keyboard + Mice",
		"Unifying Receiver","R700 Remote Presenter receiver","MK260 Wireless Combo Receiver","Unifying Receiver","Unifying Receiver",
		"3Dconnexion Spacemouse Plus XT","3Dconnexion CADman","3Dconnexion Spacemouse Classic","3Dconnexion Spaceball 5000","3Dconnexion Space Traveller 3D Mouse",
		"3Dconnexion Space Pilot 3D Mouse","3Dconnexion Space Navigator 3D Mouse","3Dconnexion Space Explorer 3D Mouse","3Dconnexion Space Navigator for Notebooks","3Dconnexion SpacePilot Pro 3D Mouse",
		"3Dconnexion Space Mouse Pro","NuLOOQ navigator","Cordless Presenter","Elite Keyboard Y-RP20 + Mouse MX900 (Bluetooth)","diNovo Wireless Desktop",
		"MX900 Bluetooth Wireless Hub (C-UJ16A)","Bluetooth wireless hub","Bluetooth wireless hub","BT Mini-Receiver (HCI mode)","MX5000 Cordless Desktop",
		"BT Mini-Receiver (HID proxy mode)","BT Mini-Receiver (HID proxy mode)","Bluetooth wireless hub","MX1000 Bluetooth Laser Mouse","Bluetooth wireless hub",
		"Bluetooth wireless hub","diNovo Edge Keyboard","Bluetooth wireless hub","Bluetooth wireless hub","Bluetooth wireless hub",
		"diNovo Mini Wireless Keyboard","Bluetooth wireless hub","MOMO Racing","Formula Vibration Feedback Wheel","Cordless Keyboard for Wii HID Receiver",
		"QuickCam Pro"};
		InsertProducts(0x046d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x3001,0x3002,0x3003,0x3005,0x3008,0x5250,0x5273,0x52e6,0x5308,0x5408,0x5500,0x5720,0x6782};
		char* mids[] = {"Keyboard","Mass Storage Device","Mass Storage Device","Mass Storage Device","Mass Storage Device",
		"Mass Storage Device","KeyMaestro Multimedia Keyboard","KeyMaestro Multimedia Keyboard","Cordless Mouse","KeyMaestro Keyboard",
		"KeyMaestro Multimedia Keyboard/Hub","Portable Keyboard 86+9 keys (Model 6100C US)","Smart Card Reader","BTC 7932 mouse+keyboard"};
		InsertProducts(0x046e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0104,0x0105,0x014f,0x0160,0x0161,0x0163,0x0164,0x0165,0x0201,0x0222,0x0302,0x0303,0x0304,0x0307,0x0308,0x030b,0x030c,0x0310,0x0311,
		0x0312,0x0314,0x0316,0x0321,0x0322,0x0325,0x0326,0x0327,0x0328,0x0329,0x032d,0x032e,0x0330,0x0331,0x0332,0x0333,0x0334,0x0401,0x0402,0x0406,
		0x0407,0x0408,0x0471,0x0601,0x0602,0x0603,0x0608,0x060a,0x060c,0x060d,0x060e,0x060f,0x0613,0x0617,0x0619,0x0666,0x0700,0x0701,0x0809,0x0811,
		0x0814,0x0815,0x0844,0x084a,0x084e,0x0888,0x1103,0x1120,0x1125,0x1137,0x1201,0x1230,0x1232,0x1233,0x1236,0x1237,0x1552,0x1801,0x200a,0x200f,
		0x2021,0x2022,0x2034,0x2036,0x203f,0x2046,0x204e,0x205e,0x206c,0x2070,0x2076,0x2079,0x2088,0x209e,0x20b6,0x20d0,0x20e3,0x20e4,0x262c,0x485d,
		0xdf55};
		char* mids[] = {"DSS350 Digital Speaker System","DSS330 Digital Speaker System [uda1321]","UDA1321","GoGear SA9200","MP3 Player",
		"MP3 Player","GoGear SA1100","GoGear SA1110/02","GoGear SA1330","Hub",
		"Creative Nomad Jukebox","PCA645VC Webcam [pwc]","PCA646VC Webcam [pwc]","Askey VC010 Webcam [pwc]","PCVC675K Webcam [pwc]",
		"PCVC680K Webcam [pwc]","PC VGA Camera (Vesta Fun)","PCVC690K Webcam [pwc]","PCVC730K Webcam [pwc]","PCVC740K ToUcam Pro [pwc]",
		"PCVC750K Webcam [pwc]","DMVC 1000K","DMVC 2000K Video Capture","FunCam","DMVC1300K PC Camera",
		"SPC 200NC PC Camera","SPC 300NC PC Camera","Webcam SPC 6000 NC (Webcam w/ mic)","SPC 700NC PC Camera","SPC 900NC PC Camera / ORITE CCD Webcam(PC370R)",
		"SPC 210NC PC Camera","SPC 315NC PC Camera","SPC 710NC PC Camera","SPC 1300NC PC Camera","SPC 1000NC PC Camera",
		"SPC 620NC PC Camera","SPC 520/525NC PC Camera","Semiconductors CICT Keyboard","PS/2 Mouse on Semiconductors CICT Keyboard","15 inch Detachable Monitor",
		"10 inch Mobile Monitor","SG3WA1/74 802.11b WLAN Adapter [Atmel AT76C503A]","Digital Speaker System","OVU1020 IR Dongle (Kbd+Mouse)","ATI Remote Wonder II Input Device",
		"ATI Remote Wonder II Controller","eHome Infrared Receiver","TSU9600 Remote Control","Consumer Infrared Transceiver (HP)","Consumer Infrared Transceiver (SRM5100)",
		"RF Dongle","Consumer Infrared Transceiver","Infrared Transceiver","IEEE802.15.4 RF Dongle","TSU9400 Remote Control",
		"Hantek DDS-3005 Arbitrary Waveform Generator","Semiconductors CICT Hub","150P1 TFT Display","AVNET Bluetooth Device","JR24 CDRW",
		"DCCX38/P data cable","eHome Infrared Receiver","SA2111/02 1GB Flash Audio Player","GoGear SA3125","GoGear SA60xx (mtp)",
		"Hantek DDS-3005 Arbitrary Waveform Generator","Digital Speaker System","Creative Rhomba MP3 player","Nike psa[128max Player","HDD065 MP3 player",
		"Arima Bluetooth Device","Wireless Adapter 11g","SNU6500 Wireless Adapter","Wireless Adapter Bootloader Download","SNU5600 802.11bg",
		"TalkTalk SNU5630NS/05 802.11bg","ISP 1581 Hi-Speed USB MPEG2 Encoder Reference Kit","Diva MP3 player","Wireless Network Adapter","802.11n Wireless Adapter",
		"SDE3273FC/97 2.5\" SATA HDD Enclosure [INIC-1608L]","GoGear SA52XX","Webcam SPC530NC","Webcam SPC1030NC","TSU9200 Remote Control",
		"TSU9800 Remote Control","GoGear RaGa (SA1942/02)","TSU9300 Remote Control","MCE IR Receiver - Spinel plusf0r ASUS","GoGear Mix",
		"GoGear Aria","GoGear Opus","MCE IR Receiver with ALS- Spinel plus for ASUS","PTA01 Wireless Adapter","GoGear Vibe",
		"SPZ2000 Webcam [PixArt PAC7332]","GoGear Raga","GoGear ViBE 8GB","SPC230NC Webcam","Senselock SenseIV v2.x",
		"LPCXpresso LPC-Link"};
		InsertProducts(0x0471, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0065,0xb086,0xb091};
		char* mids[] = {"PFU-65 Keyboard [Chicony]","Asus USB2.0 Webcam","Webcam"};
		InsertProducts(0x0472, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0110,0x0217,0x022f,0x0230,0x0231,0x0401,0x0701,0x071f,0x0722};
		char* mids[] = {"Digital Voice Recorder R200","Xacti J2","C5 Digital Media Camera (mass storage mode)","C5 Digital Media Camera (PictBridge mode)","C5 Digital Media Camera (PC control mode)",
		"Optical Drive","SCP-4900 Cellphone","Usb Com Port Enumerator","W33SA Camera"};
		InsertProducts(0x0474, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0103,0x0210};
		char* mids[] = {"NEC Petiscan","Eclipse 1200U/Episode","Scorpio Ultra 3"};
		InsertProducts(0x0475, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003};
		char* mids[] = {"QuickCam","QuickClip","QuickCam Pro"};
		InsertProducts(0x0478, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004};
		char* mids[] = {"ScreenCoder UR7HCTS2-USB"};
		InsertProducts(0x047a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0011,0x00f9,0x0101,0x020b,0x050e,0x1000,0x1002};
		char* mids[] = {"Keyboard","Keyboard and Mouse","SK-1688U Keyboard","SK-1789u Keyboard","BlueTooth Keyboard and Mouse",
		"SK-3105 SmartCard Reader","Internet Compact Keyboard","Trust Office Scan USB 19200","HP ScanJet 4300c Parallel Port"};
		InsertProducts(0x047b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001,0x1002,0x1003,0x1004,0x1005,0x1006,0x1009,0x1012,0x1013,0x1014,0x1015,0x1016,0x1018,0x101d,0x101e,0x101f,0x1020,0x1021,0x1022,0x1023,
		0x1024,0x1025,0x1026,0x1027,0x1028,0x1029,0x102a,0x102b,0x102c,0x102d,0x102e,0x102f,0x1042,0x1043,0x104a,0x105d,0x105e,0x1061,0x1062,0x1063,
		0x1064,0x1065,0x1066,0x1067,0x1068,0x1069,0x106a,0x106b,0x106c,0x106d,0x106e,0x1070,0x1071,0x1072,0x1073,0x1074,0x1075,0x1076,0x1077,0x1152,
		0x2002,0x2010,0x2012,0x2021,0x2030,0x2034,0x2041,0x2048,0x4003,0x4005,0x4006,0x4007,0x4008,0x5001,0x5002,0x5003};
		char* mids[] = {"Mouse*in*a*Box","Expert Mouse Pro","Orbit TrackBall","MouseWorks","TurboBall",
		"TurboRing","Orbit TrackBall for Mac","PocketMouse","Mouse*in*a*Box Optical Pro","Expert Mouse Pro Wireless",
		"Expert Mouse","ADB/USB Orbit","Studio Mouse","Mouse*in*a*Box Optical Pro","Studio Mouse Wireless",
		"PocketMouse Pro","Expert Mouse Trackball","Expert Mouse Wireless","Orbit Optical","Pocket Mouse Pro Wireless",
		"PocketMouse","Mouse*in*a*Box Optical Elite Wireless","Pocket Mouse Pro","StudioMouse","StudioMouse Wireless",
		"Mouse*in*a*Box Optical Elite","Mouse*in*a*Box Optical","PocketMouse","Iridio","Pilot Optical",
		"Pilot Optical Pro","Pilot Optical Pro Wireless","Ci25m Notebook Optical Mouse [Diamond Eye Precision]","Ci65m Wireless Notebook Optical Mouse","PilotMouse Mini Retractable",
		"PocketMouse Bluetooth","Bluetooth EDR Dongle","PocketMouse Grip","PocketMouse Max","PocketMouse Max Wireless",
		"PocketMouse 2.0 Wireless","PocketMouse 2.0","PocketMouse Max Glow","ValueMouse","ValueOpt White",
		"ValueOpt Black","PilotMouse Laser Wireless Mini","PilotMouse Laser - 3 Button","PilotMouse Laser - Gaming","PilotMouse Laser - Wired",
		"PilotMouse Micro Laser","ValueOpt Travel","ValueOpt RF TX","PocketMouse Colour","PilotMouse Laser - 6 Button",
		"PilotMouse Laser Wireless Mini","SlimBlade Presenter Media Mouse","SlimBlade Media Mouse","SlimBlade Presenter Mouse","Bluetooth EDR Dongle",
		"Optical Elite Wireless","Wireless Presentation Remote","Wireless Presenter with Laser Pointer","PilotBoard Wireless","PilotBoard Wireless",
		"SlimBlade Media Notebook Set","SlimBlade Trackball","Orbit Trackball with Scroll Ring","Gravis Xterminator Digital Gamepad","Gravis Eliminator GamePad Pro",
		"Gravis Eliminator AfterShock","Gravis Xterminator Force","Gravis Destroyer TiltPad","Cabo I Camera","VideoCam CABO II",
		"VideoCam"};
		InsertProducts(0x047d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0300,0x1001,0x2892,0xbad1,0xf101};
		char* mids[] = {"ORiNOCO Card","USS720 Parallel Port","Systems Soft Modem","Lucent 56k Modem","Atlas Modem"
		};
		InsertProducts(0x047e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0301,0x0411,0x0ca1,0x4254,0xac01,0xad01,0xc00e};
		char* mids[] = {"Bulk Driver","Bulk Driver","Savi Office Base Station","USB DSP v4 Audio Interface","BUA-100 Bluetooth Adapter",
		"Savi 7xx","GameCom 777 5.1 Headset","Blackwire C310 headset"};
		InsertProducts(0x047f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0004,0x0011,0x0014,0x0100,0xa006,0xa007,0xa009,0xd010};
		char* mids[] = {"InTouch Module","InTouch Module","InTouch Module","InTouch Module","Stor.E Slim USB 3.0",
		"External Disk 1.5TB","External Disk USB 3.0","Stor.E Basics","External Disk 3TB"};
		InsertProducts(0x0480, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000e,0x000f,0x0100,0x0101,0x0103,0x0105,0x0106,0x0107,0x0108,0x0203,0x0204};
		char* mids[] = {"FS-1020D Printer","FS-1920 Mono Printer","Finecam S3x","Finecam S4","Finecam S5",
		"Finecam L3","Finecam","Digital Camera Device","Digital Camera Device","AH-K3001V",
		"iBurst Terminal"};
		InsertProducts(0x0482, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0137,0x0138,0x1307,0x163d,0x2015,0x2016,0x2017,0x2018,0x2302,0x3744,0x3747,0x3748,0x4810,0x481d,0x5000,0x5001,0x5710,0x5720,0x5721,0x5740,
		0x7270,0x7554,0xdf11,0xff10};
		char* mids[] = {"BeWAN ADSL USB ST (blue or green)","Unicorn II (ST70138B + MTC-20174TQ chipset)","Cytronix 6in1 Card Reader","Cool Icam Digi-MP3","TouchChipÂ® Fingerprint Reader",
		"Fingerprint Reader","Biometric Smart Card Reader","BioSimKey","Portable Flash Device (PFD)","STLINK Pseudo disk",
		"ST Micro Connect Lite","ST-LINK/V2","ISDN adapter","BT Digital Access adapter","ST Micro/Ergenic ERG BT-002 Bluetooth Adapter",
		"ST Micro Bluetooth Device","Joystick in FS Mode","STM microSD Flash Device","Hantek DDS-3X25 Arbitrary Waveform Generator","STM32F407",
		"ST Micro Serial Bridge","56k SoftModem","STM Device in DFU Mode","Swann ST56 Modem"};
		InsertProducts(0x0483, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0185};
		char* mids[] = {"EeePC T91MT HID Touch Panel"};
		InsertProducts(0x0486, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0502,0x0503,0xd00c,0xd00e,0xe000,0xe003,0xe00d,0xe00f,0xe016,0xe02c};
		char* mids[] = {"SmartMedia Card Reader Firmware Loader","SmartMedia Card Reader","Rollei Compactline (Storage Mode)","Rollei Compactline (Video Mode)","T-Com TC 300",
		"Pirelli DP-L10","Broadcom Bluetooth 2.1 Device","Foxconn T77H114 BCM2070 [Single-Chip Bluetooth 2.1 + EDR Adapter]","Ubee PXU1900 WiMAX Adapter [Beceem BCSM250]","Atheros AR5BBU12 Bluetooth Device"
		};
		InsertProducts(0x0489, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1165,0x1336,0x1345,0x9006,0x9009,0x9135,0x9503,0x9507};
		char* mids[] = {"IT1165 Flash Controller","SD/MMC Cardreader","Multi Cardreader","IT9135 BDA Afatech DVB-T HDTV Dongle","Zolid HD DVD Maker",
		"Zolid Mini DVB-T Stick","ITE it9503 feature-limited DVB-T transmission chip [ccHDtv]","ITE it9507 full featured DVB-T transmission chip [ccHDtv]"};
		InsertProducts(0x048d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003};
		char* mids[] = {"Taxan Monitor Control"};
		InsertProducts(0x0491, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0140,0x0141};
		char* mids[] = {"MP3 player","MP3 Player"};
		InsertProducts(0x0492, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xc001};
		char* mids[] = {"Camera Device"};
		InsertProducts(0x0497, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x1001,0x1002,0x1003,0x1004,0x1005,0x1006,0x1007,0x1008,0x1009,0x100a,0x100c,0x100d,0x100e,0x100f,0x1010,0x1011,0x1012,0x1013,0x1014,
		0x1015,0x1016,0x1017,0x1018,0x1019,0x101a,0x101b,0x101c,0x101d,0x101e,0x101f,0x1020,0x1021,0x1022,0x1023,0x1024,0x1025,0x1026,0x1027,0x1028,
		0x1029,0x102a,0x102b,0x102e,0x1030,0x1031,0x1032,0x1033,0x1037,0x103c,0x1054,0x2000,0x2001,0x3001,0x3003,0x4000,0x4001,0x4002,0x4004,0x5000,
		0x5001,0x5002,0x5003,0x5004,0x5005,0x5006,0x5007,0x5008,0x5009,0x500a,0x500b,0x500c,0x6001,0x7000,0x7010};
		char* mids[] = {"UX256 MIDI I/F","MU1000","MU2000","MU500","UW500",
		"MOTIF6","MOTIF7","MOTIF8","UX96 MIDI I/F","UX16 MIDI I/F",
		"EOS BX","UC-MX","UC-KX","S08","CLP-150",
		"CLP-170","P-250","TYROS","PF-500","S90",
		"MOTIF-R","MDP-5","CVP-204","CVP-206","CVP-208",
		"CVP-210","PSR-1100","PSR-2100","CLP-175","PSR-K1",
		"EZ-J24","EZ-250i","MOTIF ES 6","MOTIF ES 7","MOTIF ES 8",
		"CVP-301","CVP-303","CVP-305","CVP-307","CVP-309",
		"CVP-309GP","PSR-1500","PSR-3000","ELS-01/01C","PSR-295/293",
		"DGX-205/203","DGX-305","DGX-505","PSR-E403","MOTIF-RACK ES",
		"S90XS Keyboard/Music Synthesizer","DGP-7","DGP-5","YST-MS55D USB Speaker","YST-M45D USB Speaker",
		"NetVolante RTA54i Broadband&ISDN Router","NetVolante RTW65b Broadband Wireless Router","NetVolante RTW65i Broadband&ISDN Wireless Router","NetVolante RTA55i Broadband VoIP Router","CS1D",
		"DSP1D","DME32","DM2000","02R96","ACU16-C",
		"NHB32-C","DM1000","01V96","SPX2000","PM5D",
		"DME64N","DME24N","CRW2200UX Lightspeed 2 External CD-RW Drive","DTX","UB99"
		};
		InsertProducts(0x0499, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"Keyboard (???)"};
		InsertProducts(0x049c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0003,0x000e,0x0012,0x0018,0x0019,0x001a,0x001e,0x001f,0x0021,0x0027,0x002a,0x002b,0x002c,0x0032,0x0033,0x0036,0x0051,0x0076,0x0080,
		0x0086,0x504a,0x505a,0x8511};
		char* mids[] = {"InkJet Color Printer","iPAQ PocketPC","Internet Keyboard","InkJet Color Printer","PA-1/PA-2 MP3 Player",
		"InkJet Color Printer","S4 100 Scanner","IJ650 Inkjet Printer","WL215 Adapter","S200 Scanner",
		"Bluetooth Multiport Module by Compaq","1400P Inkjet Printer","A3000","Lexmark X125","802.11b Adapter [ipaq h5400]",
		"Wireless LAN MultiPort W100 [Intersil PRISM 2.5]","Bluetooth Multiport Module","KU-0133 Easy Access Interner Keyboard","Wireless LAN MultiPort W200","GPRS Multiport",
		"Bluetooth Device","Personal Jukebox PJB100","Linux-USB \"CDC Subset\" Device, or Itsy (experimental)","iPAQ Networking 10/100 Ethernet [pegasus2]"};
		InsertProducts(0x049f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xfff0};
		char* mids[] = {"Telex Composite Device"};
		InsertProducts(0x04a1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004,0x001e};
		char* mids[] = {"DVD-CAM DZ-MV100A Camcorder","DVDCAM USB HS Interface"};
		InsertProducts(0x04a4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x12a6,0x1a20,0x1a2a,0x2022,0x2040,0x205e,0x2060,0x207e,0x209e,0x20ae,0x20b0,0x20be,0x20c0,0x20de,0x20f8,0x20fc,0x20fe,
		0x2137,0x2202,0x2311,0x3003,0x3008,0x300a,0x300c,0x3019,0x4000,0x4013,0x4044,0x4045,0x4048,0x6001,0x6002,0x6003,0x6004,0x6005,0x6006,0x6007,
		0x6008,0x6009,0x600a,0x600b,0x600c,0x600d,0x600e,0x600f,0x6010,0x6011,0x6012,0x6013,0x6014,0x6015,0x6125,0x6180,0x6200,0x7500,0x9000,0x9001,
		0x9213};
		char* mids[] = {"Keyboard","API Ergo K/B","API Generic K/B Mouse","AcerScan C310U","Prisa 310U",
		"Prisa 620U","Prisa 320U/340U","Prisa 620UT","ScanPrisa 640BU","Prisa 620U+/640U",
		"Prisa 640BU","ScanPrisa 640BT","S2W 3000U","S2W 3300U/4300U","Prisa 640BT",
		"Prisa 1240UT","S2W 4300U+","Benq 5000","Benq 5000","SW2 5300U",
		"Benq 5150/5250","Benq 7400UT","Benq 5560","Benq Webcam","Benq 1500",
		"Benq 3410","Benq 1016","Benq DC C40","P30 Composite Device","BenQ-Siemens EF82/SL91",
		"BenQ-Siemens SF71","BenQ-Siemens E81","BenQ M7","Mass Storage Device","Mass Storage Device",
		"ATA/ATAPI Adapter","Mass Storage Device","Mass Storage Device","Mass Storage Device","Mass Storage Device",
		"Mass Storage Device","Mass Storage Device","Mass Storage Device","Mass Storage Device","Mass Storage Device",
		"Mass Storage Device","Mass Storage Device","Mass Storage Device","Mass Storage Device","Mass Storage Device",
		"Mass Storage Device","Mass Storage Device","Mass Storage Device","Mass Storage Device","MP3 Player",
		"MP3 Player","MP3 Player","Hi-Speed Mass Storage Device","AWL300 Wireless Adapter","AWL400 Wireless Adapter",
		"Kbd Hub"};
		InsertProducts(0x04a5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00b9,0x0180,0x0181};
		char* mids[] = {"Audio","Hub Type P","HID Monitor Controls"};
		InsertProducts(0x04a6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0101,0x0102,0x0211,0x0221,0x0223,0x0224,0x0225,0x0226,0x0229,0x022a,0x022c,0x0231,0x0311,0x0321,0x0331,0x0341,0x0361,0x0362,0x0371,
		0x0380,0x0382,0x0390,0x03a0,0x0410,0x0421,0x0423,0x0424,0x0425,0x0426,0x0427,0x0444,0x0445,0x0446,0x0447,0x0448,0x0449,0x044a,0x044c,0x0474,
		0x0475,0x0478,0x0479,0x047a,0x047b,0x047d,0x0480,0x048f,0x0491,0x0493,0x0494,0x0497,0x0498,0x0499,0x049b,0x04a0,0x04ac};
		char* mids[] = {"StrobePro","Strobe Pro Scanner (1.01)","StrobePro Scanner","OneTouch 7600 Scanner","OneTouch 5300 Scanner",
		"OneTouch 8200","OneTouch 4800 USB/Microtek Scanport 3000","VistaScan Astra 3600(ENG)","OneTouch 5300 USB","OneTouch 7100",
		"OneTouch 6600","OneTouch 9000/9020","6100 Scanner","6200 EPP/USB Scanner","OneTouch 8100 EPP/USB Scanner",
		"OneTouch 8600 EPP/USB Scanner","6400","VistaScan Astra 3600(ENG)","OneTouch 9320","OneTouch 8700/8920",
		"OneTouch 7700","Photo Port 7700","9650","Xerox 4800 One Touch","OneTouch Pro 8800/8820",
		"9450 USB","9750 Scanner","Strobe XP 450","Strobe XP 100","Strobe XP 200",
		"Strobe XP 100","OneTouch 7300","CardReader 100","Xerox DocuMate 510","XEROX DocuMate 520",
		"XEROX DocuMate 250","Xerox DocuMate 252","Xerox 6400","Xerox DocuMate 262","Strobe XP 300",
		"Xerox DocuMate 272","Strobe XP 220","Strobe XP 470","9450","9650",
		"9420","9520","Strobe XP 470","Strobe XP 450","9750",
		"Strobe XP 120","Patriot 430","Patriot 680","Patriot 780","Strobe XP 100",
		"7400","Xerox Travel Scanner 100"};
		InsertProducts(0x04a7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0303,0x0404};
		char* mids[] = {"Hub","Peripheral Switch","Peripheral Switch"};
		InsertProducts(0x04a8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1005,0x1035,0x1050,0x1051,0x1052,0x1053,0x1054,0x1055,0x1056,0x1057,0x105a,0x105b,0x105c,0x105d,0x105e,0x1062,0x1063,0x1064,0x1065,0x1066,
		0x1067,0x1068,0x1069,0x106a,0x106b,0x106d,0x106e,0x1070,0x1072,0x1073,0x1074,0x1076,0x1077,0x107a,0x107b,0x107c,0x107d,0x107e,0x107f,0x1082,
		0x1084,0x1085,0x1086,0x1088,0x108a,0x108b,0x108c,0x108d,0x108f,0x1090,0x1091,0x1093,0x1094,0x1095,0x1097,0x1098,0x1099,0x109c,0x109d,0x10a0,
		0x10a2,0x10a4,0x10a5,0x10a7,0x10a8,0x10a9,0x10b6,0x10c2,0x10c4,0x1404,0x1405,0x150f,0x1510,0x1512,0x1601,0x1607,0x1700,0x1701,0x1702,0x1703,
		0x1704,0x1706,0x1707,0x1708,0x1709,0x170a,0x170b,0x170c,0x170d,0x170e,0x1710,0x1712,0x1713,0x1714,0x1715,0x1716,0x1717,0x1718,0x171a,0x171b,
		0x1721,0x1723,0x1724,0x1725,0x1726,0x1727,0x1728,0x1729,0x172b,0x173b,0x173e,0x173f,0x1748,0x174d,0x1900,0x1901,0x1904,0x1905,0x1906,0x1907,
		0x1909,0x190a,0x2200,0x2201,0x2202,0x2204,0x2205,0x2206,0x2207,0x2208,0x220a,0x220b,0x220c,0x220d,0x220e,0x220f,0x2210,0x2212,0x2213,0x2214,
		0x2215,0x2216,0x2217,0x2219,0x221b,0x221c,0x221e,0x221f,0x2220,0x2224,0x2225,0x2228,0x2229,0x2602,0x2603,0x260a,0x260e,0x2610,0x2611,0x2612,
		0x2617,0x261a,0x261b,0x261c,0x261f,0x2621,0x2622,0x2623,0x2629,0x262b,0x262d,0x262f,0x2630,0x2631,0x2632,0x2635,0x2637,0x2638,0x263c,0x263d,
		0x263e,0x263f,0x2646,0x2647,0x264d,0x264e,0x264f,0x2650,0x2651,0x2655,0x2659,0x265b,0x265c,0x265d,0x265e,0x265f,0x2660,0x2663,0x2664,0x2665,
		0x2666,0x2667,0x2669,0x266a,0x266b,0x266c,0x266d,0x266e,0x266f,0x2670,0x2671,0x2672,0x2673,0x2674,0x2675,0x2676,0x2677,0x2678,0x2679,0x267a,
		0x267b,0x267d,0x2684,0x2686,0x2687,0x2688,0x268c,0x268d,0x268e,0x268f,0x2691,0x26a3,0x26b0,0x26b4,0x26b5,0x26da,0x26e6,0x2737,0x3041,0x3042,
		0x3043,0x3044,0x3045,0x3046,0x3047,0x3048,0x3049,0x304a,0x304b,0x304c,0x304d,0x304e,0x304f,0x3050,0x3051,0x3052,0x3055,0x3056,0x3057,0x3058,
		0x3059,0x305b,0x305c,0x3060,0x3061,0x3062,0x3063,0x3065,0x3066,0x3067,0x3069,0x306a,0x306b,0x306c,0x306d,0x306e,0x306f,0x3070,0x3071,0x3072,
		0x3073,0x3074,0x3075,0x3076,0x3077,0x3078,0x307a,0x307b,0x307c,0x307d,0x307f,0x3080,0x3081,0x3082,0x3083,0x3084,0x3085,0x3087,0x3088,0x308d,
		0x308e,0x3093,0x3096,0x3099,0x309a,0x309b,0x309c,0x309d,0x309f,0x30a0,0x30a1,0x30a2,0x30a8,0x30a9,0x30b1,0x30b2,0x30b3,0x30b4,0x30b5,0x30b6,
		0x30b7,0x30b8,0x30b9,0x30ba,0x30bb,0x30bd,0x30be,0x30bf,0x30c0,0x30c1,0x30c2,0x30c4,0x30ea,0x30eb,0x30ec,0x30ee,0x30ef,0x30f0,0x30f2,0x30f4,
		0x30f5,0x30f6,0x30f8,0x30f9,0x30fa,0x30fc,0x30fd,0x30fe,0x30ff,0x3100,0x310b,0x310e,0x310f,0x3110,0x3115,0x3116,0x3117,0x3119,0x311a,0x311b,
		0x311c,0x3125,0x3126,0x3127,0x3128,0x312d,0x3136,0x3137,0x3138,0x3139,0x313a,0x3141,0x3142,0x3143,0x3145,0x3146,0x3147,0x3148,0x3149,0x314b,
		0x314c,0x314d,0x314e,0x314f,0x3150,0x3155,0x315a,0x315b,0x315d,0x315e,0x315f,0x3160,0x3170,0x3171,0x3173,0x3174,0x3175,0x3176,0x3177,0x317a,
		0x3184,0x3185,0x3186,0x318d,0x318e,0x318f,0x3191,0x3192,0x3193,0x3195,0x3196,0x319a,0x31aa,0x31ab,0x31ad,0x31af,0x31b0,0x31b1,0x31bc,0x31bd,
		0x31be,0x31bf,0x31c0,0x31c1,0x31c2,0x31c3,0x31c4,0x31cf,0x31dd,0x31df,0x31e0,0x31e1,0x31e4,0x31e5,0x31e6,0x31e7,0x31ea,0x31ee,0x31ef,0x31f0,
		0x31f1,0x31f2,0x31f3,0x31f4,0x31f5,0x31f6,0x31f7,0x31f8,0x31ff,0x3209,0x320f,0x3210,0x3211,0x3212,0x3214,0x3218,0x3223,0x3224,0x3225,0x3226,
		0x3227,0x3228,0x3229,0x322a,0x322b,0x322c,0x3233,0x3234,0x3235,0x3236,0x3237,0x3238,0x323b,0x323e,0x323f,0x3240,0x3241,0x3242,0x3243,0x3244,
		0x3245,0x3247,0x3248,0x3249,0x324a,0x3255,0x3256,0x3258,0x3259,0x325a,0x325b,0x325c,0x325e,0x325f,0x3260,0x3261,0x3262,0x3264,0x3265,0x3268,
		0x3271,0x3276,0x3277,0x327d,0x3288,0x3289,0x328a};
		char* mids[] = {"BJ Printer Hub","PD Printer Storage","BJC-8200","BJC-3000 Color Printer","BJC-6100",
		"BJC-6200","BJC-6500","BJC-85","BJC-2110 Color Printer","LR1",
		"BJC-55","S600 Printer","S400","S450 Printer","S800",
		"S500 Printer","S4500","S300 Printer","S100","S630",
		"S900","S9000","S820","S200 Printer","S520 Printer",
		"S750 Printer","S820D","S530D","I850 Printer","I550 Printer",
		"S330 Printer","i70","i950","S830D","i320",
		"i470D","i9100","i450","i860","i350",
		"i250","i255","i560","i965","i455",
		"i900D","i475D","PIXMA iP2000","i80","i9900 Photo Printer",
		"PIXMA iP1500","PIXMA iP4000","PIXMA iP3000x Printer","PIXMA iP6000D","PIXMA iP5000",
		"PIXMA iP1000","PIXMA iP8500","PIXMA iP4000R","iP90","PIXMA iP1600 Printer",
		"iP4200","iP5200R","iP5200","iP6210D","iP6220D",
		"iP6600D","PIXMA iP4300 Printer","PIXMA iP1800 Printer","Pixma iP4500 Printer","W6400PG",
		"W8400PG","BIJ2350 PCL","BIJ1350 PCL","BIJ1350D PCL","DR-2080C Scanner",
		"DR-6080 Scanner","PIXMA MP110 Scanner","PIXMA MP130 Scanner","MP410 Composite","MP430 Composite",
		"MP330 Composite","PIXMA MP750 Scanner","PIXMA MP780 Scanner","PIXMA MP760 Scanner","PIXMA MP150 Scanner",
		"PIXMA MP170 Scanner","PIXMA MP450 Scanner","PIXMA MP500 Scanner","PIXMA MP800 Scanner","MP800R",
		"MP950","MP530","PIXMA MP830 Scanner","MP160","MP180 Storage",
		"MP460 Composite","MP510","MP600 Storage","MP810 Storage","MP960",
		"MP210 ser","MP470 ser","PIXMA MP520 series","MP610 ser","MP970 ser",
		"MX300 ser","MX310 ser","MX700 ser","MP140 ser","PIXMA MP270 All-In-One Printer",
		"MP560","Pixma MP640 Multifunction device","Pixma MG5150","MX360 ser","CanoScan LiDE 90",
		"CanoScan 8800F","CanoScan LiDE 100","CanoScan LiDE 200","CanoScan 5600F","CanoScan LiDE 700F",
		"CanoScan LiDE 110","CanoScan LiDE 210","CanoScan LiDE 25","CanoScan FB320U","CanoScan FB620U",
		"CanoScan FB630U","CanoScan FB1210U","CanoScan N650U/N656U","CanoScan 1220U","CanoScan D660U",
		"CanoScan D2400UF","CanoScan D646U","CanoScan D1250U2","CanoScan N670U/N676U/LiDE 20","CanoScan N1240U/LiDE 30",
		"CanoScan 8000F","CanoScan 9900F","CanoScan 5000F","CanoScan LiDE 50/LiDE 35/LiDE 40","CanoScan LiDE 80",
		"CanoScan 3000/3000F/3000ex","CanoScan 3200F","CanoScan 5200F","CanoScan 9950F","CanoScan 4200F",
		"CanoScan LiDE 60","CanoScan 8400F","CanoScan LiDE 500F","CanoScan LIDE 25","CanoScan LiDE 600F",
		"CanoScan LiDE 70","CanoScan 4400F","CanoScan 8600F","MultiPASS C555","MultiPASS C755",
		"CAPT Printer","LBP-2000","MPC600F","SmartBase MPC400","MultiPASS C855",
		"CAPT Printer","iR1600","iR1610","iC2300","MPC200 Printer",
		"iR2000","iR2010","FAX-B180C","FAXPHONE L75","LaserShot LBP-1120 Printer",
		"iR C3200","MultiPASS MP730","MultiPASS MP700","LASER CLASS 700","FAX-L2000",
		"MPC190","iR C6800","iR C3100","Smartbase MP360","MP370",
		"MP390 FAX","MP375","MF5530 Scanner Device V1.9.1","MF5550 Composite","PIXMA MP710",
		"MF5630","MF5650 (FAX)","iR 6800C EUR","iR 3100C EUR","FP-L170/MF350/L380/L398",
		"MF8100","CAPT Printer","iR C3220","MF5730","MF5750",
		"MF5770","MF3110","iR3570/iR4570","iR2270/iR2870","iR C2620",
		"iR C5800","iR85PLUS","iR105PLUS","CAPT Device","iR8070",
		"iR9070","iR 5800C EUR","CAPT Device","iR2230","iR3530",
		"iR5570/iR6570","iR C3170","iR 3170C EUR","L120","iR2830",
		"CAPT Device","iR C2570","iR 2570C EUR","CAPT Device","iR2016",
		"iR2020","MF7100 series","MF3200 series","MF6500 series","iR4530",
		"LBP3460","iR C6870","iR 6870C EUR","iR C5870","iR 5870C EUR",
		"iR7105","MF4100 series","MF4600 series","MF4010 series","MF4200 series",
		"LBP3010B printer","iR1024","MF4410","PowerShot S10","CanoScan FS4000US Film Scanner",
		"PowerShot S20","EOS D30","PowerShot S100","IXY Digital","Digital IXUS",
		"PowerShot G1","PowerShot Pro90 IS","CP-10","IXY Digital 300","PowerShot S300",
		"Digital IXUS 300","PowerShot A20","PowerShot A10","PowerShot unknown 1","PowerShot S110",
		"Digital IXUS V","PowerShot G2","PowerShot S40","PowerShot S30","PowerShot A40",
		"PowerShot A30","ZR45MC Digital Camcorder","PowerShot unknown 2","EOS D60","PowerShot A100",
		"PowerShot A200","CP-100","PowerShot S200","Digital IXUS 330","MV550i Digital Video Camera",
		"PowerShot G3","Digital unknown 3","MVX2i Digital Video Camera","PowerShot S45","PowerShot S45 PtP Mode",
		"PowerShot G3 (normal mode)","PowerShot G3 (ptp)","PowerShot S230","PowerShot S230 (ptp)","PowerShot SD100 / Digital IXUS II (ptp)",
		"PowerShot A70 (ptp)","PowerShot A60 (ptp)","IXUS 400 Camera","PowerShot A300","PowerShot S50",
		"ZR70MC Digital Camcorder","MV650i (normal mode)","MV630i Digital Video Camera","CP-200","CP-300",
		"Optura 20","MVX150i (normal mode) / Optura 20 (normal mode)","Optura 10","MVX100i / Optura 10","EOS 10D",
		"EOS 300D / EOS Digital Rebel","PowerShot G5","Elura 50 (PTP mode)","Elura 50 (normal mode)","MVX3i",
		"FV M1 (normal mode) / MVX 3i (normal mode) / Optura Xi (normal mode)","Optura 300","IXY DV M2 (normal mode) / MVX 10i (normal mode)","EOS 300D (ptp)","PowerShot A80",
		"Digital IXUS (ptp)","PowerShot S1 IS","Powershot Pro 1","Camera","Camera",
		"Camera","Camera","Elura 60E/Optura 40 (ptp)","MVX25i (normal mode) / Optura 40 (normal mode)","PowerShot S70 (normal mode) / PowerShot S70 (PTP mode)",
		"PowerShot S60 (normal mode) / PowerShot S60 (PTP mode)","PowerShot G6 (normal mode) / PowerShot G6 (PTP mode)","PowerShot S500","PowerShot A75","Digital IXUS II2  / Digital IXUS II2 (PTP mode) / PowerShot SD110 (PTP mode) / PowerShot SD110 Digital ELPH",
		"PowerShot A400 / PowerShot A400 (PTP mode)","PowerShot A310 / PowerShot A310 (PTP mode)","Powershot A85","PowerShot S410 Digital Elph","PowerShot A95",
		"CP-220","CP-330","Digital IXUS 40","Digital IXUS 30 (PTP mode) / PowerShot SD200 (PTP mode)","Digital IXUS 50 (normal mode) / IXY Digital 55 (normal mode) / PowerShot A520 (PTP mode) / PowerShot SD400 (normal mode)",
		"PowerShot A510 (normal mode) / PowerShot A510 (PTP mode)","Digital IXUS i5 (normal mode) / IXY Digital L2 (normal mode) / PowerShot SD20 (normal mode)","EOS 1D Mark II (PTP mode)","EOS 20D","EOS 20D (ptp)",
		"EOS 350D","EOS 350D (ptp)","PowerShot S2 IS (PTP mode)","Digital IXUS 700 (normal mode) / Digital IXUS 700 (PTP mode) / IXY Digital 600 (normal mode) / PowerShot SD500 (normal mode) / PowerShot SD500 (PTP mode)","PowerShot SD30 / Ixus iZoom / IXY DIGITAL L3",
		"SELPHY CP500","SELPHY CP400","Powershot A430","PowerShot A410 (PTP mode)","PowerShot S80",
		"PowerShot A620 (PTP mode)","PowerShot A610 (normal mode)/PowerShot A610 (PTP mode)","Digital IXUS 65 (PTP mode)/PowerShot SD630 (PTP mode)","Digital IXUS 55 (PTP mode)/PowerShot SD450 (PTP mode)","PowerShot TX1",
		"SELPHY CP600","Digital IXUS 50 (PTP mode)","PowerShot A420","EOS Digital Rebel XTi","PowerShot SD900 / Digital IXUS 900 Ti / IXY DIGITAL 1000",
		"Digital IXUS 750 / PowerShot SD550 (PTP mode)","PowerShot A700","PowerShot SD700 IS / Digital IXUS 800 IS / IXY Digital 800 IS","PowerShot S3 IS","PowerShot A540",
		"PowerShot SD600 DIGITAL ELPH / DIGITAL IXUS 60 / IXY DIGITAL 70","PowerShot G7","PowerShot A530","SELPHY CP710","SELPHY CP510",
		"Elura 100","PowerShot SD800 IS / Digital IXUS 850 IS / IXY DIGITAL 900 IS","PowerShot SD40 / Digital IXUS i7 IXY / DIGITAL L4","PowerShot A710 IS","PowerShot A640",
		"PowerShot A630","SELPHY ES1","SELPHY CP730","SELPHY CP720","EOS 450D",
		"EOS 40D","EOS 1Ds Mark III","PowerShot S5 IS","PowerShot A460","PowerShot SD850 IS DIGITAL ELPH / Digital IXUS 950 IS / IXY DIGITAL 810 IS",
		"PowerShot A570 IS","PowerShot A560","PowerShot SD750 DIGITAL ELPH / DIGITAL IXUS 75 / IXY DIGITAL 90","PowerShot SD1000 DIGITAL ELPH / DIGITAL IXUS 70 / IXY DIGITAL 10","PowerShot A550",
		"PowerShot A450","PowerShot G9","PowerShot A650 IS","PowerShot A720","PowerShot SX100 IS",
		"PowerShot SD950 IS DIGITAL ELPH / DIGITAL IXUS 960 IS / IXY DIGITAL 2000 IS","Digital IXUS 860 IS","SELPHY CP750","SELPHY CP740","PowerShot SD890 IS DIGITAL ELPH / Digital IXUS 970 IS / IXY DIGITAL 820 IS",
		"PowerShot SD790 IS DIGITAL ELPH / Digital IXUS 90 IS / IXY DIGITAL 95 IS","IXY Digital 25 IS","PowerShot A590","PowerShot A580","PC1267 [Powershot A470]",
		"Digital IXUS 80 IS (PTP mode)","SELPHY ES2","SELPHY ES20","PowerShot SX100 IS","PowerShot A1000 IS",
		"PowerShot G10","PowerShot A2000 IS","PowerShot SX110 IS","PowerShot SD990 IS DIGITAL ELPH / Digital IXUS 980 IS / IXY DIGITAL 3000 IS","PowerShot SX1 IS",
		"PowerShot SD880 IS DIGITAL ELPH / Digital IXUS 870 IS / IXY DIGITAL 920 IS","EOS 7D","SELPHY CP770","SELPHY CP760","PowerShot E1",
		"SELPHY ES3","SELPHY ES30","SELPHY CP530","PowerShot D10","PowerShot SD960 IS DIGITAL ELPH / Digital IXUS 110 IS / IXY DIGITAL 510 IS",
		"PowerShot A2100 IS","PowerShot A480","PowerShot SX200 IS","PowerShot SD970 IS DIGITAL ELPH / Digital IXUS 990 IS / IXY DIGITAL 830 IS","PowerShot SD780 IS DIGITAL ELPH / Digital IXUS 100 IS / IXY DIGITAL 210 IS",
		"PowerShot A1100 IS","PowerShot SD1200 IS DIGITAL ELPH / Digital IXUS 95 IS / IXY DIGITAL 110 IS","EOS Rebel T1i / EOS 500D / EOS Kiss X3","SELPHY CP780","PowerShot G11",
		"PowerShot SX120 IS","PowerShot S90","PowerShot SX20 IS","Digital IXUS 200 IS","PowerShot SD940 IS DIGITAL ELPH / Digital IXUS 120 IS / IXY DIGITAL 220 IS",
		"SELPHY CP790","EOS Rebel T2i / EOS 550D / EOS Kiss X4","SELPHY ES40","PowerShot A495","PowerShot A490",
		"PowerShot A3100 IS / PowerShot A3150 IS","PowerShot A3000 IS","PowerShot Digital ELPH SD1400 IS","PowerShot SD1300 IS / IXUS 105","Powershot SD3500 IS / IXUS 210 IS",
		"PowerShot SX210 IS","Powershot SD4000 IS / IXUS 300 HS / IXY 30S","Powershot SD4500 IS / IXUS 1000 HS / IXY 50S","Digital IXUS 55","Vixia HF S21 A",
		"PowerShot G12","Powershot SX30 IS","PowerShot SX130 IS","Powershot S95","SELPHY CP800",
		"EOS 600D / Rebel T3i (ptp)","PowerShot A3300 IS","PowerShot A3200 IS","PowerShot ELPH 500 HS / IXUS 310 HS","PowerShow A800",
		"PowerShot ELPH 100 HS / IXUS 115 HS","PowerShot SX230 HS","PowerShot ELPH 300 HS / IXUS 220 HS","PowerShot A2200","Powershot A1200",
		"PowerShot SX220 HS","PowerShot G1 X","PowerShot SX150 IS","PowerShot ELPH 510 HS / IXUS 1100 HS","PowerShot S100",
		"PowerShot ELPH 310 HS / IXUS 230 HS","PowerShot SX40 HS","EOS Rebel T4i","PowerShot A1300","PowerShot A810",
		"PowerShot ELPH 320 HS / IXUS 240 HS","PowerShot ELPH 110 HS / IXUS 125 HS","PowerShot D20","PowerShot A4000 IS","PowerShot SX260 HS",
		"PowerShot SX240 HS","PowerShot ELPH 520 HS / IXUS 500 HS","PowerShot A3400 IS","PowerShot A2400 IS","PowerShot A2300",
		"SELPHY CP900","SELPHY CP810","PowerShot G15","PowerShot SX50 HS","PowerShot SX160 IS",
		"PowerShot S110","PowerShot SX500 IS","PowerShot N","PowerShot SX280 HS","PowerShot SX270 HS",
		"PowerShot A3500 IS","PowerShot A2600","PowerShot A1400","Powershot ELPH 130 IS / IXUS 140","PowerShot ELPH 330 HS / IXUS 255 HS",
		"PowerShot A2500","PowerShot SX170 IS","PowerShot SX510 HS","Powershot ELPH 115 IS / IXUS 132","Powershot ELPH 135 / IXUS 145",
		"PowerShot ELPH 340 HS / IXUS 265 HS","PowerShot ELPH 150 IS / IXUS 155"};
		InsertProducts(0x04a9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2501};
		char* mids[] = {"Bluetooth Device"};
		InsertProducts(0x04ad, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0102,0x0103,0x0104,0x0106,0x0107,0x0108,0x0109,0x010a,0x010b,0x010d,0x010e,0x010f,0x0110,0x0111,0x0112,0x0113,0x0114,0x0115,0x0117,0x0119,
		0x011d,0x0121,0x0122,0x0124,0x0125,0x0126,0x0129,0x012c,0x012d,0x012e,0x0130,0x0135,0x0136,0x0137,0x013a,0x013b,0x0141,0x0142,0x0163,0x0169,
		0x0202,0x0203,0x0204,0x0205,0x0206,0x0301,0x0302,0x0317,0x0402,0x0403,0x0404,0x0405,0x0406,0x0408,0x0409,0x040a,0x040c,0x040e,0x040f,0x0410,
		0x0413,0x041e,0x0422,0x0423,0x0424,0x0425,0x0428,0x0429,0x042a,0x0f03,0x4000,0x4001,0x4002};
		char* mids[] = {"Coolpix 990","Coolpix 880","Coolpix 995","Coolpix 775","Coolpix 5000",
		"Coolpix 2500","Coolpix 2500 (ptp)","Coolpix 4500","Coolpix 4500 (ptp)","Coolpix 5700 (ptp)",
		"Coolpix 4300 (storage)","Coolpix 4300 (ptp)","Coolpix 3500 (Sierra Mode)","Coolpix 3500 (ptp)","Coolpix 885 (ptp)",
		"Coolpix 5000 (ptp)","Coolpix 3100 (storage)","Coolpix 3100 (ptp)","Coolpix 2100 (ptp)","Coolpix 5400 (ptp)",
		"Coolpix 3700 (ptp)","Coolpix 3200 (ptp)","Coolpix 2200 (ptp)","Coolpix 8400 (mass storage mode)","Coolpix 8400 (ptp)",
		"Coolpix 8800","Coolpix 4800 (ptp)","Coolpix 4100 (storage)","Coolpix 4100 (ptp)","Coolpix 5600 (ptp)",
		"Coolpix 4600 (ptp)","Coolpix 5900 (ptp)","Coolpix 7900 (storage)","Coolpix 7900 (ptp)","Coolpix 100 (storage)",
		"Coolpix 100 (ptp)","Coolpix P2 (storage)","Coolpix P2 (ptp)","Coolpix P5100 (ptp)","Coolpix P50 (ptp)",
		"Coolpix SQ (ptp)","Coolpix 4200 (mass storage mode)","Coolpix 4200 (ptp)","Coolpix 5200 (storage)","Coolpix 5200 (ptp)",
		"Coolpix 2000 (storage)","Coolpix 2000 (ptp)","Coolpix L20 (ptp)","DSC D100 (ptp)","D2H (mass storage mode)",
		"D2H SLR (ptp)","D70 (mass storage mode)","DSC D70 (ptp)","D2X SLR (ptp)","D50 digital camera",
		"D50 (ptp)","D2Hs","DSC D70s (ptp)","D200 (mass storage mode)","D200 (ptp)",
		"D40 (mass storage mode)","D60 digital camera (mass storage mode)","D700 (ptp)","D5000","D3000",
		"D300S","D7000","D5100","D800 (ptp)","PD-10 Wireless Printer Adapter",
		"Coolscan LS 40 ED","LS 50 ED/Coolscan V ED","Super Coolscan LS-5000 ED"};
		InsertProducts(0x04b0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3003,0x3004,0x300a,0x3016,0x3018,0x301b,0x301c,0x3020,0x3025,0x3100,0x3103,0x3104,0x3105,0x3107,0x3108,0x3109,0x310b,0x310c,0x4427,0x4482,
		0x4485,0x4524,0x4525,0x4535,0x4550,0x4554,0x4580,0x4581,0x4604,0x4671};
		char* mids[] = {"Rapid Access III Keyboard","Media Access Pro Keyboard","Rapid Access IIIe Keyboard","UltraNav Keyboard Hub","UltraNav Keyboard",
		"SK-8815 Keyboard","Enhanced Performance Keyboard","Enhanced Performance Keyboard","NetVista Full Width Keyboard","NetVista Mouse",
		"ScrollPoint Pro Mouse","ScrollPoint Wireless Mouse","ScrollPoint Optical (HID)","ThinkPad 800dpi Optical Travel Mouse","800dpi Optical Mouse w/ Scroll Point",
		"Optical ScrollPoint Pro Mouse","Red Wheel Mouse","Wheel Mouse","Portable CD ROM","Serial Converter",
		"Serial Converter","40 Character Vacuum Fluorescent Display","Double sided CRT","4610 Suremark Printer","NVRAM (128 KB)",
		"Cash Drawer","Hub w/ NVRAM","4800-2xx Hub w/ Cash Drawer","Keyboard w/ Card Reader","4820 LCD w/ MSR/KB"
		};
		InsertProducts(0x04b3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0033,0x0060,0x0100,0x0101,0x0102,0x0130,0x0306,0x0407,0x0bad,0x1002,0x1006,0x2050,0x2830,0x4235,0x4381,0x4611,0x4616,0x5201,
		0x5202,0x5500,0x5a9b,0x6370,0x6560,0x6830,0x6831,0x7417,0x8329,0x8613,0x8614,0x861f,0xbca1,0xcc04,0xcc06,0xd5d5,0xde61,0xde64,0xf000,0xf111,
		0xf115,0xfd13};
		char* mids[] = {"Mouse","CY7C63x0x Thermometer","Mouse","Wireless optical mouse","Cino FuzzyScan F760-B",
		"Keyboard/Hub","Keyboard with APM","MyIRC Remote Receiver","Telephone Receiver","Optical Skype Mouse",
		"MetaGeek Wi-Spy","CY7C63001 R100 FM Radio","Human Interface Device","hub","Opera1 DVB-S (cold state)",
		"Monitor 02 Driver","SCAPS USC-1 Scanner Controller","Storage Adapter FX2 (CY)","Flash Disk (TPP)","Combi Keyboard-Hub (Hub)",
		"Combi Keyboard-Hub (Keyboard)","HID->COM RS232 Adapter","Dacal CD/DVD Library D-101/DC-300/DC-016RW","ViewMate Desktop Mouse CC2201","CY7C65640 USB-2.0 \"TetraHub\"",
		"CY7C68300A EZ-USB AT2 USB 2.0 to ATA/ATAPI","Storage Adapter ISD-300LP (CY)","Wireless PC Lock/Ultra Mouse","USB To keyboard/Mouse Converter","CY7C68013 EZ-USB FX2 USB 2.0 Development Kit",
		"DTV-DVB UDST7020BDA DVB-S Box(DVBS for MCE2005)","Anysee E30 USB 2.0 DVB-T Receiver","Barcode Reader","Centor USB RACIA-ALVAR USB PORT","Centor-P RACIA-ALVAR USB PORT",
		"CY7C63x0x Zoltrix Z-Boxer GamePad","Barcode Reader","Barcode Reader","CY30700 Licorice evaluation board","CY8CKIT-002 PSoC MiniProg3 Rev A Program and debug kit",
		"PSoC FirstTouch Programmer","Programmable power socket"};
		InsertProducts(0x04b4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3064};
		char* mids[] = {"Hantek DSO-3064"};
		InsertProducts(0x04b5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0015,0x0101,0x0102,0x0103,0x0104,0x0105,0x0106,0x0107,0x0108,0x0109,0x010a,0x010b,0x010c,
		0x010d,0x010e,0x010f,0x0110,0x0112,0x0114,0x0116,0x0118,0x0119,0x011a,0x011b,0x011c,0x011d,0x011e,0x011f,0x0120,0x0121,0x0122,0x0126,0x0128,
		0x0129,0x012a,0x012b,0x012c,0x012d,0x012e,0x012f,0x0130,0x0131,0x0133,0x0135,0x0136,0x0137,0x0138,0x013a,0x0142,0x0143,0x0144,0x0202,0x0401,
		0x0402,0x0403,0x0509,0x0601,0x0602,0x0801,0x0802,0x0803,0x0804,0x0805,0x0806,0x0807,0x0808,0x0809,0x080a,0x080c,0x080d,0x080e,0x080f,0x0810,
		0x0811,0x0812,0x0813,0x0814,0x0815,0x0816,0x0817,0x0818,0x0819,0x081a,0x081b,0x081c,0x081d,0x081e,0x081f,0x0820,0x0821,0x0822,0x0823,0x0824,
		0x0825,0x0826,0x0827,0x0828,0x0829,0x082a,0x082b,0x082c,0x082d,0x082e,0x082f,0x0830,0x0831,0x0832,0x0833,0x0834,0x0835,0x0836,0x0837,0x0838,
		0x0839,0x083a,0x083b,0x083c,0x083d,0x083e,0x083f,0x0841,0x0843,0x0844,0x0846,0x0847,0x0848,0x0849,0x084a,0x084d,0x084f,0x0850,0x0851,0x0852,
		0x0853,0x0854,0x0855,0x0856,0x085c,0x085d,0x085e,0x085f,0x0860,0x0861,0x0862,0x0863,0x0864,0x0865,0x0866,0x0869,0x086a,0x0870,0x0871,0x0872,
		0x0873,0x0878,0x0879,0x087b,0x087c,0x087d,0x087f,0x0880,0x0881,0x0883,0x0884,0x0885,0x088f,0x0890,0x0891,0x0892,0x0893};
		char* mids[] = {"Stylus Color 740 / Photo 750","ISD Smart Cable for Mac","ISD Smart Cable","Printer","Printer",
		"Printer","Printer","Stylus Photo R3000","GT-7000U [Perfection 636]","GT-2200",
		"GT-6600U [Perfection 610]","GT-7600UF [Perfection 1200U/1200U Photo]","Stylus Scan 2000","Stylus Scan 2500","ES-2000 [Expression 1600U]",
		"CC-700","ES-8500 [Expression 1640 XL]","GT-8700/GT-8700F [Perfection 1640SU/1640SU PHOTO]","GT-7700U [Perfection 1240U]","GT-6700U [Perfection 640]",
		"CC-500L","ES-2200 [Perfection 1680]","GT-7200U [Perfection 1250/1250 PHOTO]","GT-8200U/GT-8200UF [Perfection 1650/1650 PHOTO]","GT-9700F [Perfection 2450 PHOTO]",
		"Perfection 660","GT-9400UF [Perfection 3170]","GT-F600 [Perfection 4180]","GT-X750 [Perfection 4490 Photo]","CC-550L [1000 ICS]",
		"GT-9300UF [Perfection 2400 PHOTO]","GT-9800F [Perfection 3200]","GT-7300U [Perfection 1260/1260 PHOTO]","GT-8300UF [Perfection 1660 PHOTO]","GT-8400UF [Perfection 1670/1670 PHOTO]",
		"GT-7400U [Perfection 1270]","GT-F500/GT-F550 [Perfection 2480/2580 PHOTO]","GT-F520/GT-F570 [Perfection 3590 PHOTO]","ES-7000H [GT-15000]","GT-X700 [Perfection 4870]",
		"ES-10000G [Expression 10000XL]","GT-X800 [Perfection 4990 PHOTO]","ES-H300 [GT-2500]","GT-X900 [Perfection V700/V750 Photo]","GT-F650 [GT-S600/Perfection V10/V100]",
		"GT-F670 [Perfection V200 Photo]","GT-F700 [Perfection V350]","GT-X770 [Perfection V500]","GT-F720 [GT-S620/Perfection V30/V300 Photo]","GT-1500 [GT-D1000]",
		"GT-X970","ES-D400 [GT-S80]","ES-D200 [GT-S50]","ES-H7200 [GT-20000]","GT-X820 [Perfection V600 Photo]",
		"GT-F730 [GT-S630/Perfection V33/V330 Photo]","GT-S55","GT-S85","Receipt Printer M129C/TM-T70","CP 800 Digital Camera",
		"PhotoPC 850z","PhotoPC 3000z","JVC PIX-MC10","Stylus Photo 875DC Card Reader","Stylus Photo 895 Card Reader",
		"CC-600PX [Stylus CX5200/CX5400/CX6600]","CC-570L [Stylus CX3100/CX3200]","Printer (Composite Device)","Storage Device","Stylus CX6300/CX6400",
		"PM-A850 [Stylus Photo RX600/610]","Stylus Photo RX500/510","Stylus CX5200/CX5300/CX5400","Storage Device","F-3200",
		"ME100 [Stylus CX1500]","Stylus CX4500/4600","PX-A550 [CX-3500/3600/3650 MFP]","Stylus Photo RX420/RX425/RX430","PM-A900 [Stylus Photo RX700]",
		"PM-A870 [Stylus Photo RX620/RX630]","MFP Composite Device","Stylus CX6500/6600","PM-A700","LP-A500 [AcuLaser CX1]",
		"Printer (Composite Device)","LP-M5500/LP-M5500F","Stylus CX3700/CX3800/DX3800","PX-A650 [Stylus CX4700/CX4800/DX4800/DX4850]","PM-A750 [Stylus Photo RX520/RX530]",
		"MFP Composite Device","PM-A890 [Stylus Photo RX640/RX650]","PM-A950","MFP Composite Device","Stylus CX7700/7800",
		"Stylus CX4100/CX4200/DX4200","Stylus CX5700F/CX5800F","Storage Device","MFP Composite Device","Storage Device",
		"MFP Composite Device","Storage Device","PM-A820 [Stylus Photo RX560/RX580/RX585/RX590]","PM-A970","PM-T990",
		"PM-A920","Stylus CX5900/CX5000/DX5000/DX5050","Storage Device","Storage Device","PX-A720 [Stylus CX5900/CX6000/DX6000]",
		"PX-A620 [Stylus CX3900/DX4000/DX4050]","ME 200 [Stylus CX2800/CX2900]","Stylus CX6900F/CX7000F/DX7000F","MFP Composite Device","LP-M5600",
		"LP-M6000","AcuLaser CX21","PM-T960","PM-A940 [Stylus Photo RX680/RX685/RX690]","PX-A640 [CX7300/CX7400/DX7400]",
		"PX-A740 [CX8300/CX8400/DX8400]","PX-FA700 [CX9300F/CX9400Fax/DX9400F]","MFP Composite Device","PM-A840S [Stylus Photo RX595/RX610]","MFP Composite Device",
		"MFP Composite Device","Stylus CX4300/CX4400/CX5500/CX5600/DX4400/DX4450","PX-401A [ME 300/Stylus NX100]","LP-M5000","EP-901A/EP-901F [Artisan 800/Stylus Photo PX800FW]",
		"EP-801A [Artisan 700/Stylus Photo PX700W/TX700W]","PX-601F [ME Office 700FW/Stylus Office BX600FW/TX600FW]","ME Office 600F/Stylus Office BX300F/TX300F","Stylus SX205","PX-501A [Stylus NX400]",
		"PX-402A [Stylus SX115/Stylus NX110 Series]","ME OFFICE 510","EP-702A [Stylus Photo PX650/TX650 Series]","Stylus SX410","EP-802A [Artisan 710 Series/Stylus Photo PX710W/TX720W Series]",
		"EP-902A [Artisan 810 Series/Stylus Photo PX810FW Series]","ME OFFICE 650FN Series/Stylus Office BX310FN/TX520FN Series","PX-602F [Stylus Office BX610FW/TX620FW Series]","PX-502A [Stylus SX515W]","ME 320/330 Series [Stylus SX125]",
		"PX-603F [ME OFFICE 960FWD Series/Stylus Office BX625FWD/TX620FWD Series]","PX-503A [ME OFFICE 900WD Series/Stylus Office BX525WD]","Stylus Office BX320FW/TX525FW Series","EP-903A/EP-903F [Artisan 835/Stylus Photo PX820FWD Series]","EP-803A/EP-803AW [Artisan 725/Stylus Photo PX720WD/TX720WD Series]",
		"EP-703A [Stylus Photo PX660 Series]","ME OFFICE 620F Series/Stylus Office BX305F/BX305FW/TX320F","ME OFFICE 560W Series","ME OFFICE 520 Series","AcuLaser MX20DN/MX20DNF/MX21DNF",
		"PX-1600F","PX-673F [Stylus Office BX925FWD]","Stylus Office BX305FW Plus","K200 Series","K300 Series",
		"L200 Series","EP-704A","EP-904A/EP-904F [Artisan 837/Stylus Photo PX830FWD Series]","EP-804A/EP-804AR/EP-804AW [Stylus Photo PX730WD/Artisan 730 Series]","PX-1700F",
		"PX-B750F","PX-403A","PX-434A [Stylus NX330 Series]","PX-404A [ME OFFICE 535]","ME 340 Series/Stylus NX130 Series",
		"Stylus NX430W Series","Stylus NX230 Series","Stylus Office BX635FWD","ME OFFICE 940FW Series/Stylus Office BX630FW Series","Stylus Office BX535WD",
		"Stylus Office BX935FWD","EP-774A"};
		InsertProducts(0x04b8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0300,0x1000,0x1001,0x1002,0x1003,0x1004,0x1005,0x1006,0x1200,0x1201,0x1202,0x1203,0x1204,0x1205,0x1206,0x1300,0x1301,0x1302,0x1303,0x1304,
		0x1305,0x1306};
		char* mids[] = {"SafeNet USB SuperPro/UltraPro","iKey 1000 Token","iKey 1200 Token","iKey Token","iKey Token",
		"iKey Token","iKey Token","iKey Token","iKey 2000 Token","iKey Token",
		"iKey 2032 Token","iKey Token","iKey Token","iKey Token","iKey 4000 Token",
		"iKey 3000 Token","iKey 3000","iKey Token","iKey Token","iKey Token",
		"iKey Token","iKey Token"};
		InsertProducts(0x04b9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0201,0x0204,0x0206,0x0301,0x0314,0x0319,0x031a,0x031b,0x031e,0x0502,0x0528,0x0901,0x0904,0x0913,0x0919,0x0922,0x0930,0x0937,0x0938,
		0x093b,0x093f,0x0944,0x0945,0x0947,0x0948,0x0a03,0x0a07,0x0a08,0x0c01};
		char* mids[] = {"USB2-IDE/ATAPI Bridge Adapter","USB2-IDE/ATAPI Bridge Adapter","DVD Multi-plus unit iU-CD2","DVD Multi-plus unit DVR-UEH8","Storage Device",
		"USB-SSMRW SD-card","USB2-IDE/ATAPI Bridge Adapter","USB2-IDE/ATAPI Bridge Adapter","USB2-IDE/ATAPI Bridge Adapter","USB-SDRW SD-card",
		"Nogatech Live! (BT)","GV-USB Video Capture","USB ETT","ET/TX Ethernet [pegasus]","ET/TX-S Ethernet [pegasus2]",
		"USB WN-B11","IOData AirPort WN-B11/USBS 802.11b","ETG-US2","WN-WAG/USL Wireless LAN Adapter","WN-G54/USL Wireless LAN Adapter",
		"WN-GDN/USB","WNGDNUS2 802.11n","WHG-AGDN/US Wireless LAN Adapter","WN-GDN/US3 Wireless LAN Adapter","WN-G150U Wireless LAN Adapter",
		"WN-G300U Wireless LAN Adapter","Serial USB-RSAQ1","USB2-iCN Adapter","USB2-iCN Adapter","FM-10 Pro Disk"
		};
		InsertProducts(0x04bb, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0115,0x0116,0x0117,0x0118,0x0135,0x0202,0x0309,0x030a,0x030b,0x030c,0x0310,0x0311,0x0317,0x0318,0x0319,0x0320,0x0321,0x0a28};
		char* mids[] = {"MediaReader CF","USB-PDC Adapter UPA9664","USB-cdmaOne Adapter UCA1464","USB-PHS Adapter UHA6400","USB-PHS Adapter UPA6400",
		"MediaReader Dual","73S1121F Smart Card Reader-","Bluetooth USB dongle","IBM Bluetooth Ultraport Module","Bluetooth Device",
		"Ultraport Bluetooth Device","Integrated Bluetooth","Integrated Bluetooth Device","Bluetooth UltraPort Module from IBM","IBM Integrated Bluetooth",
		"Bluetooth Adapter","Bluetooth Adapter","Bluetooth Device","INDI AV-IN Device"};
		InsertProducts(0x04bf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0020,0x0022,0x007e,0x0082,0x008f,0x0097,0x009d,0x00a9,0x00b9,0x3021};
		char* mids[] = {"56K Voice Pro","56K Voice Pro","ISDN TA","OfficeConnect Analog Modem","Pro ISDN TA",
		"OfficeConnect Analog","HomeConnect Webcam [vicam]","ISDN Pro TA-U","HomeConnect IDSL Modem","56k Voice FaxModem Pro"
		};
		InsertProducts(0x04c1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1102,0x2102};
		char* mids[] = {"Mouse","Mouse"};
		InsertProducts(0x04c3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1029,0x1033,0x1041,0x1042,0x105b,0x1084,0x1096,0x1097,0x10ae,0x10af,0x10c7,0x10e0,0x10e1,0x10e7,0x10fe,0x1150,0x201d};
		char* mids[] = {"fi-4010c Scanner","fi-4110CU","fi-4120c Scanner","fi-4220c Scanner","AH-F401U Air H device",
		"PalmSecure Sensor V2","fi-5110EOX","fi-5110C","fi-4120C2","fi-4220C2",
		"fi-60f scanner","fi-5120c Scanner","fi-5220C","fi-5900C","S500",
		"fi-6230","SATA 3.0 6Gbit/s Adaptor [GROOVY]"};
		InsertProducts(0x04c5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0720,0x0721,0x0722,0x0723,0x0726,0x0728,0x0729,0x072c,0x072d};
		char* mids[] = {"Digital Color Camera","e-miniD Camera","e-mini","KD-200Z Camera","KD-310Z Camera",
		"Revio C2 Mass Storage Device","Revio C2 Digital Camera","Revio KD20M","Revio KD410Z"};
		InsertProducts(0x04c8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x004f,0x1766,0x2004,0x9304,0xf01c};
		char* mids[] = {"SK-9020 keyboard","HID Monitor Controls","Bluetooth 4.0 [Broadcom BCM20702A0]","Hub","TT1280DA DVB-T TV Tuner"
		};
		InsertProducts(0x04ca, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0103,0x0104,0x0108,0x0109,0x010a,0x010b,0x010d,0x010e,0x010f,0x0110,0x0111,0x0112,0x0113,0x0114,0x0115,0x0116,0x0117,0x0118,0x0119,
		0x011a,0x011b,0x011c,0x011d,0x0120,0x0121,0x0122,0x0123,0x0124,0x0125,0x0126,0x0127,0x0128,0x0129,0x012a,0x012b,0x012c,0x012d,0x012f,0x0130,
		0x0131,0x013b,0x013c,0x013d,0x013e,0x013f,0x0142,0x0148,0x0149,0x014a,0x014b,0x014c,0x0159,0x0165,0x0168,0x0169,0x016b,0x016c,0x016e,0x016f,
		0x0171,0x0172,0x0177,0x0179,0x0186,0x0188,0x018e,0x018f,0x0192,0x0193,0x019b,0x01af,0x01bf,0x01c0,0x01c1,0x01c4,0x01c5,0x01c6,0x01d2,0x01d3,
		0x01d4,0x01d5,0x01f7,0x01fd,0x023e,0x0240,0x0241,0x0278};
		char* mids[] = {"FinePix 30i/40i/50i, A101/201, 1300/2200, 1400/2400/2600/2800/4500/4700/4800/4900/6800/6900 Zoom","FinePix NX-500/NX-700 printer","FinePix A101, 2600/2800/4800/6800 Zoom (PC CAM)","FinePix F601 Zoom (DSC)","FinePix F601 Zoom (PC CAM)",
		"FinePix S602 (Pro) Zoom (DSC)","FinePix S602 (Pro) Zoom (PC CAM)","FinePix Digital Camera 020531","FinePix F402 Zoom (DSC)","FinePix F402 Zoom (PC CAM)",
		"FinePix M603 Zoom (DSC)","FinePix M603 Zoom (PC CAM)","FinePix A202, A200 Zoom (DSC)","FinePix A202, A200 Zoom (PC CAM)","FinePix F401 Zoom (DSC)",
		"FinePix F401 Zoom (PC CAM)","FinePix A203 Zoom (DSC)","FinePix A203 Zoom (PC CAM)","FinePix A303 Zoom (DSC)","FinePix A303 Zoom (PC CAM)",
		"FinePix S304/3800 Zoom (DSC)","FinePix S304/3800 Zoom (PC CAM)","FinePix A204/2650 Zoom (DSC)","FinePix A204/2650 Zoom (PC CAM)","FinePix F700 Zoom (DSC)",
		"FinePix F700 Zoom (PC CAM)","FinePix F410 Zoom (DSC)","FinePix F410 Zoom (PC CAM)","FinePix A310 Zoom (DSC)","FinePix A310 Zoom (PC CAM)",
		"FinePix A210 Zoom (DSC)","FinePix A210 Zoom (PC CAM)","FinePix A205(S) Zoom (DSC)","FinePix A205(S) Zoom (PC CAM)","FinePix F610 Zoom (DSC)",
		"FinePix Digital Camera 030513","FinePix S7000 Zoom (DSC)","FinePix S7000 Zoom (PC CAM)","FinePix Digital Camera 030731","FinePix S5000 Zoom (DSC)",
		"FinePix S5000 Zoom (PC CAM)","FinePix Digital Camera 030722","FinePix S3000 Zoom (DSC)","FinePix S3000 Zoom (PC CAM)","FinePix F420 Zoom (DSC)",
		"FinePix F420 Zoom (PC CAM)","FinePix S7000 Zoom (PTP)","FinePix A330 Zoom (DSC)","FinePix A330 Zoom (UVC)","FinePix A330 Zoom (PTP)",
		"FinePix A340 Zoom (DSC)","FinePix A340 Zoom (UVC)","FinePix F710 Zoom (DSC)","FinePix S3500 Zoom (DSC)","FinePix E500 Zoom (DSC)",
		"FinePix E500 Zoom (UVC)","FinePix E510 Zoom (DSC)","FinePix E510 Zoom (PC CAM)","FinePix S5500 Zoom (DSC)","FinePix S5500 Zoom (UVC)",
		"FinePix E550 Zoom (DSC)","FinePix E550 Zoom (UVC)","FinePix F10 (DSC)","Finepix F10 (PTP)","FinePix S5200/S5600 Zoom (DSC)",
		"FinePix S5200/S5600 Zoom (PTP)","FinePix S9500 Zoom (DSC)","FinePix S9500 Zoom (PTP)","FinePix E900 Zoom (DSC)","FinePix E900 Zoom (PTP)",
		"FinePix F30 (PTP)","FinePix A700 (PTP)","FinePix F6000fd/S6500fd Zoom (PTP)","FinePix F20 (PTP)","FinePix F31fd (PTP)",
		"FinePix S5700 Zoom (PTP)","FinePix F40fd (PTP)","FinePix A820 Zoom (PTP)","FinePix A800 Zoom (PTP)","FinePix A920 (PTP)",
		"FinePix F50fd (PTP)","FinePix F47 (PTP)","FinePix J250 (PTP)","A160","FinePix AX300",
		"FinePix S2950 Digital Camera","FinePix S3200 Digital Camera","FinePix JV300"};
		InsertProducts(0x04cb, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1122,0x1520,0x1521,0x1a62,0x2323,0x2533,0x8116};
		char* mids[] = {"Hub","USB 2.0 Hub (Avocent KVM)","USB 2.0 Hub","GW Instek GSP-830 Spectrum Analyzer (HID)","Ux500 serial debug port",
		"NFC device (PN533)","Camera"};
		InsertProducts(0x04cc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0100,0x0300,0x04ce,0x07d1};
		char* mids[] = {"SL11R-IDE IDE Bridge","USB2PRN Printer Class","Phantom 336CX - C3 scanner","SL11DEMO, VID: 0x4ce, PID: 0x4ce","SL11R, VID: 0x4ce, PID: 0x07D1"
		};
		InsertProducts(0x04ce, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0022,0x0800,0x8810,0x8811,0x8813,0x8818,0x8819,0x9920};
		char* mids[] = {"OCZ Alchemy Series Elixir II Keyboard","MTP800 Mass Storage Device","CS8810 Mass Storage Device","CS8811 Mass Storage Device","CS8813 Mass Storage Device",
		"USB2.0 to ATAPI Bridge Controller","USB 2.0 SD/MMC Reader","CS8819A2-114 Mass Storage Device"};
		InsertProducts(0x04cf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0070,0x0305,0x0311,0x2060,0xff05,0xff47,0xff49};
		char* mids[] = {"ADA70 Speakers","Non-Compliant Audio Device","ADA-310 Speakers","Claritel-i750 - vp","ADA-305 Speakers",
		"Lansing HID Audio Controls","Lansing HID Audio Controls"};
		InsertProducts(0x04d2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1be4};
		char* mids[] = {"Bluetooth Device"};
		InsertProducts(0x04d7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0003,0x000a,0x000b,0x0032,0x0033,0x0036,0x00e0,0x0a04,0x8000,0x8001,0x8101,0x8107,0x9004,0x900a,0xc001,0xf8da,0xfaff,0xfb00,0xfbb2,
		0xfbba,0xfbbb,0xfc92,0xffef};
		char* mids[] = {"PicoLCD 20x2","PICkit 2 Microcontroller Programmer","CDC RS-232 Emulation Demo","PIC18F2550 (32K Flashable 10 Channel, 10 Bit A/D USB Microcontroller)","PICkit1",
		"PICkit2","PICkit Serial Analyzer","PIC32 Starter Board","AGP LIN Serial Analyzer","In-Circuit Debugger",
		"ICD2 in-circuit debugger","PIC24F Starter Kit","Microstick II","Microchip REAL ICE","PICkit3",
		"PicoLCD 20x4","Hughski Ltd. ColorHug","Dangerous Prototypes BusPirate v4 Bootloader mode","Dangerous Prototypes BusPirate v4","GCUSB-nStep stepper motor controller",
		"DiscFerret Magnetic Disc Analyser (bootloader mode)","DiscFerret Magnetic Disc Analyser (active mode)","Open Bench Logic Sniffer","PICoPLC [APStech]"};
		InsertProducts(0x04d8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0022,0x048e,0x0499,0x1203,0x1400,0x1503,0x1603,0x1702,0x2013,0x2221,0x2323,0x2519,0x2832,0x2834,0xa055};
		char* mids[] = {"Portable Keyboard","Optical Mouse","Optical Mouse","Keyboard","PS/2 keyboard + mouse controller",
		"Shortboard Lefty","Keyboard","Keyboard LKS02","Keyboard [Das Keyboard]","Keyboard",
		"Keyboard","Shenzhen LogoTech 2.4GHz receiver","HT82A832R Audio MCU","HT82A834R Audio MCU","Keyboard"
		};
		InsertProducts(0x04d9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0901,0x0912,0x0b01,0x0b03,0x0d01,0x0d09,0x0d0a,0x0d0d,0x0d0e,0x0f40,0x104d,0x104e,0x1500,0x1800,0x1b00,0x2121,0x2316,0x2317,0x2318,0x2319,
		0x231a,0x231d,0x231e,0x2372,0x2374,0x2451,0x245b,0x2497,0x250c,0x250d,0x3904,0x3c04};
		char* mids[] = {"LS-120 Camera","SDR-S10","CD-R/RW Drive","SuperDisk 240MB","CD-R Drive KXL-840AN",
		"CD-R Drive KXL-RW32AN","CD-R Drive KXL-CB20AN","CDRCB03","DVD-ROM & CD-R/RW","Printer",
		"Elite Panaboard UB-T880 (HID)","Elite Panaboard Pen Adaptor (HID)","MFSUSB Driver","DY-WL10 802.11abgn Adapter [Broadcom BCM4323]","MultiMediaCard",
		"EB-VS6","DVC Mass Storage Device","DVC USB-SERIAL Driver for WinXP","NV-GS11/230/250 (webcam mode)","NV-GS15 (webcam mode)",
		"NV-GS11/230/250 (DV mode)","DVC Web Camera Device","DVC DV Stream Device","Lumix Camera (Storage mode)","Lumix Camera (PTP mode)",
		"HDC-SD9","HC-X920K (3MOS Full HD video camcorder)","HDC-TM700","Gobi Wireless Modem (QDL mode)","Gobi Wireless Modem",
		"N5HBZ0000055 802.11abgn Wireless Adapter [Atheros AR7010+AR9280]","JT-P100MR-20 [ePassport Reader]"};
		InsertProducts(0x04da, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x13a6,0x6006,0x6007,0x6008,0x6009,0x600a,0x600b,0x600c,0x600d,0x600e,0x600f,0x6010,0x6011,0x6012,0x6013,0x6014,0x6015,0x6016,0x6017,0x6018,
		0x6019,0x601a,0x601b,0x601c,0x601d,0x6021,0x7002,0x7004,0x7005,0x7007,0x8004,0x8005,0x8006,0x8007,0x9009,0x9014,0x9031,0x9032,0x903a,0x9050,
		0x9056,0x9073,0x9074,0x90a9,0x90d0,0x90f2,0x9120,0x9122,0x9123,0x91a3,0x939a};
		char* mids[] = {"MFC2000","AL-1216","AL-1045","AL-1255","AL-1530CS",
		"AL-1540CS","AL-1456","AL-1555","AL-1225","AL-1551CS",
		"AR-122E","AR-152E","AR-157E","SN-1045","SN-1255",
		"SN-1456","SN-1555","AR-153E","AR-122E N","AR-153E N",
		"AR-152E N","AR-157E N","AL-1217","AL-1226","AR-123E",
		"IS01","DVC Ver.1.0","VE-CG40U Digital Still Camera","VE-CG30 Digital Still Camera","VL-Z7S Digital Camcorder",
		"Zaurus SL-5000D/SL-5500 PDA","Zaurus A-300","Zaurus SL-B500/SL-5600 PDA","Zaurus C-700 PDA","AR-M160",
		"IM-DR80 Portable NetMD Player","Zaurus C-750/C-760/C-860/SL-C3000 PDA","Zaurus SL-6000","GSM GPRS","Zaurus C-860 PDA",
		"Viewcam Z","AM-900","GSM GPRS","Sharp Composite","USB-to-Serial Comm. Port",
		"Sharp 3G GSM USB Control","WS004SH","WS007SH","W-ZERO3 ES Smartphone","922SH Internet Machine",
		"IS03"};
		InsertProducts(0x04dd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0201};
		char* mids[] = {"Monitor Hub"};
		InsertProducts(0x04e1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1410};
		char* mids[] = {"XR21V1410 USB-UART IC"};
		InsertProducts(0x04e2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0005,0x0006,0x0007,0x0009,0x000a,0x000b,0x000c,0x000d,0x0012,0x0101,0x0311,0x0312,0x0313,0x0314,0x0322,0x0325,0x0327,
		0x03fe,0x0406,0x04e6,0x04e7,0x04e8,0x04e9,0x0500,0x0701,0x0702,0x0703,0x0704,0x1001,0x1010,0x1014,0x1020,0x2007,0x2009,0x200a,0x200d,0x5111,
		0x5113,0x5114,0x5115,0x5116,0x5117,0x5118,0x5119,0x511b,0x511d,0x5120,0x5121,0x5151,0x5292,0x5410,0x5591,0xe000,0xe001,0xe003};
		char* mids[] = {"E-USB ATA Bridge","eUSCSI SCSI Bridge","eUSB SmartMedia Card Reader","eUSB SmartMedia/CompactFlash Card Reader","eUSB SmartMedia Card Reader",
		"Hifd","eUSB ATA/ATAPI Adapter","eUSB CompactFlash Adapter","eUSCSI Bridge","eUSCSI Bridge",
		"Dazzle MS","Dazzle SD/MMC","eUSB ATA Bridge (Sony Spressa USB CDRW)","Dazzle DM-CF","Dazzle DM-SD/MMC",
		"Dazzle SM","Dazzle MS","e-Film Reader-5","eUSB ORCA Quad Reader","Digital Media Reader",
		"DMHS2 DFU Adapter","eUSB SmartDM Reader","eUSB DFU Adapter","STCII DFU Adapter","eUSBDM DFU Adapter",
		"DM-E DFU Adapter","Veridicom 5thSense Fingerprint Sensor and eUSB SmartCard","DCS200 Loader Device","DVD Creation Station 200","DVC100 Loader Device",
		"Digital Video Creator 100","SCR300 Smart Card Reader","USBAT-2 CompactFlash Card Reader","e-Film Reader-3","USBAT ATA/ATAPI Adapter",
		"RSA SecurID ComboReader","Citibank Smart Card Reader","Reflex v.2 Smart Card Reader","STR391 Reader","SCR331-DI SmartCard Reader",
		"SCR333 SmartCard Reader","SCR331-DI SmartCard Reader","SCR335 SmartCard Reader","SCR331-LC1 / SCR3310 SmartCard Reader","SCR3320 - Smart Card Reader",
		"Expresscard SIM Card Reader","SCR3340 - ExpressCard54 Smart Card Reader","SmartCard Reader","SCR3311 Smart Card Reader","SCR331-DI SmartCard Reader",
		"SDI010 Smart Card Reader","SCR338 Keyboard Smart Card Reader","SCL011 RFID reader","SCR35xx Smart Card Reader","SCL3711-NFC&RW",
		"SCRx31 Reader","SCR331 SmartCard Reader","SPR532 PinPad SmartCard Reader"};
		InsertProducts(0x04e6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0004,0x0007,0x0008,0x0009,0x0020,0x0021,0x0030,0x0032,0x0033,0x0041,0x0042,0x0050,0x0071,0x0072,0x0081,0x0082,0x00ff};
		char* mids[] = {"TouchScreen","Touchmonitor Interface 2600 Rev 2","4000U CarrollTouchÂ® Touchmonitor Interface","2500U IntelliTouchÂ® Touchmonitor Interface","3000U AccuTouchÂ® Touchmonitor Interface",
		"4000U CarrollTouchÂ® Touchmonitor Interface","Touchscreen Interface (2700)","Touchmonitor Interface","4500U CarrollTouchÂ® Touchmonitor Interface","Touchmonitor Interface",
		"Touchmonitor Interface","5010 Surface Capacitive Touchmonitor Interface","Touchmonitor Interface","2216 AccuTouchÂ® Touchmonitor Interface","Touchmonitor Interface",
		"Touchmonitor Interface","Touchmonitor Interface","Touchmonitor Interface","Touchmonitor Interface"};
		InsertProducts(0x04e7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0110,0x0111,0x0300,0x1003,0x1006,0x130c,0x1f05,0x1f06,0x2018,0x2035,0x2036,0x3004,0x3005,0x3008,0x300c,0x300e,0x3104,0x3210,0x3226,
		0x3228,0x322a,0x322c,0x3230,0x3232,0x3236,0x3238,0x323a,0x323b,0x323c,0x323d,0x323e,0x3240,0x3242,0x3248,0x324a,0x324c,0x324d,0x3256,0x325b,
		0x325f,0x3260,0x3268,0x326c,0x3276,0x328e,0x3292,0x3296,0x3297,0x329f,0x330c,0x3310,0x3315,0x331e,0x3409,0x340c,0x340d,0x340e,0x340f,0x3412,
		0x3413,0x3415,0x3419,0x341a,0x341b,0x341c,0x341d,0x341f,0x3420,0x3426,0x342d,0x344f,0x3605,0x3606,0x3609,0x3902,0x3903,0x390f,0x3911,0x4005,
		0x4f1f,0x5000,0x5001,0x5002,0x5003,0x5004,0x5005,0x5006,0x500d,0x5010,0x5011,0x5013,0x5015,0x501b,0x5021,0x5026,0x5027,0x502b,0x5032,0x503b,
		0x503d,0x5041,0x5050,0x5051,0x5055,0x507d,0x507f,0x5080,0x5081,0x5082,0x5083,0x508a,0x508b,0x508c,0x5090,0x5091,0x5092,0x5093,0x5095,0x510f,
		0x5119,0x511c,0x5121,0x5123,0x5a00,0x5a01,0x5a03,0x5a04,0x5a08,0x5a0f,0x5b01,0x5b02,0x5b03,0x5b04,0x5b05,0x5b11,0x5f00,0x5f01,0x5f02,0x5f03,
		0x5f04,0x5f05,0x6032,0x6034,0x60b3,0x60c4,0x61b6,0x6601,0x6602,0x6603,0x6611,0x6613,0x6615,0x6617,0x6619,0x661b,0x661e,0x6620,0x6622,0x6624,
		0x662e,0x6630,0x6632,0x663e,0x663f,0x6640,0x6651,0x6702,0x6708,0x6709,0x6734,0x6759,0x675a,0x675b,0x6772,0x6795,0x6802,0x6806,0x6807,0x681c,
		0x681d,0x6843,0x684e,0x685b,0x685c,0x685d,0x685e,0x6860,0x6863,0x6865,0x6866,0x6868,0x6875,0x6876,0x6877,0x6888,0x6889,0x689a,0x689e,0x68aa,
		0x7011,0x7021,0x7061,0x7080,0x7081,0x8001,0xe020,0xe021,0xe022,0xf000,0xff30};
		char* mids[] = {"Kingston Flash Drive (128MB)","Connect3D Flash Drive","Connect3D Flash Drive","E2530 / GT-C3350 Phones (Mass storage mode)","MP3 Player and Recorder",
		"SDC-200Z","NX100","S2 Portable [JMicron] (500GB)","HX-MU064DA portable harddisk","WIS09ABGN LinkStick Wireless LAN Adapter",
		"Digital Photo Frame Mass Storage","Digital Photo Frame Mini Monitor","ML-4600","Docuprint P1210","ML-6060 laser printer",
		"ML-1210 Printer","Laser Printer","ML-3550N","ML-5200A Laser Printer","Laser Printer",
		"Laser Printer","Laser Printer","Laser Printer","ML-1440","Laser Printer",
		"ML-1450","ML-1430","ML-1710 Printer","Phaser 3130","Laser Printer",
		"Phaser 3120","Laser Printer","Laser Printer","ML-1510 Laser Printer","Color Laser Printer",
		"Laser Printer","ML-1740 Printer","Phaser 3121","ML-1520 Laser Printer","Xerox Phaser 3117 Laser Printer",
		"Phaser 3425 Laser Printer","CLP-510 Color Laser Printer","ML-1610 Mono Laser Printer","ML-2010P Mono Laser Printer","ML-3050/ML-3051 Laser Printer",
		"CLP-310 Color Laser Printer","ML-1640 Series Laser Printer","ML-2580N Mono Laser Printer","ML-191x/ML-252x Laser Printer","CLP-325 Color Laser Printer",
		"ML-1865","ML-331x Series Laser Printer","ML-2540 Series Laser Printer","M262x/M282x Xpress Series Laser Printer","SCX-4216F Scanner",
		"SCX-5x15 series","SCX-6x20 series","MFP 560 series","Printing Support","SCX-4x20 series",
		"SCX-4100 Scanner","Composite Device","Composite Device","Printing Support","SCX-4200 series",
		"Composite Device","Composite Device","Composite Device","Composite Device","SCX-4500 Laser Printer",
		"SCX-4x28 Series","SCX-3400 Series","InkJet Color Printer","InkJet Color Printer","InkJet Color Printer",
		"InkJet Color Printer","Xerox WorkCentre XK50cx","InkJet Color Printer","SCX-1020 series","GT-S8000 Jet (msc)",
		"GT-S8000 Jet (mtp)","YP-MF series","YP-100","YP-30","YP-700",
		"YP-30","YP-300","YP-750","MP3 Player","Yepp YP-35",
		"YP-780","YP-60","yepp upgrade","MP3 Player","Yepp YP-ST5",
		"YP-MT6V","YP-T7","YP-F1","YP-J70","YP-U1 MP3 Player",
		"YP-T7F","YP-Z5","YP-U2 MP3 Player","YP-F2R","YP-T9",
		"YP-U3 (mtp)","YP-T9J","Yepp YP-K3 (msc)","Yepp YP-K3 (mtp)","YP-P2 (msc)",
		"YP-P2 (mtp)","YP-T10","YP-S5 MP3 Player","YP-S5","YP-S3 (msc)",
		"YP-S3 (mtp)","YP-U4 (msc)","YP-U4 (mtp)","YP-S2","YP-R1",
		"Yepp YP-P3","YP-Q2","YP-U5","Yepp YP-M1","YP-NEU",
		"YP-NDU","Yepp MP3 Player","YP-800","YP-90","Meizu M6 MiniPlayer",
		"Memory Stick Reader/Writer","Memory Stick Reader/Writer","Memory Stick Reader/Writer","Memory Stick Reader/Writer","Memory Stick Reader/Writer",
		"SEW-2001u Card","NEXiO Sync","NEXiO Sync","NEXiO Sync","NEXiO Sync",
		"NEXiO Sync","STORY Station 1TB","G2 Portable hard drive","G2 Portable hard drive","M2 Portable Hard Drive",
		"M2 Portable Hard Drive USB 3.0","M3 Portable Hard Drive 1TB","Mobile Phone","Galaxy","Galaxy",
		"MITs Sync","MITs Sync","MITs Sync","MITs Sync","MITs Sync",
		"MITs Sync","Handheld","Handheld","Handheld","Handheld",
		"MITs Sync","MITs Sync","MITs Sync","D900e Phone","SGH-E720/SGH-E840",
		"Usb Modem Enumerator","i8510 Innov8","X830","U600 Phone","U600",
		"Juke","D900e Media Player","D900e Mass Storage","D900e Camera","Standalone LTE device (Trial)",
		"S5230","Standalone HSPA device","Composite LTE device (Trial)","Composite HSPA device","Galaxy Portal/Spica/S",
		"Galaxy Portal/Spica Android Phone","E2530 Phone (Samsung Kies mode)","Wave (GT-S8500)","GT-I9100 Phone [Galaxy S II] (mass storage mode)","GT-I9250 Phone [Galaxy Nexus] (Mass storage mode)",
		"GT-I9100 Phone [Galaxy S II] (Download mode)","GT-I9100 / GT-C3350 Phones (USB Debugging mode)","GT-I9100 Phone [Galaxy S II], GT-I9300 Phone [Galaxy S III], GT-P7500 [Galaxy Tab 10.1] , GT-I9500 [Galaxy S 4]","GT-I9500 [Galaxy S4] / GT-I9250 [Galaxy Nexus] (network tethering)","GT-I9300 Phone [Galaxy S III] (PTP mode)",
		"GT-I9300 Phone [Galaxy S III] (debugging mode)","Escape Composite driver for Android Phones: Modem+Diagnostic+ADB","GT-B3710 Standalone LTE device (Commercial)","GT-B3710 LTE Modem","Galaxy S",
		"GT-B3730 Composite LTE device (Commercial)","GT-B3730 Composite LTE device (Commercial)","LTE Storage Driver [CMC2xx]","GT-S5670 [Galaxy Fit]","Reality",
		"SEW-2003U Card","Bluetooth Device","eHome Infrared Receiver","Anycall SCH-W580","Human Interface Device",
		"Handheld","SERI E02 SCOM 6200 UMTS Phone","SERI E02 SCOM 6200 Virtual UARTs","SERI E02 SCOM 6200 Flash Load Disk","Intensity 3 (Mass Storage Mode)",
		"SG_iMON"};
		InsertProducts(0x04e8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xe004};
		char* mids[] = {"eHome Infrared Transceiver"};
		InsertProducts(0x04eb, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0004,0x0006,0x0008,0x0009,0x000a,0x1001,0x3008,0x3009};
		char* mids[] = {"GC-QX3 Digital Still Camera","GR-DVL815U Digital Video Camera","DV Camera Storage","GZ-MG30AA/MC500E Digital Video Camera","GR-DX25EK Digital Video Camera",
		"GR-D72 Digital Video Camera","GC-A50 Camera Device","MP-PRX1 Ethernet","MP-XP7250 WLAN Adapter"};
		InsertProducts(0x04f1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0110,0x0111,0x0112,0x0116,0x0200,0x0201,0x0220,0x0402,0x0403,0x0418,0x0760,0x0841,0x0860,0x1121,0xa001,0xa120,0xa121,0xa122,
		0xa123,0xa124,0xa128,0xa133,0xa136,0xa204,0xa208,0xa209,0xa20a,0xa20c,0xa210,0xb008,0xb009,0xb010,0xb012,0xb013,0xb015,0xb016,0xb018,0xb021,
		0xb022,0xb023,0xb024,0xb025,0xb027,0xb028,0xb029,0xb036,0xb044,0xb057,0xb059,0xb064,0xb070,0xb071,0xb083,0xb091,0xb104,0xb107,0xb14c,0xb15c,
		0xb175,0xb1aa,0xb1b4,0xb1b9,0xb1cf,0xb1d6,0xb1e4,0xb213,0xb217,0xb221,0xb230,0xb257,0xb26b,0xb272,0xb2b0,0xb2b9,0xb2da,0xb2ea,0xb330,0xb354,
		0xb394};
		char* mids[] = {"KU-8933 Keyboard","NT68P81 Keyboard","KU-2971 Keyboard","KU-9908 Keyboard","KU-8933 Keyboard with PS/2 Mouse port",
		"KU-2971/KU-0325 Keyboard","KBR-0108","Gaming Keyboard KPD0250","Wireless HID Receiver","Genius LuxeMate i200 Keyboard",
		"KU-0420 keyboard","KU-0418 Tactical Pad","Acer KU-0760 Keyboard","HP Multimedia Keyboard","2.4G Multimedia Wireless Kit",
		"Periboard 717 Mini Wireless Keyboard","E-Video DC-100 Camera","ORITE CCD Webcam(PC370R)","ORITE CCD Webcam(PC370R)","ORITE CCD Webcam(PC370R)",
		"ORITE CCD Webcam(PC370R)","ORITE CCD Webcam(PC370R)","PC Camera (SN9C202 + OV7663 + EEPROM)","Gateway Webcam","LabTec Webcam 5500",
		"DSC WIA Device (1300)","DSC WIA Device (2320)","Labtec DC-2320","DSC WIA Device (3310)","DSC WIA Device (3320)",
		"Audio Device","USB 2.0 Camera","Integrated Camera","Integrated Camera","1.3 MPixel UVC Webcam",
		"USB 2.0 Camera","VGA 24fps UVC Webcam","VGA 30fps UVC Webcam","2M UVC Webcam","ViewSonic 1.3M, USB2.0 Webcam",
		"Gateway USB 2.0 Webcam","Gateway USB 2.0 Webcam","USB 2.0 Webcam","Camera","Gateway USB 2.0 Webcam",
		"VGA UVC Webcam","1.3M UVC Webcam","Asus Integrated 0.3M UVC Webcam","Acer CrystalEye Webcam","integrated USB webcam",
		"CKF7037 HP webcam","CNA7137 Integrated Webcam","Camera","2.0M UVC Webcam / CNF7129","CKF7063 Webcam (HP)",
		"Webcam","CNF7069 Webcam","CNF7070 Webcam","CNF8050 Webcam","Sony Vaio Integrated Camera",
		"4-Port Hub","Webcam-101","Lenovo Integrated Camera","Asus Integrated Webcam","Lenovo Integrated Camera",
		"CNF9055 Toshiba Webcam","Toshiba Integrated Webcam","Fujitsu Integrated Camera","Lenovo Integrated Camera (0.3MP)","integrated camera",
		"Integrated HP HD Webcam","Lenovo Integrated Camera","Sony Visual Communication Camera","Lenovo EasyCamera","Camera",
		"Lenovo Integrated Camera UVC","thinkpad t430s camera","Integrated Camera [ThinkPad]","Asus 720p CMOS webcam","UVC 1.00 device HD UVC WebCam",
		"Integrated Camera"};
		InsertProducts(0x04f2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000a,0x0103,0x01a4,0x0210,0x0212,0x0214,0x0230,0x0232,0x02f4,0x04a0};
		char* mids[] = {"Touchscreen","ActiveJet K-2024 Multimedia Keyboard","Wireless Keyboard","Optical Mouse","Laser Mouse",
		"Lynx M9 Optical Mouse","3D Optical Mouse","Mouse","2.4G Cordless Mouse","Dream Cheeky Stress/Panic Button"
		};
		InsertProducts(0x04f3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0005,0x0006,0x0007,0x0008,0x0009,0x000a,0x000b,0x000c,0x000d,0x000e,0x000f,0x0010,0x0011,0x0012,0x0013,0x0014,0x0015,0x0016,0x0017,
		0x0018,0x001a,0x001c,0x001e,0x0020,0x0021,0x0022,0x0023,0x0024,0x0025,0x0027,0x0028,0x0029,0x002a,0x002b,0x002c,0x002d,0x0039,0x0042,0x0100,
		0x0101,0x0102,0x0104,0x0105,0x0106,0x0107,0x0108,0x0109,0x010a,0x010b,0x010c,0x010d,0x010e,0x010f,0x0110,0x0111,0x0112,0x0113,0x0114,0x0115,
		0x0116,0x0119,0x011b,0x011c,0x011d,0x011e,0x011f,0x0120,0x0121,0x0122,0x0129,0x012f,0x0132,0x0135,0x0136,0x013c,0x013d,0x013e,0x013f,0x0140,
		0x0141,0x0142,0x0143,0x0144,0x0146,0x0147,0x0148,0x0149,0x014a,0x014b,0x014d,0x014e,0x0150,0x0151,0x0157,0x0158,0x015d,0x015e,0x015f,0x0160,
		0x0161,0x0162,0x0163,0x0165,0x0166,0x0168,0x0169,0x016b,0x016c,0x016d,0x016e,0x0170,0x0171,0x0172,0x0173,0x0174,0x017b,0x0180,0x0181,0x0182,
		0x0183,0x0184,0x0185,0x0186,0x0187,0x0188,0x018a,0x018c,0x018d,0x018e,0x018f,0x0190,0x0191,0x0192,0x0193,0x0194,0x0195,0x0196,0x0197,0x019a,
		0x01a2,0x01a3,0x01a4,0x01a5,0x01a6,0x01a7,0x01a8,0x01a9,0x01aa,0x01ab,0x01ae,0x01af,0x01b0,0x01b1,0x01b2,0x01b4,0x01b5,0x01b6,0x01b7,0x01b8,
		0x01ba,0x01bd,0x01be,0x01bf,0x01c0,0x01c1,0x01c2,0x01c3,0x01c4,0x01c5,0x01ca,0x01ce,0x01cf,0x01d0,0x01d1,0x01d4,0x01d5,0x01d6,0x01df,0x01e0,
		0x01e1,0x01e2,0x01e3,0x01e4,0x01e7,0x01e9,0x01ea,0x01eb,0x01f4,0x0217,0x0223,0x0248,0x1000,0x1002,0x2002,0x2004,0x2015,0x2016,0x201a,0x201b,
		0x2027,0x202b,0x2100};
		char* mids[] = {"HL-1050 Laser Printer","Printer","HL-1240 Laser Printer","HL-1250 Laser Printer","HL-1270 Laser Printer",
		"Printer","P2500 series","Printer","Printer","HL-1440 Laser Printer",
		"HL-1450 series","HL-1470N series","Printer","Printer","Printer",
		"Printer","Printer","Printer","Printer","Printer",
		"Printer","HL-1430 Laser Printer","Printer","Printer","HL-5130 series",
		"HL-5140 series","HL-5150D series","HL-5170DN series","Printer","Printer",
		"HL-2030 Laser Printer","Printer","Printer","HL-52x0 series","HL-5250DN Printer",
		"Printer","Printer","HL-5340 series","HL-2270DW Laser Printer","MFC8600/9650 series",
		"MFC9600/9870 series","MFC9750/1200 series","MFC-8300J","MFC-9600J","MFC-7300C",
		"MFC-7400C","MFC-9200C","MFC-830","MFC-840","MFC-860",
		"MFC-7400J","MFC-9200J","MFC3100C Scanner","MFC 5100C","MFC4800 Scanner",
		"MFC 6800","DCP1000 Port(FaxModem)","MFC-8500","MFC9700 Port(FaxModem)","MFC9800 Scanner",
		"DCP1400 Scanner","MFC-9660","MFC-9880","MFC-9760","MFC-9070",
		"MFC-9180","MFC-9160","MFC580 Port(FaxModem)","MFC-590","MFC-5100J",
		"Imagistics 2500 (MFC-8640D clone)","FAX-4750e","MFC-5200C RemovableDisk","MFC-100 Scanner","MFC-150CL Scanner",
		"MFC-890 Port","MFC-5200J Printer","MFC-4420C RemovableDisk","MFC-4820C RemovableDisk","DCP-8020",
		"DCP-8025D","MFC-8420","MFC-8820D","DCP-4020C RemovableDisk","MFC-3220C",
		"FAX-1820C Printer","MFC-3320CN Printer","FAX-1920CN Printer","MFC-3420C","MFC-3820CN",
		"FAX-1815C Printer","MFC-8820J","MFC-8220 Port(FaxModem)","MFC-8210J","MFC-3420J Printer",
		"MFC-3820JN Port(FaxModem)","MFC Composite Device","DCP-8045D","MFC-8440","MFC-8840D",
		"MFC-210C","MFC-420CN Remote Setup Port","MFC-410CN RemovableDisk","MFC-620CN","MFC-610CLN RemovableDisk",
		"MFC-620CLN","DCP-110C RemovableDisk","DCP-310CN RemovableDisk","FAX-2440C Printer","MFC-5440CN",
		"MFC-5840CN Remote Setup Port","FAX-1840C Printer","FAX-1835C Printer","FAX-1940CN Printer","MFC-3240C Remote Setup Port",
		"MFC-3340CN RemovableDisk","Imagistics sx2100","MFC-7420","MFC-7820N Port(FaxModem)","Composite Device",
		"DCP-7020","DCP-7025 Printer","MFC-7220 Printer","Composite Device","FAX-2820 Printer",
		"FAX-2920 Printer","MFC-9420CN","DCP-115C","DCP-116C","DCP-117C",
		"DCP-118C","DCP-120C","DCP-315CN","DCP-340CW","MFC-215C",
		"MFC-425CN","MFC-820CW Remote Setup Port","MFC-820CN Remote Setup Port","MFC-640CW","MFC-840CLN Remote Setup Port",
		"MFC-8640D","Composite Device","DCP-8065DN Printer","MFC-8460N Port(FaxModem)","MFC-8860DN Port(FaxModem)",
		"MFC-8870DW Printer","DCP-130C","DCP-330C","DCP-540CN","MFC-240C",
		"DCP-750CW RemovableDisk","MFC-440CN","MFC-660CN","MFC-665CW Remote Setup Port","MFC-845CW Remote Setup Port",
		"MFC-460CN Remote Setup Port","MFC-630CD","MFC-850CDN","MFC-5460CN Remote Setup Port","MFC-5860CN",
		"MFC-3360C","MFC-8660DN","DCP-750CN RemovableDisk","MFC-860CDN Remote Setup Port","DCP-128C",
		"DCP-129C","DCP-131C","DCP-329C","DCP-331C","MFC-239C",
		"MFC-9440CN Remote Setup Port","DCP-135C","DCP-150C","DCP-350C","DCP-560CN",
		"MFC-230C","MFC-235C","MFC-260C","DCP-155C","MFC-265C",
		"DCP-153C","DCP-157C","DCP-353C","DCP-357C","MFC-7340",
		"DCP-7040","DCP-7030","MFC-7320","MFC-5890CN","MFC-8480DN",
		"DCP-365CN","DCP-7055 scanner/printer","Printer","Printer","PTUSB Printing",
		"PT-2300/2310 p-Touch Laber Printer","QL-500 P-touch label printer","QL-550 P-touch label printer","PT-18R P-touch label printer","QL-650TD P-Touch Label Printer",
		"QL-560 P-Touch Label Printer","PT-7600 P-Touch Label Printer","Card Reader Writer"};
		InsertProducts(0x04f9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2490,0x4201};
		char* mids[] = {"DS1490F 2-in-1 Fob, 1-Wire adapter","DS4201 Audio DAC"};
		InsertProducts(0x04fa, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0005,0x0013,0x0015,0x00d3,0x0171,0x0201,0x0232,0x0538,0x0561,0x05d8,0x0c15,0x0c25,0x1528,0x1533,0x2080,0x500c,0x504a,0x504b,0x5330,
		0x5331,0x5360,0x5563,0x5720,0x6333,0x7333,0x757a,0xffff};
		char* mids[] = {"CM1092 / Wintech CM-5098 Optical Mouse","USB OpticalWheel Mouse","ViewMate Desktop Mouse CC2201","ViewMate Desktop Mouse CC2201","00052486 / Laser Mouse M1052 [hama]",
		"SPCA1527A/SPCA1528 SD card camera (Mass Storage mode)","RS232C Adapter","Fingerprint","Wireless Optical Mouse 2.4G [Bright]","Flexcam 100",
		"Wireless keyboard/mouse","SPIF215A SATA bridge","SATALink SPIF225A","SPCA1527A/SPCA1528 SD card camera (webcam mode)","Mass Storage",
		"ASUS Webcam","CA500C Digital Camera","Aiptek Mini PenCam 1.3","Aiptek Mega PockerCam 1.3/Maxell MaxPocket LE 1.3","Digitrex 2110",
		"Vivitar Vivicam 10","Sunplus Generic Digital Camera","Digital Media Player MP3/WMA [The Sharper Image]","Card Reader Driver","Siri A9 UVC chipset",
		"Finet Technology Palmpix DC-85","Aiptek, MP315 MP3 Player","PureDigital Ritz Disposable"};
		InsertProducts(0x04fc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003};
		char* mids[] = {"Smart Card Reader II"};
		InsertProducts(0x04fd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"DART Keyboard Mouse","DART-2 Keyboard"};
		InsertProducts(0x0500, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0736,0x15b1,0x1631,0x1632,0x16e1,0x16e2,0x16e3,0x3202,0x3203,0x3230,0x3317,0x3325,0x3341,0x33c3,0x33c4,0x33c7,0x33c8,0xd001};
		char* mids[] = {"Handheld","Handheld","PDA n311","c10 Series","c20 Series",
		"n10 Handheld Sync","n20 Pocket PC Sync","n30 Handheld Sync","Liquid","Liquid (Debug mode)",
		"BeTouch E120","Liquid","Iconia tablet A500","Iconia tablet A500","Liquid Gallant Duo E350",
		"Liquid Gallant Duo E350 (debug mode)","Liquid Gallant Duo E350 (USB tethering)","Liquid Gallant Duo E350 (debug mode, USB tethering)","Divio NW801/DVC-V6+ Digital Camera"};
		InsertProducts(0x0502, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x009d,0x00a0,0x00a1,0x00a2,0x00df,0x0100,0x03e8,0x0a01,0x0a11,0x11f8,0x2922,0x3021,0x4601,0xf002,0xf003,0xf100};
		char* mids[] = {"HomeConnect Camera","3CREB96 Bluetooth Adapter","Bluetooth Device","Bluetooth Device","3Com Home Connect lite",
		"HomeConnect ADSL Modem Driver","3C19250 Ethernet [klsi]","3CRSHEW696 Wireless Adapter","3CRWE254G72 802.11g Adapter","HomeConnect 3C460",
		"HomeConnect Cable Modem External with","U.S.Robotics 56000 Voice FaxModem Pro","3C460B 10/100 Ethernet Adapter","3CP4218 ADSL Modem (pre-init)","3CP4218 ADSL Modem",
		"3CP4218 ADSL Modem (pre-init)"};
		InsertProducts(0x0506, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0011};
		char* mids[] = {"Konami ParaParaParadise Controller"};
		InsertProducts(0x0507, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0801,0x0802,0x0806,0x080f,0x0812};
		char* mids[] = {"ADSL Modem","ADSL Modem (RFC1483)","DSL Modem","Binatone ADSL500 Modem Network Interface","Pirelli ADSL Modem Network Interface"
		};
		InsertProducts(0x0509, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004,0x0012,0x0013,0x0017,0x003a,0x0050,0x0081,0x0083,0x0084,0x0102,0x0103,0x0106,0x0108,0x0109,0x0115,0x0119,0x0121,0x0122,0x0131,0x016a,
		0x0200,0x0201,0x0208,0x0210,0x0211,0x0224,0x0234,0x0237,0x0240,0x0249,0x0257,0x0304,0x0307,0x0409,0x0416,0x0551,0x065a,0x0706,0x0802,0x0803,
		0x0805,0x0815,0x0826,0x0980,0x1004,0x1102,0x1103,0x1106,0x1109,0x11f2,0x1202,0x1203,0x2103,0x21f1,0x21f2,0x258a,0x3101,0x3201,0x4050,0x5055,
		0x6050,0x6051,0x615a,0x7050,0x7051,0x705a,0x705b,0x705c,0x705e,0x706a,0x8053,0x805c,0x805e,0x815c,0x815f,0x825a,0x825b,0x845a,0x905b,0x905c,
		0x935a,0x935b,0x945a,0x945b,0xd321};
		char* mids[] = {"Direct Connect","F8T012 Bluetooth Adapter","F8T013 Bluetooth Adapter","B8T017 Bluetooth+EDR 2.1","Universal Media Reader",
		"F5D6050 802.11b Wireless Adapter v2000 [Atmel at76c503a]","F8T001v2 Bluetooth","Bluetooth Device","F8T003v2 Bluetooth","Flip KVM",
		"F5U103 Serial Adapter [etek]","VideoBus II Adapter, Video","F1DE108B KVM","F5U109/F5U409 PDA Adapter","SCSI Adapter",
		"F5U120-PC Dual PS/2 Ports / F5U118-UNV ADB Adapter","F5D5050 100Mbps Ethernet","Ethernet Adapter","Bluetooth Device with trace filter","Bluetooth Mini Dongle",
		"Nostromo SpeedPad n52te Gaming Keyboard","Peripheral Switch","USBView II Video Adapter [nt1004]","F5U228 Hi-Speed USB 2.0 DVD Creator","F5U211 USB 2.0 15-in-1 Media Reader & Writer",
		"F5U224 USB 2.0 4-Port Hub","F5U234 USB 2.0 4-Port Hub","F5U237 USB 2.0 7-Port Hub","F5U240 USB 2.0 CF Card Reader","USB 2 Flash Media Device",
		"F5U257 Serial","FSU304 USB 2.0 - 4 Ports Hub","USB 2.0 - 7 ports Hub [FSU307]","F5U409 Serial","Staples 12416 7 port desktop hub",
		"F6C550-AVR UPS","F8T065BF Mini Bluetooth 4.0 Adapter","2-N-1 7-Port Hub (Lower half)","Nostromo n40 Gamepad","Nostromo 1745 GamePad",
		"Nostromo N50 GamePad","Nostromo n52 HID SpeedPad Mouse Wheel","ErgoFit Wireless Optical Mouse (HID)","HID UPS Battery","F9L1004 802.11n Surf N300 XR Wireless Adapter [Realtek RTL8192CU]",
		"F7D1102 N150/Surf Micro Wireless Adapter v1000 [Realtek RTL8188CUS]","F9L1103 N750 DB 802.11abgn 2x3:3 [Ralink RT3573]","F9L1106v1 802.11a/b/g/n/ac Wireless Adapter [Broadcom BCM43526]","F9L1109v1 802.11a/b/g/n/ac Wireless Adapter [Realtek RTL8812AU]","ISY Wireless Micro Adapter IWL 2000 [RTL8188CUS]",
		"F5U120-PC Parallel Printer Port","F5U120-PC Serial Port","F7D2102 802.11n N300 Micro Wireless Adapter v3000 [Realtek RTL8192CU]","N300 WLAN N Adapter [ISY]","RTL8192CU 802.11n WLAN Adapter [ISY IWL 4000]",
		"F5U258 Host to Host cable","F1DF102U/F1DG102U Flip Hub","F1DF102U/F1DG102U Flip KVM","ZD1211B","F5D5055 Gigabit Network Adapter [AX88xxx]",
		"F6D6050 802.11abgn Wireless Adapter [Broadcom BCM4323]","F5D6051 802.11b Wireless Network Adapter [ZyDAS ZD1201]","F7D4101 / F9L1101 802.11abgn Wireless Adapter [Broadcom BCM4323]","F5D7050 Wireless G Adapter v1000/v2000 [Intersil ISL3887]","F5D7051 802.11g Adapter v1000 [Broadcom 4320 USB]",
		"F5D7050 Wireless G Adapter v3000 [Ralink RT2571W]","Wireless G Adapter","F5D7050 Wireless G Adapter v4000 [Zydas ZD1211B]","F5D7050 Wireless G Adapter v5000 [Realtek RTL8187B]","2-N-1 7-Port Hub (Upper half)",
		"F5D8053 N Wireless USB Adapter v1000/v4000 [Ralink RT2870]","F5D8053 N Wireless Adapter v3000 [Ralink RT2870]","F5D8053 N Wireless USB Adapter v5000 [Realtek RTL8192U]","F5D8053 N Wireless USB Adapter v3000 [Ralink RT2870]","F5D8053 N Wireless USB Adapter v6000 [Realtek RTL8192SU]",
		"F5D8055 N+ Wireless Adapter v1000 [Ralink RT2870]","F5D8055 N+ Wireless Adapter v2000 [Ralink RT3072]","F7D2101 802.11n Surf & Share Wireless Adapter v1000 [Realtek RTL8192SU]","F5D9050 Wireless G+ MIMO Network Adapter v3000 [Ralink RT2573]","F5D9050 Wireless G+ MIMO Network Adapter v4000 [Ralink RT2573]",
		"F6D4050 N150 Enhanced Wireless Network Adapter v1000 [Ralink RT3070]","F6D4050 N150 Enhanced Wireless Network Adapter v2000 [Ralink RT3070]","F7D1101 v1 Basic Wireless Adapter [Realtek RTL8188SU]","F7D1101 v2 Basic Wireless Adapter [Ralink RT3370]","Dynex DX-NUSB 802.11bgn Wireless Adapter [Broadcom BCM43231]"
		};
		InsertProducts(0x050d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0003,0x0180,0x0190};
		char* mids[] = {"Hub","KC82C160S Hub","KC-180 IrDA Dongle","KC2190 USB Host-to-Host cable"};
		InsertProducts(0x050f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x1000,0xe001};
		char* mids[] = {"Keyboard","Keyboard with PS/2 Mouse Port","Mouse"};
		InsertProducts(0x0510, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x002b};
		char* mids[] = {"AOC DVB"};
		InsertProducts(0x0511, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"USB to PS2 Adaptor v1.09","EZ-9900C Keyboard"};
		InsertProducts(0x0518, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0xc002};
		char* mids[] = {"TSP100ECO/TSP100II","Xlive Bluetooth XBM-100S MP3 Player"};
		InsertProducts(0x0519, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa005};
		char* mids[] = {"Smart Display Version 9973"};
		InsertProducts(0x051a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005,0xc001,0xc002};
		char* mids[] = {"VFD Module","eHome Infrared Receiver","eHome Infrared Receiver"};
		InsertProducts(0x051c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003};
		char* mids[] = {"UPS","Uninterruptible Power Supply","UPS"};
		InsertProducts(0x051d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x100d,0x1080,0x1200,0x1265,0x3424,0xa0f0,0xa140,0xa141,0xa220,0xa4a0,0xa4a1,0xa4a2,0xa4a3,0xa4a4,0xa4a5,0xa4a6,0xa4a7,0xa4a8,0xa4a9,0xa4aa
		};
		char* mids[] = {"RFMD Bluetooth Device","NET1080 USB-USB Bridge","SSDC Adapter II","File-backed Storage Gadget","Lumidigm Venus fingerprint sensor",
		"Cambridge Electronic Devices Power1401 mk 2","USB Clik! 40","(OME) PocketZip 40 MP3 Player Driver","GVC Bluetooth Wireless Adapter","Linux-USB \"Gadget Zero\"",
		"Linux-USB Ethernet Gadget","Linux-USB Ethernet/RNDIS Gadget","Linux-USB user-mode isochronous source/sink","Linux-USB user-mode bulk source/sink","Pocketbook Pro 903",
		"Linux-USB Serial Gadget","Linux-USB Serial Gadget (CDC ACM mode)","Linux-USB Printer Gadget","Linux-USB OBEX Gadget","Linux-USB CDC Composite Gadge (Ethernet and ACM)"
		};
		InsertProducts(0x0525, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7561,0x7562,0x7563,0x7564,0x7565,0x7566,0x7567,0x7568,0x7569,0x756a};
		char* mids[] = {"TV Wonder","TV Wonder, Edition (FN5)","TV Wonder, Edition (FI)","TV Wonder, Edition (FQ)","TV Wonder, Edition (NTSC+)",
		"TV Wonder, Edition (FN5)","TV Wonder, Edition (FI)","TV Wonder, Edition (FQ)","Live! Pro (A)","Live! Pro Audio (O)"
		};
		InsertProducts(0x0528, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x030b,0x0313,0x031b,0x0323,0x0412,0x041a,0x0422,0x042a,0x050c,0x0514,0x0600,0x0620};
		char* mids[] = {"HASP v0.06","eToken R1 v3.1.3.x","eToken R1 v3.2.3.x","eToken R1 v3.3.3.x","eToken R1 v3.4.3.x",
		"eToken R2 v2.2.4.x","eToken R2 v2.2.4.x","eToken R2 v2.4.4.x","eToken R2 v2.5.4.x","eToken Pro v4.1.5.x",
		"eToken Pro v4.2.5.4","eToken Pro 64k (4.2)","Token JC"};
		InsertProducts(0x0529, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0102,0x0801,0x1512,0x1513,0x1514,0x1905,0x1911,0x2202,0x2203,0x3a06,0xd001};
		char* mids[] = {"Ca508A HP1020 Camera v.1.3.1.6","Yakumo MegaImage 37","Yakumo MegaImage IV","Aosta CX100 Webcam","Aosta CX100 Webcam Storage",
		"Yakumo MegaImage 47","Yakumo MegaImage 47 SL","WDM Still Image Capture","Sound Vision Stream Driver","DigiLife DDV-5120A",
		"P35U Camera Capture"};
		InsertProducts(0x052b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x01a0};
		char* mids[] = {"PDT"};
		InsertProducts(0x0536, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0b00,0x0b01};
		char* mids[] = {"Hub","Preh MCI 3100"};
		InsertProducts(0x053a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"Panache Surf ISDN TA"};
		InsertProducts(0x0540, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00fe,0x00ff,0x0bf2,0x0bf3,0x0ed9,0x0f01,0x1527,0x1529,0x152b,0x152e,0x1921,0x1922,0x1923,0x1a11,0x1e60,0x4153};
		char* mids[] = {"G773 Monitor Hub","P815 Monitor Hub","airpanel V150 Wireless Smart Display","airpanel V110 Wireless Smart Display","Color Pocket PC V35",
		"airsync Wi-Fi Wireless Adapter","Color Pocket PC V36","Color Pocket PC V37","Color Pocket PC V38","Pocket PC",
		"Communicator Pocket PC","Smartphone","Pocket PC V30","Wireless 802.11g Adapter","TA310 - ATSC/NTSC/PAL Driver(PCM4)",
		"ViewSonic G773 Control (?)"};
		InsertProducts(0x0543, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7333,0x8002,0x8009,0x800c,0x800d,0x8080,0x808a,0x808b,0x808d,0x810a,0x810b,0x810c,0x8135,0x813a,0x813b,0x813c,0x8333,0x888c,0x888d};
		char* mids[] = {"Trution Web Camera","IBM NetCamera","Veo PC Camera","Veo Stingray","Veo PC Camera",
		"IBM C-It Webcam","Veo PC Camera","Veo Stingray","Veo PC Camera","Veo Advanced Connect Webcam",
		"Veo PC Camera","Veo PC Camera","Veo Mobile/Advanced Web Camera","Veo PC Camera","Veo PC Camera",
		"Veo Mobile/Advanced Web Camera","Veo Stingray/Connect Web Camera","eVision 123 digital camera","eVision 123 digital camera"};
		InsertProducts(0x0545, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0daf,0x1bed,0x3097,0x3155,0x3187,0x3191,0x3273,0x3304,0xdccf};
		char* mids[] = {"PDC 2300Z","PDC 1320 Camera","PDC 310","PDC 3070 Camera","Digital Camera",
		"Ion 80 Camera","PDC 2030 Camera","a500 Digital Camera","Sound Vision Stream Driver"};
		InsertProducts(0x0546, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x1002,0x1006,0x2131,0x2235,0x2710,0x2720,0x2727,0x2750,0x2810,0x4d90,0x7777,0x9999};
		char* mids[] = {"ICSI Bluetooth Device","Python2 WDM Encoder","Hantek DSO-2100 UF","AN2131 EZUSB Microcontroller","AN2235 EZUSB-FX Microcontroller",
		"EZ-Link Loader (EZLNKLDR.SYS)","AN2720 USB-USB Bridge","Xircom PGUNET USB-USB Bridge","EZ-Link (EZLNKUSB.SYS)","Cypress ATAPI Bridge",
		"AmScope MD1900 camera","Bluetooth Device","AN2131 uninitialized (?)"};
		InsertProducts(0x0547, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1005};
		char* mids[] = {"EZ Cart II GameBoy Flash Programmer"};
		InsertProducts(0x0548, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0010,0x0014,0x0022,0x0023,0x0024,0x0025,0x002b,0x002c,0x002d,0x002e,0x0030,0x0032,0x0035,0x0036,0x0037,0x0038,0x0039,0x003c,
		0x0045,0x0046,0x004a,0x004b,0x004e,0x0056,0x0058,0x0066,0x0067,0x0069,0x006c,0x006d,0x006f,0x0073,0x0075,0x0076,0x007c,0x007f,0x0080,0x0081,
		0x0084,0x0085,0x0086,0x008b,0x0095,0x0099,0x009a,0x00ab,0x00af,0x00bf,0x00c0,0x00c6,0x00c7,0x00c8,0x00c9,0x00ca,0x00cb,0x00da,0x00e8,0x00e9,
		0x00eb,0x0101,0x0103,0x0105,0x0107,0x0110,0x0113,0x0116,0x0144,0x0147,0x014c,0x014d,0x0154,0x015f,0x0169,0x016a,0x016b,0x016d,0x016e,0x0171,
		0x017e,0x017f,0x0180,0x0181,0x0182,0x0183,0x0184,0x0185,0x0186,0x0187,0x0188,0x018a,0x018b,0x019e,0x01ad,0x01bb,0x01bd,0x01c3,0x01c6,0x01c7,
		0x01c8,0x01c9,0x01d0,0x01d5,0x01de,0x01e8,0x01e9,0x01ea,0x01ee,0x01fa,0x01fb,0x020f,0x0210,0x0219,0x021a,0x021b,0x021c,0x021d,0x0227,0x022c,
		0x022d,0x0233,0x0236,0x023b,0x023c,0x023d,0x0243,0x024b,0x0257,0x0258,0x0259,0x0267,0x0268,0x0269,0x026a,0x0271,0x027c,0x027e,0x027f,0x0286,
		0x0287,0x0290,0x029b,0x02a5,0x02af,0x02c4,0x02d1,0x02d2,0x02e1,0x02ea,0x02f9,0x0317,0x031a,0x031e,0x0325,0x033e,0x0346,0x0348,0x035b,0x035c,
		0x035f,0x0382,0x0385,0x0387,0x03bc,0x03d1,0x03d3,0x03d5,0x03fc,0x03fd,0x042f,0x0440,0x0485,0x04cb,0x0541,0x0689,0x06bb,0x088c,0x1000};
		char* mids[] = {"HUB","Standard HUB","DSC-S30/S70/S75/F505V/F505/FD92/W1 Cybershot/Mavica Digital Camera","Nogatech USBVision (SY)","Storage Adapter V2 (TPP)",
		"CD Writer","Mavica CD-1000 Camera","NW-MS7 Walkman MemoryStick Reader","Portable USB Harddrive V2","USB Floppy Disk Drive",
		"MSAC-US1 MemoryStick Reader","HandyCam MemoryStick Reader","Storage Adapter V2 (TPP)","MemoryStick MSC-U01 Reader","Network Walkman (E)",
		"Net MD","MG Memory Stick Reader/Writer","Clie PEG-S300/D PalmOS PDA","Network Walkman (MS)","VAIO-MX LCD Control",
		"Digital Imaging Video","Network Walkman","Memory Stick Hi-Fi System","Memory Stick Reader/Writer","DSC-xxx (ptp)",
		"MG Memory Stick Reader/Writer","Clie PEG-N7x0C PalmOS PDA Mass Storage","Clie PEG-N7x0C/PEG-T425 PalmOS PDA Serial","CMR-PC3 Webcam","Memorystick MSC-U03 Reader",
		"FeliCa S310 [PaSoRi]","Clie PEG-T425 PDA Mass Storage","Network Walkman (EV)","Storage CRX1750U","Net MD",
		"Storage Adapter ACR-U20","Net MD","IC Recorder (MS)","Net MD","Net MD",
		"Net MD","Net MD","Net MD","Micro Vault 64M Mass Storage","Clie s360",
		"Clie NR70 PDA Mass Storage","Clie NR70 PDA Serial","Visual Communication Camera (PCGA-UVC10)","DPP-EX Series Digital Photo Printer","IC Recorder (S)",
		"Handycam DCR-30","Net MD","Net MD","MZ-N710 Minidisc Walkman","Net MD",
		"MZ-DN430 Minidisc Walkman","MSAC-US20 Memory Stick Reader","Clie nx60","Network Walkman (MS)","Handheld",
		"Net MD","Net MD","IC Recorder (ST)","Micro Vault Hub","VCC-U01 Visual Communication Camera",
		"Digital Imaging Video","Net MD","IC Recorder (P)","Clie PEG-TH55 PDA","Visual Communication Camera (PCGA-UVC11)",
		"Aiwa AM-NX9 Net MD Music Recorder MDLP","Memory Stick Reader/Writer","Eyetoy Audio Device","IC Recorder (BM)","Clie PEG-TJ35 PDA Serial",
		"Clie PEG-TJ35 PDA Mass Storage","Mobile HDD","IC Recorder (SX)","DPP-EX50 Digital Photo Printer","Fingerprint Sensor 3500",
		"Net MD","Hi-MD WALKMAN","Net MD","Hi-MD WALKMAN","Net MD",
		"Hi-MD WALKMAN","Net MD","Hi-MD WALKMAN","Net MD","Hi-MD MZ-NH600 WALKMAN",
		"Net MD","Net MD","Hi-MD SOUND GATE","Micro Vault 1.0G Mass Storage","ATRAC HDD PA",
		"FeliCa S320 [PaSoRi]","MRW62E Multi-Card Reader/Writer","NW-E55 Network Walkman","MEMORY P-AUDIO","Printing Support",
		"PSP Type A","PSP Type B","DVD+RW External Drive DRU-700A","IC RECORDER","VRD-VC10 [Video Capture]",
		"UP-DR150 Photo Printer","Net MD","Hi-MD WALKMAN","IC RECORDER","IC Recorder (P)",
		"NW-E405 Network Walkman","Device","ATRAC HDD PA","Net MD","Hi-MD WALKMAN",
		"Net MD","Hi-MD WALKMAN","Net MD","Printing Support","Net MD",
		"Hi-MD AUDIO","ATRAC HDD PA","Mobile HDD","DVD+RW External Drive DRU-800UL","Net MD",
		"Hi-MD WALKMAN","MicroVault Flash Drive","Vaio VGX Mouse","IFU-WLM2 USB Wireless LAN Module (Wireless Mode)","IFU-WLM2 USB Wireless LAN Module (Memory Mode)",
		"IC RECORDER","Tachikoma Device","Batoh Device / PlayStation 3 Controller","HDD WALKMAN","HDD WALKMAN",
		"IC Recorder (P)","NETWORK WALKMAN","SONY Communicator","IC RECORDER","Net MD",
		"Hi-MD WALKMAN","VGP-UVC100 Visual Communication Camera","PRS-500 eBook reader","MicroVault Flash Drive","Handycam DCR-DVD306E",
		"Device","DVD RW","PSP Slim","FeliCa S330 [PaSoRi]","PlayStation 3 Memory Card Adaptor",
		"DSC-H9","WALKMAN","Walkman NWD-B103F","PRS-300/PRS-505 eBook reader","NWZ-A818",
		"DSC-W120/W290","Handycam DCR-SR55E","HandyCam HDR-TG3E","Walkman NWZ-A828","NWZ-A726/A728/A729",
		"UP-DR200 Photo Printer","Memory Stick PRO-HG Duo Adaptor (MSAC-UAH1)","Walkman NWZ-E436F","IC Recorder (P)","Webbie HD - MHS-CM1",
		"DPF-X95","DR-BT100CX","PlayStation Move motion controller","WALKMAN [NWZ-E345]","Walkman NWZ-E443",
		"PlayStation Move navigation controller","DSC-H55","MHS-PM5 HD camcorder","WALKMAN NWZ-E354","DSC-HX100V [Cybershot Digital Still Camera]",
		"Walkman NWZ-B173F","WALKMAN NWZ-F805","Portable Headphone Amplifier","Wireless Buzz! Receiver"};
		InsertProducts(0x054c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0004,0x0005,0x000b,0x014e};
		char* mids[] = {"InkJet Color Printer","InkJet Color Printer","InkJet Color Printer","Workcentre 24","CM215b Printer"
		};
		InsertProducts(0x0550, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0100,0x0140,0x0150,0x0151,0x0200,0x0201,0x0202,0x0674,0x0679,0x1002};
		char* mids[] = {"TerraCAM","CPiA Webcam","STV0672 Camera","Video Camera","CDE CAM 100",
		"Digital Blue QX5 Microscope","Dual-mode Camera0","Dual-mode Camera1","STV0680 Camera","Multi-mode Camera",
		"NMS Video Camera (Webcam)","Che-ez! Splash"};
		InsertProducts(0x0553, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"AK5370 I/F A/D Converter"};
		InsertProducts(0x0556, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2001,0x2002,0x2004,0x2006,0x2007,0x2008,0x2009,0x2011,0x2202,0x2213,0x2221,0x2404,0x2600,0x2701,0x4000,0x7000,0x7820,0x8021};
		char* mids[] = {"UC-1284 Printer Port","10Mbps Ethernet [klsi]","UC-100KM PS/2 Mouse and Keyboard adapter","UC-1284B Printer Port","UC-110T 100Mbps Ethernet [pegasus]",
		"UC-232A Serial Port [pl2303]","UC-210T Ethernet","UC-2324 4xSerial Ports [mos7840]","CS124U Miniview II KVM Switch","CS682 2-Port USB 2.0 DVI KVM Switch",
		"Winbond Hermon","4-port switch","IDE Bridge","CE700A KVM Extender","DSB-650 10Mbps Ethernet [klsi]",
		"Hub","UC-2322 2xSerial Ports [mos7820]","CS1764A [CubiQ DVI KVMP Switch]"};
		InsertProducts(0x0557, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1009,0x100a,0x2009};
		char* mids[] = {"GW Instek GDS-1000 Oscilloscope","GW Instek GDS-1000A Oscilloscope","GW Instek GDS-2000 Oscilloscope"};
		InsertProducts(0x0558, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0bb1,0x1030,0x1031,0x1040,0x1050,0x1080,0x2020,0x6780,0x6781,0x8001,0x9000,0x9001,0xa000,0xa010,0xa011,0xa012,0xa013,0xa230,0xb000,
		0xb230,0xb231};
		char* mids[] = {"Keyboard","Bluetooth Device","Optical Wheel Mouse (OMS3CB/OMGB30)","Optical Wheel Mouse (OMA3CB/OMGI30)","Mouse HID Device",
		"E-Mail Optical Wheel Mouse (OMS3CE)","Optical Wheel Mouse (OMS3CH)","Floppy Disk Drive","Keyboard V1","Keyboard Mouse",
		"E.M. Hub","AnyCam [pwc]","MPC-C30 AnyCam Premium for Notebooks [pwc]","SWL-2100U","WLAN Adapter(SWL-2300)",
		"Boot Device","WLAN Adapter(SWL-2300)","WLAN Adapter(SWL-2350)","Boot Device","11Mbps WLAN Mini Adapter",
		"Netopia 802.11b WLAN Adapter","LG Wireless LAN 11b Adapter"};
		InsertProducts(0x055d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0006,0x0007,0x0008,0x0010,0x0210,0x0218,0x0219,0x021a,0x021b,0x021c,0x021d,0x021e,0x021f,0x0400,0x0401,0x0408,0x0409,
		0x040b,0x0873,0x1000,0xa350,0xa800,0xb500,0xc005,0xc200,0xc211,0xc220,0xc230,0xc232,0xc360,0xc420,0xc430,0xc440,0xc520,0xc530,0xc540,0xc630,
		0xc631,0xc650,0xd001,0xd003,0xd004};
		char* mids[] = {"ScanExpress 1200 CU","ScanExpress 600 CU","ScanExpress 1200 USB","ScanExpress 1200 UB","ScanExpress 1200 USB Plus",
		"ScanExpress 1200 CU Plus","BearPaw 1200F","ScanExpress A3 USB","BearPaw 2400 TA","BearPaw 2400 TA Plus",
		"BearPaw 2448 TA Plus","BearPaw 1200 CU Plus","BearPaw 1200 CU Plus","BearPaw 2400 CU Plus","BearPaw 1200 TA/CS",
		"SNAPSCAN e22","BearPaw 2400 TA Pro","P 3600 A3 Pro","BearPaw 2448 CU Pro","BearPaw 2448 TA Pro",
		"ScanExpress A3 USB 1200 PRO","ScanExpress 600 USB","BearPaw 4800 TA Pro","gSmart 350 Camera","MDC 800 Camera",
		"MDC 3000 Camera","PC CAM 300A","gSmart 300","Kowa Bs888e Microcamera","gSmart mini",
		"Digicam 330K","MDC3500 Camera","DV 4000 Camera","gSmart mini 2 Camera","gSmart LCD 2 Camera",
		"DV 3000 Camera","gSmart mini 3 Camera","gSmart LCD 2 Camera","gSmart D30 Camera","MDC 4000 Camera",
		"MDC 4000 Camera","MDC 5500Z Camera","WCam 300","WCam 300A","WCam 300AN"
		};
		InsertProducts(0x055f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"Enhanced Microphone","Telex Microphone"};
		InsertProducts(0x0562, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0005,0x0041};
		char* mids[] = {"Serial Port [etek]","Enet Ethernet [klsi]","@Home Networks Ethernet [klsi]","Enet2 Ethernet [klsi]","Peracom Remote NDIS Ethernet Adapter"
		};
		InsertProducts(0x0565, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0110,0x1001,0x1002,0x1003,0x1004,0x1005,0x1006,0x1007,0x2800,0x2801,0x2802,0x3004,0x3107};
		char* mids[] = {"ViewMate Desktop Mouse CC2201","ViewMate Desktop Mouse CC2201","ViewMate Desktop Mouse CC2201","ViewMate Desktop Mouse CC2201","ViewMate Desktop Mouse CC2201",
		"ViewMate Desktop Mouse CC2201","ViewMate Desktop Mouse CC2201","ViewMate Desktop Mouse CC2201","MIC K/B","MIC K/B Mouse",
		"Kbd Hub","Genius KB-29E","Keyboard"};
		InsertProducts(0x0566, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0001,0x0002,0x0003,0x0010,0x0011,0x0012,0x0013,0x0014,0x0015,0x0016,0x0017,0x0018,0x0019,0x0020,0x0021,0x0022,0x0023,0x0024,0x0026,
		0x0027,0x0028,0x0029,0x002a,0x0030,0x0031,0x0032,0x0033,0x0034,0x0035,0x0037,0x0038,0x0039,0x003f,0x0041,0x0042,0x0043,0x0044,0x0045,0x0047,
		0x0060,0x0061,0x0062,0x0063,0x0064,0x0065,0x0069,0x0081,0x0084,0x0090,0x0093,0x009a,0x00b0,0x00b1,0x00b2,0x00b3,0x00b4,0x00b5,0x00b7,0x00b8,
		0x00b9,0x00ba,0x00bb,0x00c0,0x00c4,0x00c5,0x00c6,0x00c7,0x00cc,0x00d1,0x00d3,0x00d4,0x00d6,0x00db,0x00dd,0x00de,0x00f6,0x00f8,0x0307,0x0309,
		0x0400,0x4850};
		char* mids[] = {"PenPartner","PenPartner 4x5","PenPartner 6x8","Cintiq Partner","Graphire",
		"Graphire 2 4x5","Graphire 2 5x7","Graphire 3 4x5","Graphire 3 6x8","Graphire 4 4x5",
		"Graphire 4 6x8","CTE-450 [Bamboo Fun]","Bamboo Fun 6x8","Bamboo One Medium","Intuos 4x5",
		"Intuos 6x8","Intuos 9x12","Intuos 12x12","Intuos 12x18","Intuos5 touch S",
		"Intuos5 touch M","Intuos5 touch L","Intuos5 S","Intuos5 M","PL400",
		"PL500","PL600","PL600SX","PL550","PL800",
		"PL700","PL510","DTU-710","Cintiq 21UX (DTZ-2100)","Intuos2 4x5",
		"Intuos2 6x8","Intuos2 9x12","Intuos2 12x12","Intuos2 12x18","Intuos2 6x8",
		"Volito","PenStation2","Volito2 4x5","Volito2 2x3","PenPartner2",
		"Bamboo","Bamboo One","Graphire Wireless 6x8","Wireless adapter for Bamboo tablets","TPC90",
		"TPC93","TPC9A","Intuos3 4x5","Intuos3 6x18","Intuos3 9x12",
		"Intuos3 12x12","Intuos3 12x19","Intuos3 6x11 (PTZ-631W)","Intuos3 4x6","Intuos4 4x6",
		"Intuos4 6x9","Intuos4 8x13","Intuos4 12x19","DTF-521","DTF-720",
		"Cintiq 20WSX","Cintiq 12WX","DTU-1931","Cintiq 21UX (DTK-2100)","Bamboo Pen & Touch (CTH-460-DE)",
		"Bamboo Fun (CTH-661)","Bamboo Pen (CTL-460)","Bamboo Pen & Touch (CTH-460)","Bamboo Fun (CTH-661SE-NL)","Bamboo Pen (CTL-470)",
		"CTH-470 [Bamboo Fun Pen & Touch]","Cintiq 24HD touch (DTH-2400) touchscreen","Cintiq 24HD touch (DTH-2400) tablet","Cintiq Companion Hybrid 13HD (DTH-A1300) tablet","Cintiq Companion Hybrid 13HD (DTH-A1300) touchscreen",
		"PenPartner 4x5","PenPartner 6x8"};
		InsertProducts(0x056a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0006,0x8007,0x8100,0x8101};
		char* mids[] = {"KwikLink Host-Host Connector","Kwik232 Serial Port","KwikLink Host-Host Connector","KwikLink USB-USB Bridge"};
		InsertProducts(0x056c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0001,0x0002,0x0003};
		char* mids[] = {"Hub","Monitor","HID Monitor Controls","Device Bay Controller"};
		InsertProducts(0x056d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0072,0x200c,0x4002,0x4005,0x400b,0x4010,0x5003,0x5004,0x6008,0xabc1};
		char* mids[] = {"29UO Mouse","Mouse","LD-USB/TX","Laneed 100Mbps Ethernet LD-USB/TX [pegasus]","LD-USBL/TX",
		"LD-USB/TX","LD-USB20","UC-SGT","UC-SGT","Flash Disk",
		"LD-USB/TX"};
		InsertProducts(0x056e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xcd00};
		char* mids[] = {"CDM-751 CD organizer"};
		InsertProducts(0x056f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"echoFX InterView Lite"};
		InsertProducts(0x0571, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0040,0x0041,0x0042,0x1232,0x1234,0x1252,0x1253,0x1300,0x1301,0x1328,0x2000,0x2002,0x262a,0x8390,0x8392,0xcafc,0xcafe,0xcb00,
		0xcb01,0xcb06};
		char* mids[] = {"Ezcam II Webcam","Ezcam II Webcam","Wondereye CP-115 Webcam","Webcam Notebook","Webcam Notebook",
		"V.90 modem","Typhoon Redfun Modem V90 56k","HCF V90 Data Fax Voice Modem","Zoom V.92 Faxmodem","SoftK56 Data Fax Voice CARP",
		"Modem Enumerator","TrendNet TFM-561 modem","SoftGate 802.11 Adapter","SoftGate 802.11 Adapter","tm5600 Video & Audio Grabber Capture",
		"WinFast PalmTop/Novo TV Video","WinFast PalmTop/Novo TV Video","CX861xx ROM Boot Loader","AccessRunner ADSL Modem","ADSL Modem",
		"ADSL Modem","StarModem Network Interface"};
		InsertProducts(0x0572, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0400,0x0600,0x1300,0x2000,0x2001,0x2101,0x2d00,0x2d01,0x3000,0x3001,0x4000,0x4001,0x4002,0x4003,0x4008,0x4009,0x4010,0x4100,0x4110,
		0x4400,0x4401,0x4450,0x4451,0x4452,0x4500,0x4501,0x4550,0x4551,0x4d00,0x4d01,0x4d02,0x4d03,0x4d04,0x4d10,0x4d11,0x4d12,0x4d14,0x4d20,0x4d21,
		0x4d22,0x4d23,0x4d24,0x4d25,0x4d26,0x4d27,0x4d28,0x4d29,0x4d2a,0x4d2b,0x4d2c,0x4d30,0x4d31,0x4d32,0x4d34,0x4d35,0x4d36,0x4d37,0x4d38};
		char* mids[] = {"USBGear USBG-V1","D-Link V100","Dazzle USBVision (1006)","leadtek USBVision (1006)","X10 va10a Wireless Camera",
		"Dazzle EmMe (2001)","Zoran Co. PMD (Nogatech) AV-grabber Manhattan","Osprey 50","Hauppauge USB-Live Model 600","Dazzle MicroCam (NTSC)",
		"Dazzle MicroCam (PAL)","Nogatech TV! (NTSC)","Nogatech TV! (PAL)","Nogatech TV! (PAL-I-)","Nogatech TV! (MF-)",
		"Nogatech TV! (NTSC) (T)","Nogatech TV! (PAL) (T)","Nogatech TV! (NTSC) (A)","USB-TV FM (NTSC)","PNY USB-TV (NTSC) FM",
		"Nogatech TV! Pro (NTSC)","Nogatech TV! Pro (PAL)","PixelView PlayTv-USB PRO (PAL) FM","Nogatech TV! Pro (PAL+)","Nogatech TV! Pro (PAL-I+)",
		"Nogatech TV! Pro (NTSC)","Nogatech TV! Pro (PAL)","ZTV ZT-721 2.4GHz A/V Receiver","Dazzle TV! Pro Audio (P+)","Hauppauge WinTV-USB USA",
		"Hauppauge WinTV-USB","Hauppauge WinTV-USB UK","Hauppauge WinTV-USB France","Hauppauge WinTV (PAL D/K)","Hauppauge WinTV-USB with FM USA radio",
		"Hauppauge WinTV-USB (PAL) with FM radio","Hauppauge WinTV-USB UK with FM Radio","Hauppauge WinTV (PAL D/K FM)","Hauppauge WinTV-USB II (PAL) with FM radio","Hauppauge WinTV-USB II (PAL)",
		"Hauppauge WinTV-USB II (PAL) Model 566","Hauppauge WinTV-USB France 4D23","Hauppauge WinTV Pro (PAL D/K)","Hauppauge WinTV-USB Model 40209 rev B234","Hauppauge WinTV-USB Model 40209 rev B243",
		"Hauppauge WinTV-USB Model 40204 Rev B281","Hauppauge WinTV-USB Model 40204 rev B283","Hauppauge WinTV-USB Model 40205 rev B298","Hauppague WinTV-USB Model 602 Rev B285","Hauppague WinTV-USB Model 602 Rev B282",
		"Hauppauge WinTV Pro (PAL/SECAM)","Hauppauge WinTV-USB FM Model 40211 Rev B123","Hauppauge WinTV-USB III (PAL) with FM radio Model 568","Hauppauge WinTV-USB III (PAL) FM Model 573","Hauppauge WinTV Pro (PAL D/K FM)",
		"Hauppauge WinTV-USB III (PAL) FM Model 597","Hauppauge WinTV Pro (PAL B/G FM)","Hauppauge WinTV-USB Model 40219 rev E189","Hauppauge WinTV Pro (NTSC FM)"};
		InsertProducts(0x0573, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0001,0x0006,0x0010,0x0020,0x0030};
		char* mids[] = {"FlashBuster-U Floppy","Tri-Media Reader Floppy","Tri-Media Reader Card Reader","Memory Stick Reader Writer","HEXA Media Drive 6-in-1 Card Reader Writer",
		"Memory Card Viewer (TV)"};
		InsertProducts(0x057b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0b00,0x0c00,0x1000,0x1900,0x2000,0x2200,0x2300,0x2800,0x3200,0x3500,0x3701,0x3702,0x3800,0x3a00,0x3c00,0x3d00,0x3e01,0x4001,0x4101,0x4201,
		0x4601,0x4602,0x4701,0x5401,0x5601,0x6201,0x62ff,0x8401,0x8402,0x8403,0x84ff};
		char* mids[] = {"ISDN-Controller B1 Family","ISDN-Controller FRITZ!Card","ISDN-Controller FRITZ!Card v2.0","ISDN-Controller FRITZ!Card v2.1","ISDN-Connector FRITZ!X",
		"BlueFRITZ!","Teledat X130 DSL","ISDN-Connector TA","Teledat X130 DSL","FRITZ!Card DSL SL",
		"FRITZ!Box SL","FRITZ!Box","BlueFRITZ! Bluetooth Stick","FRITZ!Box Fon","FRITZ!Box WLAN",
		"Fritz!Box","FRITZ!Box (Annex A)","FRITZ!Box Fon (Annex A)","FRITZ!Box WLAN (Annex A)","FRITZ!Box Fon WLAN (Annex A)",
		"Eumex 5520PC (WinXP/2000)","Eumex 400 (WinXP/2000)","AVM FRITZ!Box Fon ata","Eumex 300 IP","AVM Fritz!WLAN [Texas Instruments TNETW1450]",
		"AVM Fritz!WLAN v1.1 [Texas Instruments TNETW1450]","AVM Fritz!WLAN USB (in CD-ROM-mode)","Fritz!WLAN N [Atheros AR9001U]","Fritz!WLAN N 2.4 [Atheros AR9001U]","Fritz!WLAN N v2 [Atheros AR9271]",
		"AVM Fritz!WLAN USB N (in CD-ROM-mode)"};
		InsertProducts(0x057c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0305,0x0306};
		char* mids[] = {"Broadcom BCM2045A Bluetooth Radio [Nintendo Wii]","Wii Remote Controller RVL-003"};
		InsertProducts(0x057e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6238};
		char* mids[] = {"USB StrikePad"};
		InsertProducts(0x057f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0002,0x0003,0x0004,0x0005,0x0007,0x0008,0x0009,0x000b,0x000c,0x0010,0x0011,0x0012,0x0013,0x0014,0x0015,0x0016,0x0017,0x0018,0x001b,
		0x001c,0x001d,0x001e,0x0023,0x0024,0x0025,0x0026,0x0027,0x0028,0x0029,0x002a,0x002b,0x002c,0x002d,0x002e,0x002f,0x0030,0x0033,0x0034,0x0035,
		0x0037,0x0038,0x003b,0x003c,0x0040,0x0041,0x0042,0x0043,0x0044,0x0047,0x0048,0x0049,0x004a,0x004b,0x004c,0x004d,0x004e,0x004f,0x0050,0x0052,
		0x0054,0x0060,0x0064,0x0065,0x0066,0x0067,0x006a,0x006b,0x006d,0x006e,0x0073,0x0074,0x0075,0x0076,0x007a,0x007b,0x007d,0x0080,0x0081,0x0084,
		0x0089,0x008b,0x008c,0x008d,0x0092,0x0093,0x0096,0x009a,0x009d,0x00a0,0x00a2,0x00a3,0x00a6,0x00a9,0x00ad,0x00b2,0x00b3,0x00b7,0x00c2,0x00c4,
		0x00c5,0x00c7,0x00d1,0x00d3,0x00da,0x00db,0x00dc,0x00de,0x00e6,0x00e7,0x00e9,0x00eb,0x00f6,0x00f8,0x00fc,0x00fd,0x00fe,0x00ff,0x0100,0x0101,
		0x0102,0x0104,0x0106,0x0108,0x0109,0x010d,0x010f,0x0110,0x0111,0x0113,0x0114,0x0116,0x0117,0x0119,0x011c,0x011e,0x0120,0x0121,0x0123,0x0124,
		0x0127,0x012a,0x012b,0x012f,0x0130,0x0132,0x0134,0x0138,0x0139,0x013a,0x013e,0x0145,0x014b,0x014d,0x0150,0x0151,0x0154,0x0156,0x0158,0x0159,
		0x015b,0x015d,0x0505};
		char* mids[] = {"UA-100(G)","UM-4/MPU-64 MIDI Interface","SoundCanvas SC-8850","U-8","UM-2(C/EX)",
		"SoundCanvas SC-8820","PC-300","UM-1(E/S/X)","SK-500","SC-D70",
		"EDIROL UA-5","Edirol UA-5 Sound Capture","XV-5050","XV-5050","EDIROL UM-880 MIDI I/F (native)",
		"EDIROL UM-880 MIDI I/F (generic)","EDIROL SD-90","EDIROL SD-90","UA-1A","MMP-2",
		"MMP-2","V-SYNTH","V-SYNTH","EDIROL UM-550","EDIROL UM-550",
		"EDIROL UA-20","EDIROL UA-20","EDIROL SD-20","EDIROL SD-20","EDIROL SD-80",
		"EDIROL SD-80","EDIROL UA-700","EDIROL UA-700","XV-2020 Synthesizer","XV-2020 Synthesizer",
		"VariOS","VariOS","EDIROL PCR","EDIROL PCR","M-1000",
		"Digital Piano","Digital Piano","BOSS GS-10","BOSS GS-10","GI-20",
		"GI-20","RS-70","RS-70","EDIROL UA-1000","EDIROL UR-80 WAVE",
		"EDIROL UR-80 MIDI","EDIROL UR-80 WAVE","EDIROL UR-80 MIDI","EDIROL M-100FX","EDIROL PCR-A WAVE",
		"EDIROL PCR-A MIDI","EDIROL PCR-A WAVE","EDIROL PCR-A MIDI","EDIROL UA-3FX","EDIROL UM-1SX",
		"Digital Piano","EXR Series","EDIROL PCR-1 WAVE","EDIROL PCR-1 MIDI","EDIROL PCR-1 WAVE",
		"EDIROL PCR-1 MIDI","SP-606","SP-606","FANTOM-X","FANTOM-X",
		"EDIROL UA-25","EDIROL UA-25","BOSS DR-880","BOSS DR-880","RD",
		"RD","EDIROL UA-101","G-70","G-70","V-SYNTH XT",
		"BOSS GT-PRO","EDIROL PC-50","EDIROL PC-50","EDIROL UA-101 USB1","EDIROL PC-80 WAVE",
		"EDIROL PC-80 MIDI","EDIROL UA-1EX","EDIROL UM-3EX","EDIROL UM-1","MD-P1",
		"Digital Piano","EDIROL UA-4FX","Juno-G","MC-808","SH-201",
		"VG-99","VG-99","BK-7m/VIMA JM-5/8","SonicCell","EDIROL M-16DX",
		"SP-555","V-Synth GT","Music Atelier","M-380/400","BOSS GT-10",
		"BOSS GT-10 Guitar Effects Processor","BOSS GT-10B","Fantom G","EDIROL UA-25EX (Advanced mode)","EDIROL UA-25EX",
		"UA-1G","VS-100","GW-8/AX-Synth","JUNO Series","VS-700C",
		"VS-700","VS-700 M1","VS-700 M2","VS-700","VS-700 M2",
		"VB-99","UM-1G","UM-2G","UM-3G","eBand JS-8",
		"A-500S","A-PRO","A-PRO","GAIA SH-01","ME-25",
		"SD-50","WAVE/MP3 RECORDER R-05","VS-20","OCTAPAD SPD-30","Lucina AX-09",
		"BR-800","OCTA-CAPTURE","OCTA-CAPTURE","JUNO-Gi","M-300",
		"GR-55","UM-ONE","DUO-CAPTURE","QUAD-CAPTURE","MICRO BR BR-80",
		"TRI-CAPTURE","V-Mixer","Boss RC-300 (Audio mode)","Boss RC-300 (Storage mode)","JUPITER-80",
		"R-26","SPD-SX","eBand JS-10","GT-100","TD-15",
		"TD-11","JUPITER-50","A-Series","TD-30","DUO-CAPTURE EX",
		"INTEGRA-7","R-88","EDIROL UA-101"};
		InsertProducts(0x0582, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x2030,0x2031,0x2032,0x2033,0x2050,0x205f,0x206f,0x3050,0x3379,0x337f,0x509f,0x5259,0x525f,0x5308,0x5359,0x535f,0x5659,0x565f,
		0x6009,0x600f,0x6258,0x6889,0x688f,0x7070,0xa000,0xa015,0xa019,0xa020,0xa021,0xa022,0xa023,0xa024,0xa025,0xa130,0xa131,0xa132,0xa133,0xa202,
		0xa209,0xb000,0xb001,0xb002,0xb005,0xb008,0xb009,0xb00a,0xb00b,0xb00c,0xb00d,0xb00e,0xb00f,0xb010,0xb012,0xb013,0xb016,0xb018,0xff60};
		char* mids[] = {"4 Axis 12 button +POV","4 Axis 12 button +POV","RM-203 USB Nest [mode 1]","RM-203 USB Nest [mode 2]","RM-203 USB Nest [mode 3]",
		"RM-203 USB Nest [mode 4]","PX-205 PSX Bridge","PSX/USB converter","USB, 2-axis 8-button gamepad","QF-305u Gamepad",
		"Rockfire X-Force","Rockfire USB RacingStar Vibra","USB,4-Axis,12-Button with POV","Rockfire USB SkyShuttle Vibra","USB Vibration Pad",
		"USB Wireless VibrationPad","Rockfire USB SkyShuttle Pro","USB,real VibrationPad","Rockfire USB SkyShuttle Vibra","USB VibrationPad",
		"Revenger","USB,GameBoard II","USB, 4-axis, 6-button joystick w/view finder","Windstorm Pro","QF-688uv Windstorm Pro Joystick",
		"QF-707u Bazooka Joystick","MaxFire G-08XU Gamepad","4-Axis,16-Button with POV","USB, Vibration ,4-axis, 8-button joystick w/view finder","USB,4-Axis,10-Button with POV",
		"USB,4-Axis,12-Button with POV","USB,4-Axis,14-Button with POV","USB,4-Axis,16-Button with POV","4axis,12button vibrition audio gamepad","4axis,12button vibrition audio gamepad",
		"USB Wireless 2.4GHz Gamepad","USB Wireless 2.4GHz Joystick","USB Wireless 2.4GHz Wheelpad","USB Wireless 2.4GHz Wheel&Gamepad","ForceFeedbackWheel",
		"MetalStrike FF","USB,4-Axis,12-Button with POV","USB,4-Axis,12-Button with POV","Vibration,12-Button USB Wheel","USB,12-Button Wheel",
		"USB Wireless 2.4GHz Wheel","USB,12-Button  Wheel","PSX/USB converter","PSX/USB converter","PSX/USB converter",
		"PSX/USB converter","4-Axis,12-Button with POV","USB,5-Axis,10-Button with POV","MetalStrike Pro","Wireless MetalStrike",
		"USB,Wiress  2.4GHZ Joystick","USB,5-Axis,10-Button with POV","TW6 Wheel","USB Wireless VibrationPad"};
		InsertProducts(0x0583, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0008,0x0220,0xb000,0xb020};
		char* mids[] = {"Fujifilm MemoryCard ReaderWriter","U2SCX SCSI Converter","REX-USB60","REX-USB60F"};
		InsertProducts(0x0584, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0009,0x000a,0x000b,0x000c,0x000d,0x000e,0x000f};
		char* mids[] = {"Digital Camera","Digital Camera","Digital Camera","Digital Camera","Digital Camera",
		"Digital Camera","Digital Camera","Digital Camera","Digital Camera","Digital Camera",
		"Digital Camera","Digital Camera","Digital Camera","Digital Camera","Digital Camera"
		};
		InsertProducts(0x0585, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0025,0x0102,0x1000,0x1500,0x2011,0x3304,0x3309,0x330a,0x330e,0x3400,0x3401,0x3402,0x3403,0x3407,0x3408,0x3409,0x340a,0x340c,0x340f,0x3410,
		0x3412,0x3413,0x3415,0x3416,0x3417,0x3418,0x3419,0x341a,0x341e,0x341f,0x3425,0x343e};
		char* mids[] = {"802.11b/g/n USB Wireless Network Adapter","omni.net II ISDN TA","Omni NET Modem / ISDN TA","Omni 56K Plus","Scorpion-980N keyboard",
		"LAN Modem","ADSL Modem Prestige 600 series","ADSL Modem Interface","USB Broadband ADSL Modem Rev 1.10","ZyAIR B-220 IEEE 802.11b Adapter",
		"ZyAIR G-220 802.11bg","ZyAIR G-220F 802.11bg","AG-200 802.11abg Wireless Adapter [Atheros AR5523]","G-200 v2 802.11bg","G-260 802.11bg",
		"AG-225H 802.11bg","M-202 802.11bg","G-270S 802.11bg Wireless Adapter [Atheros AR5523]","G-220 v2 802.11bg","ZyAIR G-202 802.11bg",
		"802.11bg","ZyAIR AG-225H v2 802.11bg","G-210H 802.11g Wireless Adapter","NWD-210N 802.11b/g/n-draft wireless adapter","NWD271N 802.11n Wireless Adapter [Atheros AR9001U-(2)NG]",
		"NWD211AN 802.11abgn Wireless Adapter [Ralink RT2870]","G-220 v3 802.11bg Wireless Adapter [ZyDAS ZD1211B]","NWD-270N Wireless N-lite USB Adapter","NWD2105 802.11bgn Wireless Adapter [Ralink RT3070]","NWD2205 802.11n Wireless N Adapter [Realtek RTL8192CU]",
		"NWD6505 802.11a/b/g/n/ac Wireless Adapter [MediaTek MT7610U]","N220 802.11bgn Wireless Adapter"};
		InsertProducts(0x0586, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0015,0x001c,0x0041};
		char* mids[] = {"Flash Loader utility","Flash Drive","Flash Loader utility"};
		InsertProducts(0x058b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0007,0x0008,0x000a,0x0010,0x0011,0x0012,0x0013,0x0014,0x0015,0x0016,0x0017,0x0018,0x0019,0x001a,0x001b,0x001c,0x001d,0x001e,0x001f,0xffe5
		};
		char* mids[] = {"Flash","LP130","LP530","Projector","Projector",
		"Projector","Projector","Projector","Projector","Projector",
		"Projector","Projector","Projector","Projector","Projector",
		"Projector","Projector","Projector","Projector","IN34 Projector"
		};
		InsertProducts(0x058c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1234,0x2412,0x2802,0x5492,0x6232,0x6254,0x6331,0x6332,0x6335,0x6360,0x6361,0x6362,0x6364,0x6366,0x6377,0x6386,0x6387,0x6390,0x9213,0x9215,
		0x9254,0x9310,0x9320,0x9321,0x9330,0x9331,0x9340,0x9350,0x9360,0x9361,0x9368,0x9380,0x9382,0x9384,0x9410,0x9472,0x9510,0x9520,0x9540,0x9720,
		0xa014,0xb002};
		char* mids[] = {"Flash Drive","SCard R/W CSR-145","Monterey Keyboard","Hub","Hi-Speed 16-in-1 Flash Card Reader/Writer",
		"USB Hub","SD/MMC/MS Card Reader","Multi-Function Card Reader","SD/MMC Card Reader","Multimedia Card Reader",
		"Multimedia Card Reader","Flash Card Reader/Writer","AU6477 Card Reader Controller","Multi Flash Reader","AU6375 4-LUN card reader",
		"Memory Card","Flash Drive","USB 2.0-IDE bridge","MacAlly Kbd Hub","AU9814 Hub",
		"Hub","Mass Storage (UID4/5A & UID7A)","Micro Storage Driver for Win98","Micro Storage Driver for Win98","SD Reader",
		"Micro Storage Driver for Win98","Delkin eFilm Reader-32","Delkin eFilm Reader-32","8-in-1 Media Card Reader","Multimedia Card Reader",
		"Multimedia Card Reader","Flash Drive","Acer/Sweex Flash drive","qdi U2Disk T209M","Keyboard",
		"Keyboard Hub","ChunghwaTL USB02 Smartcard Reader","EMV Certified Smart Card Reader","AU9540 Smartcard Reader","USB-Serial Adapter",
		"Asus Integrated Webcam","Acer Integrated Webcam"};
		InsertProducts(0x058f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004,0x000b,0x0028};
		char* mids[] = {"Cable Modem","MR56SVS","HJ-720IT / HEM-7080IT-E / HEM-790IT"};
		InsertProducts(0x0590, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"UPS (X-Slot)"};
		InsertProducts(0x0592, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001,0x2002,0x4343};
		char* mids[] = {"Digitrex DSC-1300/DSC-2100 (mass storage mode)","DIGITAL STILL CAMERA 6M 4X","Digital Camera EX-20 DSC"};
		InsertProducts(0x0595, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0500,0x0543};
		char* mids[] = {"Touchscreen","Touch Screen Controller","PCT Multitouch HID Controller","DELL XPS touchscreen"};
		InsertProducts(0x0596, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x000b,0x0021,0x0030,0x0031,0x0032,0x0034,0x0037,0x0040,0x0042,0x0050,0x0053,0x0056,0x0057,0x005d,0x005f,0x0060,0x0061,0x006d,0x0070,
		0x007c,0x007d,0x007e,0x00db,0x0150,0x015d,0x0173,0x0174,0x0176,0x0177,0x0178,0x0179,0x017a,0x017b,0x017c,0x0251,0x0252,0x0278,0x027a,0x0470,
		0x047a,0x0571,0x0579,0x1052};
		char* mids[] = {"Zip 100 (Type 1)","Zip 100 (Type 2)","Win98 Disk Controller","Zip 250 (Ver 1)","Zip 100 (Type 3)",
		"Zip 250 (Ver 2)","Zip 100 Driver","Zip 750 MB","SCSI Bridge","Rev 70 GB",
		"Zip CD 650 Writer","CDRW55292EXT CD-RW External Drive","External CD-RW Drive Enclosure","Mass Storage Device","Mass Storage Device",
		"CDRW64892EXT3-C CD-RW 52x24x52x External Drive","PCMCIA PocketZip Dock","Varo PocketZip 40 MP3 Player","HipZip MP3 Player","eGo Portable Hard Drive",
		"Ultra Max USB/1394","HTC42606 0G9AT00 [Iomega HDD]","Mini 256MB/512MB Flash Drive [IOM2D5]","FotoShow Zip 250 Driver","Mass Storage Device",
		"Super DVD Writer","Hi-Speed USB-to-IDE Bridge Controller","Hi-Speed USB-to-IDE Bridge Controller","Hi-Speed USB-to-IDE Bridge Controller","Hi-Speed USB-to-IDE Bridge Controller",
		"Hi-Speed USB-to-IDE Bridge Controller","Hi-Speed USB-to-IDE Bridge Controller","HDD","HDD/1394A","HDD/1394B",
		"Optical","Optical","LDHD-UPS [Professional Desktop Hard Drive eSATA / USB2.0]","LPHD250-U [Portable Hard Drive Silver Series 250 Go]","Prestige Portable Hard Drive",
		"Select Portable Hard Drive","Prestige Portable Hard Drive","eGo Portable Hard Drive","DVD+RW External Drive"};
		InsertProducts(0x059b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0201,0x0202,0x0203,0x0211,0x0212,0x0213,0x0323,0x0421,0x0525,0x0641,0x0829,0x100c,0x1010,0x1019,0x1021,0x1027,0x102a,0x1049,0x1052,0x1064,
		0xa601,0xa602};
		char* mids[] = {"StudioDrive USB2","StudioDrive USB2","StudioDrive USB2","PocketDrive","PocketDrive",
		"PocketDrive USB2","LaCie d2 Drive USB2","Big Disk G465","BigDisk Extreme 500","Mobile Hard Drive",
		"BigDisk Extreme+","Rugged Triple Interface Mobile Hard Drive","Desktop Hard Drive","Desktop Hard Drive","Little Disk",
		"iamaKey V2","Rikiki Hard Drive","rikiki Harddrive","P'9220 Mobile Drive","Rugged 16 and 32 GB",
		"HardDrive","CD R/W"};
		InsertProducts(0x059f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8388};
		char* mids[] = {"Marvell 88W8388 802.11a/b/g WLAN"};
		InsertProducts(0x05a3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x2000,0x9720,0x9722,0x9731,0x9783,0x9837,0x9862,0x9881};
		char* mids[] = {"WKB-1000S Wireless Ergo Keyboard with Touchpad","WKB-2000 Wireless Keyboard with Touchpad","Keyboard Mouse","Keyboard","MCK-600W/MCK-800USB Keyboard",
		"Wireless Keypad","Targus Number Keypad","Targus Number Keypad (Composite Device)","IR receiver [VRC-1100 Vista MCE Remote Control]"};
		InsertProducts(0x05a4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004};
		char* mids[] = {"CVA124 Cable Voice Adapter (WDM)","CVA122 Cable Voice Adapter (WDM)","CVA124E Cable Voice Adapter (WDM)","CVA122E Cable Voice Adapter (WDM)"};
		InsertProducts(0x05a6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0511,0x0518,0x0519,0x1550,0x2640,0x2643,0x264b,0x2800,0x4519,0x7670,0x8519,0xa511,0xa518};
		char* mids[] = {"OV511 Webcam","OV518 Webcam","OV519 Microphone","VEHO Filmscanner","OV2640 Webcam",
		"Monitor Webcam","Monitor Webcam","SuperCAM","Webcam Classic","OV7670 Webcam",
		"OV519 Webcam","OV511+ Webcam","D-Link DSB-C310 Webcam"};
		InsertProducts(0x05a9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0030,0x0031,0x0060,0x0061,0x0101,0x0130,0x0200,0x0201,0x0202,0x0300,0x0301,0x0350,0x0351,0x081a,0x0cda,0x1001,0x5700,0x5701,0x5901,
		0x5a01,0x5d01};
		char* mids[] = {"Parallel Port","Storage Adapter V2 (TPP)","ATA Bridge","USB 2.0 ATA Bridge","Storage Adapter V3 (TPP-I)",
		"Storage Adapter (TPP)","Compact Flash and Microdrive Reader (TPP)","USS725 ATA Bridge","Storage Adapter (TPP)","ATA Bridge",
		"Portable Hard Drive (TPP)","Portable Hard Drive V2","Portable Hard Drive (TPP)","Portable Hard Drive V2","ATA Bridge",
		"ATA Bridge for CD-R/RW","BAYI Printer Class Support","Storage Adapter V2 (TPP)","USB Storage Adapter V2","Smart Board (TPP)",
		"ATI Storage Adapter (TPP)","DataBook Adapter (TPP)"};
		InsertProducts(0x05ab, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0201,0x0202,0x0205,0x0206,0x020b,0x020c,0x020d,0x020e,0x020f,0x0214,0x0215,0x0216,0x0217,0x0218,0x0219,0x021a,0x021b,0x021c,0x021d,0x021e,
		0x021f,0x0220,0x0221,0x0222,0x0223,0x0224,0x0225,0x0229,0x022a,0x022b,0x0230,0x0231,0x0232,0x0236,0x0237,0x0238,0x023f,0x0240,0x0241,0x0242,
		0x0243,0x0244,0x0245,0x0246,0x0247,0x024a,0x024d,0x0250,0x0252,0x0253,0x0254,0x0263,0x0301,0x0302,0x0304,0x0306,0x030a,0x030b,0x030d,0x030e,
		0x1000,0x1001,0x1002,0x1003,0x1006,0x1008,0x1101,0x1105,0x1107,0x1112,0x1201,0x1202,0x1203,0x1204,0x1205,0x1206,0x1207,0x1208,0x1209,0x120a,
		0x1223,0x1224,0x1225,0x1227,0x1231,0x1240,0x1242,0x1243,0x1245,0x1246,0x1255,0x1260,0x1261,0x1262,0x1263,0x1265,0x1266,0x1267,0x1281,0x1290,
		0x1291,0x1292,0x1293,0x1294,0x1296,0x1297,0x1299,0x129a,0x129c,0x129e,0x129f,0x12a0,0x12a2,0x12a3,0x12a4,0x12a5,0x12a6,0x12a8,0x12a9,0x12aa,
		0x12ab,0x1300,0x1301,0x1302,0x1303,0x1401,0x1402,0x1500,0x8005,0x8006,0x8007,0x8202,0x8203,0x8204,0x8205,0x8206,0x820a,0x820b,0x820f,0x8213,
		0x8215,0x8216,0x8217,0x8218,0x821a,0x821f,0x8240,0x8241,0x8242,0x8281,0x8286,0x8300,0x8403,0x8404,0x8501,0x8502,0x8505,0x8507,0x8508,0x8509,
		0x850a,0x8510,0x911c,0x9127,0x912f,0x9215,0x9217,0x9218,0x9219,0x921c,0x921e,0x9221,0x9226,0x9227,0x9232,0xffff};
		char* mids[] = {"USB Keyboard [Alps or Logitech, M2452]","Keyboard [ALPS]","Extended Keyboard [Mitsumi]","Extended Keyboard [Mitsumi]","Pro Keyboard [Mitsumi, A1048/US layout]",
		"Extended Keyboard [Mitsumi]","Pro Keyboard [Mitsumi, A1048/JIS layout]","Internal Keyboard/Trackpad (ANSI)","Internal Keyboard/Trackpad (ISO)","Internal Keyboard/Trackpad (ANSI)",
		"Internal Keyboard/Trackpad (ISO)","Internal Keyboard/Trackpad (JIS)","Internal Keyboard/Trackpad (ANSI)","Internal Keyboard/Trackpad (ISO)","Internal Keyboard/Trackpad (JIS)",
		"Internal Keyboard/Trackpad (ANSI)","Internal Keyboard/Trackpad (ISO)","Internal Keyboard/Trackpad (JIS)","Aluminum Mini Keyboard (ANSI)","Aluminum Mini Keyboard (ISO)",
		"Aluminum Mini Keyboard (JIS)","Aluminum Keyboard (ANSI)","Aluminum Keyboard (ISO)","Aluminum Keyboard (JIS)","Internal Keyboard/Trackpad (ANSI)",
		"Internal Keyboard/Trackpad (ISO)","Internal Keyboard/Trackpad (JIS)","Internal Keyboard/Trackpad (ANSI)","Internal Keyboard/Trackpad (MacBook Pro) (ISO)","Internal Keyboard/Trackpad (MacBook Pro) (JIS)",
		"Internal Keyboard/Trackpad (MacBook Pro 4,1) (ANSI)","Internal Keyboard/Trackpad (MacBook Pro 4,1) (ISO)","Internal Keyboard/Trackpad (MacBook Pro 4,1) (JIS)","Internal Keyboard/Trackpad (ANSI)","Internal Keyboard/Trackpad (ISO)",
		"Internal Keyboard/Trackpad (JIS)","Internal Keyboard/Trackpad (ANSI)","Internal Keyboard/Trackpad (ISO)","Internal Keyboard/Trackpad (JIS)","Internal Keyboard/Trackpad (ANSI)",
		"Internal Keyboard/Trackpad (ISO)","Internal Keyboard/Trackpad (JIS)","Internal Keyboard/Trackpad (ANSI)","Internal Keyboard/Trackpad (ISO)","Internal Keyboard/Trackpad (JIS)",
		"Internal Keyboard/Trackpad (MacBook Air) (ISO)","Internal Keyboard/Trackpad (MacBook Air) (ISO)","Aluminium Keyboard (ISO)","Internal Keyboard/Trackpad (ANSI)","Internal Keyboard/Trackpad (ISO)",
		"Internal Keyboard/Trackpad (JIS)","Apple Internal Keyboard / Trackpad (MacBook Retina)","USB Mouse [Mitsumi, M4848]","Optical Mouse [Fujitsu]","Mighty Mouse [Mitsumi, M1152]",
		"Optical USB Mouse [Fujitsu]","Internal Trackpad","Internal Trackpad","Magic Mouse","MC380Z/A [Magic Trackpad]",
		"Bluetooth HCI MacBookPro (HID mode)","Keyboard Hub [ALPS]","Extended Keyboard Hub [Mitsumi]","Hub in Pro Keyboard [Mitsumi, A1048]","Hub in Aluminum Keyboard",
		"Mini DisplayPort to Dual-Link DVI Adapter","Speakers","Audio in LED Cinema Display","Thunderbolt Display Audio","FaceTime HD Camera (Display)",
		"3G iPod","iPod 2G","iPod 4.Gen Grayscale 40G","iPod [Photo]","iPod Mini 1.Gen/2.Gen",
		"iPod '06'","iPod '07'","iPod '08'","iPod Video","iPod Nano",
		"iPod Classic/Nano 3.Gen (DFU mode)","iPod Nano 3.Gen (DFU mode)","iPod Nano 4.Gen (DFU mode)","Mobile Device (DFU Mode)","iPod Nano 5.Gen (DFU mode)",
		"iPod Nano 2.Gen (DFU mode)","iPod Nano 3.Gen (WTF mode)","iPod Nano 4.Gen (WTF mode)","iPod Classic 3.Gen (WTF mode)","iPod Nano 5.Gen (WTF mode)",
		"iPod Nano 4.Gen (DFU mode)","iPod Nano 2.Gen","iPod Classic","iPod Nano 3.Gen","iPod Nano 4.Gen",
		"iPod Nano 5.Gen","iPod Nano 6.Gen","iPod Nano 7.Gen","Apple Mobile Device [Recovery Mode]","iPhone",
		"iPod Touch 1.Gen","iPhone 3G","iPod Touch 2.Gen","iPhone 3GS","iPod Touch 3.Gen (8GB)",
		"iPhone 4","iPod Touch 3.Gen","iPad","iPhone 4(CDMA)","iPod Touch 4.Gen",
		"iPad 2","iPhone 4S","iPad 2 (3G; 64GB)","iPad 2 (CDMA)","iPad 3 (wifi)",
		"iPad 3 (CDMA)","iPad 3 (3G, 16 GB)","iPhone5/5C/5S","iPad 2","iPod Touch 5.Gen [A1421]",
		"iPad 4 (WiFi, 32GB)","iPod Shuffle","iPod Shuffle 2.Gen","iPod Shuffle 3.Gen","iPod Shuffle 4.Gen",
		"Modem","Ethernet Adapter [A1277]","SuperDrive [A1379]","OHCI Root Hub Simulation","EHCI Root Hub Simulation",
		"XHCI Root Hub USB 2.0 Simulation","HCF V.90 Data/Fax Modem","Bluetooth HCI","Built-in Bluetooth 2.0+EDR HCI","Bluetooth HCI",
		"Bluetooth HCI","Bluetooth HID Keyboard","Bluetooth HID Mouse","Bluetooth HCI","Bluetooth Host Controller",
		"Built-in Bluetooth 2.0+EDR HCI","Bluetooth USB Host Controller","Bluetooth USB Host Controller","Bluetooth Host Controller","Bluetooth Host Controller",
		"Built-in Bluetooth 2.0+EDR HCI","Built-in IR Receiver","Built-in IR Receiver","Built-in IR Receiver","Bluetooth Host Controller",
		"Bluetooth Host Controller","Built-in iSight (no firmware loaded)","Internal Memory Card Reader","Internal Memory Card Reader","Built-in iSight [Micron]",
		"Built-in iSight","Built-in iSight","Built-in iSight","iSight in LED Cinema Display","FaceTime HD Camera",
		"FaceTime Camera","FaceTime HD Camera (Built-in)","Hub in A1082 [Cinema HD Display 23\"]","Hub in Thunderbolt Display","Hub in 30\" Cinema Display",
		"Studio Display 15\"","Studio Display 17\"","Cinema Display 23\"","Cinema Display 20\"","A1082 [Cinema HD Display 23\"]",
		"Cinema Display 24\"","30\" Cinema Display","LED Cinema Display","Thunderbolt Display","Cinema HD Display 30\"",
		"Bluetooth in DFU mode - Driver"};
		InsertProducts(0x05ac, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0806,0x0809,0x0821,0x3062,0x9167,0x9267};
		char* mids[] = {"HP SK806A Keyboard","Wireless Keyboard and Mouse","IDE to","Cordless Keyboard","KB 9151B - 678",
		"KB 9251B - 678 Mouse"};
		InsertProducts(0x05af, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1389};
		char* mids[] = {"Bluetooth Wireless Adapter"};
		InsertProducts(0x05b1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4857,0x6001};
		char* mids[] = {"M-Any DAH-210","Digisette DUO-MP3 AR-100"};
		InsertProducts(0x05b4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3002};
		char* mids[] = {"Scroll Mouse"};
		InsertProducts(0x05b8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0007,0x0008,0x000a};
		char* mids[] = {"Fingerprint Reader","Fingerprint Reader","Fingerprint Reader"};
		InsertProducts(0x05ba, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004};
		char* mids[] = {"Trackball"};
		InsertProducts(0x05bc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0004,0x0008};
		char* mids[] = {"AccelePort USB 2","AccelePort USB 4","AccelePort USB 8"};
		InsertProducts(0x05c5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0114,0x1000,0x3100,0x3196,0x3197,0x6000,0x6503,0x6613,0x9000,0x9001,0x9002,0x9008,0x9018,0x9025,0x9201,0x9202,0x9203,0x9205,0x9211,0x9212,
		0x9214,0x9215,0x9221,0x9222,0x9224,0x9225,0x9231,0x9234,0x9235,0x9244,0x9245,0x9264,0x9265,0x9274,0x9275};
		char* mids[] = {"Select RW-200 CDMA Wireless Modem","Mass Storage Device","CDMA Wireless Modem/Phone","CDMA Wireless Modem","CDMA Wireless Modem/Phone",
		"Siemens SG75","AnyData APE-540H","Onda H600/N501HS ZTE MF330","SIMCom SIM5218 modem","Gobi Wireless Modem",
		"Gobi Wireless Modem","Gobi Wireless Modem (QDL mode)","Qualcomm HSUSB Device","Qualcomm HSUSB Device","Gobi Wireless Modem (QDL mode)",
		"Gobi Wireless Modem","Gobi Wireless Modem","Gobi 2000","Acer Gobi Wireless Modem (QDL mode)","Acer Gobi Wireless Modem",
		"Acer Gobi 2000 Wireless Modem (QDL mode)","Acer Gobi 2000 Wireless Modem","Gobi Wireless Modem (QDL mode)","Gobi Wireless Modem","Sony Gobi 2000 Wireless Modem (QDL mode)",
		"Sony Gobi 2000 Wireless Modem","Gobi Wireless Modem (QDL mode)","Top Global Gobi 2000 Wireless Modem (QDL mode)","Top Global Gobi 2000 Wireless Modem","Samsung Gobi 2000 Wireless Modem (QDL mode)",
		"Samsung Gobi 2000 Wireless Modem","Asus Gobi 2000 Wireless Modem (QDL mode)","Asus Gobi 2000 Wireless Modem","iRex Technologies Gobi 2000 Wireless Modem (QDL mode)","iRex Technologies Gobi 2000 Wireless Modem"
		};
		InsertProducts(0x05c6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0113,0x1001,0x2001,0x2011,0x6001};
		char* mids[] = {"PC Line Mouse","Lynx Mouse","Keyboard","SCorpius Keyboard","Ten-Keypad"
		};
		InsertProducts(0x05c7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0103,0x021a,0x0318,0x0361,0x036e,0x0403,0x041b};
		char* mids[] = {"FO13FF-65 PC-CAM","HP Webcam","Webcam","SunplusIT INC. HP Truevision HD Webcam","Webcam",
		"Webcam","HP 2.0MP High Definition Webcam"};
		InsertProducts(0x05c8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0325,0x032d,0x032f,0x03a1,0x0403,0x0405,0x0406,0x1803,0x1810,0x1812,0x1814,0x1820,0x1830,0x1832,0x1833,0x1834,0x1835,0x1836,0x1837,
		0x1839,0x183a,0x183b,0x183d,0x183e,0x1841,0x1870,0x18b0,0x18b1,0x18b3,0x18b5,0x2201,0x2202,0x2203,0x2204,0x2205,0x2206,0x2207,0x2208,0x2209,
		0x220a,0x220b,0x220c,0x220d,0x220e,0x220f,0x2211,0x2212,0x2213,0x2214,0x2215,0x2216,0x2222};
		char* mids[] = {"RDC-5300 Camera","Caplio GX (ptp)","Caplio GX 8 (ptp)","Caplio R3 (ptp)","IS200e",
		"Printing Support","Type 101","Type 102","V5 camera [R5U870]","Pavilion Webcam [R5U870]",
		"Pavilion Webcam","HD Webcam","Integrated Webcam","Visual Communication Camera VGP-VCC2 [R5U870]","Visual Communication Camera VGP-VCC3 [R5U870]",
		"Visual Communication Camera VGP-VCC2 [R5U870]","Visual Communication Camera VGP-VCC2 [R5U870]","Visual Communication Camera VGP-VCC5 [R5U870]","Visual Communication Camera VGP-VCC4 [R5U870]","Visual Communication Camera VGP-VCC4 [R5U870]",
		"Visual Communication Camera VGP-VCC6 [R5U870]","Visual Communication Camera VGP-VCC7 [R5U870]","Visual Communication Camera VGP-VCC8 [R5U870]","Sony Vaio Integrated Webcam","Visual Communication Camera VGP-VCC9 [R5U870]",
		"Fujitsu F01/ Lifebook U810 [R5U870]","Webcam 1000","Sony Vaio Integrated Webcam","Sony Vaio Integrated Webcam","Sony Vaio Integrated Webcam",
		"Sony Vaio Integrated Webcam","RDC-7 Camera","Caplio RR30","Caplio 300G","Caplio G3",
		"Caplio RR30 / Medion MD 6126 Camera","Konica DG-3Z","Caplio Pro G3","Caplio G4","Caplio 400G wide",
		"KONICA MINOLTA DG-4Wide","Caplio RX","Caplio GX","Caplio R1/RZ1","Sea & Sea 5000G",
		"Rollei dr5 / Rollei dr5 (PTP mode)","Caplio R1S","Caplio R1v Camera","Caplio R2","Caplio GX 8",
		"DSC 725","Caplio R3","RDC-i500"};
		InsertProducts(0x05ca, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1483};
		char* mids[] = {"PV8630 interface (scanners, webcams)"};
		InsertProducts(0x05cb, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2100,0x2219,0x2265,0x2267,0x2280,0x3000,0x3100,0x3363};
		char* mids[] = {"MicroLink ISDN Office","MicroLink ISDN","MicroLink 56k","MicroLink 56k (V.250)","MicroLink 56k Fun",
		"Micolink USB2Ethernet [pegasus]","AirLancer USB-11","MicroLink ADSL Fun"};
		InsertProducts(0x05cc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003};
		char* mids[] = {"Bluetooth Adapter BL-554"};
		InsertProducts(0x05d1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0099};
		char* mids[] = {"10Mbps Ethernet [klsi]"};
		InsertProducts(0x05d7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4001,0x4002,0x4003,0x4004,0x4005,0x4006,0x4007,0x4008,0x4009,0x4013,0x8105,0x8106,0x8107,0x8108,0x8109};
		char* mids[] = {"Artec Ultima 2000","Artec Ultima 2000 (GT6801 based)/Lifetec LT9385/ScanMagic 1200 UB Plus Scanner","Artec E+ 48U","Artec E+ Pro","MEM48U",
		"TRUST EASY WEBSCAN 19200","TRUST 240H EASY WEBSCAN GOLD","Trust Easy Webscan 19200","Umax Astraslim","IT Scan 1200",
		"Artec T1 USB TVBOX (cold)","Artec T1 USB TVBOX (warm)","Artec T1 USB TVBOX with AN2235 (cold)","Artec T1 USB TVBOX with AN2235 (warm)","Artec T1 USB2.0 TVBOX (cold"
		};
		InsertProducts(0x05d8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa225,0xa758,0xa794};
		char* mids[] = {"A225 Printer","A758 Printer","A794 Printer"};
		InsertProducts(0x05d9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0091,0x0093,0x0094,0x0099,0x009a,0x00a0,0x00a3,0x00ac,0x00b6,0x00ef,0x1006,0x1011,0x1018,0x1020,0x1025,0x1026,0x1043,0x1045,0x1047,0x1048,
		0x1049,0x1051,0x1052,0x1053,0x1054,0x1055,0x1056,0x1057,0x1058,0x1059,0x1060,0x2007,0x200c,0x200e,0x2017,0x201c,0x201d,0x201f,0x202e,0x208b,
		0x208f,0x209e,0x20a7,0x20b0,0x20b1,0x20b4,0x20bd,0x20c9,0x20d2,0x20d6,0x20de,0x20e0,0x20ed,0x20ee,0x3008,0x300a,0x300b,0x300f,0x3020,0x3021,
		0x3022,0x3023,0x30c1,0x30ce,0x30cf,0x30d4,0x30d8,0x30d9,0x30e4,0x30e5,0x30e6,0x40b3,0x40b8,0x40c7,0x40ca,0x40cb,0x40dd,0x40ff,0x5003,0x5013,
		0x80a3,0x80ac};
		char* mids[] = {"ScanMaker X6u","ScanMaker V6USL","Phantom 336CX/C3","ScanMaker X6/X6U","Phantom C6",
		"Phantom 336CX/C3 (#2)","ScanMaker V6USL","ScanMaker V6UL","ScanMaker V6UPL","ScanMaker V6UPL",
		"Jenoptik JD350 entrance","NHJ Che-ez! Kiss Digital Camera","Digital Dream Enigma 1.3","Digital Dream l'espion xtra","Take-it Still Camera Device",
		"Take-it","Take-It 1300 DSC Bulk Driver","Take-it D1","Take-it Camera Composite Device","Take-it Q3",
		"3M Still Camera Device","Camcorder Series","Mass Storage Device","Take-it DV Composite Device","Mass Storage Device",
		"Digital Camera Series(536)","Mass Storage Device","Take-it DSC Camera Device(536)","Mass Storage Device","Camcorder DSC Series",
		"Microtek Take-it MV500","ArtixScan DI 1210","1394_USB2 Scanner","ArtixScan DI 810","UF ICE Scanner",
		"4800 Scanner","ArtixScan DI 1610","4800 Scanner-ICE","ArtixScan DI 2020","ScanMaker 6800",
		"ArtixScan DI 2010","ScanMaker 4700LP","ScanMaker 5600","ScanMaker X12USL","ScanMaker 8700",
		"ScanMaker 4700","ScanMaker 5700","ScanMaker 6700","Microtek ArtixScan 1800f","PS4000",
		"ScanMaker 9800XL","ScanMaker 9700XL","ScanMaker 4700","Micortek ScanMaker X12USL","Scanner",
		"4800 ICE Scanner","4800 Scanner","MiniScan C5","4800dpi Scanner","1200dpi Scanner",
		"Scanner 4800dpi","USB1200II Scanner","USB600 Scanner","ScanMaker 3800","ScanMaker 4800",
		"USB1200 Scanner","Scanner","USB2400 Scanner","ScanMaker 4100","USB3200 Scanner",
		"ScanMaker i320","ScanMaker 3600","ScanMaker 3700","ScanMaker 4600","ScanMaker 3600",
		"ScanMaker 3700","ScanMaker 3750i","ScanMaker 3600","Goya","3200 Scanner",
		"ScanMaker V6USL (#2)","ScanMaker V6UL/SpicyU"};
		InsertProducts(0x05da, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0005,0x0009,0x000a,0x000b,0x0011};
		char* mids[] = {"SUNTAC U-Cable type D2","SUNTAC U-Cable type P1","SUNTAC Slipper U","SUNTAC Ir-Trinity","SUNTAC U-Cable type A3",
		"SUNTAC U-Cable type A4"};
		InsertProducts(0x05db, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0080,0x0081,0x00a7,0x0100,0x0200,0x0300,0x0301,0x0302,0x0303,0x0304,0x0310,0x0311,0x0312,0x0313,0x0320,0x0321,0x0322,
		0x0323,0x0330,0x0340,0x0350,0x0400,0x0401,0x0403,0x0405,0x0407,0x0409,0x040b,0x040d,0x040f,0x0410,0x0411,0x0413,0x0415,0x0417,0x0419,0x041b,
		0x041d,0x041f,0x0420,0x0421,0x0423,0x0425,0x0427,0x0429,0x042b,0x042d,0x042f,0x0431,0x0433,0x4d02,0x4d12,0x4d30,0xa209,0xa300,0xa400,0xa410,
		0xa411,0xa420,0xa421,0xa422,0xa430,0xa431,0xa432,0xa440,0xa450,0xa460,0xa501,0xa510,0xa530,0xa531,0xa560,0xa701,0xa731,0xa768,0xa790,0xa811,
		0xa813,0xa815,0xb002,0xb018,0xb047,0xba02,0xc753};
		char* mids[] = {"jumpSHOT CompactFlash Reader","JumpShot","JumpShot","Jumpdrive Secure 64MB","RBC Compact Flash Drive",
		"JumpDrive Impact","JumpDrive PRO","JumpDrive 2.0 Pro","Jumpdrive Geysr","JumpDrive Classic",
		"JD Micro","JD Micro Pro","JD Secure II","JumpDrive","JumpDrive Classic",
		"JD Micro","JD Micro Pro","JumpDrive","JD Micro","JD Micro Pro",
		"UFC","JumpDrive Expression","JumpDrive TAD","Express Card","UFDC",
		"UFDC","Locked B Device","Locked C Device","Locked D Device","Locked E Device",
		"Locked F Device","Locked G Device","Locked H Device","JumpDrive","JumpDrive",
		"Locked J Device","Locked K Device","Locked L Device","Locked M Device","Locked N Device",
		"Locked O Device","Locked P Device","JumpDrive","JumpDrive","Locked R Device",
		"Locked S Device","Locked T Device","Locked U Device","Locked V Device","Locked W Device",
		"Locked X Device","Locked Y Device","Locked Z Device","MP3 Player","MP3 Player",
		"MP3 Player","JumpDrive S70","JumpDrive2","JumpDrive trade; Pro 40-501","JumpDrive 128MB/256MB",
		"JumpDrive Traveler","JumpDrive Pro","JumpDrive Pro II","JumpDrive Micro Pro","JumpDrive Secure",
		"JumpDrive Secure II","JumpDrive Classic","JumpDrive Lightning","JumpDrive TouchGuard","JD Mercury",
		"JumpDrive Classic","JumpDrive Sport","JumpDrive Expression","JumpDrive Secure II","JumpDrive FireFly",
		"JumpDrive FireFly","JumpDrive FireFly","JumpDrive Retrax","JumpDrive 2GB","16GB Gizmo!",
		"16gB flash thumb drive","JumpDrive V10","USB CF Reader","Multi-Card Reader","SDHC Reader [RW047-7000]",
		"Workflow CFR1","JumpDrive TwistTurn"};
		InsertProducts(0x05dc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xff31,0xff32,0xff35,0xff91};
		char* mids[] = {"AWU-120","FriendlyNET AeroLAN AL2011","PCW 100 - Wireless 802.11b Adapter","2Wire PC Port Phoneline 10Mbps Adapter"};
		InsertProducts(0x05dd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0700,0x0800,0x1200,0x1900,0x2000,0x200d};
		char* mids[] = {"Bar Code Scanner (CS1504)","Spectrum24 Wireless LAN Adapter","Bar Code Scanner","SNAPI Imaging Device","MC3090 Rugged Mobile Computer",
		"MC70 Rugged Mobile Computer"};
		InsertProducts(0x05e0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0408,0x0500,0x0501,0x0890,0x0892,0x0895,0x0896,0x2010};
		char* mids[] = {"802.11g + Bluetooth Wireless Adapter","STK1160 Video Capture Device","DC-112X Webcam","DC-1125 Webcam","STK011 Camera",
		"STK013 Camera","STK016 Camera","STK017 Camera","ARCTIC Sound P261 Headphones"};
		InsertProducts(0x05e1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000a,0x000b,0x0100,0x0120,0x0131,0x0142,0x0143,0x0180,0x0182,0x0189,0x018a,0x0300,0x0301,0x0406,0x0501,0x0502,0x0503,0x0504,0x0604,0x0605,
		0x0606,0x0607,0x0608,0x0610,0x0660,0x0700,0x0701,0x0702,0x0703,0x0704,0x0705,0x0706,0x0707,0x0708,0x0709,0x070a,0x070b,0x070e,0x070f,0x0710,
		0x0711,0x0712,0x0715,0x0716,0x0717,0x0718,0x0719,0x0722,0x0723,0x0726,0x0727,0x0731,0x0732,0x0736,0x0741,0x0743,0x0760,0x0761,0x0780,0x07a0,
		0x0880,0x0927,0x1205,0xa700,0xf102,0xf103,0xf104,0xfd21,0xfe00};
		char* mids[] = {"Keyboard with PS/2 Port","Mouse","Nintendo Game Boy Advance SP","Pacific Image Electronics PrimeFilm 1800u slide/negative scanner","CF/SM Reader/Writer",
		"Multiple Slides Scanner-3600","Multiple Frames Film Scanner-36series","Plustek Scanner","Wize Media 1000","ScanJet 4600 series",
		"Xerox 6400","GLUSB98PT Parallel Port","USB2LPT Cable Release2","Hub","GL620USB Host-Host interface",
		"GL620USB-A GeneLink USB-USB Bridge","Webcam","HID Keyboard Filter","USB 1.1 Hub","USB 2.0 Hub",
		"USB 2.0 Hub / D-Link DUB-H4 USB 2.0 Hub","Logitech G110 Hub","Hub","4-port hub","USB 2.0 Hub",
		"SIIG US2256 CompactFlash Card Reader","USB 2.0 IDE Adapter","USB 2.0 IDE Adapter [GL811E]","Card Reader","Card Reader",
		"Card Reader","Card Reader","Card Reader","Card Reader","Card Reader",
		"Pen Flash","DMHS1B Rev 3 DFU Adapter","USB 2.0 Card Reader","Pen Flash","USB 2.0 33-in-1 Card Reader",
		"Card Reader","Delkin Mass Storage Device","USB 2.0 microSD Reader","USB 2.0 Multislot Card Reader/Writer","All-in-1 Card Reader",
		"IDE/SATA Adapter","SATA adapter","SD/MMC card reader","GL827L SD/MMC/MS Flash Card Reader","SD Card Reader",
		"microSD Reader/Writer","GL3310 SATA 3Gb/s Bridge Controller","All-in-One Cardreader","microSD Reader/Writer","microSD Card Reader",
		"SDXC and microSDXC CardReader","USB 2.0 Card Reader/Writer","Genesys Mass Storage Device","USBFS DFU Adapter","Pen Flash",
		"Wasp (SL-6612)","Card Reader","Afilias Optical Mouse H3003 / Trust Optical USB MultiColour Mouse MI-2330","Pen Flash","VX7012 TV Box",
		"VX7012 TV Box","VX7012 TV Box","3M TL20 Temperature Logger","Razer Mouse"};
		InsertProducts(0x05e3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0008,0x0009,0x000c,0x000d,0x0014,0x0040,0x2008};
		char* mids[] = {"KL5KUSB101B Ethernet [klsi]","Sony 10Mbps Ethernet [pegasus]","USB-to-RS-232","USB-to-RS-232","RS-232 J104",
		"Ethernet Adapter","Ethernet Adapter"};
		InsertProducts(0x05e9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x020a,0x8884,0x8888};
		char* mids[] = {"Top Shot Pegasus Joystick","Mag Turbo Force Wheel","Top Shot Force Feedback Racing Wheel"};
		InsertProducts(0x05ef, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"DA-Port DAC"};
		InsertProducts(0x05f0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010};
		char* mids[] = {"AQ Mouse"};
		InsertProducts(0x05f2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0007,0x0081,0x00ff,0x0203,0x020b,0x0232,0x0261,0x0264};
		char* mids[] = {"Kinesis Advantage PRO MPC/USB Keyboard","Kinesis Integrated Hub","VEC Footpedal","Y-mouse Keyboard & Mouse Adapter","PS2 Adapter",
		"X-Keys Switch Interface, Programming Mode","X-Keys Switch Interface, SPLAT Mode","X-Keys Switch Interface, Composite Mode"};
		InsertProducts(0x05f3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1104,0x2202,0x2206,0x2601,0x2602,0x5204};
		char* mids[] = {"Magellan 2200VS","Point of Sale Handheld Scanner","Datalogic Gryphon GFS4170","Datalogin Magellan 1000i Barcode Scanner","Datalogic Magellan 1100i Barcode Scanner",
		"Datalogic Gryphon GFS4170 (config mode)"};
		InsertProducts(0x05f9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3301,0x3302,0x3303};
		char* mids[] = {"Keyboard with PS/2 Mouse Port","Keyboard","Keyboard with PS/2 Mouse Port"};
		InsertProducts(0x05fa, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7849};
		char* mids[] = {"Harman/Kardon SoundSticks"};
		InsertProducts(0x05fc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0239,0x0251,0x0253,0x0286,0x107a,0x262a,0x262f,0xdaae};
		char* mids[] = {"SV-239 HammerHead Digital","Raider Pro","ProPad 8 Digital","SV-286 Cyclone Digital","PowerPad Pro X-Box pad",
		"3dfx HammerHead FX","HammerHead Fx","Game Shark"};
		InsertProducts(0x05fd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0003,0x0005,0x0007,0x0009,0x0011,0x0014,0x1010,0x2001};
		char* mids[] = {"Mouse","Cypress USB Mouse","Viewmaster 4D Browser Mouse","Twinhead Mouse","Inland Pro 4500/5000 Mouse",
		"Browser Mouse","Gamepad","Optical Wireless","Microsoft Wireless Receiver 700"};
		InsertProducts(0x05fe, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003};
		char* mids[] = {"Internet Security Co., Ltd. SecureKey"};
		InsertProducts(0x0601, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001};
		char* mids[] = {"ViCam Webcam"};
		InsertProducts(0x0602, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00f1,0x00f2,0x6871};
		char* mids[] = {"Keyboard","Keyboard (Labtec Ultra Flat Keyboard)","Mouse"};
		InsertProducts(0x0603, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x031d,0x0322,0x0334,0xff12};
		char* mids[] = {"eHome Infrared Receiver","eHome Infrared Receiver","eHome Infrared Receiver","SMK Bluetooth Device"};
		InsertProducts(0x0609, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0230,0x1006,0x2101,0x2231,0x2270,0x5253,0x5811,0x5903,0x6001,0x6002,0x6003,0x6231,0x8007,0xa001};
		char* mids[] = {"MacAlly Keyboard","KSK-8003 UX Keyboard","Japanese Keyboard - 260U","Keyboard","KSK-6001 UELX Keyboard",
		"Gigabyte K8100 Aivia Gaming Keyboard","Thermaltake MEKA G-Unit Gaming Keyboard","ACK-571U Wireless Keyboard","Japanese Keyboard - 595U","SolidTek USB 2p HUB",
		"SolidTek USB Keyboard","Japanese Keyboard - 600HM","Thermaltake eSPORTS Meka Keyboard","P-W1G1F12 VER:1 [Macally MegaCam]","Maxwell Compact Pc PM3"
		};
		InsertProducts(0x060b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"Mouse"};
		InsertProducts(0x0618, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0102,0x0103,0x0104,0x0105,0x0501,0x0502};
		char* mids[] = {"SLP-100 Driver","SLP-200 Driver","SLP-100N Driver","SLP-200N Driver","SLP-240 Driver",
		"SLP-440 Driver","SLP-450 Driver"};
		InsertProducts(0x0619, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0110,0x0200,0x8200,0x9200};
		char* mids[] = {"5thSense Fingerprint Sensor","FPS200 Fingerprint Sensor","VKI-A Fingerprint Sensor/Flash Storage (dumb)","VKI-B Fingerprint Sensor/Flash Storage (smart)"};
		InsertProducts(0x061a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xc020};
		char* mids[] = {"SSU-100"};
		InsertProducts(0x061d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0010};
		char* mids[] = {"nissei 128DE-USB -","nissei 128DE-PNA -"};
		InsertProducts(0x061e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004,0x0007,0x000a,0x000b};
		char* mids[] = {"QuickVideo weeCam","QuickVideo weeCam","QuickVideo weeCam","QuickVideo weeCam"};
		InsertProducts(0x0620, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0248,0x0249,0x0251,0x0294,0x0402,0x0403};
		char* mids[] = {"Virtual Hub","Virtual Keyboard/Mouse","Virtual Mass Storage","Dell 03R874 KVM dongle","Cisco Virtual Keyboard and Mouse",
		"Cisco Virtual Mass Storage"};
		InsertProducts(0x0624, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0001,0x0102,0x0201,0x0252,0x3286,0x6301,0x9003,0x9004};
		char* mids[] = {"Optical mouse","Notebook Optical Mouse","Wireless Keyboard/Mouse Combo [MK1152WC]","Defender Office Keyboard (K7310) S Zodiak KM-9010","Emerge Uni-retractable Laser Mouse",
		"Nano Receiver [Sandstrom Laser Mouse SMWLL11]","Trust Wireless Optical Mouse MI-4150K","VoIP Conference Hub (A16GH)","USR9602 USB Internet Mini Phone"};
		InsertProducts(0x062a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0655};
		char* mids[] = {"Embedded Mass Storage Drive [RealSSD]"};
		InsertProducts(0x0634, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003};
		char* mids[] = {"Vivicam 35Xx"};
		InsertProducts(0x0636, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0268,0x026a,0x0a10,0x0a13,0x0a15,0x0a16,0x0a30,0x0a41,0x0f01,0x4004};
		char* mids[] = {"iVina 1200U Scanner","Minolta Dimage Scan Dual II AF-2820U (2886)","iVina FB1600/UMAX Astra 4500","AV600U","Konica Minolta SC-110",
		"Konica Minolta SC-215","UMAX Astra 6700 Scanner","Avision AM3000/MF3000 Series","fi-4010CU","Minolta Dimage Scan Elite II AF-2920 (2888)"
		};
		InsertProducts(0x0638, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0026};
		char* mids[] = {"LPC-Stick"};
		InsertProducts(0x0640, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0200,0x1000,0x800d,0x800e,0x801d,0x8021,0xd001,0xd002,0xd010};
		char* mids[] = {"Floppy","All-In-One Multi-Card Reader CA200/B/S","CD-ROM Drive","TASCAM Portastudio DP-01FX","TASCAM US-122L",
		"DR-100","TASCAM US-122mkII","CD-R/RW Unit","CD-R/RW Unit","CD-RW/DVD Unit"
		};
		InsertProducts(0x0644, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0101,0x0102,0x0103,0x03e9,0x03ea,0x03eb,0x03ec};
		char* mids[] = {"ARC SpectraPro UV/VIS/IR Monochromator/Spectrograph","ARC AM-VM Mono Airpath/Vacuum Monochromator/Spectrograph","ARC Inspectrum Mono","ARC Filterwheel","Inspectrum 128x1024 F VIS Spectrograph",
		"Inspectrum 256x1024 F VIS Spectrograph","Inspectrum 128x1024 B VIS Spectrograph","Inspectrum 256x1024 B VIS Spectrograph"};
		InsertProducts(0x0647, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0165};
		char* mids[] = {"Blackfin 535 [ADZS HPUSB ICE]"};
		InsertProducts(0x064b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa100,0xa101,0xa102,0xa103,0xa110,0xa114,0xa116,0xa136,0xa219,0xc107,0xd101,0xd217,0xe201,0xe203,0xe258,0xf102,0xf103,0xf300};
		char* mids[] = {"Acer OrbiCam","Acer CrystalEye Webcam","Acer/Lenovo Webcam [CN0316]","Acer/HP Integrated Webcam [CN0314]","HP Webcam",
		"Lemote Webcam","UVC 1.3MPixel WebCam","Asus Integrated Webcam [CN031B]","1.3M WebCam (notebook emachines E730, Acer sub-brand)","HP webcam [dv6-1190en]",
		"Acer CrystalEye Webcam","HP TrueVision HD","Lenovo Integrated Webcam","Lenovo Integrated Webcam","HP TrueVision HD Integrated Webcam",
		"Lenovo Integrated Webcam [R5U877]","Lenovo Integrated Webcam [R5U877]","UVC 0.3M Webcam"};
		InsertProducts(0x064e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x03e9,0x03f2,0x03f3,0x0bd7,0x0bd8};
		char* mids[] = {"CmStick (article no. 1001)","CmStick/M (article no. 1010)","CmStick/M (article no. 1011)","BOX/U","BOX/RU"
		};
		InsertProducts(0x064f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005,0x0006,0x0007,0x0016};
		char* mids[] = {"Device Bay Controller","Hub","Device Bay Controller","Hub"};
		InsertProducts(0x0654, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0009};
		char* mids[] = {"Opticon OPR-2001 / NLV-1001 (keyboard mode)","NLV-1001 (serial mode) / OPN-2001 [Opticon]"};
		InsertProducts(0x065a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0103};
		char* mids[] = {"CobraPad"};
		InsertProducts(0x0663, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0301,0x0302,0x0303,0x0304,0x0305,0x0306,0x0307,0x0309};
		char* mids[] = {"Groovy Technology Corp. GTouch Touch Screen","Groovy Technology Corp. GTouch Touch Screen","Groovy Technology Corp. GTouch Touch Screen","Groovy Technology Corp. GTouch Touch Screen","Groovy Technology Corp. GTouch Touch Screen",
		"Groovy Technology Corp. GTouch Touch Screen","Groovy Technology Corp. GTouch Touch Screen","Groovy Technology Corp. GTouch Touch Screen"};
		InsertProducts(0x0664, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5161};
		char* mids[] = {"USB to Serial"};
		InsertProducts(0x0665, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0fa1};
		char* mids[] = {"TD-U8000 Tape Drive"};
		InsertProducts(0x0667, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0105,0x010a,0x200c,0x2202,0x2203,0x2204,0x2206,0x2207,0x2211,0x2212,0x2213,0x2219,0x400b};
		char* mids[] = {"SCM eUSB SmartMedia Card Reader","Melco MCR-U2 SmartMedia / CompactFlash Reader","USB10TX","USB10TX Ethernet [pegasus]","USB100TX Ethernet [pegasus]",
		"USB100TX HomePNA Ethernet [pegasus]","USB Ethernet [pegasus]","HomeLink Phoneline 10M Network Adapter","WUSB11 802.11b Adapter","WUSB11v2.5 802.11b Adapter",
		"WUSB12v1.1 802.11b Adapter","Instant Wireless Network Adapter","USB10TX"};
		InsertProducts(0x066b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x003b,0x003e,0x003f,0x0040,0x0041,0x0042,0x0043,0x004b,0x3400,0x3410,0x3500,0x3780,0x4200,0x4210,0x8000,0x8001,0x8004,0x8008,0x8020,0x8034,
		0x8036,0x8038,0x8056,0x8060,0x8066,0x807e,0x8092,0x8096,0x809a,0x80aa,0x80ac,0x80b8,0x80ba,0x80bc,0x80bf,0x80c5,0x80c8,0x80ca,0x80cc,0x8104,
		0x8106,0x8108,0x810a,0x810c,0x8122,0x8124,0x8126,0x8128,0x8134,0x8136,0x8138,0x813a,0x813e,0x8140,0x8142,0x8144,0x8146,0x8148,0x814c,0x8201,
		0x8202,0x8203,0x8204,0x8205,0x8206,0x8207,0x8208,0x8209,0x820a,0x820b,0x820c,0x820d,0x820e,0x820f,0x8210,0x8211,0x8212,0x8213,0x8214,0x8215,
		0x8216,0x8217,0x8218,0x8219,0x821a,0x821b,0x821c,0x821d,0x821e,0x821f,0x8220,0x8221,0x8222,0x8223,0x8224,0x8225,0x8226,0x8227,0x8228,0x8229,
		0x8230,0x829c,0x82e0,0x8320,0x835d,0x9000,0x9001,0x9002};
		char* mids[] = {"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","A-Max PA11 MP3 Player","STMP3400 D-Major MP3 Player","STMP3410 D-Major MP3 Player",
		"Player Recovery Device","STMP3780/i.MX23 SystemOnChip in RecoveryMode","STIr4200 IrDA Bridge","STIr4210 IrDA Bridge","MSCN MP3 Player",
		"SigmaTel MSCN Audio Player","MSCNMMC MP3 Player","i-Bead 100 MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"Jens of Sweden / I-BEAD 150M/150H MP3 player","MP3 Player","MP3 Player","MP3 Player","Digital MP3 Music Player",
		"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player","TrekStor i.Beat fun","MP3 Player",
		"MP3 Player","MP3 Player","MP3 Player"};
		InsertProducts(0x066f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0005};
		char* mids[] = {"Calibrator","Enable Cable"};
		InsertProducts(0x0670, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1041,0x5000};
		char* mids[] = {"LCS1040 Speaker System","SpaceBall 4000 FLX"};
		InsertProducts(0x0672, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5000};
		char* mids[] = {"Keyboard"};
		InsertProducts(0x0673, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0110,0x0530,0x0550,0x1688,0x6694};
		char* mids[] = {"Vigor 128 ISDN TA","Vigor530 IEEE 802.11G Adapter (ISL3880+NET2280)","Vigor550","miniVigor 128 ISDN TA","USB ISDN TA"
		};
		InsertProducts(0x0675, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x07d5,0x0fa1};
		char* mids[] = {"TM-ED1285(USB)","TD-U8000 Tape Drive"};
		InsertProducts(0x0677, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0001,0x0307,0x04bb,0x0600,0x0610,0x0611,0x2303,0x2305,0x2306,0x2307,0x2313,0x2315,0x2316,0x2317,0x2501,0x2506,0x2507,0x2515,0x2517,
		0x2528,0x25a1,0x2773,0x3400,0x3500,0x3507,0xaaa0,0xaaa2};
		char* mids[] = {"PL2301 USB-USB Bridge","PL2302 USB-USB Bridge","Motorola Serial Adapter","PL2303 Serial (IODATA USB-RSAQ2)","IDE Bridge",
		"Onext EG210U MODEM","AlDiga AL-11U Quad-band GSM/GPRS/EDGE modem","PL2303 Serial Port","PL2305 Parallel Port","Raylink Bridge Controller",
		"PL2307 USB-ATAPI4 Bridge","FITEL PHS U Cable Adaptor","Flash Disk Embedded Hub","Flash Disk Security Device","Mass Storage Device",
		"PL2501 USB-USB Bridge (USB 2.0)","Kaser 8gB micro hard drive","PL2507 Hi-speed USB to IDE bridge controller","Flash Disk Embedded Hub","Flash Disk Mass Storage Device",
		"Storage device (8gB thumb drive)","PL25A1 Host-Host Bridge","PL2773 SATAII bridge controller","Hi-Speed Flash Disk with TruePrint AES3400","Hi-Speed Flash Disk with TruePrint AES3500",
		"PL3507 ATAPI6 Bridge","Prolific Pharos","PL2303 Serial Adapter (IODATA USB-RSAQ3)"};
		InsertProducts(0x067b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001,0x1022,0x1023,0x4020,0x4031,0x4032,0x4033,0x4060,0x4062,0x5667,0xc031,0xc032,0xc033,0xc060,0xd667,0xe240,0xe540};
		char* mids[] = {"Siemens SpeedStream 100MBps Ethernet","Siemens SpeedStream 1022 802.11b Adapter","SpeedStream Wireless","SpeedStream 4020 ATM/ADSL Installer","Efficient ADSL Modem",
		"SpeedStream 4031 ATM/ADSL Installer","SpeedStream 4031 ATM/ADSL Installer","Alcatel Speedstream 4060 ADSL Modem","Efficient Networks 4060 Loader","Efficient Networks Virtual Bus for ADSL Modem",
		"SpeedStream 4031 ATM/ADSL Installer","SpeedStream 4031 ATM/ADSL Installer","SpeedStream 4031 ATM/ADSL Installer","SpeedStream 4060 Miniport ATM/ADSL Adapter","Efficient Networks Virtual Bus for ADSL Modem",
		"Speedstream Ethernet Adapter E240","Speedstream Ethernet Adapter E240"};
		InsertProducts(0x067c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0801,0x0803,0x0805,0x1001};
		char* mids[] = {"HID Keyboard, Barcode scanner","VCP, Barcode scanner","VCP + UVC, Barcode scanner","Mobile Computer"};
		InsertProducts(0x067e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4552,0x6542,0x6549,0x7541};
		char* mids[] = {"DSL-200 ADSL Modem","DSL Modem","DSL Modem","DSL Modem"};
		InsertProducts(0x067f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"Arowana Optical Wheel Mouse MSOP-01"};
		InsertProducts(0x0680, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0005,0x0012,0x001b,0x001d,0x0022,0x0026,0x002b,0x002e,0x0034,0x3c06};
		char* mids[] = {"Dect Base","Gigaset 3075 Passive ISDN","ID-Mouse with Fingerprint Reader","I-Gate 802.11b Adapter","WLL013",
		"Hipath 1000","Gigaset SX353 ISDN","DECT Data - Gigaset M34","A-100-I ADSL Modem","ADSL Router_S-141",
		"GSM module MC35/ES75 USB Modem","54g USB Network Adapter"};
		InsertProducts(0x0681, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7000};
		char* mids[] = {"HSDPA Modem"};
		InsertProducts(0x0685, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2001,0x2004,0x2005,0x3001,0x3005,0x3006,0x3009,0x300b,0x300c,0x302e,0x3034,0x4001,0x4003,0x4004,0x4005,0x4006,0x4007,0x4008,0x4009,0x400a,
		0x400b,0x400c,0x400d,0x400e,0x400f,0x4010,0x4011,0x4012,0x4014,0x4015,0x4016,0x4017,0x4018,0x4019,0x401a,0x401c,0x401e};
		char* mids[] = {"PagePro 4110W","PagePro 1200W","Magicolor 2300 DL","PagePro 4100","PagePro 1250E",
		"PagePro 1250W","Magicolor 2300W","PagePro 1350W","PagePro 1300W","Develop D 1650iD PCL",
		"Develop D 2050iD PCL","Dimage 2300","Dimage 2330 Zoom Camera","Dimage Scan Elite II AF-2920 (2888)","Minolta DiMAGE E201 Mass Storage Device",
		"Dimage 7 Camera","Dimage S304 Camera","Dimage 5 Camera","Dimage X Camera","Dimage S404 Camera",
		"Dimage 7i Camera","Dimage F100 Camera","Dimage Scan Dual III AF-2840 (2889)","Dimage Scan Elite 5400 (2890)","Dimage 7Hi Camera",
		"Dimage Xi Camera","Dimage F300 Camera","Dimage F200 Camera","Dimage S414 Camera","Dimage XT Camera [storage]",
		"Dimage XT Camera [remote mode]","Dimage E223","Dimage Z1  Camera","Dimage A1 Camera [remote mode]","Dimage A1 Camera [storage]",
		"Dimage X20 Camera","Dimage E323 Camera"};
		InsertProducts(0x0686, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00d3,0x00e2,0x00f1,0x00f2,0x00f3,0x00f4,0x00fa,0x00ff,0x0500,0x0501,0x0504};
		char* mids[] = {"OEM 3 axis 5 button joystick","HFX OEM Joystick","Pro Throttle","Flight Sim Pedals","Fighterstick",
		"Combatstick","Ch Throttle Quadrant","Flight Sim Yoke","GameStick 3D","CH Pro Pedals",
		"F-16 Combat Stick"};
		InsertProducts(0x068e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0003,0x0005,0x0006,0x0007,0x000a};
		char* mids[] = {"FlashGate SmartMedia Card Reader","FlashGate CompactFlash Card Reader","FlashGate","SM PCCard R/W and SPD","FlashGate ME (Authenticated)",
		"SDCard/MMC Reader/Writer"};
		InsertProducts(0x0693, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"Mindstorms Tower","Mindstorms NXT"};
		InsertProducts(0x0694, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1786,0x2003,0x9999};
		char* mids[] = {"1300ex Monitor","CTX M730V built in Camera","VLxxxx Monitor+Hub"};
		InsertProducts(0x0698, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0347};
		char* mids[] = {"AFG 3022B"};
		InsertProducts(0x0699, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0303,0x0311,0x0318,0x0319,0x0320,0x0321,0x0402,0x0811,0x0821,0x4402,0x4403,0x4501};
		char* mids[] = {"VC010 Webcam [pwc]","Cable Modem","ADSL Router Remote NDIS Device","Remote NDIS Device","220V Remote NDIS Device",
		"IEEE 802.11b Wireless LAN Card","Dynalink WLL013 / Compex WLU11A 802.11b Adapter","Scientific Atlanta WebSTAR 100 & 200 series Cable Modem","BT Virtual Bus for Helium","BT Voyager 1010 802.11b Adapter",
		"Scientific Atlanta WebSTAR 2000 series Cable Modem","Scientific Atlanta WebSTAR 300 series Cable Modem","Scientific-Atlanta WebSTAR 2000 series Cable Modem"};
		InsertProducts(0x069a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0704,0x0705,0x0709,0x070c,0x070d,0x070e,0x070f,0x0731,0x0761,0x0778,0x2220,0x300a,0x3012,0x3013,0x5557};
		char* mids[] = {"DCM245 Cable Modem","THG540K Cable Modem","Lyra PDP2424","MP3 Player","MP3 Player",
		"MP3 Player","RCA Lyra RD1071 MP3 Player","Lyra M200E256","RCA H100A","PEARL USB Device",
		"RCA Kazoo RD1000 MP3 Player","RCA Lyra MP3 Player","MP3 Player","MP3 Player","RCA CDS6300"
		};
		InsertProducts(0x069b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"Satellite Receiver Device","Satellite Device"};
		InsertProducts(0x069d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005};
		char* mids[] = {"Marx CryptoBox v1.2"};
		InsertProducts(0x069e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010,0x0011,0x1000,0x1004};
		char* mids[] = {"Tornado Speakerphone FaxModem 56.0","Tornado Speakerphone FaxModem 56.0","ADT VvBus for CopperJet","CopperJet 821 RouterPlus"};
		InsertProducts(0x069f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0033};
		char* mids[] = {"USB Mouse"};
		InsertProducts(0x06a2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0006,0x0109,0x0160,0x0200,0x0241,0x0255,0x040b,0x040c,0x0422,0x0460,0x0463,0x0464,0x0471,0x0501,0x0502,0x0506,0x051e,0x052d,0x053c,0x053f,
		0x056c,0x056f,0x05d2,0x075c,0x0762,0x0763,0x0764,0x0805,0x0b4e,0x0bac,0x0c2d,0x0d05,0x0d06,0x0d67,0x1003,0x1009,0x100a,0x100b,0x1509,0x1589,
		0x2541,0x3509,0x353e,0x3589,0x35be,0x5509,0x712c,0x8000,0x801e,0x8020,0x8021,0x802d,0x803f,0x806f,0x80c0,0x80c1,0xa2ae,0xa502,0xf518,0xff04,
		0xff0c,0xff0d,0xff12,0xff17,0xff52,0xffb5};
		char* mids[] = {"Cyborg Gold Joystick","P880 Pad","ST290 Pro","Xbox Adrenalin Hub","Xbox Adrenalin Gamepad",
		"X52 Flight Controller","P990 Dual Analog Pad","P2900 Wireless Pad","ST90 Joystick","ST290 Pro Flight Stick",
		"ST290","Cyborg Evo","Cyborg Graphite Stick","R100 Sports Wheel","ST200 Stick",
		"R220 Digital Wheel","Cyborg Digital II Stick","P750 Gamepad","X45 Flight Controller","X36F Flightstick",
		"P2000 Tilt Pad","P2000 Tilt Pad","PC Dash 2","X52 Flight Controller","Saitek X52 Pro Flight Control System",
		"Pro Flight Rudder Pedals","Flight Pro Combat Rudder","R440 Force Wheel","Pro Flight Backlit Information Panel","Pro Flight Yoke",
		"Pro Flight Quadrant","Pro Flight Radio Panel","Flight Pro Multi Panel","Pro Flight Switch Panel","GM2 Action Pad",
		"Action Pad","SP550 Pad and Joystick Combo","SP550 Pad","P3000 Wireless Pad","P3000 Wireless Pad",
		"X45 Flight Controller","P3000 RF GamePad","Cyborg Evo Wireless","P3000 Wireless Pad","Cyborg Evo",
		"P3000 Wireless Pad","Pro Flight Yoke integrated hub","Gamers' Keyboard","Cyborg 3D Digital Stick II","Eclipse Keyboard",
		"Eclipse II Keyboard","P750 Pad","X36 Flight Controller","P2000 Tilt Pad","Pro Gamer Command Unit",
		"Cyborg Command Pad Unit","Pro Flight Instrument Panel","Gaming Mouse","P3200 Rumble Force Game Pad","R440 Force Wheel",
		"Cyborg Force Rumble Pad","P2600 Rumble Force Pad","Cyborg 3D Force Stick","ST 330 Rumble Force Stick","Cyborg 3D Rumble Force Joystick",
		"Cyborg Evo Force Joystick"};
		InsertProducts(0x06a3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0xd001,0xd800,0xd820};
		char* mids[] = {"Typhoon Webcam 100k [nw8000]","ProLink DS3303u Webcam","Chicony TwinkleCam","Wize Media 1000"};
		InsertProducts(0x06a5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0042,0x0043};
		char* mids[] = {"SignatureGem 1X5 Pad","SignatureGem 1X5-HID Pad"};
		InsertProducts(0x06a8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005,0x0006,0x000a,0x000b,0x000e};
		char* mids[] = {"WireSpeed Dual Connect Modem","WireSpeed Dual Connect Modem","WireSpeed Dual Connect Modem","WireSpeed Dual Connect Modem","A90-211WG-01 802.11g Adapter [Intersil ISL3887]"
		};
		InsertProducts(0x06a9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0120,0x0121,0x2001,0x4061,0x4062,0xa5a5};
		char* mids[] = {"SpeedTouch 120g 802.11g Wireless Adapter [Intersil ISL3886]","SpeedTouch 121g Wireless Dongle","SPEED TOUCH Card","SpeedTouch ISDN or ADSL Modem","SpeedTouch ISDN or ADSL router",
		"DynaMiTe Modem"};
		InsertProducts(0x06b9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000b,0x0027,0x00f7,0x015e,0x01c9,0x020b,0x02bb,0x0a91,0x3801};
		char* mids[] = {"Okipage 14ex Printer","Okipage 14e","OKI B4600 Mono Printer","OKIPOS 411/412 POS Printer","OKI B430 Mono Printer",
		"OKI ES4140 Mono Printer","OKI PT390 POS Printer","B2500MFP (printer+scanner)","B6100 Laser Printer"};
		InsertProducts(0x06bc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0100,0x0101,0x0200,0x02bf,0x0400,0x0401,0x0403,0x0404,0x2061,0x208d,0x208f,0x2091,0x2093,0x2095,0x2097,0x20fd,0x20ff};
		char* mids[] = {"SnapScan 1212U","SnapScan 1236U","SnapScan Touch","SNAPSCAN ELITE","ScanMaker 8700",
		"DUOSCAN f40","CL30","Mass Storage","ePhoto CL18 Camera","ePhoto CL20 Camera",
		"SnapScan 1212U (?)","Snapscan e40","SnapScan e50","SnapScan e20","SnapScan e10",
		"SnapScan e25","SnapScan e26","SnapScan e52","SnapScan e42"};
		InsertProducts(0x06bd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0800,0x1005,0xd001};
		char* mids[] = {"Optimedia Camera","Dazzle DPVM! (1005)","P35U Camera Capture"};
		InsertProducts(0x06be, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0030,0x0031,0x0038,0x0039,0x003a,0x0040,0x0044,0x0045,0x0048,0x0049,0x004a,0x004b,0x0051,0x0052,0x0053,0x0058,0x0070,0x0071,0x0072,0x0073,
		0x0074,0x0075};
		char* mids[] = {"PhidgetRFID","RFID reader","4-Motor PhidgetServo v3.0","1-Motor PhidgetServo v3.0","8-Motor PhidgetAvancedServo",
		"PhidgetInterface Kit 0-0-4","PhidgetInterface Kit 0-16-16","PhidgetInterface Kit 8-8-8","PhidgetStepper (Under Development)","PhidgetTextLED Ver 1.0",
		"PhidgetLED Ver 1.0","PhidgetEncoder Ver 1.0","PhidgetInterface Kit 0-5-7 (Custom)","PhidgetTextLCD","PhidgetInterfaceKit 0-8-8",
		"PhidgetMotorControl Ver 1.0","PhidgetTemperatureSensor Ver 1.0","PhidgetAccelerometer Ver 1.0","PhidgetWeightSensor Ver 1.0","PhidgetHumiditySensor",
		"PhidgetPHSensor","PhidgetGyroscope"};
		InsertProducts(0x06c2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005,0x0007,0x0009};
		char* mids[] = {"Monitor Control","Monitor Control","Monitor Control"};
		InsertProducts(0x06c9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0005,0x0006,0x0007,0x0008,0x0009,0x000e,0x0010,0x0013};
		char* mids[] = {"TouchPad","Integrated TouchPad","cPad","Touchpad/FPS","TouchScreen",
		"USB Styk","WheelPad","Composite TouchPad and TrackPoint","HID Device","Wireless TouchPad",
		"DisplayPad"};
		InsertProducts(0x06cb, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0102,0x0103,0x0104,0x0304};
		char* mids[] = {"Cable Modem","Cable Modem","Cable Modem","Cable Modem","Cable Modem"
		};
		InsertProducts(0x06cc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0102,0x0103,0x0104,0x0105,0x0106,0x0107,0x0108,0x0109,0x010a,0x010b,0x010c,0x010d,0x010e,0x010f,0x0110,0x0111,0x0112,0x0113,0x0114,
		0x0115,0x0116,0x0117,0x0118,0x0119,0x011a,0x011b,0x011c,0x011d,0x011e,0x0121,0x012a,0x0201,0x0202};
		char* mids[] = {"USA-28 PDA [no firmware]","USA-28X PDA [no firmware]","USA-19 PDA [no firmware]","PDA [prerenum]","USA-18X PDA [no firmware]",
		"USA-19W PDA [no firmware]","USA-19 PDA","USA-19W PDA","USA-49W serial adapter [no firmware]","USA-49W serial adapter",
		"USA-19Qi serial adapter [no firmware]","USA-19Qi serial adapter","USA-19Q serial Adapter (no firmware)","USA-19Q serial Adapter","USA-28 PDA",
		"USA-28Xb PDA","USA-18 serial Adapter","USA-18X PDA","USA-28Xb PDA [no firmware]","USA-28Xa PDA [no firmware]",
		"USA-28Xa PDA","USA-18XA serial Adapter (no firmware)","USA-18XA serial Adapter","USA-19QW PDA [no firmware]","USA-19QW PDA",
		"USA-49Wlc serial adapter [no firmware]","MPR Serial Preloader (MPRQI)","MPR Serial (MPRQI)","MPR Serial Preloader (MPRQ)","MPR Serial (MPRQ)",
		"USA-19hs serial adapter","USA-49Wlc serial adapter","UIA-10 Digital Media Remote [Cypress AN2131SC]","UIA-11 Digital Media Remote"};
		InsertProducts(0x06cd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8311};
		char* mids[] = {"COM-1(USB)H"};
		InsertProducts(0x06ce, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1010,0x1012};
		char* mids[] = {"PanoCam 10","PanoCam 12/12X"};
		InsertProducts(0x06cf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0622};
		char* mids[] = {"LapLink Gold USB-USB Bridge [net1080]"};
		InsertProducts(0x06d0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0284,0x0380,0x0381,0x0385,0x0387,0x038b,0x038c,0x0393,0x0394,0x03a1,0x3b30,0x3b31};
		char* mids[] = {"FX-USB-AW/-BD RS482 Converters","CP8000D Port","CP770D Port","CP900D Port","CP980D Port",
		"CP3020D Port","CP900DW(ID) Port","CP9500D/DW Port","CP9000D/DW Port","CP9550D/DW Port",
		"CP-D70DW / CP-D707DW","CP-K60DW-S"};
		InsertProducts(0x06d3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4000};
		char* mids[] = {"Japanese Keyboard"};
		InsertProducts(0x06d5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0025,0x0026,0x002d,0x002e,0x0030,0x0031,0x003a,0x003b,0x003c,0x003f,0x0050,0x0062,0x0066,0x0067,0x006b};
		char* mids[] = {"Gamepad","Predator TH 400 Gamepad","Trust PowerC@m 350FT","Trust PowerC@m 350FS","Trust 710 LCD POWERC@M ZOOM - MSD",
		"Trust 610/710 LCD POWERC@M ZOOM","Trust PowerC@m 770Z (mass storage mode)","Trust PowerC@m 770Z (webcam mode)","Trust 910z PowerC@m","Trust 735S POWERC@M ZOOM, WDM DSC Bulk Driver",
		"Trust 738AV LCD PV Digital Camera","TRUST 782AV LCD P. V. Video Capture","TRUST Digital PCTV and Movie Editor","Trust 350FS POWERC@M FLASH","TRUST AUDIO VIDEO EDITOR"
		};
		InsertProducts(0x06d6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0003};
		char* mids[] = {"UPS","1300VA UPS"};
		InsertProducts(0x06da, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0012,0x0014};
		char* mids[] = {"Scan 1200c Scanner","Prolink Winscan Pro 2448U"};
		InsertProducts(0x06dc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0319,0xf101,0xf103,0xf104,0xf107,0xf120};
		char* mids[] = {"MT9234ZBA-USB MultiModem ZBA","MT5634ZBA-USB MultiModemUSB (old firmware)","MT5634MU MultiMobileUSB","MT5634ZBA-USB MultiModemUSB (new firmware)","MT5634ZBA-USB-V92 MultiModemUSB",
		"MT9234ZBA-USB-CDC-ACM-XR MultiModem ZBA CDC-ACM-XR"};
		InsertProducts(0x06e0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0008,0x0009,0x0833,0xa155,0xa160,0xa161,0xa190,0xa191,0xa337,0xa701,0xa708,0xb337,0xb701};
		char* mids[] = {"UBS-10BT Ethernet [klsi]","UBS-10BT Ethernet","Mass Storage Device","FM Radio Receiver/Instant FM Music (RDX-155-EF)","Instant Video-To-Go RDX-160 (no firmware)",
		"Instant Video-To-Go RDX-160","Instand VCD Capture","Instant VideoXpress","Mini DigitalTV","DVD Xpress",
		"saa7114H video input card (Instant VideoMPX)","Mini DigitalTV","DVD Xpress B"};
		InsertProducts(0x06e1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0200,0x0201,0x0202,0x0203,0x0210,0x0211,0x0212,0x031c,0x031d,0x031e,0x3200,0x3201,0x3202,0x3203,0x7200,0x7210,0x7250,0x825c,0x831c,0x831d,
		0x831e,0xb200,0xb201,0xb202,0xb210,0xb211,0xb212,0xb250,0xb251,0xb252,0xc200,0xc201,0xc202,0xc203,0xc210,0xc211,0xc212,0xc213,0xc25c,0xc290,
		0xc291,0xc292,0xc293,0xc31c,0xc39c,0xc39d,0xc39e,0xc39f,0xc700,0xc701,0xc702,0xc703,0xc710,0xc711,0xc712,0xc713,0xcf00,0xcf01,0xcf02,0xcf03,
		0xd210,0xd211,0xd212,0xd213,0xd700,0xd701,0xd702,0xd703,0xd710,0xd711,0xd712,0xd713,0xdf00,0xdf01,0xdf02,0xdf03,0xf200,0xf201,0xf202,0xf203,
		0xf210,0xf250,0xf252,0xf310,0xf350};
		char* mids[] = {"Internet Phone","Internet Phone","Composite Device","Internet Phone","Composite Device",
		"Internet Phone","Internet Phone","Internet Phone","Internet Phone","Internet Phone",
		"Composite Device","Internet Phone","Composite Device","Composite Device","Composite Device",
		"Composite Device","Composite Device","Internet Phone","Internet Phone","Composite Device",
		"Composite Device","Composite Device","Composite Device","Internet Phone","Internet Phone",
		"Composite Device","Composite Device","Composite Device","Internet Phone","Internet Phone",
		"Internet Phone","Internet Phone","Composite Device","Internet Phone","Personal PhoneGateway",
		"Personal PhoneGateway","Personal PhoneGateway","PPG Device","Composite Device","PPG Device",
		"PPG Device","PPG Device","Personal PhoneGateway","Composite Device","Personal PhoneGateway",
		"PPG Device","PPG Device","PPG Device","Internet Phone","Internet Phone",
		"Composite Device","Internet Phone","VoIP Combo Device","VoIP Combo","VoIP Combo Device",
		"VoIP Combo Device","Composite Device","Internet Phone","Internet Phone","Composite Device",
		"Personal PhoneGateway","PPG Device","PPG Device","Personal PhoneGateway","Composite Device",
		"Composite Device","Internet Phone","Composite Device","VoIP Combo","VoIP Combo Device",
		"VoIP Combo","VoIP Combo","Composite Device","Composite Device","Internet Phone",
		"Internet Phone","Internet Phone","Internet Phone","Composite Device","Composite Device",
		"Internet Phone","Composite Device","Internet Phone","Internet Phone","Composite Device"
		};
		InsertProducts(0x06e6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"NetCom Roadster II 56k","Roadster II 56k"};
		InsertProducts(0x06ea, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xde01,0xde02};
		char* mids[] = {"DualCam Video Camera","DualCam Still Camera"};
		InsertProducts(0x06f0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa011,0xa021};
		char* mids[] = {"SonicPort","SonicPort Optical"};
		InsertProducts(0x06f1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0011};
		char* mids[] = {"KVM Switch Keyboard"};
		InsertProducts(0x06f2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003};
		char* mids[] = {"USB->Din 4 Adaptor"};
		InsertProducts(0x06f7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3002,0x3004,0x3005,0x3007,0x3020,0xa300,0xb000,0xc000,0xd002,0xe000,0xe010,0xe020,0xe031,0xe032,0xe033};
		char* mids[] = {"Hercules Blog Webcam","Hercules Classic Silver","Hercules Dualpix Exchange","Hercules Dualpix Chat and Show","Hercules Webcam EC300",
		"Dual Analog Leader GamePad","Hercules DJ Console","Hercules Muse Pocket","Hercules DJ Console","HWGUSB2-54 WLAN",
		"HWGUSB2-54-LB","HWGUSB2-54V2-AP","Hercules HWNUm-300 Wireless N mini [Realtek RTL8191SU]","HWGUm-54 [Hercules Wireless G Ultra Mini Key]","Hercules HWNUp-150 802.11n Wireless N Pico [Realtek RTL8188CUS]"
		};
		InsertProducts(0x06f8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0102,0x0201};
		char* mids[] = {"Audio Device","Audio Device","2-piece Audio Device"};
		InsertProducts(0x06fd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0200,0x0201,0xee04,0xee06,0xee13};
		char* mids[] = {"2202 Ethernet [klsi]","2202 Ethernet [pegasus]","EZ Connect USB Ethernet","SMCWUSB32 802.11b Wireless LAN Card","SMC2862W-G v1 EZ Connect 802.11g Adapter [Intersil ISL3886]",
		"SMC2862W-G v2 EZ Connect 802.11g Adapter [Intersil ISL3887]"};
		InsertProducts(0x0707, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x047e};
		char* mids[] = {"USB-1284 BRIDGE"};
		InsertProducts(0x0708, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4002,0x4003};
		char* mids[] = {"Bluetooth Device","Bluetooth Device"};
		InsertProducts(0x070a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x8001};
		char* mids[] = {"WhiteHeat (fake ID)","WhiteHeat"};
		InsertProducts(0x0710, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0180,0x0181,0x0200,0x0210,0x0230,0x0231,0x0232,0x0240,0x0300,0x0302,0x0900,0x5001,0x5100};
		char* mids[] = {"Hub","IRXpress Infrared Device","IRXpress Infrared Device","BAY-3U1S1P Serial Port","MCT1S Serial Port",
		"MCT-232 Serial Port","PS/2 Mouse Port","Serial On Port","PS/2 to USB Converter","BAY-3U1S1P Parallel Port",
		"Parallel Port","SVGA Adapter","Trigger UV-002BD[Startech USBVGAE]","Magic Control Technology Corp. (USB2VGA dongle)"};
		InsertProducts(0x0711, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003};
		char* mids[] = {"ADB to USB convertor"};
		InsertProducts(0x0714, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0003,0x0060,0x0061,0x0062,0x0063,0x0064,0x0065,0x0066,0x0067,0x0068,0x0084,0x043c,0x0582,0x0622,0x0624,0x1120,0xd000};
		char* mids[] = {"SuperDisk 120MB","SuperDisk 120MB (Authenticated)","Flash Drive","Flash Drive","Flash Drive",
		"Swivel Flash Drive","Flash Drive","Flash Drive","Flash Drive","Flash Drive",
		"Flash Drive","Flash Drive Mini","Flash drive 16GB [Nano Pro]","Revo Flash Drive","TDK Trans-It 4GB",
		"TDK Trans-It 16GB","RDX External dock (redbud)","Disc Stakka CD/DVD Manager"};
		InsertProducts(0x0718, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0101,0x0201,0x0301,0x3203,0x32bb};
		char* mids[] = {"DTI-56362-USB Digital Interface Unit","Audio4-USB DSP Data Acquisition Unit","Audio4-5410 DSP Data Acquisition Unit","SB-USB JTAG Emulator","Rockchip Media Player",
		"Music Mediatouch"};
		InsertProducts(0x071b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x1003,0x2000};
		char* mids[] = {"Diva ISDN TA","Diva","Teledat Surf"};
		InsertProducts(0x071d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"Palladia 300/400 Adsl Modem"};
		InsertProducts(0x0723, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000};
		char* mids[] = {"USC-1000 Serial Port"};
		InsertProducts(0x0729, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0008,0x1000,0x1001,0x2200,0x8002,0x8003,0x8103,0x9000,0x90cc,0x90cf,0x90d0};
		char* mids[] = {"AC1030-based SmartCard Reader","ACR 80 Smart Card Reader","PLDT Drive","PLDT Drive","ACR122U",
		"AET63 BioTRUSTKey","ACR120","ACR120","ACR38 AC1038-based Smart Card Reader","ACR38 SmartCard Reader",
		"ACR38 SAM Smart Card Reader","PertoSmart EMV - Card Reader"};
		InsertProducts(0x072f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0528};
		char* mids[] = {"SonyEricsson DCU-11 Cable"};
		InsertProducts(0x0731, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0110,0x0401,0x0402,0x0430,0x0630,0x0631,0x0780,0x1310,0x1311,0x1314,0x2211,0x2221,0x3261,0x3281};
		char* mids[] = {"Digital Video Camera","VQ110 Video Camera","CS330 Webcam","M-318B Webcam","Intel Pro Share Webcam",
		"VQ630 Dual Mode Digital Camera(Bulk)","Hercules Dualpix","Smart Cam Deluxe(composite)","Epsilon 1.3/Jenoptik JD C1.3/UMAX AstraPix 470","Digital Dream Epsilon 1.3",
		"Mercury 2.1MEG Deluxe Classic Cam","Jenoptik jdc 21 LCD Camera","Mercury Digital Pro 3.1p","Concord 3045 spca536a Camera","Cyberpix S550V"
		};
		InsertProducts(0x0733, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x043a,0x043b};
		char* mids[] = {"560V Modem","Lasat 560V Modem","DVS Audio","3DeMon USB Capture"};
		InsertProducts(0x0734, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2100,0x2101,0x6694,0xc541};
		char* mids[] = {"ISDN Adapter","ISDN Adapter","ISDNlink 128K","ISDN TA 280"};
		InsertProducts(0x0735, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4507,0x4516,0x4520,0x4526,0x4536,0x4540,0x4556,0x4566,0x4576,0x4586,0x4588,0x8818};
		char* mids[] = {"XBox Device","XBox Device","XBox Device","XBox Device","XBox Device",
		"XBox Device","XBox Device","XBox Device","XBox Device","XBox Device",
		"XBox Device","Street Fighter IV Arcade FightStick (PS3)"};
		InsertProducts(0x0738, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2230};
		char* mids[] = {"infrared dongle for remote"};
		InsertProducts(0x073a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0305,0x0322,0x0324,0x0330,0x0424,0x0450,0x0505,0x0522,0x0624};
		char* mids[] = {"Pole Display (PC305-3415  2 x 20 Line Display)","Pole Display (PC322-3415  2 x 20 Line Display)","Pole Display (LB324-USB   4 x 20 Line Display)","Pole Display (P330-3415   2 x 20 Line Display)","Pole Display (SP324-4415  4 x 20 Line Display)",
		"Pole Display (L450-USB   Graphic Line Display)","Pole Display (SPC505-3415 2 x 20 Line Display)","Pole Display (SPC522-3415 2 x 20 Line Display)","Pole Display (SP324-3415  4 x 20 Line Display)"};
		InsertProducts(0x073c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005,0x0007,0x0025,0x0c00,0x0d00};
		char* mids[] = {"Crypto Token","CryptoIdentity CCID","SmartKey 3","Pocket Reader","StarSign Bio Token 3.0 EU"
		};
		InsertProducts(0x073d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0301};
		char* mids[] = {"Game Pad"};
		InsertProducts(0x073e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5500};
		char* mids[] = {"SE-U55 Audio Device"};
		InsertProducts(0x0746, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3553,0x3554,0x3556};
		char* mids[] = {"Composite USB-Device","Composite USB-Device","Composite USB-Device"};
		InsertProducts(0x074d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"PS/2 Adapter","PS/2 Adapter"};
		InsertProducts(0x074e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Kick-off! Watchdog"};
		InsertProducts(0x075b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0115,0x0117,0x0119,0x0150,0x0160,0x0192,0x0193,0x0194,0x0195,0x0196,0x0197,0x0198,0x0199,0x019a,0x019b,0x019c,0x1001,0x1002,0x1003,0x1010,
		0x1011,0x1014,0x1015,0x1020,0x1021,0x1030,0x1031,0x1033,0x1040,0x1041,0x1110,0x2001,0x2002,0x2003,0x2004,0x2006,0x2007,0x2008,0x200d,0x200f,
		0x2010,0x2012,0x2013,0x2015,0x2016,0x2019,0x201a,0x201b,0x201d,0x2024,0x2080,0x2081,0x2803,0x2804,0x2806,0x2815,0x2816,0x281b,0x2880,0x2881
		};
		char* mids[] = {"O2 / KeyRig 25","Trigger Finger","MidAir","M-Audio Uno","M-Audio 1x1",
		"M-Audio Keystation 88es","ProKeys 88","ProKeys 88sx","Oxygen 8 v2","Oxygen 49",
		"Oxygen 61","Axiom 25","Axiom 49","Axiom 61","KeyRig 49",
		"KeyStudio","MidiSport 2x2","MidiSport 2x2","MidiSport 2x2","MidiSport 1x1",
		"MidiSport 1x1","M-Audio Keystation Loader","M-Audio Keystation","Midisport 4x4","MidiSport 4x4",
		"Midisport 8x8","MidiSport 8x8/s Loader","MidiSport 8x8/s","M-Audio MidiSport 2x4 Loader","M-Audio MidiSport 2x4",
		"MidiSport 1x1","M Audio Quattro","M Audio Duo","M Audio AudioPhile","M-Audio MobilePre",
		"M-Audio Transit","M-Audio Sonica Theater","M-Audio Ozone","M-Audio OmniStudio","M-Audio MobilePre",
		"M-Audio Fast Track","M-Audio Fast Track Pro","M-Audio JamLab","M-Audio RunTime DFU","M-Audio RunTime DFU",
		"M-Audio Ozone Academic","M-Audio Micro","M-Audio RunTime DFU","M-Audio Producer","M-Audio Fast Track MKII",
		"M-Audio RunTime DFU","M-Audio RunTime DFU / Fast Track Ultra 8R","M-Audio Audiophile DFU","M-Audio MobilePre DFU","M-Audio Transit DFU",
		"M-Audio DFU","M-Audio DFU","M-Audio DFU","M-Audio DFU","M-Audio DFU"
		};
		InsertProducts(0x0763, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005,0x0501};
		char* mids[] = {"Cyber Power UPS","CP1500 AVR UPS"};
		InsertProducts(0x0764, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5001,0x5020,0x6003,0xd094};
		char* mids[] = {"Huey PRO Colorimeter","i1 Display Pro","ColorMunki Smile","X-Rite DTP94 [Quato Silver Haze Pro]"};
		InsertProducts(0x0765, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x001b,0x0204};
		char* mids[] = {"Packard Bell Go","TopSpeed Cyberlink Remote Control"};
		InsertProducts(0x0766, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0006,0x0023};
		char* mids[] = {"Camtel Technology USB TV Genie Pro FM Model TVB330","eHome Infrared Receiver"};
		InsertProducts(0x0768, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x11f2,0x11f3,0x11f7,0x31f3};
		char* mids[] = {"EP-9001-g 802.11g 54M WLAN Adapter","RT2570","802.11g 54M WLAN Adapter","RT2573"};
		InsertProducts(0x0769, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0596,0x1021,0x1221,0x1784,0x3021,0x3610,0x3621,0x3821,0x4321,0x5121,0x5125,0x6622,0xa011,0xa021,0xa022,0xc000,0xc001};
		char* mids[] = {"CardMan 2020","CardMan 1021","CardMan 1221","CardMan 6020","CardMan 3121",
		"CardMan 3620","CardMan 3621","CardMan 3821","CardMan 4321","CardMan 5121",
		"CardMan 5125","CardMan 6121","CCID Smart Card Reader Keyboard","CCID Smart Card Reader","CardMan Smart@Link",
		"CardMan 3x21 CS","CardMan 5121 CS"};
		InsertProducts(0x076b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4455,0xae0f};
		char* mids[] = {"OMC45III","OMC45III"};
		InsertProducts(0x0771, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x08be,0x2219,0x2226,0x2227};
		char* mids[] = {"BEFCMU10 v4 Cable Modem","WUSB11 V2.6 802.11b Adapter","USB200M 100baseTX Adapter","Network Everywhere NWU11B"};
		InsertProducts(0x077b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005};
		char* mids[] = {"NEC Keyboard"};
		InsertProducts(0x077c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0223,0x0405,0x0410,0x041a,0x04aa,0x07af,0x1016,0x627a};
		char* mids[] = {"IMic Audio In/Out","iMate, ADB Adapter","PowerMate","PowerWave","SoundKnob",
		"iMic","AirClick","Radio SHARK"};
		InsertProducts(0x077d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1202,0x1302,0x1303,0xdf55};
		char* mids[] = {"ORGA 900 Smart Card Terminal Virtual Com Port","ORGA 6000 Smart Card Terminal Virtual Com Port","ORGA 6000 Smart Card Terminal USB RNDIS","ORGA 900/6000 Smart Card Terminal DFU"};
		InsertProducts(0x0780, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0005,0x0100,0x0200,0x0400,0x0621,0x0720,0x0729,0x0810,0x0830,0x1234,0x5150,0x5151,0x5153,0x5204,0x5402,0x5406,0x5408,0x540e,
		0x5530,0x5567,0x556c,0x556d,0x5571,0x5576,0x5580,0x5581,0x5e10,0x6100,0x7100,0x7101,0x7102,0x7103,0x7104,0x7105,0x7106,0x7112,0x7113,0x7114,
		0x7115,0x7301,0x7302,0x7400,0x7401,0x7420,0x7421,0x7422,0x7423,0x7430,0x7431,0x7432,0x7433,0x7434,0x7435,0x7450,0x7451,0x7460,0x7480,0x7481,
		0x74b0,0x74b1,0x74c0,0x74c1,0x74c2,0x74c3,0x74d0,0x74d1,0x8181,0x8183,0x8185,0x8888,0x8889,0x8919,0x8989,0x9191,0x9219,0x9292,0x9393,0x9595,
		0x9797,0x9919,0x9999,0xa7c1,0xa7e8,0xb2b3,0xb4b5};
		char* mids[] = {"SDDR-05a ImageMate CompactFlash Reader","SDDR-31 ImageMate II CompactFlash Reader","SDDR-05b (CF II) ImageMate CompactFlash Reader","ImageMate SDDR-12","SDDR-09 (SSFDC) ImageMate SmartMedia Reader [eusb]",
		"SecureMate SD/MMC Reader","SDDR-86 Imagemate 6-in-1 Reader","Sansa C200 series in recovery mode","Sansa E200 series in recovery mode","SDDR-75 ImageMate CF-SM Reader",
		"ImageMate CF/MMC/SD Reader","Cruzer Mini Flash Drive","SDCZ2 Cruzer Mini Flash Drive (thin)","Cruzer Micro Flash Drive","Cruzer Flash Drive",
		"Cruzer Crossfire","U3 Cruzer Micro","Cruzer Micro U3","Cruzer Titanium U3","Cruzer Contour Flash Drive",
		"Cruzer","Cruzer Blade","Ultra","Memory Vault","Cruzer Fit",
		"Cruzer Facet","SDCZ80 Flash Drive","Ultra","Encrypted","Ultra II SD Plus 2GB",
		"Cruzer Mini","Pen Flash","Cruzer Mini","Cruzer Mini","Cruzer Micro Mini 256MB Flash Drive",
		"Cruzer Mini","Cruzer Mini","Cruzer Micro 128MB Flash Drive","Cruzer Micro 256MB Flash Drive","Cruzer Mini",
		"Cruzer Mini","Sansa e100 series (mtp)","Sansa e100 series (msc)","Sansa M200 series (mtp)","Sansa M200 series (msc)",
		"Sansa E200 series (mtp)","Sansa E200 Series (msc)","Sansa E200 series v2 (mtp)","Sansa E200 series v2 (msc)","Sansa M200 series",
		"Sansa M200 series V4 (msc)","Sansa Clip (mtp)","Sansa Clip (msc)","Sansa Clip V2 (mtp)","Sansa Clip V2 (msc)",
		"Sansa C250","Sansa C240","Sansa Express","Sansa Connect","Sansa Connect (in recovery mode)",
		"Sansa View (msc)","Sansa View (mtp)","Sansa Fuze (mtp)","Sansa Fuze (msc)","Sansa Fuze V2 (mtp)",
		"Sansa Fuze V2 (msc)","Sansa Clip+ (mtp)","Sansa Clip+ (msc)","Pen Flash","Hi-Speed Mass Storage Device",
		"SDCZ2 Cruzer Mini Flash Drive (older, thick)","Card Reader","SDDR-88 Imagemate 8-in-1 Reader","Card Reader","ImageMate 12-in-1 Reader",
		"ImageMate CF","Card Reader","ImageMate CF Reader/Writer","ImageMate SD-MMC","ImageMate xD-SM",
		"ImageMate MS-PRO","Card Reader","SDDR-99 5-in-1 Reader","Storage device (SD card reader)","SDDR-113 MicroMate SDHC Reader",
		"SDDR-103 MobileMate SD+ Reader","SDDR-89 V4 ImageMate 12-in-1 Reader"};
		InsertProducts(0x0781, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0006,0x0009,0x0010};
		char* mids[] = {"LTC31 SmartCard Reader","LTC31v2","KBR36","LTC32"};
		InsertProducts(0x0783, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x1310,0x1688,0x1689,0x2620,0x2888,0x3330,0x4300,0x5260,0x5300};
		char* mids[] = {"Vivicam 2655","Vivicam 3305","Vivicam 3665","Gateway DC-M42/Labtec DC-505/Vivitar Vivicam 3705","AOL Photocam Plus",
		"Polaroid DC700","Nytec ND-3200 Camera","Traveler D1","Werlisa Sport PX 100 / JVC GC-A33 Camera","Pretec dc530"
		};
		InsertProducts(0x0784, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0003};
		char* mids[] = {"MN128mini-V ISDN TA","MN128mini-J ISDN TA"};
		InsertProducts(0x0785, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0026,0x0033,0x0063,0x0064,0x00b3,0x0105,0x010c,0x0160,0x0162,0x0163,0x0164,0x0166,0x0168,0x0170};
		char* mids[] = {"LHD Device","DVD Multi-plus unit LDR-H443SU2","LDR Device","LDR-R Device","DVD Multi-plus unit LDR-H443U2",
		"LAN-TX/U1H2 10/100 Ethernet Adapter [pegasus II]","Realtek RTL8187 Wireless 802.11g 54Mbps Network Adapter","LAN-GTJ/U2A","LAN-WN22/U2 Wireless LAN Adapter","LAN-WN12/U2 Wireless LAN Adapter",
		"LAN-W150/U2M Wireless LAN Adapter","LAN-W300N/U2 Wireless LAN Adapter","LAN-W150N/U2 Wireless LAN Adapter","LAN-W300AN/U2 Wireless LAN Adapter"};
		InsertProducts(0x0789, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010,0x0020,0x0030};
		char* mids[] = {"Driving UGCI","Flying UGCI","Fighting UGCI"};
		InsertProducts(0x078b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0090,0x0100,0x0200,0x0300,0x0400};
		char* mids[] = {"Tablet Adapter","Tablet Adapter","Tablet Adapter","Tablet Adapter","Digitizer (Whiteboard)"
		};
		InsertProducts(0x078c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6801,0x6802,0x8001,0x801a,0x801c,0x8901,0x8909,0x8911};
		char* mids[] = {"Flatbed Scanner","InkJet Color Printer","SmartCam","Typhoon StyloCam","Meade Binoculars/Camera",
		"ScanHex SX-35a","ScanHex SX-35b","ScanHex SX-35c"};
		InsertProducts(0x0797, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0640,0x0680};
		char* mids[] = {"Braille Voyager","BC640","BC680"};
		InsertProducts(0x0798, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7651};
		char* mids[] = {"Programming Unit"};
		InsertProducts(0x0799, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0024,0x0026,0x0027,0x002f,0x0030,0x0042,0x0047,0x004a,0x004b,0x0052,0x0056,0x005d,0x0062,0x0078};
		char* mids[] = {"MSO300/MSO301 Fingerprint Sensor","MSO350/MSO351 Fingerprint Sensor & SmartCard Reader","USB-Serial Controller","Mobile","Mobile Communication Device",
		"Mobile","CBM/MSO1300 Fingerprint Sensor","XG-760A 802.11bg","Wi-Fi 11g adapter","MSO1350 Fingerprint Sensor & SmartCard Reader",
		"Agfa AP1100 Photo Printer","Mobile Mass Storage","XG-76NA 802.11bg","Laser Pro Monochrome MFP"};
		InsertProducts(0x079b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0201};
		char* mids[] = {"GamePort Adapter"};
		InsertProducts(0x079d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xd952};
		char* mids[] = {"Palladio USB V.92 Modem"};
		InsertProducts(0x07a1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x07c2,0x0986,0x8266,0x8511,0x8513,0x8515};
		char* mids[] = {"AN986A Ethernet","AN986 Pegasus Ethernet","Infineon WildCard-USB Wireless LAN Adapter","ADM8511 Pegasus II Ethernet","AN8513 Ethernet",
		"AN8515 Ethernet"};
		InsertProducts(0x07a6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0004,0x000c,0x000d,0x0011,0x0012,0x0017,0x0018,0x001a,0x001c,0x002e,0x002f,0x0031,0x003c,0x003f,0x0041,0x0042,0x0043,0x0047,0x0051,
		0x7613,0x9601};
		char* mids[] = {"Ether USB-T Ethernet [klsi]","FEther USB-TX Ethernet [pegasus]","WirelessLAN USB-11","FEther USB-TXS","Wireless LAN USB-11 mini",
		"Stick-11 802.11b Adapter","FEther USB2-TX","Wireless LAN USB-11 mini 2","ULUSB-11 Key","CG-WLUSB2GT 802.11g Wireless Adapter [Intersil ISL3880]",
		"CG-WLUSB2GPX [Ralink RT2571W]","CG-WLUSB2GNL","CG-WLUSB2GS 802.11bg [Atheros AR5523]","CG-WLUSB2GNL","CG-WLUSB300AGN",
		"CG-WLUSB300GNS","CG-WLUSB300GNM","CG-WLUSB300N rev A2 [Realtek RTL8192U]","CG-WLUSBNM","CG-WLUSB300NM",
		"Stick-11 V2 802.11b Adapter","FEther USB-TXC"};
		InsertProducts(0x07aa, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xfc01,0xfc02,0xfc03,0xfcd6,0xfcf6,0xfcf8,0xfcfe};
		char* mids[] = {"IDE bridge","Cable II USB-2","USB2-IDE IDE bridge","Freecom HD Classic","DataBar 512 MB",
		"Freecom Classic SL Network Drive","Hard Drive 80GB"};
		InsertProducts(0x07ab, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004,0x0005,0x0006,0xfc01};
		char* mids[] = {"SCSI-DB25 SCSI Bridge [shuttle]","SCSI-HD50 SCSI Bridge [shuttle]","CameraMate SmartMedia and CompactFlash Card Reader [eusb/shuttle]","Freecom USB-IDE"};
		InsertProducts(0x07af, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0005,0x0006,0x0007,0x0008};
		char* mids[] = {"ISDN TA","ISDN TA128 Plus","ISDN TA128 Deluxe","ISDN TA128 SE","ISDN TA128 CE",
		"ISDN TA","ISDN TA"};
		InsertProducts(0x07b0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0900,0x0950,0x1000,0x4100,0x4200,0x4210,0x4220,0x4500,0x450b,0x450e,0x5100,0x5101,0x5120,0x5121,0x7030};
		char* mids[] = {"SURFboard Voice over IP Cable Modem","SURFboard Gateway","SURFboard SBG950 Gateway","SURFboard SBG1000 Gateway","SurfBoard SB4100 Cable Modem",
		"SurfBoard SB4200 Cable Modem","SurfBoard 4210 Cable Modem","SURFboard SB4220 Cable Modem","CG4500 Communications Gateway","CG4501 Communications Gateway",
		"CG4500E Communications Gateway","SurfBoard SB5100 Cable Modem","SurfBoard SB5101 Cable Modem","SurfBoard SB5120 Cable Modem (RNDIS)","Surfboard 5121 Cable Modem",
		"WU830G 802.11bg Wireless Adapter [Envara WiND512]"};
		InsertProducts(0x07b2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0003,0x0010,0x0011,0x0013,0x0014,0x0015,0x0017,0x0204,0x0400,0x0401,0x0403,0x0404,0x0405,0x0406,0x0410,0x0412,0x0413,0x0601,0x0800,
		0x0900,0x090c,0x0a06,0x0b00,0x0c03,0x0c04,0x0c0c,0x0c26,0x0c2b,0x0e08,0x1300,0x1301};
		char* mids[] = {"OpticPro 1212U Scanner","Scanner","OpticPro U12 Scanner","OpticPro U24 Scanner","OpticPro UT12 Scanner",
		"Scanner","OpticPro U24 Scanner","OpticPro UT12/16/24 Scanner","Scanner","OpticPro 1248U Scanner",
		"OpticPro 1248U Scanner #2","OpticPro U16B Scanner","Scanner","A8 Namecard-s Controller","A8 Namecard-D Controller",
		"Scanner","Scanner","OpticSlim 1200 Scanner","OpticPro ST24 Scanner","OpticPro ST48 Scanner",
		"OpticBook 3600 Scanner","OpticBook 3600 Plus Scanner","TVcam VD100","SmartPhoto F50","OpticPro ST64+ Scanner",
		"Optic Film 7200i scanner","PL806 Scanner","OpticBook 4600 Scanner","Mobile Office D428 Scanner","Plustek OpticBook A300 Scanner",
		"OpticBook 3800 Scanner","OpticBook 4800 Scanner"};
		InsertProducts(0x07b3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0102,0x0105,0x0109,0x010a,0x0112,0x0113,0x0114,0x0118,0x0125,0x0184,0x0202,0x0203,0x0206,0x0207,0x0209,0x020b,0x020d,0x0211,0x0218,
		0x0244,0x024f,0x0280};
		char* mids[] = {"Camedia C-2100/C-3000 Ultra Zoom Camera","Camedia E-10/C-220/C-50 Camera","Camedia C-310Z/C-700/C-750UZ/C-755/C-765UZ/C-3040/C-4000/C-5050Z/D-560/C-3020Z Zoom Camera","C-370Z/C-500Z/D-535Z/X-450","MAUSB-10 xD and SmartMedia Card Reader",
		"MAUSB-100 xD Card Reader","Mju 500","C-350Z Camera","Mju Mini Digital/Mju Digital 500 Camera / Stylus 850 SW","Tough TG-1 Camera",
		"P-S100 port","Foot Switch RS-26","Digital Voice Recorder DW-90","Digital Voice Recorder DS-330","Digital Voice Recorder & Camera W-10",
		"Digital Voice Recorder DM-20","Digital Voice Recorder DS-4000","Digital Voice Recorder VN-240PC","Digital Voice Recorder DS-2300","Foot Switch RS-28",
		"Digital Voice Recorder VN-8500PC","Digital Voice Recorder DS-7000","m:robe 100"};
		InsertProducts(0x07b4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0017,0x0213,0x0312,0x9902};
		char* mids[] = {"Joystick","Thrustmaster Firestorm Digital 3 Gamepad","Gamepad","GamePad"};
		InsertProducts(0x07b5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x110c,0x1201,0x200c,0x2573,0x2770,0x2870,0x3070,0x3071,0x3072,0x4000,0x4002,0x4003,0x4004,0x4007,0x400b,0x400c,0x401a,0x4102,0x4104,0x420a,
		0x5301,0x6001,0x8188,0xa001,0xabc1,0xb000,0xb02a,0xb02b,0xb02c,0xb02d,0xb02e,0xb030,0xb031,0xb032,0xb033,0xb21a,0xb21b,0xb21c,0xb21d,0xb21e,
		0xb21f,0xd011,0xe001,0xe002,0xe003,0xe004,0xe005,0xe006,0xe007,0xe008,0xe009,0xe00a,0xe4f0,0xf101};
		char* mids[] = {"XX1","IEEE 802.11b Adapter","XX2","Wireless LAN Card","802.11n/b/g Mini Wireless LAN USB2.0 Adapter",
		"802.11n/b/g Wireless LAN USB2.0 Adapter","802.11n/b/g Mini Wireless LAN USB2.0 Adapter","802.11n/b/g Mini Wireless LAN USB2.0 Adapter","802.11n/b/g Mini Wireless LAN USB2.0 Adapter","DU-E10 Ethernet [klsi]",
		"DU-E100 Ethernet [pegasus]","1/10/100 Ethernet Adapter","XX4","XX5","XX6",
		"XX7","RTL8151","USB 1.1 10/100M Fast Ethernet Adapter","XX9","UF200 Ethernet",
		"GW-US54ZGL 802.11bg","802.11bg","AboCom Systems Inc [WN2001 Prolink Wireless-N Nano Adapter]","WUG2200 802.11g Wireless Adapter [Envara WiND512]","DU-E10 Ethernet [pegasus]",
		"BWU613","AboCom Bluetooth Device","Bluetooth dongle","BCM92045DG-Flash with trace filter","BCM92045DG-Flash with trace filter",
		"BCM92045DG-Flash with trace filter","BCM92045DG-Flash with trace filter","BCM92045DG-Flash with trace filter","BCM92045DG-Flash with trace filter","BCM92045DG-Flash with trace filter",
		"WUG2400 802.11g Wireless Adapter [Texas Instruments TNETW1450]","HWU54DM","RT2573","RT2573","RT2573",
		"WUG2700","MP3 Player","Mass Storage Device","Mass Storage Device","Mass Storage Device",
		"Mass Storage Device","Mass Storage Device","Mass Storage Device","Mass Storage Device","Mass Storage Device",
		"Mass Storage Device","Mass Storage Device","Card Reader Driver","DSB-560 Modem [atlas]"};
		InsertProducts(0x07b8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1113,0x1116,0x1121,0x1500,0x1501,0x1502,0x1503,0x1511,0x1512};
		char* mids[] = {"JoyWarrior24F8","JoyWarrior24F14","The Claw","IO-Warrior 40","IO-Warrior 24",
		"IO-Warrior 48","IO-Warrior 28","IO-Warrior 24 Power Vampire","IO-Warrior 24 Power Vampire"};
		InsertProducts(0x07c0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0068};
		char* mids[] = {"HKS-0200 USBDAQ"};
		InsertProducts(0x07c1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0102,0x0103,0x1234,0xa000,0xa001,0xa002,0xa003,0xa004,0xa005,0xa006,0xa007,0xa103,0xa107,0xa109,0xa10b,0xa200,0xa400,0xa600,0xa604,0xad01,
		0xae01,0xaf01,0xb000,0xb001,0xb004,0xb006,0xb00a,0xb00b,0xc010};
		char* mids[] = {"USB to LS120","USB to IDE","USB to ATAPI","CompactFlash Card Reader","CompactFlash & SmartMedia Card Reader [eusb]",
		"Disk Drive","Datafab-based Reader","USB to MMC Class Drive","CompactFlash & SmartMedia Card Reader","SmartMedia Card Reader",
		"Memory Stick Class Drive","MDSM-B reader","USB to Memory Stick (LC1) Drive","LC1 CompactFlash & SmartMedia Card Reader","USB to CF+MS(LC1)",
		"DF-UT-06 Hama MMC/SD Reader","CompactFlash & Microdrive Reader","Card Reader","12-in-1 Card Reader","Mass Storage Device",
		"Mass Storage Device","Mass Storage Device","USB to CF(LC1)","USB to CF+PCMCIA","MMC/SD Reader",
		"USB to PCMCIA","USB to CF+SD Drive(LC1)","USB to Memory Stick(LC1)","Kingston FCR-HS2/ATA Card Reader"};
		InsertProducts(0x07c4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0500};
		char* mids[] = {"Cash Drawer"};
		InsertProducts(0x07c5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0003};
		char* mids[] = {"Bodega Wireless Access Point","Bodega Wireless Network Adapter"};
		InsertProducts(0x07c6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0202};
		char* mids[] = {"MN128-SOHO PAL"};
		InsertProducts(0x07c8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xb100};
		char* mids[] = {"AT-USB100"};
		InsertProducts(0x07c9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0026,0x0337,0x0837,0x1228,0x1830,0x3835,0x850a,0x850b,0xa309,0xa801,0xa815,0xa827,0xa867,0xb800,0xe880,0xe882};
		char* mids[] = {"AVerTV PVR USB/EZMaker Pro Device","AVerTV","A867 DVB-T dongle","H837 Hybrid ATSC/QAM","MPEG-2 Capture Device (M038)",
		"AVerTV Volar Video Capture (H830)","AVerTV Volar Green HD (A835B)","AverTV Volar Black HD (A850)","AverTV Red HD+ (A850T)","AVerTV DVB-T (A309)",
		"AVerTV DVB-T (A800)","AVerTV DVB-T Volar X (A815)","AVerTV Hybrid Volar HX (A827)","AVerTV DVB-T (A867)","MR800 FM Radio",
		"MPEG-2 Capture Device (E880)","MPEG-2 Capture Device (E882)"};
		InsertProducts(0x07ca, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x000c,0x000d,0x000e,0x000f,0x0010,0x0012,0x0014,0x0030,0x0040,0x0100,0x0101,0x0102,
		0x0103,0x0104,0x0200,0x0201,0x0202,0x0203,0x0204,0x0205,0x0206,0x0207,0x0208,0x0210,0x0213,0x0214,0x0215,0x0217,0x0223,0x0224,0x0225,0x0227,
		0x0234,0x0235,0x0237,0x0300,0x0301,0x0303,0x0304,0x0305,0x0308,0x0309,0x0310,0x0311,0x0320,0x0321,0x0330,0x0350,0x0500,0x0501};
		char* mids[] = {"CF Card Reader","Reader (UICSE)","Reader (UIS)","SM Card Reader","SM/CF/PCMCIA Card Reader",
		"Reader (UISA2SE)","SM/CF/PCMCIA Card Reader","Reader (UISA6SE)","SM/CF Card Reader","SM/CF Card Reader",
		"Reader (UISDA)","Reader (UICLIK)","Reader (UISMA)","Reader (UISC6SE-FLASH)","Litronic Fortezza Reader",
		"Mass Storage (UISDMC12S)","Mass Storage (UISDMC13S)","Reader (UID)","Reader (UIM)","Reader (UISDMA)",
		"Reader (UISDMC)","Reader (UISDM)","6-in-1 Card Reader","Mass Storage (UISDMC1S & UISDMC3S)","Mass Storage (UISDMC5S)",
		"Mass Storage (UISMC5S)","Mass Storage (UIM4/5S & UIM7S)","Mass Storage (UIS4/5S & UIS7S)","Mass Storage (UISDMC10S & UISDMC11S)","Mass Storage (UPIDMA)",
		"Mass Storage (UCFC II)","Mass Storage (UPIXXA)","Mass Storage (UPIDA)","Mass Storage (UPIMA)","Mass Storage (UPISA)",
		"Mass Storage (UPISDMA)","Mass Storage (UCIDA)","Mass Storage (UCIMA)","Mass Storage (UIS7S)","Mass Storage (UCIDMA)",
		"Mass Storage (UIM7S)","Mass Storage (UIS4S-S)","Velper (UISDMC4S)","6-in-1 Card Reader","6-in-1 Card Reader",
		"Mass Storage (UID10W)","Mass Storage (UIM10W)","Mass Storage (UIS10W)","Mass Storage (UIC10W)","Mass Storage (UISC3W)",
		"Mass Storage (UISDMA2W)","Mass Storage (UISDMC14W)","Mass Storage (UISDMC4W)","Mass Storage (UISDMC37W)","WINTERREADER Reader",
		"9-in-1 Card Reader","Mass Storage","Mass Storage"};
		InsertProducts(0x07cc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"USBuart Serial Port"};
		InsertProducts(0x07cd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001,0x1003,0x1004,0x1011,0x1116,0x1125,0x1133,0x1225,0x1233,0x2002,0x3801,0x4001,0x4007,0x4104,0x4107,0x4500,0x6801,0x6802};
		char* mids[] = {"QV-8000SX/5700/3000EX Digicam; Exilim EX-M20","Exilim EX-S500","Exilim EX-Z120","USB-CASIO PC CAMERA","EXILIM EX-Z19",
		"Exilim EX-H10 Digital Camera (mass storage mode)","Exilim EX-Z350 Digital Camera (mass storage mode)","Exilim EX-H10 Digital Camera (PictBridge mode)","Exilim EX-Z350 Digital Camera (PictBridge mode)","E-125 Cassiopeia Pocket PC",
		"WMP-1 MP3-Watch","Label Printer KL-P1000","CW50 Device","Cw75 Device","CW-L300 Device",
		"LV-20 Digital Camera","PL-40R","MIDI Keyboard"};
		InsertProducts(0x07cf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0327,0x1001,0x1002,0x1102,0x1103,0x1104,0x1105,0x1106,0x1202,0x2000,0x2001,0x4100,0x4101,
		0x4959};
		char* mids[] = {"Digital Video Creator I","Global Village VideoFX Grabber","Fusion Model DVC-50 Rev 1 (NTSC)","DVC-800 (PAL) Grabber","Fusion Video and Audio Ports",
		"DVC 150 Loader Device","DVC 150","Fusion Digital Media Reader","DM-FLEX DFU Adapter","DMHS2 DFU Adapter",
		"CF Reader/Writer","SD Reader/Writer","SM Reader/Writer","MS Reader/Writer","xD/SM Reader/Writer",
		"MultiSlot Reader/Writer","FX2 DFU Adapter","eUSB CompactFlash Reader","Kingsun SF-620 Infrared Adapter","Connectivity Cable (CA-42 clone)",
		"Kingsun KS-959 Infrared Adapter"};
		InsertProducts(0x07d0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x13ec,0x13ed,0x13f1,0x13f2,0x3300,0x3302,0x3303,0x3304,0x3a07,0x3a08,0x3a09,0x3a0d,0x3a0f,0x3a10,0x3b01,0x3b10,0x3b11,0x3c03,0x3c04,0x3c05,
		0x3c06,0x3c07,0x3c09,0x3c0a,0x3c0b,0x3c0d,0x3c0e,0x3c0f,0x3c10,0x3c11,0x3c13,0x3c15,0x3c16,0x3e02,0x5100,0xa800,0xf101,0xfc01};
		char* mids[] = {"VvBus for Helium 2xx","VvBus for Helium 2xx","DSL-302G Modem","DSL-502G Router","DWA-130 802.11n Wireless N Adapter(rev.E) [Realtek RTL8191SU]",
		"DWA-130 802.11n Wireless N Adapter(rev.C2) [Realtek RTL8191SU]","DWA-131 802.11n Wireless N Nano Adapter(rev.A1) [Realtek RTL8192SU]","FR-300USB 802.11bgn Wireless Adapter","WUA-2340 RangeBooster G Adapter(rev.A) [Atheros AR5523]","WUA-2340 RangeBooster G Adapter(rev.A) (no firmware) [Atheros AR5523]",
		"DWA-160 802.11abgn Xtreme N Dual Band Adapter(rev.A2) [Atheros AR9170+AR9104]","DWA-120 802.11g Wireless 108G Adapter [Atheros AR5523]","DWA-130 802.11n Wireless N Adapter(rev.D) [Atheros AR9170+AR9102]","DWA-126 802.11n Wireless Adapter [Atheros AR9271]","AirPlus G DWL-G122 Wireless Adapter(rev.D) [Marvell 88W8338+88W8010]",
		"DWA-142 RangeBooster N Adapter [Marvell 88W8362+88W8060]","DWA-130 802.11n Wireless N Adapter(rev.A1) [Marvell 88W8362+88W8060]","AirPlus G DWL-G122 Wireless Adapter(rev.C1) [Ralink RT2571W]","WUA-1340","EH103 Wireless G Adapter",
		"DWA-111 802.11bg Wireless Adapter [Ralink RT2571W]","DWA-110 Wireless G Adapter(rev.A1) [Ralink RT2571W]","DWA-140 RangeBooster N Adapter(rev.B1) [Ralink RT2870]","DWA-140 RangeBooster N Adapter(rev.B2) [Ralink RT3072]","DWA-110 Wireless G Adapter(rev.B) [Ralink RT2870]",
		"DWA-125 Wireless N 150 Adapter(rev.A1) [Ralink RT3070]","WUA-2340 RangeBooster G Adapter(rev.B) [Ralink RT2070]","AirPlus G DWL-G122 Wireless Adapter(rev.E1) [Ralink RT2070]","DWA-160 802.11abgn Xtreme N Dual Band Adapter(rev.A1) [Atheros AR9170+AR9104]","DWA-160 Xtreme N Dual Band USB Adapter(rev.B) [Ralink RT2870]",
		"DWA-130 802.11n Wireless N Adapter(rev.B) [Ralink RT2870]","DWA-140 RangeBooster N Adapter(rev.B3) [Ralink RT2870]","DWA-125 Wireless N 150 Adapter(rev.A2) [Ralink RT3070]","DWM-156 3.75G HSUPA Adapter","Remote NDIS Device",
		"DWM-152 3.75G HSUPA Adapter","DBT-122 Bluetooth","DBT-120 Bluetooth Adapter"};
		InsertProducts(0x07d1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2820};
		char* mids[] = {"VC500 Video Capture Dongle"};
		InsertProducts(0x07de, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5201};
		char* mids[] = {"V.90 Modem"};
		InsertProducts(0x07e1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0967,0x0968};
		char* mids[] = {"SCard R/W CSR-145","SCard R/W CSR-145"};
		InsertProducts(0x07e4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x05c2,0x5c01};
		char* mids[] = {"IDE-to-USB2.0 PCA","Que! CDRW"};
		InsertProducts(0x07e5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"Cash Drawer I/F"};
		InsertProducts(0x07ee, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Internet Access Device"};
		InsertProducts(0x07ef, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"KEYLOK II"};
		InsertProducts(0x07f2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005,0x011e};
		char* mids[] = {"ScanLogic/Century Corporation uATA","Century USB Disk Enclosure"};
		InsertProducts(0x07f7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0778,0x1012,0x1196,0xa904,0xa905};
		char* mids[] = {"miniVigor 128 ISDN TA","BeWAN ADSL USB ST (grey)","BWIFI-USB54AR 802.11bg","BeWAN ADSL","BeWAN ADSL ST"
		};
		InsertProducts(0x07fa, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0001,0x0002};
		char* mids[] = {"FastLane MIDI Interface","FastLane Quad MIDI Interface","MOTU Audio for 64 bit"};
		InsertProducts(0x07fd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00ff};
		char* mids[] = {"Portable Hard Drive"};
		InsertProducts(0x07ff, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003};
		char* mids[] = {"Mini Swipe Reader (Keyboard Emulation)","Mini Swipe Reader","Magstripe Insert Reader"};
		InsertProducts(0x0801, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1300,0x3095,0x4310,0x4410,0x5241,0x5551,0x9700,0x9800,0xa312};
		char* mids[] = {"V92 Faxmodem","V.92 56K Mini External Modem Model 3095","4410a Wireless-G Adapter [Intersil ISL3887]","4410b Wireless-G Adapter [ZyDAS ZD1211B]","Cable Modem",
		"DSL Modem","2986L FaxModem","Cable Modem","Wireless-G"};
		InsertProducts(0x0803, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0010};
		char* mids[] = {"Fingerprint Scanner (After ReNumeration)","300LC Series Fingerprint Scanner (Before ReNumeration)"};
		InsertProducts(0x080b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0300,0x0400,0x0500,0x0600};
		char* mids[] = {"Gryphon D120 Barcode Scanner","Gryphon D120 Barcode Scanner","Gryphon D120 Barcode Scanner","Gryphon M100 Barcode Scanner"};
		InsertProducts(0x080c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0102,0x0104,0x0110};
		char* mids[] = {"Hercules Scan@home 48","3.2Slim","UMAX AstraSlim 1200 Scanner"};
		InsertProducts(0x080d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003};
		char* mids[] = {"Dual PSX Adaptor","Dual PCS Adaptor","PlayStation Gamepad"};
		InsertProducts(0x0810, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"Intel Play QX3 Microscope","Dual Mode Camera Plus"};
		InsertProducts(0x0813, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"License Management and Copy Protection"};
		InsertProducts(0x0819, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000};
		char* mids[] = {"Duo Pen Tablet"};
		InsertProducts(0x081a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0600,0x0601};
		char* mids[] = {"Storage Adapter","Storage Adapter"};
		InsertProducts(0x081b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xdf00};
		char* mids[] = {"Handheld"};
		InsertProducts(0x081e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2001};
		char* mids[] = {"IRXpress Infrared Device"};
		InsertProducts(0x0822, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0200,0x0300,0x0400,0x0500,0x0600};
		char* mids[] = {"Visor","Treo","Treo 600","Handheld","Handheld",
		"Handheld"};
		InsertProducts(0x082d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0010,0x0011,0x0012,0x0013,0x0014,0x0020,0x0021,0x0022,0x0023,0x0024,0x0030,0x0031,0x0032,0x0033,
		0x0034,0x0040,0x0041,0x0042,0x0043,0x0044,0x0050,0x0051,0x0052,0x0053,0x0054,0x0060,0x0061,0x0062,0x0063,0x0064,0x0070,0x0071,0x0072,0x0080,
		0x0081,0x0082,0x00a0,0x0101};
		char* mids[] = {"m500","m505","m515","Handheld","Handheld",
		"Handheld","Handheld","Handheld","Handheld","Handheld",
		"Handheld","i705","Handheld","Handheld","Handheld",
		"Handheld","Handheld","Tungsten W","Handheld","Handheld",
		"Handheld","m125","Handheld","Handheld","Handheld",
		"Handheld","m130","Handheld","Handheld","Handheld",
		"Handheld","Tungsten C/E/T/T2/T3 / Zire 71","Lifedrive / Treo 650/680 / Tunsten E2/T5/TX / Centro / Zire 21/31/72 / Z22","Handheld","Handheld",
		"Handheld","Zire","Handheld","Handheld","Serial Adapter [for Palm III]",
		"Handheld","Handheld","Treo 800w","Pre"};
		InsertProducts(0x0830, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5850};
		char* mids[] = {"Cable"};
		InsertProducts(0x0832, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x012e,0x039f};
		char* mids[] = {"KeikaiDenwa 8 with charger","KeikaiDenwa 8"};
		InsertProducts(0x0833, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2836};
		char* mids[] = {"i.Beat mood"};
		InsertProducts(0x0836, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005,0x0008,0x0009,0x000a,0x000e,0x0010,0x1003,0x1005,0x1009,0x1012,0x1058,0x1064,0x1542,0x3000};
		char* mids[] = {"Digimax Camera","Digimax 230 Camera","Digimax 340","Digimax 410","Digimax 360",
		"Digimax 300","Digimax 210SE","Digimax 220","Digimax V4","6500 Document Camera",
		"S730 Camera","Digimax D830 Camera","Digimax 50 Duo","Digimax 35 MP3"};
		InsertProducts(0x0839, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1046,0x1060,0x1f4d,0x3046,0x3060,0x3501,0x3502,0x3503,0x4501,0x4502,0x4505,0x4507,0x4521,0x5046,0x5501,0x6500,0x6618,0x7511,0x7512,0x7522,
		0x8522,0x8541,0xa512,0xa618,0xa701,0xb004,0xb522,0xbb01,0xc003,0xc501,0xc561,0xd522,0xe501,0xe503,0xe506,0xf501,0xf502,0xf522};
		char* mids[] = {"10/100 Ethernet [pegasus]","HomeLine Adapter","SMC8013WG Broadband Remote NDIS Device","10/100 Series Adapter","1/10/100 Adapter",
		"2664W","WN3501D Wireless Adapter","T-Sinus 111 Wireless Adapter","T-Sinus 154data","Siemens S30853-S1016-R107 802.11g Wireless Adapter [Intersil ISL3886]",
		"SMCWUSB-G 802.11bg","SMCWUSBT-G2 802.11g Wireless Adapter [Atheros AR5523]","Siemens S30863-S1016-R107-2 802.11g Wireless Adapter [Intersil ISL3887]","SpeedStream 10/100 Ethernet [pegasus]","Wireless Adapter 11g",
		"Cable Modem","802.11n Wireless Adapter","Arcadyan 802.11N Wireless Adapter","Arcadyan 802.11N Wireless Adapter","Arcadyan 802.11N Wireless Adapter",
		"Arcadyan 802.11N Wireless Adapter","WN4501F 802.11g Wireless Adapter [Intersil ISL3887]","Arcadyan 802.11N Wireless Adapter","SMCWUSBS-N EZ Connect N Draft 11n Wireless Adapter [Ralink RT2870]","SMCWUSBS-N3 EZ Connect N Wireless Adapter [Ralink RT3070]",
		"CPWUE001 USB/Ethernet Adapter","SMCWUSBS-N2 EZ Connect N Wireless Adapter [Ralink RT2870]","BlueExpert Bluetooth Device","802.11b Wireless Adapter","Zoom 4410 Wireless-G [Intersil ISL3887]",
		"802.11a/g Wireless Adapter","Speedport W 102 Stick IEEE 802.11n USB 2.0 Adapter","ZD1211B","Arcadyan WN4501 802.11b/g","WUS-201 802.11bg",
		"802.11g Wireless Adapter","802.11g Wireless Adapter","Arcadyan WN7512 802.11n"};
		InsertProducts(0x083a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xb100};
		char* mids[] = {"TelePort V.90 Fax/Modem"};
		InsertProducts(0x083f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0060};
		char* mids[] = {"Storage Adapter Bridge Module"};
		InsertProducts(0x0840, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Rio 500"};
		InsertProducts(0x0841, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001,0x1002,0x1020,0x1040,0x1100,0x4110,0x4200,0x4210,0x4220,0x4230,0x4240,0x4260,0x4300,0x4301,0x5f00,0x6a00,0x7100,0x9000,0x9001,0x9010,
		0x9011,0x9012,0x9018,0x9020,0x9021,0x9030,0x9040,0x9041,0x9042,0x9050,0x9052,0xa001,0xf001};
		char* mids[] = {"EA101 10 Mbps 10BASE-T Ethernet [Kawasaki LSI KL5KLUSB101B]","Ethernet","FA101 Fast Ethernet USB 1.1","FA120 Fast Ethernet USB 2.0 [Asix AX88172 / AX8817x]","Managed Switch M4100 series, M5300 series, M7100 series",
		"MA111(v1) 802.11b Wireless [Intersil Prism 3.0]","WG121(v1) 54 Mbps Wireless [Intersil ISL3886]","WG121(v2) 54 Mbps Wireless [Intersil ISL3886]","WG111(v1) 54 Mbps Wireless [Intersil ISL3886]","MA111(v2) 802.11b Wireless [SIS SIS 162]",
		"WG111(v1) rev 2 54 Mbps Wireless [Intersil ISL3887]","WG111v3 54 Mbps Wireless [realtek RTL8187B]","WG111U Double 108 Mbps Wireless [Atheros AR5004X / AR5005UX]","WG111U (no firmware) Double 108 Mbps Wireless [Atheros AR5004X / AR5005UX]","WPN111 802.11g Wireless Adapter [Atheros AR5523]",
		"WG111v2 54 Mbps Wireless [RealTek RTL8187L]","WN121T RangeMax Next Wireless-N [Marvell TopDog]","WN111(v1) RangeMax Next Wireless [Marvell 88W8362+88W8060]","WN111(v2) RangeMax Next Wireless [Atheros AR9170+AR9101]","WNDA3100v1 802.11abgn [Atheros AR9170+AR9104]",
		"WNDA3100v2 802.11abgn [Broadcom BCM4323]","WNDA4100 802.11abgn 3x3:3 [Ralink RT3573]","WNDA3200 802.11abgn Wireless Adapter [Atheros AR7010+AR9280]","WNA3100(v1) Wireless-N 300 [Broadcom BCM43231]","WNA3100M(v1) Wireless-N 300 [Realtek RTL8192CU]",
		"WNA1100 Wireless-N 150 [Atheros AR9271]","WNA1000 Wireless-N 150 [Atheros AR9170+AR9101]","WNA1000M 802.11bgn [Realtek RTL8188CUS]","On Networks N150MA 802.11bgn [Realtek RTL8188CUS]","A6200 802.11a/b/g/n/ac Wireless Adapter [Broadcom BCM43526]",
		"A6100 AC600 DB Wireless Adapter [Realtek RTL8811AU]","PA101 10 Mbps HPNA Home Phoneline RJ-1","On Networks N300MA 802.11bgn [Realtek RTL8192CU]"};
		InsertProducts(0x0846, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0003,0x0011,0x0014,0x0019,0x0025,0x1001};
		char* mids[] = {"Jenoptik JD800i","S-Cam F5/D-Link DSC-350 Digital Camera","Argus DC3500 Digital Camera","Praktica DC 32","Praktica DPix3000",
		"Praktica DC 60","ScanHex SX-35d"};
		InsertProducts(0x084d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x1001,0x1002};
		char* mids[] = {"JamCam Camera","Jam Studio Tablet","Pablo Tablet"};
		InsertProducts(0x084e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Empeg-Car Mark I/II Player"};
		InsertProducts(0x084f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1542,0x1543,0xa168};
		char* mids[] = {"SiPix Blink","Maxell WS30 Slim Digital Camera, or Pandigital PI8004W01 digital photo frame","MXIC"};
		InsertProducts(0x0851, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100};
		char* mids[] = {"HHKB Professional"};
		InsertProducts(0x0853, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0101};
		char* mids[] = {"I/O Board","I/O Board, rev1"};
		InsertProducts(0x0854, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xac01};
		char* mids[] = {"uLinks USOTL4 RS422/485 Adapter"};
		InsertProducts(0x0856, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3102,0xffff};
		char* mids[] = {"Bluetooth Device","Maxell module with BlueCore in DFU mode"};
		InsertProducts(0x0858, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0003,0x0008,0x0009,0x000b,0x0021,0x0022,0x0023,0x0024,0x0027,0x0028,0x0032,0x003c,0x0299,0x8021,0x8023,0x8027};
		char* mids[] = {"Portstation Dual Serial Port","Portstation Paraller Port","Ethernet","Ethernet","Portstation Dual PS/2 Port",
		"1 port to Serial Converter","Parallel Port","2 port to Serial Converter","Parallel Port","1 port to Serial Converter",
		"PortGear to SCSI Converter","PortStation SCSI Module","Bluetooth Adapter","Colorvision, Inc. Monitor Spyder","1 port to Serial",
		"2 port to Serial","PGSDB9 Serial Port"};
		InsertProducts(0x085a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0200,0x0300,0x0400};
		char* mids[] = {"Spyder 1","Spyder 2","Spyder 3","Spyder 4"};
		InsertProducts(0x085c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4100,0x4102};
		char* mids[] = {"MA101 802.11b Adapter","MA101 802.11b Adapter"};
		InsertProducts(0x0864, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x9812,0x9816,0x9836};
		char* mids[] = {"ECON Data acquisition unit","DT9816 ECON data acquisition module","DT9836 data acquisition card"};
		InsertProducts(0x0867, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003};
		char* mids[] = {"Unitor8","AMT8","MT4"};
		InsertProducts(0x086a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001,0x1002,0x1003,0x1004,0x1005,0x1006,0x1007,0x1008,0x1009,0x100a,0x100b,0x100c,0x100d,0x100e,0x1011,0x1012,0x1013,0x1014,0x1019,0x101a,
		0x1021,0x1022,0x1023,0x1024,0x1025,0x1029,0x102c,0x1030,0x1032,0x1033,0x1034,0x1041,0x1042,0x1055,0x1056,0x2000};
		char* mids[] = {"Eumex 504PC ISDN TA","Eumex 504PC (FlashLoad)","TA33 ISDN TA","TA33 (FlashLoad)","Eumex 604PC HomeNet",
		"Eumex 604PC HomeNet (FlashLoad)","Eumex 704PC DSL","Eumex 704PC DSL (FlashLoad)","Eumex 724PC DSL","Eumex 724PC DSL (FlashLoad)",
		"OpenCom 30","OpenCom 30 (FlashLoad)","BeeTel Home 100","BeeTel Home 100 (FlashLoad)","USB2DECT",
		"USB2DECT (FlashLoad)","Eumex 704PC LAN","Eumex 704PC LAN (FlashLoad)","Eumex 504 SE","Eumex 504 SE (Flash-Mode)",
		"OpenCom 40","OpenCom 40 (FlashLoad)","OpenCom 45","OpenCom 45 (FlashLoad)","Sinus 61 data",
		"dect BOX","Eumex 604PC HomeNet [FlashLoad]","Eumex 704PC DSL [FlashLoad]","OpenCom 40 [FlashLoad]","OpenCom 30 plus",
		"OpenCom 30 plus (FlashLoad)","Eumex 220PC","Eumex 220PC (FlashMode)","Eumex 220 Version 2 ISDN TA","Eumex 220 Version 2 ISDN TA (Flash-Mode)",
		"OpenCom 1000"};
		InsertProducts(0x086c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1920};
		char* mids[] = {"SGC-X2UL"};
		InsertProducts(0x086e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Ricochet GS"};
		InsertProducts(0x0870, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0005};
		char* mids[] = {"SDDR-01 Compact Flash Reader","SDDR-31 Compact Flash Reader","SDDR-05 Compact Flash Reader"};
		InsertProducts(0x0871, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5704};
		char* mids[] = {"Ethernet"};
		InsertProducts(0x087d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0630};
		char* mids[] = {"Intel PC Camera CS630"};
		InsertProducts(0x0886, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1002};
		char* mids[] = {"DigiView DV3100"};
		InsertProducts(0x088a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4944};
		char* mids[] = {"MassWorks ID-75 TouchScreen"};
		InsertProducts(0x088b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2030};
		char* mids[] = {"Ticket Printer TTP 2030"};
		InsertProducts(0x088c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5036};
		char* mids[] = {"Portable secure storage for software licenses"};
		InsertProducts(0x088e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"Smartdio Reader/Writer"};
		InsertProducts(0x0892, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010};
		char* mids[] = {"Remote NDIS Network Device"};
		InsertProducts(0x0894, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"Power Debug/Power Debug II"};
		InsertProducts(0x0897, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0051};
		char* mids[] = {"B-SV4"};
		InsertProducts(0x08a6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005,0x0009,0x0012,0x0013,0x0014,0x0015};
		char* mids[] = {"USBee ZX","USBee SX","USBee AX-Standard","USBee AX-Plus","USBee AX-Pro",
		"USBee DX"};
		InsertProducts(0x08a9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0006,0x0015,0x001a};
		char* mids[] = {"814 Sample Processor","857 Titrando","852 Titrando"};
		InsertProducts(0x08b0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Playstation adapter"};
		InsertProducts(0x08b7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x01f4};
		char* mids[] = {"USBSIMM1"};
		InsertProducts(0x08b8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2702,0x2704,0x2706,0x2900,0x2901,0x2902,0x2904,0x2910,0x29b0,0x29b2,0x29b3,0x29b6,0x29c0,0x29c2,0x29c3,0x29c6};
		char* mids[] = {"Speakers","Audio Codec","PCM2706 Audio Codec","PCM2900 Audio Codec","PCM2901 Audio Codec",
		"PCM2902 Audio Codec","PCM2904 Audio Codec","PCM2912 Audio Codec","PCM2900B Audio CODEC","PCM2902 Audio CODEC",
		"PCM2903B Audio CODEC","PCM2906B Audio CODEC","PCM2900C Audio CODEC","PCM2902C Audio CODEC","PCM2903C Audio CODEC",
		"PCM2906C Audio CODEC"};
		InsertProducts(0x08bb, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0208,0x1100};
		char* mids[] = {"CLP-521 Label Printer","X1-USB Floppy"};
		InsertProducts(0x08bd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0006,0x0100,0x0101,0x0300,0x0400,0x0401,0x0402,0x0404,0x0405,0x0406};
		char* mids[] = {"100 SC","100 A","100 SC BioKeyboard","100 A BioKeyboard","100 MC ISP",
		"100 MC FingerPrint and SmartCard Reader","100 AX","100 SC","150 MC","200 MC FingerPrint and SmartCard Reader",
		"100 SC Upgrade","150 MC Upgrade","100 MC Upgrade"};
		InsertProducts(0x08c3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x02f2};
		char* mids[] = {"Skyline 802.11b Wireless Adapter","Farallon Home Phoneline Adapter"};
		InsertProducts(0x08c4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0010,0x0020,0x0021,0x0022,0x0023,0x0024,0x0100,0x0102,0x0103,0x0104,0x0105,0x0106,0x0107,0x0109,0x010a,0x0111,0x2008,0x2010,0x2011,
		0x2016,0x2018,0x2020,0x2022,0x2024,0x2028,0x2040,0x2042,0x2043,0x2060};
		char* mids[] = {"Tablet","Tablet","APT-6000U Tablet","APT-2 Tablet","Tablet",
		"Tablet","Tablet","Pen Drive","DualCam","Pocket DV Digital Camera",
		"Pocket DVII","Mega DV(Disk)","Pocket DV3100+","Pocket DV3100","Nisis DV4 Digital Camera",
		"Trust 738AV LCD PV Mass Storage","PenCam VGA Plus","Mini PenCam 2","Pocket CAM 3 Mega (webcam)","Pocket CAM 3 Mega (storage)",
		"PocketCam 2 Mega","Pencam SD 2M","Slim 3000F","Slim 3200","Pocket DV3500",
		"Pocket Cam4M","Pocket DV4100M","Pocket DV5100M Composite Device","Pocket DV5100M (Disk)","Pocket DV5300"
		};
		InsertProducts(0x08ca, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0003};
		char* mids[] = {"smartNIC Ethernet [catc]","smartNIC 2 PnP Ethernet"};
		InsertProducts(0x08d1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0009};
		char* mids[] = {"SCR SmartCard Reader"};
		InsertProducts(0x08d4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0003,0x0100};
		char* mids[] = {"USB-to-CAN compact","USB-to-CAN II","USB-to-CAN"};
		InsertProducts(0x08d8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0112,0x0113,0x0986,0x0987,0x0988,0x1986,0x2103,0x8511,0x90ff};
		char* mids[] = {"Wireless LAN Adapter","Wireless LAN Adapter","USB-100N Ethernet [pegasus]","USBLP-100 HomePNA Ethernet [pegasus]","USBEL-100 Ethernet [pegasus]",
		"10/100 LAN Adapter","DVB-T TV-Tuner Card-R","USBE-100 Ethernet [pegasus2]","USB2AR Ethernet"};
		InsertProducts(0x08dd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7a01};
		char* mids[] = {"802.11b Adapter"};
		InsertProducts(0x08de, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0a00};
		char* mids[] = {"Rosetta Token V1","Rosetta Token V2","Rosetta Token V3","Lynks Interface"};
		InsertProducts(0x08df, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0100,0x0101,0x0102,0x0301};
		char* mids[] = {"USB-RS232 Bridge","Interface ADSL","Interface ADSL","ADSL","RNIS"
		};
		InsertProducts(0x08e3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0430,0x0432,0x0435,0x0437,0x1359,0x2202,0x3437,0x3438,0x3478,0x34ec,0x4433,0x5501,0x5503,0xace0};
		char* mids[] = {"GemPC-Touch 430","GemPC430 SmartCard Reader","GemPC432 SmartCard Reader","GemPC435 SmartCard Reader","GemPC433 SL SmartCard Reader",
		"UA SECURE STORAGE TOKEN","Gem e-Seal Pro Token","GemPC Twin SmartCard Reader","GemPC Key SmartCard Reader","PinPad Smart Card Reader",
		"Compact Smart Card Reader Writer","GemPC433-Swap","GemProx-PU Contactless Smart Card Reader","Prox-DU Contactless Interface","UA HYBRID TOKEN"
		};
		InsertProducts(0x08e6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100};
		char* mids[] = {"XTNDAccess IrDA Dongle"};
		InsertProducts(0x08e9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00c9,0x00ca,0x00ce,0xabba,0xabbb};
		char* mids[] = {"ADSL Modem HM120dp Loader","ADSL WAN Modem HM120dp","HM230d Virtual Bus for Helium","USB Driver for Bluetooth Wireless Technology","Bluetooth Device in DFU State"
		};
		InsertProducts(0x08ea, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0005,0x0008,0x0010,0x0011,0x0012,0x0014,0x0015,0x0016,0x0020,0x0021,0x0022,0x0023,0x0024,0x0025,0x0026,0x0027,0x0028,0x0029,
		0x0030,0x0822,0x0832,0x0834,0x0998,0x0999,0x1000,0x2000,0x2038,0x2039,0x204a,0x204b};
		char* mids[] = {"TravelDrive 2C","TravelDrive 2C","TravelDrive 2C","TravelDrive 2C","DiskOnKey",
		"DiskOnKey","TravelDrive 2C","TravelDrive 2C","Kingston DataTraveler ELITE","Kingston DataTraveler U3",
		"TravelDrive Intuix U3 2GB","TravelDrive","TravelDrive","TravelDrive","TravelDrive",
		"TravelDrive","TravelDrive","TravelDrive","TravelDrive","TravelDrive",
		"TravelDrive","TravelDrive 2C","Hi-Speed Mass Storage Device","M-Disk 220","Kingston Data Traveler2.0 Disk Driver",
		"Kingston Data Traveler2.0 Disk Driver","TravelDrive 2C","TravelDrive 2C","TravelDrive","TravelDrive",
		"TravelDrive","TravelDrive"};
		InsertProducts(0x08ec, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"CECT M800 memory card"};
		InsertProducts(0x08ed, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x007f};
		char* mids[] = {"Super Q2 Tablet"};
		InsertProducts(0x08f2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004};
		char* mids[] = {"LabPro","EasyTemp/Go!Temp","Go!Link","Go!Motion"};
		InsertProducts(0x08f7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Bluetooth Device"};
		InsertProducts(0x08fd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1600,0x1610,0x1660,0x1680,0x168f,0x2500,0x2501,0x2502,0x2503,0x2504,0x2505,0x2506,0x2507,0x2508,0x2509,0x250a,0x250b,0x250c,0x250d,0x250e,
		0x250f,0x2510,0x2550,0x2580,0x2588,0x2589,0x258a,0x258b,0x258c,0x258d,0x258e,0x258f,0x2660,0x2680,0x268f,0x2810,0x3400,0x3401,0x3402,0x3403,
		0x3404,0x3405,0x3406,0x3407,0x4902,0x4903,0x5500,0x5501,0x5503,0x5505,0x5507,0x55ff,0x5700,0x5701,0x5702,0x5703,0x5704,0x5705,0x5706,0x5707,
		0x5710,0x5711,0x5712,0x5713,0x5714,0x5715,0x5716,0x5717,0x5730,0x5731,0x5732,0x5733,0x5734,0x5735,0x5736,0x5737,0xafe3,0xafe4,0xafe5,0xafe6,
		0xfffd,0xffff};
		char* mids[] = {"AES1600","AES1600","AES1660 Fingerprint Sensor","AES1660 Fingerprint Sensor","AES1660 Fingerprint Sensor",
		"AES2501","AES2501","AES2501","AES2501","AES2501",
		"AES2501","AES2501","AES2501","AES2501","AES2501",
		"AES2501","AES2501","AES2501","AES2501","AES2501",
		"AES2501","AES2510","AES2550 Fingerprint Sensor","AES2501 Fingerprint Sensor","AES2501",
		"AES2501","AES2501","AES2501","AES2501","AES2501",
		"AES2501","AES2501","AES2660 Fingerprint Sensor","AES2660 Fingerprint Sensor","AES2660 Fingerprint Sensor",
		"AES2810","AES3400 TruePrint Sensor","AES3400 Sensor","AES3400 Sensor","AES3400 Sensor",
		"AES3400 TruePrint Sensor","AES3400 TruePrint Sensor","AES3400 TruePrint Sensor","AES3400 TruePrint Sensor","BioMV with TruePrint AES3500",
		"BioMV with TruePrint AES3400","AES4000","AES4000 TruePrint Sensor","AES4000 TruePrint Sensor","AES4000 TruePrint Sensor",
		"AES4000 TruePrint Sensor","AES4000 TruePrint Sensor.","AES3500 Fingerprint Reader","AES3500 TruePrint Sensor","AES3500 TruePrint Sensor",
		"AES3500 TruePrint Sensor","AES3500-BZ TruePrint Sensor","AES3500-BZ TruePrint Sensor","AES3500-BZ TruePrint Sensor","AES3500-BZ TruePrint Sensor",
		"AES3500 TruePrint Sensor","AES3500 TruePrint Sensor","AES3500 TruePrint Sensor","AES3500 TruePrint Sensor","AES3500-BZ TruePrint Sensor",
		"AES3500-BZ TruePrint Sensor","AES3500-BZ TruePrint Sensor","AES3500-BZ TruePrint Sensor","AES3500 TruePrint Sensor","AES3500 TruePrint Sensor",
		"AES3500 TruePrint Sensor","AES3500 TruePrint Sensor","AES3500-BZ TruePrint Sensor","AES3500-BZ TruePrint Sensor","AES3500-BZ TruePrint Sensor",
		"AES3500-BZ TruePrint Sensor","FingerLoc Sensor Module (Anchor)","FingerLoc Sensor Module (Anchor)","FingerLoc Sensor Module (Anchor)","FingerLoc Sensor Module (Anchor)",
		"AES2510 Sensor (USB Emulator)","Sensor (Emulator)"};
		InsertProducts(0x08ff, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"Hard Drive Adapter (TPP)","SigmaDrive Adapter (TPP)"};
		InsertProducts(0x0901, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x01f4,0x01fe,0x2701};
		char* mids[] = {"SIMATIC NET CP 5711","SIMATIC NET PC Adapter A2","ShenZhen SANZHAI Technology Co.,Ltd Spy Pen VGA"};
		InsertProducts(0x0908, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001,0x1100,0x1200,0x1540};
		char* mids[] = {"T33520 Flash Card Controller","Comotron C3310 MP3 player","MP3 player","Digitex Container Flash Disk"};
		InsertProducts(0x090a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0371,0x0373,0x037a,0x037b,0x1000,0x1132,0x337b,0x3710,0x3720,0x37bc,0x37c0,0x6000,0x6200,0x71b3,0x837b,0x937b,0xb370,0xb371};
		char* mids[] = {"Silicon Motion SM371 Camera","Silicon Motion Camera","Silicon Motion Camera","Silicon Motion Camera","Flash Drive",
		"5-in-1 Card Reader","Silicon Motion Camera","Silicon Motion Camera","Silicon Motion Camera","HP Webcam-101 Integrated Camera",
		"Silicon Motion Camera","SD/SDHC Card Reader (SG365 / FlexiDrive XC+)","microSD card reader","SM731 Camera","Silicon Motion Camera",
		"Silicon Motion Camera","Silicon Motion SM370 Camera","Silicon Motion SM371 Camera"};
		InsertProducts(0x090c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x149a,0x2512};
		char* mids[] = {"SpeechMike II Pro Plus LFH5276","SpeechMike Pro"};
		InsertProducts(0x0911, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0005,0x2000,0x2002,0x8000,0x8005,0x8101,0x8102,0x8103,0x8104,0x8400,0x8401,0x8402,0x8500,0x8501};
		char* mids[] = {"DSL Modem","ADSL ATM Modem","LAN Modem","802.11 Adapter","802.11 Adapter",
		"ADSL LAN Modem","DSL-302G Modem","ADSL WAN Modem","DSL-200 ADSL Modem","DSL-200 ADSL Modem",
		"DSL-200 Modem","DSL Modem","DSL Modem","DSL Modem","DSL Modem",
		"DSL Modem"};
		InsertProducts(0x0915, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0200,0x0201,0x0202,0x0204,0x0205,0x0206,0x0207,0x020f,0xda01,0xffff};
		char* mids[] = {"eFilm Reader-11 SM/CF","eFilm Reader-11 SM","eFilm Reader-11 CF","FireFly","FireLite",
		"STORAGE ADAPTER (FirePower)","FlashTrax Storage","STORAGE ADAPTER (CrossFire)","FireFly 20G HDD","FireLite",
		"STORAGE ADAPTER (FireLite)","eFilm Reader-11 Test","eFilm Reader-11 (Class/PDR)"};
		InsertProducts(0x0917, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100};
		char* mids[] = {"Fast Flicks Digital Camera"};
		InsertProducts(0x0919, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0004,0x0200,0x1200,0x21a5,0x2236,0x2271,0x2295,0x22b6,0x231b,0x2353,0x2380,0x23cc,0x2459,0x2491,0x2519,0x2535,0x253c,0x255b};
		char* mids[] = {"GPS (various models)","iQue 3600","Data Card Programmer (install)","Data Card Programmer","etrex Cx (msc)",
		"nuvi 360","Edge 605/705","Colorado 300","eTrex Vista HCx (Mass Storage mode)","Oregon 400t",
		"NÃ¼vi 205T","Oregon series","nÃ¼vi 1350","GPSmap 62/78 series","Edge 800",
		"eTrex 30","Edge 800","GPSmap 62sc","Nuvi 2505LM"};
		InsertProducts(0x091e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7500};
		char* mids[] = {"Network Interface"};
		InsertProducts(0x0920, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001};
		char* mids[] = {"GoCOM232 Serial"};
		InsertProducts(0x0921, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0007,0x0009,0x0019,0x001a,0x0020,0x1001};
		char* mids[] = {"LabelWriter 330","LabelWriter 310","LabelWriter 400","LabelWriter 400 Turbo","LabelWriter 450",
		"LabelManager PnP"};
		InsertProducts(0x0922, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x010f};
		char* mids[] = {"SIIG MobileCam"};
		InsertProducts(0x0923, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x23dd,0x3ce8,0x3d5b,0x420f,0x421f,0x423b,0x4274,0xffef,0xfffb};
		char* mids[] = {"DocuPrint M760 (X760_USB)","Phaser 3428 Printer","Phaser 6115MFP TWAIN Scanner","WorkCentre PE220 Series","M20 Scanner",
		"Printing Support","Xerox Phaser 3635MFPX","WorkCenter M15","DocuPrint M750 (X750_USB)"};
		InsertProducts(0x0924, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005,0x03e8,0x3881,0x8101,0x8104,0x8800,0x8866};
		char* mids[] = {"Gamtec.,Ltd SmartJoy PLUS Adapter","Wii Classic Controller Adapter","Saleae Logic","Phidgets, Inc., 1-Motor PhidgetServo v2.0","Phidgets, Inc., 4-Motor PhidgetServo v2.0",
		"WiseGroup Ltd, MP-8800 Quad Joypad","WiseGroup Ltd, MP-8866 Dual Joypad"};
		InsertProducts(0x0925, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8000};
		char* mids[] = {"Firmware uploader"};
		InsertProducts(0x0928, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004,0x0005};
		char* mids[] = {"JTAG-4","JTAG-5"};
		InsertProducts(0x092f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0009,0x000c,0x0010,0x0200,0x0301,0x0302,0x0305,0x0307,0x0308,0x0309,0x030b,0x0501,0x0502,0x0503,0x0505,0x0506,0x0507,0x0508,0x0509,0x0706,
		0x0707,0x0708,0x0709,0x070a,0x070b,0x0a07,0x0a13,0x0b05,0x0b09,0x0b1a,0x1300,0x1301,0x1302,0x1303,0x1308,0x130b,0x130c,0x1311,0x1400,0x642f,
		0x6506,0x6507,0x6508,0x6509,0x6510,0x6517,0x6518,0x6519,0x651a,0x651b,0x651c,0x651d,0x651e,0x651f,0x6520,0x6521,0x6522,0x6523,0x6524,0x6525,
		0x6526,0x6527,0x6528,0x6529,0x652a,0x652b,0x652c,0x652d,0x652f,0x6530,0x6531,0x6532,0x6533,0x6534,0x653c,0x653d,0x653e,0x6540,0x6544,0x6545
		};
		char* mids[] = {"Gigabeat F/X (HDD audio player)","Gigabeat F (mtp)","Gigabeat S (mtp)","Integrated Bluetooth (Taiyo Yuden)","PCX1100U Cable Modem (WDM)",
		"PCX2000 Cable Modem (WDM)","Cable Modem PCX3000","Cable Modem PCX2500","PCX2200 Cable Modem (WDM)","PCX5000 Cable Modem (WDM)",
		"Cable Modem PCX2600","Bluetooth Controller","Integrated Bluetooth","Bluetooth Controller","Integrated Bluetooth",
		"Integrated Bluetooth","Bluetooth Adapter","Integrated Bluetooth HCI","BT EDR Dongle","PocketPC e740",
		"Pocket PC e330 Series","Pocket PC e350Â Series","Pocket PC e750 Series","Pocket PC e400 Series","Pocket PC e800 Series",
		"WLM-10U1 802.11abgn Wireless Adapter [Ralink RT3572]","AX88179 Gigabit Ethernet [Toshiba]","PX1220E-1G25 External hard drive","PX1396E-3T01 External hard drive","STOR.E ALU 2S",
		"Wireless Broadband (CDMA EV-DO) SM-Bus Minicard Status Port","Wireless Broadband (CDMA EV-DO) Minicard Status Port","Wireless Broadband (3G HSDPA) SM-Bus Minicard Status Port","Wireless Broadband (3G HSDPA) Minicard Status Port","Broadband (3G HSDPA) SM-Bus Minicard Diagnostics Port",
		"F3507g Mobile Broadband Module","F3607gw Mobile Broadband Module","F3607gw v2 Mobile Broadband Module","Memory Stick 2GB","TravelDrive",
		"TravelDrive 2C","TravelDrive 2C","TravelDrive 2C","TravelDrive 2C","TravelDrive 2C",
		"TravelDrive 2C","TravelDrive 2C","Kingston DataTraveler 2.0 USB Stick","TravelDrive 2C","TravelDrive 2C",
		"TravelDrive 2C","TravelDrive 2C","TravelDrive 2C","TravelDrive 2C","TravelDrive 2C",
		"TravelDrive 2C","TravelDrive 2C","TravelDrive","TravelDrive","TravelDrive",
		"TravelDrive","TravelDrive","TravelDrive","TravelDrive","TravelDrive",
		"TravelDrive","TravelDrive","TravelDrive","TravelDrive","TravelDrive",
		"TravelDrive","256M Stick","512M Stick","TravelDrive","Kingston DataTraveler 2.0 Stick (512M)",
		"Kingston DataTraveler 2.0 Stick (1GB)","Flash Memory","TransMemory Flash Memory","Kingston DataTraveler 2.0 Stick (2GB)","Kingston DataTraveler 102 Flash Drive / HEMA Flash Drive 2 GB / PNY Attache 4GB Stick"
		};
		InsertProducts(0x0930, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0300,0x0302,0x0320,0x0482,0x1100,0x1112,0xa311};
		char* mids[] = {"VideoAdvantage","Syntek DC-112X","VideoAdvantage","USB2.0 TVBOX","DC-1100 Video Enhamcement Device",
		"Veo Web Camera","Video Enhancement Device"};
		InsertProducts(0x0932, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000c,0x0030,0x003c};
		char* mids[] = {"Rhythmedics 6 BioData Integrator","Composite Device, Mass Storage Device (Flash Drive) amd HID","Rhythmedics HID Bootloader"};
		InsertProducts(0x0936, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0b15};
		char* mids[] = {"Toshiba Stor.E Alu 2"};
		InsertProducts(0x0939, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0007,0x010e,0x010f,0x020f,0x050f,0x2460,0x2468,0x2470,0x2471,0x2500,0x2510,0x2521,0x2600,0x2601,0x2603,0x2608,0x260e,0x260f,0x2621,0x2622,
		0x2624};
		char* mids[] = {"CMOS 100K-R Rev. 1.90","Digital camera, CD302N/Elta Medi@ digi-cam/HE-501A","Argus DC-1610/DC-1620/Emprex PCD3600/Philips P44417B keychain camera/Precision Mini,Model HA513A/Vivitar Vivicam 55","Bullet Line Photo Viewer","Mars-Semi Pc-Camera",
		"Q-TEC WEBCAM 100","SoC PC-Camera","SoC PC-Camera","SoC PC-Camera","USB Optical Mouse",
		"Optical Mouse","Optical Mouse","Typhoon Easycam USB 330K (newer)/Typhoon Easycam USB 2.0 VGA 1.3M/Sansun SN-508","SPC 610NC Laptop Camera","PAC7312 Camera",
		"PAC7311 Trust WB-3300p","PAC7311 Gigaware VGA PC Camera:Trust WB-3350p:SIGMA cam 2350","PAC7311 SnakeCam","PAC731x Trust Webcam","Webcam Genius",
		"Webcam"};
		InsertProducts(0x093a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010,0x0011,0x0041,0x0042,0xa002,0xa003,0xa004,0xa005,0xa102,0xa104};
		char* mids[] = {"Storage Adapter","PlexWriter 40/12/40U","PX-708A DVD RW","PX-712UF DVD RW","ConvertX M402U XLOADER",
		"ConvertX AV100U A/V Capture Audio","ConvertX TV402U XLOADER","ConvertX TV100U A/V Capture","ConvertX M402U A/V Capture","ConvertX PX-TV402U/NA"
		};
		InsertProducts(0x093b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0601,0x0701};
		char* mids[] = {"ValueCAN","NeoVI Blue vehicle bus interface"};
		InsertProducts(0x093c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0020,0x0023,0x010d,0x010e,0x010f,0x0117,0x0f03};
		char* mids[] = {"PXR4 4-Track Digital Recorder","KAOSS Pad KP3 Dynamic Effect/Sampler","KAOSSILATOR PRO Dynamic Phrase Synthesizer","nanoKEY MIDI keyboard","nanoPAD pad controller",
		"nanoKONTROL studio controller","nanoKONTROL2 MIDI Controller","K-Series K61P MIDI studio controller"};
		InsertProducts(0x0944, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0301,0x0302,0x0303,0x0304,0x1105};
		char* mids[] = {"USB Pro (24/48)","USB Pro (24/96 playback)","USB Pro (24/96 record)","USB Pro (16/48)","USB One"
		};
		InsertProducts(0x0948, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"neonode N2"};
		InsertProducts(0x094b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x05fc};
		char* mids[] = {"U640MO-03","METALWEAR-HDD"};
		InsertProducts(0x094f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0008,0x000a,0x1600,0x1601,0x1602,0x1603,0x1606,0x1607,0x160d,0x1613,0x1616,0x1621,0x1624,0x1625,0x162a,0x162d,0x1630,0x1642,0x1643,0x1653,
		0x1656,0x1665,0x1689,0x168a,0x168c};
		char* mids[] = {"Ethernet","KNU101TX 100baseTX Ethernet","DataTraveler II Pen Drive","DataTraveler II+ Pen Drive","DataTraveler Mini",
		"DataTraveler 1GB/2GB Pen Drive","Eee PC 701 SD Card Reader [ENE UB6225]","DataTraveler 100","DataTraveler Vault Privacy","DataTraveler DT101C Flash Drive",
		"DataTraveler Locker 4GB","DataTraveler 150 (32GB)","DataTraveler G2","DataTraveler 101 II","DataTraveler 112 4GB Pen Drive",
		"DataTraveler 102","DataTraveler 200 (32GB)","DT101 G2","DataTraveler G3","Data Traveler 100 G2 8 GiB",
		"DataTraveler Ultimate G2","Digital DataTraveler SE9 64GB","DataTraveler SE9","DataTraveler Micro","DT Elite 3.0"
		};
		InsertProducts(0x0951, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7030,0x7100,0x7820,0xb400,0xb401};
		char* mids[] = {"Tegra 3 (recovery mode)","Notion Ink Adam","Tegra 2 AC100 developer mode","SHIELD (debug)","SHIELD"
		};
		InsertProducts(0x0955, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0200,0x0202,0x0407,0x0518,0x0a07,0x1745,0x2918};
		char* mids[] = {"E-Video DC-350 Camera","E-Video DC-350 Camera","33220A Waveform Generator","82357B GPIB Interface","34411A Multimeter",
		"Test and Measurement Device (IVI)","U2702A oscilloscope"};
		InsertProducts(0x0957, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2bd0};
		char* mids[] = {"Intelligent ISDN (Ver. 3.60.04)"};
		InsertProducts(0x0959, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3003};
		char* mids[] = {"Express Ethernet"};
		InsertProducts(0x095a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Polycom ViaVideo"};
		InsertProducts(0x095d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0204};
		char* mids[] = {"WarpLink 802.11b Adapter"};
		InsertProducts(0x0967, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0120,0x0802,0x0807};
		char* mids[] = {"Microcosm Ltd Dinkey","ePass2000 (G&D STARCOS SPK 2.4)","ePass2003"};
		InsertProducts(0x096e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2000,0x2001,0x2003,0x2005,0x2007};
		char* mids[] = {"i1 Pro","i1 Monitor","Eye-One display","Huey","ColorMunki Photo"
		};
		InsertProducts(0x0971, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"e-gate Smart Card"};
		InsertProducts(0x0973, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0222,0x0224,0x0226,0x0227};
		char* mids[] = {"Keychain Display","JL2005A Toy Camera","JL2005A Toy Camera","JL2005B/C/D Toy Camera"};
		InsertProducts(0x0979, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Digital Wallet"};
		InsertProducts(0x097a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0035};
		char* mids[] = {"MP35 v1.0"};
		InsertProducts(0x097e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0040,0x0200};
		char* mids[] = {"SATA Wire (2.5\")","Hard Drive Storage (TPP)"};
		InsertProducts(0x0984, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0045,0x00a3};
		char* mids[] = {"Mach4/200 Label Printer","A3/200 or A3/300 Label Printer"};
		InsertProducts(0x0985, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"REB1100 eBook Reader","eBook"};
		InsertProducts(0x0993, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0638,0x610c,0x713a,0x7160};
		char* mids[] = {"Sanwa Supply Inc. Small Keyboard","EL-610 Super Mini Electron luminescent Keyboard","WK-713 Multimedia Keyboard","Hyper Slim Keyboard"};
		InsertProducts(0x099a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8001};
		char* mids[] = {"Mass Storage Device"};
		InsertProducts(0x09a6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x3642};
		char* mids[] = {"Prism GT 802.11b/g Adapter","Prism 2.x 802.11b Adapter"};
		InsertProducts(0x09aa, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"eBookman Palm Computer"};
		InsertProducts(0x09b2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"MPaxx MP150 MP3 Player"};
		InsertProducts(0x09bc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"MySmartPad"};
		InsertProducts(0x09be, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00c0,0x00db,0x00dc,0x00dd,0x00de,0x00e0,0x00e2,0x00f1,0x00f2,0x00f5,0x8000,0x8001,0x8002,0x8005};
		char* mids[] = {"COMpact 2104 ISDN PBX","COMpact 4410/2206 ISDN","COMpact 4406 DSL (PBX)","COMpact 2204 (PBX)","COMpact 2104 (Rev.2 PBX)",
		"COMmander Business (PBX)","COMmander Basic.2 (PBX)","COMfort 2000 (System telephone)","COMfort 1200 (System telephone)","COMfortel 2500 (System telephone)",
		"COMpact 2104 DSL (DSL modem)","COMpact 4406 DSL (DSL modem)","Analog/ISDN Converter (Line converter)","WG-640 (Automatic event dialer)"};
		InsertProducts(0x09bf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0136,0x0202,0x0203,0x0204,0x0205,0x0206};
		char* mids[] = {"Axon CNS, MultiClamp 700B","8PSK DVB-S tuner","Skywalker-1 DVB-S tuner","Skywalker-CW3K DVB-S tuner","Skywalker-CW3K DVB-S tuner",
		"Skywalker-2 DVB-S tuner"};
		InsertProducts(0x09c0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1337};
		char* mids[] = {"TOUCHSTONE DEVICE"};
		InsertProducts(0x09c1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0007,0x0008,0x0014};
		char* mids[] = {"Reader V2","ZFG-9800-AC SmartCard Reader","ActivIdentity ActivKey SIM USB Token"};
		InsertProducts(0x09c3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0011};
		char* mids[] = {"ACT-IR2000U IrDA Dongle"};
		InsertProducts(0x09c4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0404};
		char* mids[] = {"BAFO USB-ATA/ATAPI Bridge Controller"};
		InsertProducts(0x09cc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2001};
		char* mids[] = {"Psion WaveFinder DAB radio receiver"};
		InsertProducts(0x09cd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x000b};
		char* mids[] = {"ISDN TA / Light Rider 128K","Bluetooth Adapter class 1 [BlueLight]"};
		InsertProducts(0x09d3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100};
		char* mids[] = {"NovAtel FlexPack GPS receiver"};
		InsertProducts(0x09d7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0006,0x000a,0x000e,0x0018,0x001a,0x002a,0x022b,0x024f,0x0260,0x032b,0x8090,0x9033,0x9066,0x9090};
		char* mids[] = {"Optical Mouse WOP-35 / Trust 450L Optical Mouse","Optical Mouse Opto 510D","X-F710F Optical Mouse 3xFire Gaming Mouse","Trust Human Interface Device","Wireless Mouse & RXM-15 Receiver",
		"Wireless Optical Mouse NB-30","Wireless Mouse (Battery Free)","RF Receiver and G6-20D Wireless Optical Mouse","KV-300H Isolation Keyboard","Wireless Mouse (Battery Free)",
		"X-718BK Oscar Optical Gaming Mouse","X-718BK Optical Mouse","F3 V-Track Gaming Mouse","XL-730K / XL-750BK / XL-755BK Mice"};
		InsertProducts(0x09da, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0075,0x0076,0x007a,0x0081,0x0082,0x0088};
		char* mids[] = {"MiniLab 1008","PMD-1024","PMD-1208LS","USB-1616FS","USB-1208FS",
		"USB-1616FS internal hub"};
		InsertProducts(0x09db, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5121};
		char* mids[] = {"MicroLink dLAN"};
		InsertProducts(0x09e1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0062,0x006d,0x0071,0x0076};
		char* mids[] = {"MPD16 MIDI Pad Controller Unit","EWI electronic wind instrument","MPK25 MIDI Keyboard","LPK25 MIDI Keyboard"};
		InsertProducts(0x09e8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4331};
		char* mids[] = {"iRhythm Tuner Remote"};
		InsertProducts(0x09eb, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"MD-Port DG2 MiniDisc Interface"};
		InsertProducts(0x09ef, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0018,0x0028,0x0048,0x0064,0x0300};
		char* mids[] = {"GF-46 Multi-Mode Display Module","RP-48 Combination Pushbutton-Rotary Module","LGTII - Landing Gear and Trim Control Module","MCPPro - Airliner Mode Control Panel (Autopilot)","EFIS - Electronic Flight Information System"
		};
		InsertProducts(0x09f3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0168,0x0188,0x0850};
		char* mids[] = {"Network Adapter","LAN Adapter","Adapter"};
		InsertProducts(0x09f5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6001};
		char* mids[] = {"Blaster"};
		InsertProducts(0x09fb, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7211};
		char* mids[] = {"hub"};
		InsertProducts(0x0a05, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0064,0x0078,0x0082,0x00c8,0x00d0,0x00da};
		char* mids[] = {"ADU100 Data Acquisition Interface","ADU120 Data Acquisition Interface","ADU130 Data Acquisition Interface","ADU200 Relay I/O Interface","ADU208 Relay I/O Interface",
		"ADU218 Solid-State Relay I/O Interface"};
		InsertProducts(0x0a07, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2514};
		char* mids[] = {"CTS-1000 Internal Hub"};
		InsertProducts(0x0a0d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0009,0x000a,0x000b,0x0043,0x0100,0x0101,0x0102,0x0103,0x0104,0x0105,0x1000,0x1010,
		0x1011,0x1012,0xffff};
		char* mids[] = {"Bluetooth Dongle (HCI mode)","Frontline Test Equipment Bluetooth Device","Nanosira","Nanosira WHQL Reference Radio","Nanosira-Multimedia",
		"Nanosira-Multimedia WHQL Reference Radio","Nanosira3-ROM","Nanosira3-ROM","Nanosira4-EDR WHQL Reference Radio","Nanosira4-EDR-ROM",
		"Nanosira5-ROM","Bluetooth Device","Casira with BlueCore2-External Module","Casira with BlueCore2-Flash Module","Casira with BlueCore3-Multimedia Module",
		"Casira with BlueCore3-Flash Module","Casira with BlueCore4-External Module","Casira with BlueCore4-Multimedia Module","Bluetooth Dongle (HID proxy mode)","Bluetooth Device",
		"Bluetooth Device","Bluetooth Device","USB Bluetooth Device in DFU State"};
		InsertProducts(0x0a12, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1111,0x8888,0x9988};
		char* mids[] = {"ThumbDrive","IBM USB Memory Key","Trek2000 TD-G2"};
		InsertProducts(0x0a16, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004,0x0006,0x0007,0x0009,0x000a,0x000c,0x000d,0x0015,0x003b,0x003d,0x0043,0x0047,0x0052,0x006e,0x0070,0x0093,0x00a7,0x1001};
		char* mids[] = {"Optio 330","Optio S","Optio 550","Optio 33WR","Optio 555",
		"Optio 43WR (mass storage mode)","Optio 43WR","Optio S40/S5i","Optio 50 (mass storage mode)","Optio S55",
		"*ist DL","Optio S60","Optio 60 Digital Camera","K10D","K100D",
		"K200D","Optio E50","EI2000 Camera powered by Digita!"};
		InsertProducts(0x0a17, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8001};
		char* mids[] = {"MMT-7305WW [Medtronic Minimed CareLink]"};
		InsertProducts(0x0a21, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0102};
		char* mids[] = {"SP35"};
		InsertProducts(0x0a27, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0008};
		char* mids[] = {"GPIO Ports"};
		InsertProducts(0x0a2c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0110};
		char* mids[] = {"TG82tp","Deck 82-key backlit keyboard"};
		InsertProducts(0x0a34, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x002a,0x008a};
		char* mids[] = {"SAC - Software Assigned Controller","SAC Hub"};
		InsertProducts(0x0a35, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0163};
		char* mids[] = {"KN-W510U 1.0 Wireless LAN Adapter"};
		InsertProducts(0x0a3a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0268,0x6688,0x8515,0x9000,0x9601};
		char* mids[] = {"ST268","ZT6688 Fast Ethernet Adapter","ADMtek ADM8515 NIC","DM9000E Fast Ethernet Adapter","DM9601 Fast Ethernet Adapter"
		};
		InsertProducts(0x0a46, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3233,0x3239,0x3258,0x3259,0x5000,0x500a,0x500f,0x5010,0x5011,0x5014,0x5020,0x5021,0x5022,0x5023,0x5024,0x5025};
		char* mids[] = {"Multimedia Card Reader","Multimedia Card Reader","Dane Elec zMate SD Reader","Dane Elec zMate CF Reader","MediaGear xD-SM",
		"Mass Storage Device","Mass Storage Device","Mass Storage Device","Mass Storage Device","Mass Storage Device",
		"Mass Storage Device","Mass Storage Device","Mass Storage Device","Mass Storage Device","Mass Storage Device",
		"Mass Storage Device"};
		InsertProducts(0x0a48, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x15d9};
		char* mids[] = {"OPTICAL MOUSE"};
		InsertProducts(0x0a4c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0064,0x0065,0x0066,0x0067,0x0078,0x0079,0x007a,0x008c,0x008d,0x008e,0x008f,0x0090,0x0091,0x00a0,0x00a1,0x00a2,0x00a3,0x00b5,0x00d2,0x00f0,
		0x00f1,0x00f5};
		char* mids[] = {"MK-225 Driver","MK-225C Driver","MK-225C Driver","MK-425C Driver","MK-37 Driver",
		"MK-37C Driver","MK-37C Driver","TerraTec MIDI MASTER","MK-249C Driver","MK-249C MIDI Keyboard",
		"MK-449C Driver","Keystation 49e Driver","Keystation 61es Driver","MK-361 Driver","MK-361C Driver",
		"MK-361C Driver","MK-461C MIDI Keyboard","Keystation Pro 88 Driver","E-Keys Driver","UC-16 Driver",
		"X-Session Driver","UC-33e MIDI Controller"};
		InsertProducts(0x0a4d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x2000,0x2001,0x2013,0x2014,0x2015,0x2016,0x202a,0x3000,0x3002,0x3015,0x302a,0x5001};
		char* mids[] = {"Scanner","Q-Scan A6 Scanner","Q-Scan A6 Scanner","Media Drive A6 Scanner","Media Drive A6 Scanner",
		"BizCardReader 600C","BizCardReader 600C","Scanshell-CSSN","Q-Scan A8 Scanner","Q-Scan A8 Reader",
		"BizCardReader 300G","LM9832 - PA570 Mini Business Card Scanner [Targus]","BizCardReader 900C"};
		InsertProducts(0x0a53, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0201,0x2000,0x2001,0x2009,0x200a,0x200f,0x201d,0x201e,0x2020,0x2021,0x2033,0x2035,0x2038,0x2039,0x2045,0x2046,0x2047,0x205e,0x2100,0x2101,
		0x2102,0x2110,0x2111,0x2120,0x2121,0x2122,0x2123,0x2130,0x2131,0x2145,0x2148,0x2150,0x2151,0x2154,0x217d,0x217f,0x2198,0x219b,0x21b1,0x21b4,
		0x21b9,0x21ba,0x21bb,0x21bc,0x21bd,0x21d7,0x21e1,0x21e3,0x21e6,0x21e8,0x21f1,0x22be,0x4500,0x4502,0x4503,0x5800,0x5801,0x5802,0x5803,0x6300,
		0xbd11,0xbd13,0xbd16,0xbd17,0xd11b};
		char* mids[] = {"iLine10(tm) Network Adapter","Bluetooth Device","Bluetooth Device","BCM2035 Bluetooth","BCM2035 Bluetooth dongle",
		"Bluetooth Controller","Bluetooth Device","IBM Integrated Bluetooth IV","Bluetooth dongle","BCM2035B3 Bluetooth Adapter",
		"BCM2033 Bluetooth","BCM2035 Bluetooth","Blutonium Device","BCM2045 Bluetooth","Bluetooth Controller",
		"Bluetooth Device","Bluetooth Device","Bluetooth Device","Bluetooth 2.0+eDR dongle","BCM2045 Bluetooth",
		"ANYCOM Blue USB-200/250","BCM2045B (BDC-2) [Bluetooth Controller]","ANYCOM Blue USB-UHE 200/250","2045 Bluetooth 2.0 USB-UHE Device with trace filter","BCM2210 Bluetooth",
		"Bluetooth 2.0+EDR dongle","Bluetooth dongle","2045 Bluetooth 2.0 USB-UHE Device with trace filter","2045 Bluetooth 2.0 Device with trace filter","BCM2045B (BDC-2.1) [Bluetooth Controller]",
		"BCM92046DG-CL1ROM Bluetooth 2.1 Adapter","BCM2046 Bluetooth Device","Bluetooth","BCM92046DG-CL1ROM Bluetooth 2.1 UHE Dongle","HP Bluethunder",
		"BCM2045B (BDC-2.1)","Bluetooth 3.0 Device","Bluetooth 2.1 Device","HP Bluetooth Module","BCM2070 Bluetooth 2.1 + EDR",
		"BCM2070 Bluetooth 2.1 + EDR","BCM2070 Bluetooth 2.1 + EDR","BCM2070 Bluetooth 2.1 + EDR","BCM2070 Bluetooth 2.1 + EDR","BCM2070 Bluetooth 2.1 + EDR",
		"BCM43142 Bluetooth 4.0","HP Portable SoftSailing","HP Portable Valentine","BCM20702 Bluetooth 4.0 [ThinkPad]","BCM20702A0 Bluetooth 4.0",
		"HP Portable Bumble Bee","BCM2070 Bluetooth 3.0 + HS","BCM2046B1 USB 2.0 Hub (part of BCM2046 Bluetooth)","Keyboard (Boot Interface Subclass)","Mouse (Boot Interface Subclass)",
		"BCM5880 Secure Applications Processor","BCM5880 Secure Applications Processor with fingerprint swipe sensor","BCM5880 Secure Applications Processor with fingerprint touch sensor","BCM5880 Secure Applications Processor with secure keyboard","Pirelli Remote NDIS Device",
		"TiVo AG0100 802.11bg Wireless Adapter [Broadcom BCM4320]","BCM4323 802.11abgn Wireless Adapter","BCM4319 802.11bgn Wireless Adapter","BCM43236 802.11abgn Wireless Adapter","Eminent EM4045 [Broadcom 4320 USB]"
		};
		InsertProducts(0x0a5c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0009,0x0081,0x008b,0x00d1,0x930a};
		char* mids[] = {"LP2844 Printer","GK420t Label Printer","HC100 wristbands Printer","Zebra GC420d Label Printer","Printer"
		};
		InsertProducts(0x0a5f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010};
		char* mids[] = {"MPMan MP-F40 MP3 Player"};
		InsertProducts(0x0a62, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x000f};
		char* mids[] = {"Compact Flash R/W with MP3 player","FlashDisk"};
		InsertProducts(0x0a6b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0400};
		char* mids[] = {"Xanboo"};
		InsertProducts(0x0a6f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"VP485 Printer"};
		InsertProducts(0x0a71, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"XD-2 [Spike]"};
		InsertProducts(0x0a73, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0103,0x0203,0x0205,0x0701,0xff01};
		char* mids[] = {"Keyboard","Keyboard","Mouse","PS/2 Keyboard+Mouse Adapter","USB Missile Launcher",
		"Wireless Missile Launcher"};
		InsertProducts(0x0a81, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4600};
		char* mids[] = {"TravelScan 460/464"};
		InsertProducts(0x0a82, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2011};
		char* mids[] = {"Filter Driver For JAE XMC R/W"};
		InsertProducts(0x0a8e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3801};
		char* mids[] = {"Targus PAKP003 Mouse"};
		InsertProducts(0x0a91, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0011,0x0021,0x0031,0x0053,0x0061,0x0071,0x0091,0x00b1,0x1000,0x1010,0x1020,0x1030,0x1090,0x10a0};
		char* mids[] = {"SYS WaveTerminal U2A","GIGAPort","GIGAPortAG","AudioTrak Optoplay","Waveterminal U24",
		"MAYA EX7","Maya 44","MAYA EX5","MIDI Mate","RoMI/O",
		"M4U","M8U","KeyControl49","KeyControl25"};
		InsertProducts(0x0a92, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0005,0x000d,0x0010,0x0a93};
		char* mids[] = {"C-Pen 10","MyPen Light","Input Pen","C-Pen 20","PayPen"
		};
		InsertProducts(0x0a93, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0801};
		char* mids[] = {"irock! 500 Series","MP3 Player"};
		InsertProducts(0x0aa5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x1501};
		char* mids[] = {"Hercules Jukebox","Store 'n' Go HD Drive"};
		InsertProducts(0x0aa6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0101,0x0102,0x0103,0x0104,0x0200,0x0201,0x0202,0x0203,0x0204,0x0300,0x0301,0x0302,0x0303,0x0304,0x0305,0x0306,0x0307,0x0308,0x0309,
		0x030a,0x0400,0x0401,0x0402,0x0500,0x0501,0x0502,0x4304,0x4305,0x4500};
		char* mids[] = {"POS Keyboard, TA58P-USB","POS Keyboard, TA85P-USB","POS Keyboard, TA59-USB","POS Keyboard, TA60-USB","SNIkey Keyboard, SNIKey-KB-USB",
		"Operator Display, BA63-USB","Operator Display, BA66-USB","Operator Display & Scanner, XiCheck-BA63","Operator Display & Scanner, XiCheck-BA66","Graphics Operator Display, BA63GV",
		"POS Printer (printer class mode), TH210","POS Printer (native mode), TH210","POS Printer (printer class mode), TH220","POS Printer (native mode), TH220","POS Printer, TH230",
		"Lottery Printer, XiPrintPlus","POS Printer (printer class mode), TH320","POS Printer (native mode), TH320","POS Printer (printer class mode), TH420","POS Printer (native mode), TH420",
		"POS Printer, TH200B","Lottery Scanner, Xiscan S","Lottery Scanner, Xiscan 3","Programmable Magnetic Swipe Card Reader, MSRP-USB","IDE Adapter",
		"Hub Printer Interface","Hub SNIKey Keyboard","Banking Printer TP07","Banking Printer TP07c","WN Central Special Electronics"
		};
		InsertProducts(0x0aa7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0060,0x1001,0x3002,0x8001,0x8002,0xa001,0xa002,0xffda};
		char* mids[] = {"TG 11Mbps WLAN Mini Adapter","DreamComboM4100","InkJet Color Printer","TG_iMON","TG_KLOSS",
		"TG_X2","TGVFD_KLOSS","iMON_VFD"};
		InsertProducts(0x0aa8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xf01b};
		char* mids[] = {"Medion MD 6242 MP3 Player"};
		InsertProducts(0x0aa9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x000c,0x0013,0x0014,0x0015,0x0016,0x0017,0x0018,0x0019,0x0021,0x0023,0x002c,0x002d,0x002f,0x0051,0x0052,0x0062,0x0070,0x0083,0x0095
		};
		char* mids[] = {"NRP-Z21","NRP-Z11","NRP-Z22","NRP-Z23","NRP-Z24",
		"NRP-Z51","NRP-Z52","NRP-Z55","NRP-Z56","NRP-Z91",
		"NRP-Z81","NRP-Z31","NRP-Z37","NRP-Z27","NRP-Z28",
		"NRP-Z98","NRP-Z92","NRP-Z57","NRP-Z85","NRP-Z86"
		};
		InsertProducts(0x0aad, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"OBID RFID-Reader"};
		InsertProducts(0x0ab1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8001,0x8002};
		char* mids[] = {"Tracker 110 Protocol Analyzer","Explorer 200 Protocol Analyzer"};
		InsertProducts(0x0aba, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"SL1200 DAC"};
		InsertProducts(0x0abe, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3370};
		char* mids[] = {"I2C/SPI Adapter - U2C-12"};
		InsertProducts(0x0abf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0301,0x0302,0x0321,0x0323,0x0328,0x0336,0x301b,0x303b,0x305b,0x307b,0x332d,0x3343,0x3370,0x3420,0xc001,0xc002,0xc302,0xc303,0xc326,0xc33f,
		0xc429,0xc42d};
		char* mids[] = {"Web Camera","ZC0302 Webcam","Vimicro generic vc0321 Camera","Luxya WC-1200 USB 2.0 Webcam","A4Tech PK-130MG",
		"Elecom UCAM-DLQ30","ZC0301 Webcam","ZC0303 Webcam","ZC0305 Webcam","USB 1.1 Webcam",
		"Vega USB 2.0 Camera","Sirius USB 2.0 Camera","Traveler TV 6500 SF Dia-scanner","Venus USB2.0 Camera","Sony embedded vimicro Camera",
		"Visual Communication Camera VGP-VCC1","Vega USB 2.0 Camera","Saturn USB 2.0 Camera","Namuga 1.3M Webcam","Webcam",
		"Lenovo ThinkCentre Web Camera","Lenovo IdeaCentre Web Camera"};
		InsertProducts(0x0ac8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0001,0x0010,0x0011,0x0110,0x0111,0x1234};
		char* mids[] = {"Backpack CD-ReWriter","BACKPACK  2 Cable","BACKPACK","Backpack 40GB Hard Drive","BACKPACK",
		"BackPack","BACKPACK"};
		InsertProducts(0x0ac9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1060};
		char* mids[] = {"OPEN NT1 Plus II"};
		InsertProducts(0x0aca, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0300,0x0401,0x0630,0x0810,0x2030};
		char* mids[] = {"IDT1221U RS-232 Adapter","Spectrum III Hybrid Smartcard Reader","Spectrum III Mag-Only Insert Reader (SPT3-355 Series) USB-CDC","SecurePIN (IDPA-506100Y) PIN Pad","ValueMag Magnetic Stripe Reader"
		};
		InsertProducts(0x0acd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1201,0x1211,0x1215,0x1221,0x1602,0x1608,0x1611,0x2011,0x20ff,0xa211,0xb215};
		char* mids[] = {"ZD1201 802.11b","ZD1211 802.11g","ZD1211B 802.11g","ZD1221 802.11n","ZyXEL Omni FaxModem 56K",
		"ZyXEL Omni FaxModem 56K UNO","ZyXEL Omni FaxModem 56K Plus","Virtual media for 802.11bg","Virtual media for 802.11bg","ZD1211 802.11b/g Wireless Adapter",
		"802.11bg"};
		InsertProducts(0x0ace, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005};
		char* mids[] = {"DK2"};
		InsertProducts(0x0ada, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2101,0x2102,0x2103,0x2104,0x2201,0x2202,0x2203,0x2204,0x2205,0x2206,0x2301,0x2302,0x2303,0x2304,0x3016,0x3050,0x3060,0x3101,0x3102,0x3201,
		0x3216,0x3260,0x5010};
		char* mids[] = {"SmartMedia Card Reader","CompactFlash Card Reader","MMC/SD Card Reader","MemoryStick Card Reader","SmartMedia+CompactFlash Card Reader",
		"SmartMedia+MMC/SD Card Reader","SmartMedia+MemoryStick Card Reader","CompactFlash+MMC/SD Card Reader","CompactFlash+MemoryStick Card Reader","MMC/SD+MemoryStick Card Reader",
		"SmartMedia+CompactFlash+MMC/SD Card Reader","SmartMedia+CompactFlash+MemoryStick Card Reader","SmartMedia+MMC/SD+MemoryStick Card Reader","CompactFlash+MMC/SD+MemoryStick Card Reader","MMC/SD+Memory Stick Card Reader",
		"ND3050 8-in-1 Card Reader","1.1 FS Card Reader","MMC/SD Card Reader","MemoryStick Card Reader","MMC/SD+MemoryStick Card Reader",
		"HS Card Reader","7-in-1 Card Reader","ND5010 Card Reader"};
		InsertProducts(0x0aec, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5000,0x6000,0x6300,0x6600,0x6711,0x6971,0x7251,0x7501,0x7601,0x7701,0xd055};
		char* mids[] = {"UMTS Card","GlobeTrotter 3G datacard","GT 3G Quad UMTS/GPRS Card","GlobeTrotter 3G+ datacard","GlobeTrotter Express 7.2 v2",
		"Globetrotter HSDPA Modem","Globetrotter HSUPA Modem (aka iCON HSUPA E)","Globetrotter HSUPA Modem (icon 411 aka \"Vodafone K3760\")","Globetrotter MO40x 3G Modem (GTM 382)","Globetrotter HSUPA Modem (aka icon 451)",
		"Globetrotter GI0505 [iCON 505]"};
		InsertProducts(0x0af0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"Digital TV USB Receiver (DVB-S/T/C / ATSC)"};
		InsertProducts(0x0af7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010,0x0011};
		char* mids[] = {"USB SightCam 100","Micro Innovations IC50C Webcam"};
		InsertProducts(0x0af9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x07d2};
		char* mids[] = {"Controller Board for Projected Capacitive Touch Screen DUS3000"};
		InsertProducts(0x0afa, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x1101,0x1706,0x1707,0x1708,0x170b,0x170c,0x170d,0x1712,0x1715,0x1716,0x1717,0x171b,0x171c,0x171f,0x1723,0x1724,0x1726,0x172a,0x172b,
		0x1731,0x1732,0x1734,0x173c,0x173f,0x1742,0x1743,0x1751,0x175b,0x1760,0x1761,0x1774,0x1776,0x1779,0x1784,0x1786,0x1788,0x1791,0x179d,0x179e,
		0x179f,0x17a0,0x17a1,0x17ab,0x17c9,0x4c80,0x4c90,0x4c91,0x4d00,0x4d01,0x4daf,0x5410,0x5412,0x6101,0x620a,0xb700};
		char* mids[] = {"MeMO Pad HD 7 (CD-ROM mode)","Mass Storage (UISDMC4S)","WL-167G v1 802.11g Adapter [Ralink RT2571]","WL-167G v1 802.11g Adapter [Ralink RT2571]","Mass Storage Device",
		"Mass Storage Device","WL-159g 802.11bg","802.11b/g Wireless Network Adapter","BT-183 Bluetooth 2.0+EDR adapter","2045 Bluetooth 2.0 Device with trace filter",
		"Bluetooth Device","WL169gE 802.11g Adapter [Broadcom 4320 USB]","A9T wireless 802.11bg","802.11b/g Wireless Network Adapter","My Cinema U3000 Mini [DiBcom DiB7700P]",
		"WL-167G v2 802.11g Adapter [Ralink RT2571W]","RT2573","Laptop OLED Display","ASUS 802.11n Network Adapter","802.11n Network Adapter",
		"802.11n Network Adapter","802.11n Network Adapter","ASUS AF-200","BT-183 Bluetooth 2.0","My Cinema U3100 Mini",
		"802.11n Network Adapter","Xonar U1 Audio Station","BT-253 Bluetooth Adapter","Laptop OLED Display","802.11n Network Adapter",
		"USB-N11 802.11n Network Adapter [Ralink RT2870]","Gobi Wireless Modem (QDL mode)","Gobi Wireless Modem","My Cinema U3100 Mini Plus [AF9035A]","USB-N13 802.11n Network Adapter (rev. A1) [Ralink RT3072]",
		"USB-N10 802.11n Network Adapter [Realtek RTL8188SU]","BT-270 Bluetooth Adapter","WL-167G v3 802.11n Adapter [Realtek RTL8188SU]","USB-N53 802.11abgn Network Adapter [Ralink RT3572]","Eee Note EA800 (network mode)",
		"Eee Note EA800 (tablet mode)","Xonar U3 sound card","Eee Note EA800 (mass storage mode)","USB-N13 802.11n Network Adapter (rev. B1) [Realtek RTL8192CU]","USB-AC53 802.11a/b/g/n/ac Wireless Adapter [Broadcom BCM43526]",
		"Transformer Pad TF300TG","Transformer Pad Infinity TF700","Transformer Pad Infinity TF700 (Debug mode)","Transformer Prime TF201","Transformer Prime TF201 (debug mode)",
		"Transformer Pad Infinity TF700 (Fastboot)","MeMO Pad HD 7 (MTP mode)","MeMO Pad HD 7 (PTP mode)","Cable Modem","Remote NDIS Device",
		"Broadcom Bluetooth 2.1"};
		InsertProducts(0x0b05, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x106e};
		char* mids[] = {"Datamax E-4304"};
		InsertProducts(0x0b0b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0009,0x001e,0x002e,0x003f,0x0050};
		char* mids[] = {"Todos Argos Mini II Smart Card Reader","e.dentifier2 (ABN AMRO electronic banking card reader NL)","C200 smartcard controller (Nordea card reader)","Todos C400 smartcard controller (Handelsbanken card reader)","Argos Mini II Smart Card Reader (CCID)"
		};
		InsertProducts(0x0b0c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000};
		char* mids[] = {"CenturyCD"};
		InsertProducts(0x0b0d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0420,0x094d,0x1022,0x2007,0x620c,0x9330};
		char* mids[] = {"Jabra SPEAK 510","GN Netcom / Jabra REVO Wireless","Jabra PRO 9450, Type 9400BS (DECT Headset)","GN 2000 Stereo Corded Headset","Jabra BT620s",
		"Jabra GN9330 Headset"};
		InsertProducts(0x0b0e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8007};
		char* mids[] = {"Blackhawk USB560-BP JTAG Emulator"};
		InsertProducts(0x0b1e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0006};
		char* mids[] = {"SM Media-Shuttle Card Reader"};
		InsertProducts(0x0b30, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0020,0x0700};
		char* mids[] = {"ShuttleXpress","RollerMouse Pro"};
		InsertProducts(0x0b33, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0010};
		char* mids[] = {"Keyboard","107-Key Keyboard"};
		InsertProducts(0x0b38, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0109,0x0421,0x0801,0x0901,0x0c03};
		char* mids[] = {"Composite USB PS2 Converter","USB TO Ethernet","Serial","USB-Parallel Bridge","OCT To Fast Ethernet Converter",
		"LAN DOCK Serial Converter"};
		InsertProducts(0x0b39, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0163,0x1601,0x1602,0x1612,0x1613,0x1620,0x1630,0x5630,0x6630};
		char* mids[] = {"TL-WN320G 1.0 WLAN Adapter","Allnet 0193 802.11b Adapter","ZyXEL ZyAIR B200 802.11b Adapter","AIR.Mate 2@net 802.11b Adapter","802.11b Wireless LAN Adapter",
		"Allnet Wireless Network Adapter [Envara WiND512]","QuickWLAN 802.11bg","802.11bg","ZD1211"};
		InsertProducts(0x0b3b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa010,0xc000,0xc700};
		char* mids[] = {"Simple_Way Printer/Scanner/Copier","Olicard 100","Olicard 100 (Mass Storage mode)"};
		InsertProducts(0x0b3c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0011};
		char* mids[] = {"Crossam2+USB IR commander"};
		InsertProducts(0x0b41, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0005};
		char* mids[] = {"PS2 Controller Converter","GameCube Adaptor"};
		InsertProducts(0x0b43, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1003,0x1004,0x1005,0x1006,0x1007,0x1008,0x1009,0x3001,0x3002,0x3003,0x3004,0x3005,0x3006,0x3007,0x3008,0x3009,0x300a,0x300b,0x300c,0x300d,
		0x300e};
		char* mids[] = {"Technotrend/Hauppauge USB-Nova","TT-PCline","Technotrend/Hauppauge USB-Nova","Technotrend/Hauppauge DEC3000-s","TT-micro plus Device",
		"Technotrend/Hauppauge DEC2000-t","Technotrend/Hauppauge DEC2540-t","DVB-S receiver","DVB-C receiver","DVB-T receiver",
		"TT TV-Stick","TT TV-Stick (8kB EEPROM)","TT-connect S-2400 DVB-S receiver","TT-connect S2-3600","TT-connect",
		"TT-connect S-2400 DVB-S receiver (8kB EEPROM)","TT-connect S2-3650 CI","TT-connect C-3650 CI","TT-connect T-3650 CI","TT-connect CT-3650 CI",
		"TT-connect C-2400"};
		InsertProducts(0x0b48, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x064f};
		char* mids[] = {"Trance Vibrator"};
		InsertProducts(0x0b49, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100};
		char* mids[] = {"D'music MP3 Player"};
		InsertProducts(0x0b4b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x110a};
		char* mids[] = {"Graphtec CC200-20"};
		InsertProducts(0x0b4d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6500,0x8028,0x8920};
		char* mids[] = {"MP3 Player","MP3 Player","MP3 Player"};
		InsertProducts(0x0b4e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0020};
		char* mids[] = {"Comfort Keyboard"};
		InsertProducts(0x0b51, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000b,0x0059};
		char* mids[] = {"Bluetooth Device","iBOT2 Webcam"};
		InsertProducts(0x0b62, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0041};
		char* mids[] = {"Xtreme"};
		InsertProducts(0x0b66, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x555e};
		char* mids[] = {"SCB-R9000"};
		InsertProducts(0x0b67, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa132};
		char* mids[] = {"WUP-005 [Nintendo Wii U Pro Controller]"};
		InsertProducts(0x0b6a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00ba};
		char* mids[] = {"iRiver H10 20GB"};
		InsertProducts(0x0b70, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x07d0};
		char* mids[] = {"Bluetooth Dongle"};
		InsertProducts(0x0b7a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0012,0x0102,0x0103,0x0200,0x0201,0x0220,0x0221};
		char* mids[] = {"Biothentic II smartcard reader with fingerprint sensor","DFU-Enabled Devices (DFU)","BioPAD biometric module (DFU + CDC)","Certis V1 fingerprint reader","Certis V2 fingerprint reader",
		"CL1356T / CL1356T5 / CL1356A smartcard readers (CCID)","CL1356T / CL1356T5 / CL1356A smartcard readers (DFU + CCID)","CL1356A FFPJP smartcard reader (CCID + HID)","CL1356A smartcard reader (DFU + CCID + HID)"};
		InsertProducts(0x0b81, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5100,0x5110,0x5200,0x5201,0x5202,0x5280,0xfff0};
		char* mids[] = {"XMC5100 Zippy Drive","XMC5110 Flash Drive","XMC5200 Zippy Drive","XMC5200 Zippy Drive","XMC5200 Zippy Drive",
		"XMC5280 Storage Drive","ISP5200 Debugger"};
		InsertProducts(0x0b86, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x00c3};
		char* mids[] = {"Interactive Whiteboard Controller (SB6) (HID)","Sympodium ID350"};
		InsertProducts(0x0b8c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1720,0x1780,0x1790,0x7720,0x772a,0x772b,0x7e2b};
		char* mids[] = {"10/100 Ethernet","AX88178","AX88179 Gigabit Ethernet","AX88772","AX88772A Fast Ethernet",
		"AX88772B","AX88772B"};
		InsertProducts(0x0b95, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7732,0x7761,0x7762,0x7772};
		char* mids[] = {"Smart Card Reader","Oz776 1.1 Hub","Oz776 SmartCard Reader","OZ776 CCID Smartcard Reader"};
		InsertProducts(0x0b97, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4012};
		char* mids[] = {"Reflex RC-controller Interface"};
		InsertProducts(0x0b9b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00e5,0x00eb,0x00ec,0x00f1,0x00f2,0x00f5,0x00f6,0x00f7,0x00f8,0x00f9,0x00fa,0x00fb,0x0111,0x0118,0x011b,0x0121,0x0303,0x6112};
		char* mids[] = {"USR6000","USR1120 802.11b Adapter","56K Faxmodem","SureConnect ADSL ATM Adapter","SureConnect ADSL Loader",
		"SureConnect ADSL ATM Adapter","SureConnect ADSL Loader","SureConnect ADSL ATM Adapter","SureConnect ADSL Loader","SureConnect ADSL ATM Adapter",
		"SureConnect ADSL Loader","SureConnect ADSL Ethernet/USB Router","USR5420 802.11g Adapter [Broadcom 4320 USB]","U5 802.11g Adapter","Wireless MAXg Adapter [Broadcom 4320]",
		"USR5423 802.11bg Wireless Adapter [ZyDAS ZD1211B]","USR5637 56K Faxmodem","FaxModem Model 5633"};
		InsertProducts(0x0baf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x5007};
		char* mids[] = {"Sound Vision Stream","3340z/Rollei DC3100"};
		InsertProducts(0x0bb0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0302,0x6098};
		char* mids[] = {"U10H010 802.11b Wireless Adapter [Intersil PRISM 3]","USB Cable Modem"};
		InsertProducts(0x0bb2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00ce,0x00cf,0x0a01,0x0a02,0x0a03,0x0a04,0x0a05,0x0a06,0x0a07,0x0a08,0x0a09,0x0a0a,0x0a0b,0x0a0c,0x0a0d,0x0a0e,0x0a0f,0x0a10,0x0a11,0x0a12,
		0x0a13,0x0a14,0x0a15,0x0a16,0x0a17,0x0a18,0x0a19,0x0a1a,0x0a1b,0x0a1c,0x0a1d,0x0a1e,0x0a1f,0x0a20,0x0a21,0x0a22,0x0a23,0x0a24,0x0a25,0x0a26,
		0x0a27,0x0a28,0x0a29,0x0a2a,0x0a2b,0x0a2c,0x0a2d,0x0a2e,0x0a2f,0x0a30,0x0a31,0x0a32,0x0a33,0x0a34,0x0a35,0x0a36,0x0a37,0x0a38,0x0a39,0x0a3a,
		0x0a3b,0x0a3c,0x0a3d,0x0a3e,0x0a3f,0x0a40,0x0a41,0x0a42,0x0a43,0x0a44,0x0a45,0x0a46,0x0a47,0x0a48,0x0a49,0x0a4a,0x0a4b,0x0a4c,0x0a4d,0x0a4e,
		0x0a4f,0x0a50,0x0a51,0x0a52,0x0a53,0x0a54,0x0a55,0x0a56,0x0a57,0x0a58,0x0a59,0x0a5a,0x0a5b,0x0a5c,0x0a5d,0x0a5e,0x0a5f,0x0a60,0x0a61,0x0a62,
		0x0a63,0x0a64,0x0a65,0x0a66,0x0a67,0x0a68,0x0a69,0x0a6a,0x0a6b,0x0a6c,0x0a6d,0x0a6e,0x0a6f,0x0a70,0x0a71,0x0a72,0x0a73,0x0a74,0x0a75,0x0a76,
		0x0a77,0x0a78,0x0a79,0x0a7a,0x0a7b,0x0a7c,0x0a7d,0x0a7e,0x0a7f,0x0a80,0x0a81,0x0a82,0x0a83,0x0a84,0x0a85,0x0a86,0x0a87,0x0a88,0x0a89,0x0a8a,
		0x0a8b,0x0a8c,0x0a8d,0x0a8e,0x0a8f,0x0a90,0x0a91,0x0a92,0x0a93,0x0a94,0x0a95,0x0a96,0x0a97,0x0a98,0x0a99,0x0a9a,0x0a9b,0x0a9c,0x0a9d,0x0a9e,
		0x0a9f,0x0b03,0x0b04,0x0b05,0x0b06,0x0b0c,0x0b1f,0x0b2f,0x0b51,0x0bce,0x0c01,0x0c02,0x0c03,0x0c13,0x0c1f,0x0c5f,0x0c86,0x0c87,0x0c8d,0x0c91,
		0x0c94,0x0c97,0x0c99,0x0c9e,0x0ca2,0x0ca5,0x0cae,0x0dea,0x0ff8,0x0ff9,0x0ffe,0x0fff};
		char* mids[] = {"mmO2 XDA GSM/GPRS Pocket PC","SPV C500 Smart Phone","PocketPC Sync","Himalaya GSM/GPRS Pocket PC","PocketPC Sync",
		"PocketPC Sync","PocketPC Sync","PocketPC Sync","Magician PocketPC SmartPhone / O2 XDA","PocketPC Sync",
		"PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync",
		"PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync",
		"PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync",
		"PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync",
		"PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync",
		"PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync",
		"PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync",
		"PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync",
		"PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync",
		"PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync",
		"PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync",
		"PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync",
		"PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync",
		"PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync","PocketPC Sync",
		"PocketPC Sync","SmartPhone (MTP)","SPV C400 / T-Mobile SDA GSM/GPRS Pocket PC","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync","SmartPhone Sync",
		"SmartPhone Sync","Ozone Mobile Broadband","Hermes / TyTN / T-Mobile MDA Vario II / O2 Xda Trion","P3600","Athena / Advantage x7500 / Dopod U1000 / T-Mobile AMEO",
		"Elf / Touch / P3450 / T-Mobile MDA Touch / O2 Xda Nova / Dopod S1","Sony Ericsson XPERIA X1","Rhodium","Qtek 8310 mobile phone [Tornado Noble]","Vario MDA",
		"Dream / ADP1 / G1 / Magic / Tattoo","Dream / ADP1 / G1 / Magic / Tattoo (Debug)","Android Phone [Fairphone First Edition (FP1)]","Diamond","Sony Ericsson XPERIA X1",
		"Snap","Sensation","Desire (debug)","EVO 4G (debug)","Vision",
		"Vision","Legend","Desire (debug)","Incredible","Desire HD (debug mode)",
		"Android Phone [Evo Shift 4G]","T-Mobile MyTouch 4G Slide [Doubleshot]","M7_UL [HTC One]","Desire HD (Tethering Mode)","Desire / Desire HD / Hero / Thunderbolt (Charge Mode)",
		"Desire HD (modem mode)","Android Fastboot Bootloader"};
		InsertProducts(0x0bb4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0502,0x0503,0x2000,0x2100,0x2200,0x2300,0x2320,0x3008,0x3101,0x3312,0x3320,0x3332,0x5020,0x5021,0x5030,0x5031,0x5070,0x50a1,0x50a5,0x5121,
		0x5161,0xa003,0xa0a1,0xa0a4,0xab00};
		char* mids[] = {"ST3300601CB-RK 300 GB External Hard Drive","ST3250824A [Barracuda 7200.9]","Storage Adapter V3 (TPP)","FreeAgent Go","FreeAgent Go FW",
		"Expansion Portable","USB 3.0 bridge [Portable Expansion Drive]","FreeAgent Desk 1TB","FreeAgent XTreme 640GB","SRD00F2 [Expansion Desktop Drive 2TB]",
		"SRD00F2 [Expansion Desktop Drive]","Expansion","FreeAgent GoFlex","FreeAgent GoFlex USB 2.0","FreeAgent GoFlex Upgrade Cable STAE104",
		"FreeAgent GoFlex USB 3.0","FreeAgent GoFlex Desk","FreeAgent GoFlex Desk","FreeAgent GoFlex Desk USB 3.0","FreeAgent GoFlex",
		"FreeAgent GoFlex dock","Backup Plus","Backup Plus Desktop","Backup Plus Desktop Drive","Slim Portable Drive"
		};
		InsertProducts(0x0bc2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"UMTS-TDD (TD-CDMA) modem"};
		InsertProducts(0x0bc3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0009,0x000a,0x000b,0x000c,0x000d,0x000e,0x000f};
		char* mids[] = {"ActiveHome (ACPI-compliant)","Firecracker Interface (ACPI-compliant)","VGA Video Sender (ACPI-compliant)","X10 Receiver","Wireless Transceiver (ACPI-compliant)",
		"Wireless Transceiver (ACPI-compliant)","Wireless Transceiver (ACPI-compliant)","Wireless Transceiver (ACPI-compliant)","Wireless Transceiver (ACPI-compliant)","Wireless Transceiver (ACPI-compliant)",
		"Transceiver (ACPI-compliant)","Transceiver (ACPI-compliant)","Transceiver (ACPI-compliant)","Transceiver (ACPI-compliant)","Transceiver (ACPI-compliant)"
		};
		InsertProducts(0x0bc7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa021};
		char* mids[] = {"Amptek DP4 multichannel signal analyzer"};
		InsertProducts(0x0bd7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0103,0x0104,0x0106,0x0107,0x0108,0x0111,0x0113,0x0115,0x0116,0x0117,0x0118,0x0119,0x0129,0x0138,0x0139,0x0151,0x0152,0x0153,0x0156,0x0157,
		0x0158,0x0159,0x0161,0x0168,0x0169,0x0171,0x0176,0x0178,0x0184,0x0186,0x0301,0x1724,0x2831,0x2832,0x2838,0x8150,0x8151,0x8171,0x8172,0x8174,
		0x8176,0x8178,0x8179,0x817f,0x8187,0x8189,0x8192,0x8193,0x8197,0x8198,0x8199,0x8812};
		char* mids[] = {"USB 2.0 Card Reader","Mass Storage Device","Mass Storage Device","Mass Storage Device","Mass Storage Device",
		"RTS5111 Card Reader Controller","Mass Storage Device","Mass Storage Device (Multicard Reader)","RTS5116 Card Reader Controller","Mass Storage Device",
		"Mass Storage Device","Storage Device (SD card reader)","RTS5129 Card Reader Controller","RTS5138 Card Reader Controller","RTS5139 Card Reader Controller",
		"Mass Storage Device (Multicard Reader)","Mass Storage Device","Mass Storage Device","Mass Storage Device","Mass Storage Device",
		"USB 2.0 multicard reader","RTS5159 Card Reader Controller","Mass Storage Device","Mass Storage Device","Mass Storage Device",
		"Mass Storage Device","Mass Storage Device","Mass Storage Device","RTS5182 Card Reader","Card Reader",
		"multicard reader","RTL8723AU 802.11n WLAN Adapter","RTL2831U DVB-T","RTL2832U DVB-T","RTL2838 DVB-T",
		"RTL8150 Fast Ethernet Adapter","RTL8151 Adapteon Business Mobile Networks BV","RTL8188SU 802.11n WLAN Adapter","RTL8191SU 802.11n WLAN Adapter","RTL8192SU 802.11n WLAN Adapter",
		"RTL8188CUS 802.11n WLAN Adapter","RTL8192CU 802.11n WLAN Adapter","RTL8188EUS 802.11n Wireless Network Adapter","RTL8188RU 802.11n WLAN Adapter","RTL8187 Wireless Adapter",
		"RTL8187B Wireless 802.11g 54Mbps Network Adapter","RTL8191SU 802.11n Wireless Adapter","RTL8192DU 802.11an WLAN Adapter","RTL8187B Wireless Adapter","RTL8187B Wireless Adapter",
		"RTL8187SU 802.11g WLAN Adapter","RTL8812AU 802.11a/b/g/n/ac WLAN Adapter"};
		InsertProducts(0x0bda, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x1002,0x1049,0x1900,0x1902,0x1904,0x1905,0x1906,0x1909,0x190a,0x190b};
		char* mids[] = {"BV Bluetooth Device","Bluetooth Device 1.2","C3607w Mobile Broadband Module","F3507g Mobile Broadband Module","F3507g v2 Mobile Broadband Module",
		"F3607gw Mobile Broadband Module","F3607gw v2 Mobile Broadband Module","F3607gw v3 Mobile Broadband Module","F3307 v2 Mobile Broadband Module","F3307 Mobile Broadband Module",
		"C3607w v2 Mobile Broadband Module"};
		InsertProducts(0x0bdb, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1100,0x1101};
		char* mids[] = {"CASHFLOW SC","Series 2000 Combo Acceptor"};
		InsertProducts(0x0bed, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003};
		char* mids[] = {"netMod Driver Ver 2.4.17 (CAPI)","netMod Driver Ver 2.4 (CAPI)","netMod Driver Ver 2.4 (CAPI)"};
		InsertProducts(0x0bf1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0103,0x1234,0xa000,0xa001,0xa002};
		char* mids[] = {"Storage Device","Storage Device","Cable 205 (TPP)","Cable 205","IDE Bridge"
		};
		InsertProducts(0x0bf6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001,0x1006,0x1007,0x1009,0x100c,0x100f,0x1017};
		char* mids[] = {"Fujitsu Pocket Loox 600 PDA","SmartCard Reader 2A","Connect2Air E-5400 802.11g Wireless Adapter","Connect2Air E-5400 D1700 802.11g Wireless Adapter [Intersil ISL3887]","Keyboard FSC KBPC PX",
		"miniCard D2301 802.11bg Wireless Module [SiS 163U]","Keyboard KB SCR"};
		InsertProducts(0x0bf8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004,0x000b,0x000e};
		char* mids[] = {"USBcan II","Leaf Light HS","Leaf SemiPro HS"};
		InsertProducts(0x0bfd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0378};
		char* mids[] = {"Q 16MB Storage Device"};
		InsertProducts(0x0c08, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa5a5};
		char* mids[] = {"Litto Version USB2.0"};
		InsertProducts(0x0c09, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x27cb,0x27d7,0x27da,0x27dc,0x27e7,0x27ee,0x2814,0x2815,0x281d,0x5fab,0xa109,0xa10c,0xb001,0xb004};
		char* mids[] = {"6-in-1 Flash Reader and Writer","Multi Memory reader/writer MD-005","Multi Memory reader/writer MD-005","Multi Memory reader/writer MD-005","3,5'' HDD case MD-231",
		"3,5'' HDD case MD-231","3,5'' HDD case MD-231","3,5'' HDD case MD-231","3,5'' HDD case MD-231","Storage Adaptor",
		"CF/SM Reader and Writer","SD/MS Reader and Writer","USB 2.0 Mass Storage IDE adapter","MMC/SD Reader and Writer"};
		InsertProducts(0x0c0b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005,0x0030,0x700e,0x8801,0x8802,0x8809,0x880a,0x8810,0x9902};
		char* mids[] = {"PSX Vibration Feedback Converter","PSX Vibration Feedback Converter","Logic Analyzer (LAP-C-16032)","Xbox Controller","Xbox Controller",
		"Red Octane Ignition Xbox DDR Pad","Pelican Eclipse PL-2023","Xbox Controller","VibraX"};
		InsertProducts(0x0c12, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0003,0x0008,0x0080,0x0081};
		char* mids[] = {"RF Technology Receiver","RF Technology Receiver","RF Technology Receiver","eHome Infrared Receiver","eHome Infrared Receiver"
		};
		InsertProducts(0x0c16, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0005,0x000b,0x000c,0x000e,0x000f,0x0010,0x0012,0x0018,0x0019,0x0021,0x0c24,0xffff};
		char* mids[] = {"Bluetooth Adaptor","Bluetooth Device2","Bluetooth Device(BC04-External)","Bluetooth Device(BC04-External)","Bluetooth Adaptor",
		"Bluetooth Device(BC04-External)","Bluetooth Device (V2.0+EDR)","Bluetooth Device(BC04-External)","Bluetooth Device(BC04-External)","Bluetooth Device(BC04-External)",
		"Bluetooth Device","Bluetooth Device (V2.1+EDR)","Bluetooth Device(SAMPLE)","Bluetooth module with BlueCore in DFU mode"};
		InsertProducts(0x0c24, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0310};
		char* mids[] = {"Scream Cam"};
		InsertProducts(0x0c25, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0018};
		char* mids[] = {"USB-Serial Controller [Icom Inc. OPC-478UC]"};
		InsertProducts(0x0c26, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3bfa};
		char* mids[] = {"pcProx Card Reader"};
		InsertProducts(0x0c27, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0007,0x0200,0x0204,0x0206,0x0700,0x0720,0x0b61,0x0b6a};
		char* mids[] = {"Metrologic MS7120 Barcode Scanner (IBM SurePOS mode)","MS7120 Barcode Scanner","Metrologic MS7120 Barcode Scanner (keyboard mode)","Metrologic MS4980 Barcode Scanner","Metrologic MS7120 Barcode Scanner (uni-directional serial mode)",
		"Metrologic MS7120 Barcode Scanner (bi-directional serial mode)","Vuquest 3310g","Vuquest 3310 Area-Imaging Scanner"};
		InsertProducts(0x0c2e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0021,0x0022,0x03a2,0x41d9};
		char* mids[] = {"iDEN P2k0 Device","iDEN P2k1 Device","iDEN Smartphone","i1 phone"};
		InsertProducts(0x0c44, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0011,0x0520,0x1018,0x1020,0x1028,0x1030,0x1031,0x1032,0x1033,0x1034,0x1035,0x1036,0x1037,0x1050,0x1058,0x1060,0x1061,0x1062,0x1063,0x1064,
		0x1065,0x1066,0x1067,0x1158,0x184c,0x6001,0x6005,0x6007,0x6009,0x600d,0x6011,0x6019,0x6024,0x6025,0x6028,0x6029,0x602a,0x602b,0x602c,0x602d,
		0x602e,0x6030,0x603f,0x6040,0x606a,0x607a,0x607b,0x607c,0x607e,0x6080,0x6082,0x6083,0x608c,0x608e,0x608f,0x60a8,0x60aa,0x60ab,0x60af,0x60b0,
		0x60c0,0x60c8,0x60cc,0x60ec,0x60ef,0x60fa,0x60fb,0x60fc,0x60fe,0x6108,0x6122,0x6123,0x6128,0x612a,0x612c,0x612e,0x612f,0x6130,0x6138,0x613a,
		0x613b,0x613c,0x613e,0x6143,0x6240,0x6242,0x6243,0x6248,0x624b,0x624c,0x624e,0x624f,0x6251,0x6253,0x6260,0x6262,0x6270,0x627a,0x627b,0x627c,
		0x627f,0x6280,0x6282,0x6283,0x6288,0x628a,0x628b,0x628c,0x628e,0x628f,0x62a0,0x62a2,0x62b0,0x62b3,0x62ba,0x62bb,0x62bc,0x62be,0x62c0,0x62e0,
		0x6300,0x6310,0x6340,0x6341,0x63e0,0x63f1,0x63f8,0x6409,0x6413,0x6417,0x6419,0x641d,0x643f,0x644d,0x6480,0x648b,0x64bd,0x7401,0x7402,0x7403,
		0x8000,0x8006,0x800a};
		char* mids[] = {"EBUDDY","MaxTrack Wireless Mouse","Compact Flash storage memory card reader","Mass Storage Reader","Mass Storage Reader",
		"Mass Storage Reader","Sonix Mass Storage Device","Mass Storage Reader","Sonix Mass Storage Device","Mass Storage Reader",
		"Mass Storage Reader","Mass Storage Reader","Sonix Mass Storage Device","CF Card Reader","HDD Reader",
		"iFlash SM-Direct Card Reader","Mass Storage Reader","Mass Storage Reader","Sonix Mass Storage Device","Mass Storage Reader",
		"Mass Storage Reader","Mass Storage Reader","Mass Storage Reader","A56AK","VoIP Phone",
		"Genius VideoCAM NB","Sweex Mini Webcam","VideoCAM Eye","VideoCAM ExpressII","TwinkleCam USB camera",
		"PC Camera (SN9C102)","PC Camera (SN9C102)","VideoCAM ExpressII","VideoCAM ExpressII","Typhoon Easycam USB 330K (older)",
		"Triplex i-mini PC Camera","Meade ETX-105EC Camera","VideoCAM NB 300","Clas Ohlson TWC-30XOP Webcam","VideoCAM ExpressII",
		"VideoCAM Messenger","VideoCAM ExpressII","VideoCAM ExpressII","CCD PC Camera (PC390A)","CCD PC Camera (PC390A)",
		"CCD PC Camera (PC390A)","Win2 PC Camera","CCD PC Camera (PC390A)","CCD PC Camera (PC390A)","Audio (Microphone)",
		"VideoCAM Look","VideoCAM Look","VideoCAM Look","VideoCAM Look","PC Camera (SN9C103 + OV7630)",
		"VideoCAM Look","VideoCAM Look","PC Camera","VideoCAM Look","Genius VideoCam Look",
		"PC Camera with Mic (SN9C105)","Win2 PC Camera","PC Camera with Mic (SN9C105)","PC Camera with Mic (SN9C105)","Win2 PC Camera",
		"PC Camera with Mic (SN9C105)","Composite Device","PC Camera with Mic (SN9C105)","Audio (Microphone)","Win2 PC Camera",
		"PC Camera (SN9C110)","PC Camera (SN9C110)","PC Camera (SN9C325 + OM6802)","PC Camera (SN9C325)","PC Camera (SN9C110)",
		"PC Camera (SN9C110)","PC Camera (SN9C110)","PC Camera (SN9C120)","Win2 PC Camera","PC Camera (SN9C120)",
		"Win2 PC Camera","PC Camera (SN9C120)","PC Camera (SN9C120)","PC Camera (SN9C120 + SP80708)","PC Camera (SN9C201 + MI1300)",
		"PC Camera (SN9C201 + MI1310)","PC Camera (SN9C201 + S5K4AAFX)","PC Camera (SN9C201 + OV9655)","PC Camera (SN9C201 + CX1332)","PC Camera (SN9C201 + MI1320)",
		"PC Camera (SN9C201 + SOI968)","PC Camera (SN9C201 + OV9650)","PC Camera (SN9C201 + OV9650)","PC Camera (SN9C201 + OV9650)","PC Camera (SN9C201 + OV7670ISP)",
		"PC Camera (SN9C201 + OM6802)","PC Camera (SN9C201 + MI0360/MT9V011 or MI0360SOC/MT9V111) U-CAM PC Camera NE878, Whitcom WHC017, ...","PC Camera (SN9C201 + S5K53BEB)","PC Camera (SN9C201 + OV7660)","PC Camera (SN9C201 + HV7131R)",
		"PC Camera (SN9C201 + OV965x + EEPROM)","PC Camera with Microphone (SN9C202 + MI1300)","PC Camera with Microphone (SN9C202 + MI1310)","PC Camera with Microphone (SN9C202 + S5K4AAFX)","PC Camera with Microphone (SN9C202 + OV9655)",
		"PC Camera with Microphone (SN9C202 + ICM107)","PC Camera with Microphone (SN9C202 + CX1332)","PC Camera with Microphone (SN9C202 + MI1320)","PC Camera with Microphone (SN9C202 + SOI968)","PC Camera with Microphone (SN9C202 + OV9650)",
		"PC Camera with Microphone (SN9C202 + OV7670ISP)","PC Camera with Microphone (SN9C202 + OM6802)","PC Camera with Microphone (SN9C202 + MI0360/MT9V011 or MI0360SOC/MT9V111)","PC Camera with Microphone (SN9C202 + OV9655)","PC Camera with Microphone (SN9C202 + S5K53BEB)",
		"PC Camera with Microphone (SN9C202 + OV7660)","PC Camera with Microphone (SN9C202 + HV7131R)","PC Camera with Microphone (SN9C202 + OV7663)","Sonix USB 2.0 Camera","MSI Starcam Racer",
		"PC Microscope camera","Sonix USB 2.0 Camera","Camera","Defender G-Lens 2577 HD720p Camera","Sonix Integrated Webcam",
		"Integrated Webcam","Sonix Integrated Webcam","Webcam","Integrated Webcam","Integrated Webcam",
		"Integrated Webcam","1.3 MPixel Integrated Webcam","Dell Integrated HD Webcam","1.3 MPixel Integrated Webcam","Sonix 1.3 MP Laptop Integrated Webcam",
		"Integrated Webcam","Sony Visual Communication Camera","TEMPer Temperature Sensor","TEMPerHUM Temperature & Humidity Sensor","Foot Switch",
		"DC31VC","Dual Mode Camera (8006 VGA)","Vivitar Vivicam3350B"};
		InsertProducts(0x0c45, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0889,0x088a};
		char* mids[] = {"Timy","Timy 2"};
		InsertProducts(0x0c4a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0300,0x0501,0x9102};
		char* mids[] = {"cyberJack e-com/pinpad","cyberJack pinpad(a)","cyberJack RFID comfort dual interface smartcard reader","cyberJack RFID basis contactless smartcard reader"};
		InsertProducts(0x0c4b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0021};
		char* mids[] = {"EMP-21 Universal Programmer"};
		InsertProducts(0x0c4c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2101,0x2102,0x2103,0x2104,0x2211,0x2212,0x2213,0x2221,0x2222,0x2223,0x2411,0x2412,0x2413,0x2421,0x2422,0x2423,0x2431,0x2432,0x2433,0x2441,
		0x2442,0x2443,0x2811,0x2812,0x2813,0x2821,0x2822,0x2823,0x2831,0x2832,0x2833,0x2841,0x2842,0x2843,0x2851,0x2852,0x2853,0x2861,0x2862,0x2863,
		0x2871,0x2872,0x2873,0x2881,0x2882,0x2883,0x9020,0xa02a,0xa02b,0xa02c,0xa02d};
		char* mids[] = {"SeaLINK+232","SeaLINK+485","SeaLINK+232I","SeaLINK+485I","SeaPORT+2/232 (Port 1)",
		"SeaPORT+2/485 (Port 1)","SeaPORT+2 (Port 1)","SeaPORT+2/232 (Port 2)","SeaPORT+2/485 (Port 2)","SeaPORT+2 (Port 2)",
		"SeaPORT+4/232 (Port 1)","SeaPORT+4/485 (Port 1)","SeaPORT+4 (Port 1)","SeaPORT+4/232 (Port 2)","SeaPORT+4/485 (Port 2)",
		"SeaPORT+4 (Port 2)","SeaPORT+4/232 (Port 3)","SeaPORT+4/485 (Port 3)","SeaPORT+4 (Port 3)","SeaPORT+4/232 (Port 4)",
		"SeaPORT+4/485 (Port 4)","SeaPORT+4 (Port 4)","SeaLINK+8/232 (Port 1)","SeaLINK+8/485 (Port 1)","SeaLINK+8 (Port 1)",
		"SeaLINK+8/232 (Port 2)","SeaLINK+8/485 (Port 2)","SeaLINK+8 (Port 2)","SeaLINK+8/232 (Port 3)","SeaLINK+8/485 (Port 3)",
		"SeaLINK+8 (Port 3)","SeaLINK+8/232 (Port 4)","SeaLINK+8/485 (Port 4)","SeaLINK+8 (Port 4)","SeaLINK+8/232 (Port 5)",
		"SeaLINK+8/485 (Port 5)","SeaLINK+8 (Port 5)","SeaLINK+8/232 (Port 6)","SeaLINK+8/485 (Port 6)","SeaLINK+8 (Port 6)",
		"SeaLINK+8/232 (Port 7)","SeaLINK+8/485 (Port 7)","SeaLINK+8 (Port 7)","SeaLINK+8/232 (Port 8)","SeaLINK+8/485 (Port 8)",
		"SeaLINK+8 (Port 8)","SeaLINK+422","SeaLINK+8 (Port 1+2)","SeaLINK+8 (Port 3+4)","SeaLINK+8 (Port 5+6)",
		"SeaLINK+8 (Port 7+8)"};
		InsertProducts(0x0c52, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0510,0x0540,0x5416,0x6416};
		char* mids[] = {"Spectrum Digital XDS510 JTAG Debugger","SPI540","TMS320C5416 DSK","TMS320C6416 DDB"};
		InsertProducts(0x0c55, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005};
		char* mids[] = {"Color 320 x 240 LCD Display Terminal with Touchscreen"};
		InsertProducts(0x0c6a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x04b2};
		char* mids[] = {"Specbos 1201"};
		InsertProducts(0x0c6c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0747};
		char* mids[] = {"USB08 Development board","Eye Movement Recorder [Visagraph]/[ReadAlyzer]"};
		InsertProducts(0x0c70, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000c,0x000d};
		char* mids[] = {"PCAN-USB","PCAN Pro"};
		InsertProducts(0x0c72, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"OL 700-30 Goniometer"};
		InsertProducts(0x0c74, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x1600,0x1605,0x1607};
		char* mids[] = {"Mass Storage Controller","Mass Storage Controller","USBdisk","Mass Storage Controller","Transcend Flash disk",
		"Transcend JetFlash","Mass Storage Device","Ion Quick Play LP turntable","SSS Headphone Set","audio controller"
		};
		InsertProducts(0x0c76, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001,0x1002,0x1010,0x1011,0x1015};
		char* mids[] = {"SiPix Web2","SiPix SC2100","SiPix Snap","SiPix Blink 2","SiPix CAMeleon"
		};
		InsertProducts(0x0c77, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0021,0x17da};
		char* mids[] = {"Handheld","Qualcomm Kyocera CDMA Technologies MSM"};
		InsertProducts(0x0c88, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6000};
		char* mids[] = {"Luxian Series"};
		InsertProducts(0x0c8e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa000};
		char* mids[] = {"EPP 1217"};
		InsertProducts(0x0c94, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1140};
		char* mids[] = {"USB PC Watchdog"};
		InsertProducts(0x0c98, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0170};
		char* mids[] = {"3873 Manual Insert card reader"};
		InsertProducts(0x0c9d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010,0x0050,0x1077,0x107e,0x2010,0x3050};
		char* mids[] = {"EZUSB PC/SC Smart Card Reader","EZ220PU Reader Controller","Bludrive Family Smart Card Reader","Reader Controller","myPad110 PC/SC Smart Card Reader",
		"EZ710 Smart Card Reader"};
		InsertProducts(0x0ca6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x9001};
		char* mids[] = {"PowerPad Pocket PCÂ Device"};
		InsertProducts(0x0cad, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2507,0x2515,0x2516,0x2517,0x25c7,0x3a00,0x3a20,0x3acd};
		char* mids[] = {"Hi-Speed USB-to-IDE Bridge Controller","Flash Disk Embedded Hub","Flash Disk Security Device","Flash Disk Mass Storage Device","Hi-Speed USB-to-IDE Bridge Controller",
		"Hard Drive","Mass Storage Device","Mass Storage Device"};
		InsertProducts(0x0caf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0201,0x0301,0x0401};
		char* mids[] = {"Pocket PC P6C","Personal Digital Assistant","Personal Digital Assistant P6M+","Pocket PC"};
		InsertProducts(0x0cbc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0012,0x0013,0x0014,0x0015,0x0021,0x0023,0x0028,0x0032,0x0035,0x0036,0x0037,0x0038,0x0039,0x003b,0x003c,0x0042,0x0043,0x004e,0x004f,0x0055,
		0x005c,0x0069,0x006b,0x0072,0x0077,0x0078,0x0086,0x008e,0x0097,0x0099,0x00a5,0x00a9,0x00b3,0x00e0,0x10a7};
		char* mids[] = {"PHASE 26","PHASE 26","PHASE 26","Flash Update for TerraTec PHASE 26","Cameo Grabster 200",
		"Mystify Claw","Aureon 5.1 MkII","MIDI HUBBLE","Miditech Play'n Roll","Cinergy 250 Audio",
		"Cinergy 250 Audio","Cinergy TÂ² DVB-T Receiver","Grabster AV 400","Cinergy 400","Grabster AV 250",
		"Cinergy Hybrid T XS","Cinergy T XS","Cinergy T XS","Cinergy Analog XS","Cinergy T XE (Version 1, AF9005)",
		"Cinergy TÂ²","Cinergy T XE (Version 2, AF9015)","Cinergy HT PVR (EU)","Cinergy Hybrid T","Aureon Dual USB",
		"Cinergy T XXS","Cinergy Hybrid XE","Cinergy HTC XS","Cinergy T RC MKII","AfaTech 9015 [Cinergy T Stick Dual]",
		"Cinergy Hybrid Stick","RTL2838 DVB-T COFDM Demodulator [TerraTec Cinergy T Stick Black]","NOXON DAB/DAB+ Stick","NOXON DAB/DAB+ Stick V2","TerraTec G3"
		};
		InsertProducts(0x0ccd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"BeolinkPC2"};
		InsertProducts(0x0cd4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0009};
		char* mids[] = {"U3","UE9"};
		InsertProducts(0x0cd5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2007};
		char* mids[] = {"Smart Card Reader/JSTU-9700"};
		InsertProducts(0x0cd8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0008,0x0009,0x0011,0x0012,0x0013,0x0014,0x0015,0x0016,0x0018,0x001a,0x001c,0x0020,0x0022,0x0023,
		0x0025,0x0026,0x0027};
		char* mids[] = {"XI-750 802.11b Wireless Adapter [Atmel AT76C503A]","XI-725/726 Prism2.5 802.11b Adapter","Sagem 802.11b Dongle","Sagem 802.11b Dongle","XI-735 Prism3 802.11b Adapter",
		"XG-300 802.11b Adapter","XG-703A 802.11g Wireless Adapter [Intersil ISL3887]","(ZD1211)IEEE 802.11b+g Adapter","ZD1211","AR5523",
		"AR5523 driver (no firmware)","NB 802.11g Wireless LAN Adapter(3887A)","XG-705A 802.11g Wireless Adapter [Intersil ISL3887]","NB 802.11g Wireless LAN Adapter(3887A)","NB 802.11a/b/g Wireless LAN Adapter(3887A)",
		"802.11bg","802.11b/g Wireless Network Adapter","AG-760A 802.11abg Wireless Adapter [ZyDAS ZD1211B]","802.11b/g/n Wireless Network Adapter","UB81 802.11bgn",
		"802.11b/g/n USB Wireless Network Adapter","UB82 802.11abgn","Sphairon Homelink 1202 802.11n Wireless Adapter [Atheros AR9170]"};
		InsertProducts(0x0cde, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003};
		char* mids[] = {"Matrix"};
		InsertProducts(0x0ce5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001};
		char* mids[] = {"PicoScope3000 series PC Oscilloscope"};
		InsertProducts(0x0ce9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6220,0x6225,0x6250};
		char* mids[] = {"SD Card Reader (SG361)","SD card reader (UB6225)","SD card reader (UB6250)"};
		InsertProducts(0x0cf2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x1001,0x1002,0x1006,0x1010,0x20ff,0x3000,0x3002,0x3004,0x3005,0x3008,0x7015,0x9170,0x9271,0xb002,
		0xb003};
		char* mids[] = {"AR5523","AR5523 (no firmware)","AR5523","AR5523 (no firmware)","AR5523",
		"AR5523 (no firmware)","Thomson TG121N [Atheros AR9001U-(2)NG]","TP-Link TL-WN821N v2 / TL-WN822N v1 802.11n [Atheros AR9170]","TP-Link TL-WN322G v3 / TL-WN422G v2 802.11g [Atheros AR9271]","3Com 3CRUSBN275 802.11abgn Wireless Adapter [Atheros AR9170]",
		"AR7010 (no firmware)","AR3011 Bluetooth (no firmware)","AR3011 Bluetooth","AR3012 Bluetooth 4.0","AR3011 Bluetooth",
		"Bluetooth (AR3011)","TP-Link TL-WN821N v3 / TL-WN822N v2 802.11n [Atheros AR7010+AR9287]","AR9170 802.11n","AR9271 802.11n","Ubiquiti WiFiStation 802.11n [Atheros AR9271]",
		"Ubiquiti WiFiStationEXT 802.11n [Atheros AR9271]"};
		InsertProducts(0x0cf3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0750};
		char* mids[] = {"Claritel-i750 - vp"};
		InsertProducts(0x0cf8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2301,0x2350,0x3100,0x7300};
		char* mids[] = {"Magicolor 2300 DL","Magicolor 2350EN/3300","Magicolor 3100","Magicolor 5450/5550"};
		InsertProducts(0x0cfc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0320};
		char* mids[] = {"SR-380N"};
		InsertProducts(0x0cff, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0602,0x0603};
		char* mids[] = {"DV007 [serial]","DV007 [storage]"};
		InsertProducts(0x0d08, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"StormPort (WDM)"};
		InsertProducts(0x0d10, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0004,0x0100,0x0102,0x0103,0x0104,0x0105,0x0200};
		char* mids[] = {"PhotoShuttle","Photo Printer 730 series","Photo Printer 63xPL/PS","Photo Printer 63xPL/PS","Photo Printer 64xPS",
		"Photo Printer 730 series","Photo Printer 63xPL/PS","Photo Printer 64xPS","Photo Printer 64xDL"};
		InsertProducts(0x0d16, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0204};
		char* mids[] = {"LPC1768"};
		InsertProducts(0x0d28, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0206,0x0207,0x0500};
		char* mids[] = {"Series 3xxx Cash Drawer","Series 3xxx Cash Drawer","Magnetic Stripe Reader"};
		InsertProducts(0x0d3a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0040};
		char* mids[] = {"HID Keyboard","PS/2 Adapter"};
		InsertProducts(0x0d3d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2012,0x3003,0x4000,0x4001,0x4081};
		char* mids[] = {"KAAN Standard Plus (Smartcard reader)","mIDentity Light / KAAN SIM III","mIDentity (mass storage)","mIDentity Basic/Classic (composite device)","mIDentity Basic/Classic (installationless)"
		};
		InsertProducts(0x0d46, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0004,0x0100};
		char* mids[] = {"ACTIVboard","ACTIVboard","Audio"};
		InsertProducts(0x0d48, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3000,0x3010,0x3100,0x3200,0x5000,0x5010,0x5020,0x7000,0x7010,0x7100,0x7310,0x7410,0x7450};
		char* mids[] = {"Drive","3000LE Drive","Hi-Speed USB-IDE Bridge Controller","Personal Storage 3200","5000XT Drive",
		"5000LE Drive","Mobile Hard Disk Drive","OneTouch","OneTouch","OneTouch II 300GB External Hard Disk",
		"OneTouch 4","Mobile Hard Disk Drive (1TB)","Basics Portable USB Device"};
		InsertProducts(0x0d49, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x047a,0x1000,0x1001};
		char* mids[] = {"WLAN Card","Wireless Card Model 0801","Wireless Card Model 0802"};
		InsertProducts(0x0d4e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0011,0x0040};
		char* mids[] = {"USB-Temp2 Thermometer","F4 foot switch"};
		InsertProducts(0x0d50, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa001,0xa002};
		char* mids[] = {"SMC2662W (v1) EZ Connect 802.11b Wireless Adapter [Atmel AT76C503A]","SMC2662W v2 / SMC2662W-AR / Belkin F5D6050 [Atmel at76c503a]"};
		InsertProducts(0x0d5c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2346};
		char* mids[] = {"BT Digital Access adapter"};
		InsertProducts(0x0d5e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0004,0x001c,0x0306,0x0800,0x2021,0x2026,0x2050,0x2106,0xa100};
		char* mids[] = {"Smartcard Reader","Keyboard","Benq X120 Internet Keyboard Pro","M530 Mouse","Magic Wheel",
		"AM805 Keyboard","TECOM Bluetooth Device","Mouse","Dell L20U Multimedia Keyboard","Optical Mouse"
		};
		InsertProducts(0x0d62, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0105,0x0107,0x0108,0x0202,0x0303,0x1001,0x1002,0x1003,0x1021,0x1208,0x2208,0x3105,0x3108};
		char* mids[] = {"Dual Mode Digital Camera 1.3M","Horus MT-409 Camera","Dual Mode Digital Camera","Dual Mode Video Camera Device","DXG-305V Camera",
		"SiPix Stylecam/UMAX AstraPix 320s","Fashion Cam 01 Dual-Mode DSC (Video Camera)","Fashion Cam Dual-Mode DSC (Controller)","D-Link DSC 350F","Dual Mode Still Camera Device",
		"Mass Storage","Dual Mode Digital Camera Disk","Digicam Mass Storage Device"};
		InsertProducts(0x0d64, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"CrypToken"};
		InsertProducts(0x0d7a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0110,0x0120,0x0124,0x0240,0x110e,0x1240,0x1270,0x1300,0x1320,0x1400,0x1420,0x1470,0x1620,0x1900};
		char* mids[] = {"PS1001/1011/1006/1026 Flash Disk","Gigabyte FlexDrive","Disk Pro 64MB","GIGABYTE Disk","I/O-Magic/Transcend 6-in-1 Card Reader",
		"NEC uPD720121/130 USB-ATA/ATAPI Bridge","Apacer 6-in-1 Card Reader 2.0","Wolverine SixPac 6000","Flash Disk","PS2031 Flash Disk",
		"Attache 256MB USB 2.0 Flash Drive","PS2044 Pen Drive","Vosonic X's-Drive II+ VP2160","USB Disk Pro","USB Thumb Drive"
		};
		InsertProducts(0x0d7d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2507,0x2517,0x25c7};
		char* mids[] = {"Hi-Speed USB-to-IDE Bridge Controller","Hi-Speed Mass Storage Device","Hi-Speed USB-to-IDE Bridge Controller"};
		InsertProducts(0x0d7e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100};
		char* mids[] = {"P5 Glove glove controller"};
		InsertProducts(0x0d7f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"TEPRA PRO"};
		InsertProducts(0x0d8a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0006,0x000c,0x000d,0x000e,0x001f,0x0102,0x0103,0x0104,0x0105,0x0107,0x010f,0x0115,0x013c,0x0201,0x5000,0x5200,0xb213
		};
		char* mids[] = {"Audio Device","Composite Device","Sound Device","Storm HP-USB500 5.1 Headset","Audio Adapter",
		"Composite Device","Audio Adapter (Planet UP-100, Genius G-Talk)","CM108 Audio Controller","CM106 Like Sound Device","CM102-A+/102S+ Audio Controller",
		"CM103+ Audio Controller","CM108 Audio Controller","CM108 Audio Controller","CM108 Audio Controller","CM108 Audio Controller",
		"CM108 Audio Controller","CM6501","Mass Storage Controller","Mass Storage Controller(0D8C,5200)","USB Phone CM109 (aka CT2000,VPT1000)"
		};
		InsertProducts(0x0d8c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0234,0x0550,0x0551,0x0552,0x0651,0x0652,0x0653,0x0654,0x0655,0x0656,0x0657,0x0658,0x0659,0x0660,0x0661,0x0662,0x0850,0x0851,0x0852,0x0901,
		0x0902,0x0903,0x4754,0xbb00,0xbb01,0xbb02,0xbb03,0xbb04,0xbb05,0xfffe,0xffff};
		char* mids[] = {"V-234 Composite Device","V-550 Composite Device","V-551 Composite Device","V-552 Composite Device","V-651 Composite Device",
		"V-652 Composite Device","V-653 Composite Device","V-654 Composite Device","V-655 Composite Device","V-656 Composite Device",
		"V-657 Composite Device","V-658 Composite Device","V-659 Composite Device","V-660 Composite Device","V-661 Composite Device",
		"V-662 Composite Device","V-850 Composite Device","V-851 Composite Device","V-852 Composite Device","V-901 Composite Device",
		"V-902 Composite Device","V-903 Composite Device","Voyager DMP Composite Device","Bloomberg Composite Device","Bloomberg Composite Device",
		"Bloomberg Composite Device","Bloomberg Composite Device","Bloomberg Composite Device","Bloomberg Composite Device","Global Tuner Composite Device",
		"Voyager DMP Composite Device"};
		InsertProducts(0x0d8d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0163,0x1621,0x3762,0x3763,0x7100,0x7110,0x7605,0x7801,0x7802,0x7811,0x7812,0x7a01};
		char* mids[] = {"802.11g 54 Mbps Wireless Dongle","802.11b Wireless Adapter","Cohiba 802.11g Wireless Mini adapter [Intersil ISL3887]","802.11g Wireless dongle","802.11b Adapter",
		"WL-210 / WU210P 802.11b Wireless Adapter [Atmel AT76C503A]","TRENDnet TEW-224UB 802.11b Wireless Adapter [Atmel AT76C503A]","AR5523","AR5523 (no firmware)","AR5523",
		"AR5523 (no firmware)","PRISM25 802.11b Adapter"};
		InsertProducts(0x0d8e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x3300,0x4100,0x4102,0x4104,0x410a,0x5200};
		char* mids[] = {"Jenoptik JD350 video","SX330z Camera","SX410z Camera","MD 9700 Camera","Jenoptik JD-4100z3s",
		"Medion 9801/Novatech SX-410z","SX-520z Camera"};
		InsertProducts(0x0d96, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0101};
		char* mids[] = {"SBIG Astronomy Camera (without firmware)","SBIG Astronomy Camera (with firmware)"};
		InsertProducts(0x0d97, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0300,0x1007};
		char* mids[] = {"Avaya Wireless Card","Discovery Kids Digital Camera"};
		InsertProducts(0x0d98, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Bluetooth Device"};
		InsertProducts(0x0d9a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0300};
		char* mids[] = {"Wireless Card"};
		InsertProducts(0x0d9e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x00a2,0x00a3,0x00a4,0x00a5,0x00a6};
		char* mids[] = {"Uninterruptible Power Supply","Black Knight PRO / WOW Uninterruptible Power Supply (Cypress HID->COM RS232)","Imperial Uninterruptible Power Supply (HID PDC)","Smart King PRO Uninterruptible Power Supply (HID PDC)","WOW Uninterruptible Power Supply (HID PDC)",
		"Vanguard Uninterruptible Power Supply (HID PDC)","Black Knight PRO Uninterruptible Power Supply (HID PDC)"};
		InsertProducts(0x0d9f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Interface"};
		InsertProducts(0x0da4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"SDS 200A Oscilloscope"};
		InsertProducts(0x0da8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100};
		char* mids[] = {"DVR/CVR-M140 MP3 Player"};
		InsertProducts(0x0dab, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1020,0x1967,0x3801,0x4011,0x4023,0x4600,0x5501,0x5502,0x5513,0x5515,0x5516,0x5580,0x5581,0x6823,0x6826,0x6855,0x6861,0x6865,0x6869,0x6874,
		0x6877,0x6881,0x688a,0x6899,0x6970,0x697a,0x6982,0xa861,0xa874,0xa970,0xa97a,0xb970,0xb97a};
		char* mids[] = {"PC2PC WLAN Card","Bluetooth Dongle","Motorola Bluetooth 2.1+EDR Device","Medion Flash XL V2.0 Card Reader","Lexar Mobile Card Reader",
		"802.11b/g Turbo Wireless Adapter","Mass Storage Device","Mass Storage Device","MP3 Player","MP3 Player",
		"MP3 Player","Mega Sky 580 DVB-T Tuner [M902x]","Mega Sky 580 DVB-T Tuner [GL861]","UB11B/MS-6823 802.11b Wi-Fi adapter","IEEE 802.11g Wireless Network Adapter",
		"Bluetooth Device","MSI-6861 802.11g WiFi adapter","RT2570","RT2570","RT2573",
		"RT2573","Bluetooth Class I EDR Device","Bluetooth Class I EDR Device","802.11bgn 1T1R Mini Card Wireless Adapter","MS-6970 BToes Bluetooth adapter",
		"Bluetooth Dongle","Medion Flash XL Card Reader","RT2573","RT2573","Bluetooth dongle",
		"Bluetooth EDR Device","Bluetooth EDR Device","Bluetooth EDR Device"};
		InsertProducts(0x0db0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"Goldpfeil P-LAN"};
		InsertProducts(0x0db7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3000};
		char* mids[] = {"Mbox 2"};
		InsertProducts(0x0dba, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003};
		char* mids[] = {"AND Serial Cable [AND Smart Cable]"};
		InsertProducts(0x0dbc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0200,0x021b,0x0300,0x0333,0x0707};
		char* mids[] = {"SmartDongle Security Key","HDD Storage Solution","USB-2.0 IDE Adapter","Storage Adapter","Storage Adapter",
		"ZIV Drive"};
		InsertProducts(0x0dbf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0801,0x0802,0x1104,0x1701,0x1702};
		char* mids[] = {"ASEDrive III","ASEDrive IIIe","ASEDrive IIIe KB","ASEKey","ASEKey"
		};
		InsertProducts(0x0dc3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0040,0x0041,0x0042,0x0101,0x020a};
		char* mids[] = {"Mass Storage Device","Mass Storage Device","Mass Storage Device","Hi-Speed Mass Storage Device","Oyen Digital MiniPro 2.5\" hard drive enclosure"
		};
		InsertProducts(0x0dc4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2301};
		char* mids[] = {"Wireless Touchpad Keyboard"};
		InsertProducts(0x0dc6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"Remote Interface Adapter","High Bandwidth Codec"};
		InsertProducts(0x0dcd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1002};
		char* mids[] = {"Triple Talk Speech Synthesizer"};
		InsertProducts(0x0dd0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003};
		char* mids[] = {"Mass Storage (P)"};
		InsertProducts(0x0dd2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1060,0xe007,0xf607};
		char* mids[] = {"USB-CF-Card","OnlyDisk U222 Pendrive","OnlyDisk U208 1G flash drive [U-SAFE]"};
		InsertProducts(0x0dd8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0005,0x0008,0x0009,0x000a,0x000b,0x0101,0x0102,0x0301,0x0302,0x1001,0x2001,0x2002,0x2003,0x2005,0x2006,0x2007,0x2008,
		0x2013,0x2014,0x2023,0x2024,0x2026,0x2027,0x2315,0x2318,0x2321};
		char* mids[] = {"Multi-Card Reader 6in1","Multi-Card Reader 7in1","Flash Disk","Internal Multi-Card Reader 6in1","SD single card reader",
		"MS single card reader","MS+SD Dual Card Reader","SM single card reader","All-In-One Card Reader","All-In-One Card Reader",
		"MP3 Player","Multi-Card MP3 Player","Multi-Flash Disk","Multi-Card Reader","Q018 default PID",
		"Multi-Card Reader","Datalux DLX-1611 16in1 Card Reader","All-In-One Card Reader","USB to ATAPI bridge","All-In-One Card Reader",
		"SD/MS Combo Card Reader","SD/MS Single Card Reader","card reader SD/MS DEMO board with ICSI brand name (MaskROM version)","card reader SD/MS DEMO board with Generic brand name (MaskROM version)","USB2.0 Card Reader",
		"USB 2.0 Card Reader","UFD MP3 player (model 2)","UFD MP3 player (model 1)","UFD MP3 player"};
		InsertProducts(0x0dda, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0191,0x01a5,0x01c3};
		char* mids[] = {"U401 Interface card","U421 interface card","U451 relay interface card"};
		InsertProducts(0x0de7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4010};
		char* mids[] = {"Storage Adapter"};
		InsertProducts(0x0dee, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0201};
		char* mids[] = {"MNG-2005"};
		InsertProducts(0x0df4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0004,0x0007,0x000b,0x000d,0x0017,0x0019,0x001a,0x002b,0x002c,0x002d,0x0036,0x0039,0x003b,0x003c,0x003d,0x003e,0x003f,0x0040,0x0041,
		0x0042,0x0045,0x0047,0x0048,0x0049,0x004a,0x004b,0x004c,0x0050,0x0056,0x005d,0x0060,0x0062,0x0072,0x061c,0x21f4,0x2200,0x2208,0x2209,0x9071,
		0x9075,0x90ac,0x9712};
		char* mids[] = {"C-Media VOIP Device","Bluetooth 2.0 Adapter 100m","Bluetooth 2.0 Adapter 10m","Bluetooth 2.0 Adapter DFU","WL-168 Wireless Network Adapter 54g",
		"WL-182 Wireless-N Network USB Card","Bluetooth 2.0 adapter 10m CN-512v2 001","Bluetooth 2.0 adapter 100m CN-521v2 001 ","WL-188 Wireless Network 300N USB Adapter","WL-301 Wireless Network 300N USB Adapter",
		"WL-302 Wireless Network 300N USB dongle ","WL-603 Wireless Adapter","WL-315 Wireless-N USB Adapter","WL-321 Wireless USB Gaming Adapter 300N","WL-323 Wireless-N USB Adapter",
		"WL-324 Wireless USB Adapter 300N","WL-343 Wireless USB Adapter 150N X1","WL-608 Wireless USB Adapter 54g","WL-344 Wireless Adapter 300N X2 [Ralink RT3071]","WL-329 Wireless Dualband USB adapter 300N",
		"WL-345 Wireless USB adapter 300N X3","WL-353 Wireless USB Adapter 150N Nano","WL-352v1 Wireless USB Adapter 300N 002","WL-349v1 Wireless Adapter 150N 002 [Ralink RT3070]","WL-356 Wireless Adapter 300N",
		"WL-358v1 Wireless Micro USB Adapter 300N X3 002","WL-349v3 Wireless Micro Adapter 150N X1 [Realtek RTL8192SU]","WL-352 802.11n Adapter [Realtek RTL8191SU]","WL-349v4 Wireless Micro Adapter 150N X1 [Ralink RT3370]","LN-031 10/100/1000 Ethernet Adapter",
		"WLA-2000 v1.001 WLAN [RTL8191SU]","WLA-4000 802.11bgn [Ralink RT3072]","WLA-5000 802.11abgn [Ralink RT3572]","AX88179 Gigabit Ethernet [Sitecom]","LN-028 Network USB 2.0 Adapter",
		"44 St Bluetooth Device","Sitecom bluetooth2.0 class 2 dongle CN-512","Sitecom bluetooth2.0 class 2 dongle CN-520","Sitecom bluetooth2.0 class 1 dongle CN-521","WL-113 rev 1 Wireless Network USB Adapter",
		"WL-117 Hi-Speed USB Adapter","WL-172 Wireless Network USB Adapter 54g Turbo","WL-113 rev 2 Wireless Network USB Adapter"};
		InsertProducts(0x0df6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0620,0x0700,0x0720,0x0722,0x0730,0x0800,0x0820,0x0900,0x1800,0x1802};
		char* mids[] = {"MA-620 Infrared Adapter","MA-700 Bluetooth Adapter","MA-720 Bluetooth Adapter","Bluetooth Dongle","MA-730/MA-730G Bluetooth Adapter",
		"Data Cable","Data Cable","MA i-gotU Travel Logger GPS","Generic Card Reader","Card Reader"
		};
		InsertProducts(0x0df7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Touchscreen"};
		InsertProducts(0x0dfc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x9031,0x9041};
		char* mids[] = {"802.11n Wireless USB Card","802.11n Wireless USB Card"};
		InsertProducts(0x0e0b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"LonUSB LonTalk Network Adapter"};
		InsertProducts(0x0e0c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0xf80a};
		char* mids[] = {"Device","Virtual USB Hub","Virtual Mouse","Virtual CCID","Virtual Mass Storage",
		"Virtual Keyboard","Smoker FX2"};
		InsertProducts(0x0e0f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"NoteTaker"};
		InsertProducts(0x0e20, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0300,0x0400,0x0500,0x0510,0x0513,0x0520,0x0601,0x0681,0x0700,0x0751,0x0760,0x0800,0x0801,0x0910,0x0920};
		char* mids[] = {"iAudio CW200","MP3 Player","iAudio M3","iAudio X5, subpack USB port","iAudio X5, side USB port",
		"iAudio M5, side USB port","iAudio G3","iAUDIO E2","iAudio U3","iAudio 7",
		"iAUDIO U5 / iAUDIO G2","Cowon D2 (UMS mode)","Cowon D2 (MTP mode)","iAUDIO 9","J3"
		};
		InsertProducts(0x0e21, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0008,0x0009,0x000a,0x000b,0x000e,0x000f,0x0010,0x0011,0x0012,0x0013,0x0014,0x0018,0x001b,0x0042,0x00fd,0x00fe};
		char* mids[] = {"Handyscope HS3","Handyscope HS3 (br)","Handyscope HS4","Handyscope HS4 (br)","Handyscope HS4-DIFF",
		"Handyscope HS4-DIFF (br)","Handyscope HS2","TiePieSCOPE HS805 (br)","TiePieSCOPE HS805","Handyprobe HP3",
		"Handyprobe HP3","Handyprobe HP2","Handyscope HS5","TiePieSCOPE HS801","USB To Parallel adapter",
		"USB To Parallel adapter"};
		InsertProducts(0x0e36, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0137};
		char* mids[] = {"Bluetooth Device"};
		InsertProducts(0x0e39, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1100};
		char* mids[] = {"CW-1100 Wireless Network Adapter"};
		InsertProducts(0x0e3a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4147,0x414d,0x4156,0x4250,0x4252,0x4642,0x4650,0x4750,0x5044,0x5050,0x534d};
		char* mids[] = {"TonePort GX","Pod HD500","POD HD Desktop","BassPODxt","BassPODxt Pro",
		"BassPODxt Live","PODxt Live","GuitarPort","PODxt","PODxt Pro",
		"SeaMonkey"};
		InsertProducts(0x0e41, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100};
		char* mids[] = {"CardPro SmartCard Reader"};
		InsertProducts(0x0e48, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1097,0x2390,0x7288};
		char* mids[] = {"Gamester Controller","Games Jtech Controller","funkey reader"};
		InsertProducts(0x0e4c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"Matrixlock Dongle (HID)"};
		InsertProducts(0x0e50, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x110a,0x110b};
		char* mids[] = {"Tanic S110-SG1 + ISSC IS1002N [Slow Infra-Red (SIR) & Bluetooth 1.2 (Class 2) Adapter]","MS3303H USB-to-Serial Bridge"};
		InsertProducts(0x0e55, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6021};
		char* mids[] = {"K-PEX 100"};
		InsertProducts(0x0e56, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6118,0x6119,0x6441};
		char* mids[] = {"LCD Device","remote receive and control device","C-Media Sound Device"};
		InsertProducts(0x0e5c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6622};
		char* mids[] = {"CW6622"};
		InsertProducts(0x0e5e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0003,0x0009,0x000b,0x0013,0x0015,0x0017,0x0018,0x400b,0x400c};
		char* mids[] = {"HWUN1 Hi-Gain Wireless-300N Adapter w/ Upgradable Antenna [Ralink RT2870]","HWDN1 Hi-Gain Wireless-300N Dish Adapter [Ralink RT2870]","HWUN2 Hi-Gain Wireless-150N Adapter w/ Upgradable Antenna [Ralink RT2770]","HWDN2 Hi-Gain Wireless-150N Dish Adapter [Ralink RT2770]","HWUN3 Hi-Gain Wireless-N Adapter [Ralink RT3070]",
		"HWDN2 Rev. E Hi-Gain Wireless-150N Dish Adapter [Realtek RTL8191SU]","HAWNU1 Hi-Gain Wireless-150N Network Adapter with Range Amplifier [Ralink RT3070]","Wireless-N Network Adapter [Ralink RT2870]","UF100 10/100 Network Adapter","UF100 Ethernet [pegasus2]"
		};
		InsertProducts(0x0e66, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"Wrist PDA"};
		InsertProducts(0x0e67, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x6001};
		char* mids[] = {"MA100 [USB-UART Bridge IC]","GEMBIRD Flexible keyboard KB-109F-B-DE"};
		InsertProducts(0x0e6a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0005,0x0006};
		char* mids[] = {"Freebird wireless Controller","Eclipse wireless Controller","Edge wireless Controller"};
		InsertProducts(0x0e6f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1106,0x1204,0x1306,0x1330,0x1332,0x1416,0x1417,0x14ad,0x150e,0x3001};
		char* mids[] = {"Pocket Media Assistant - PMA400","Gmini XS 200","504 Portable Multimedia Player","5 Tablet","5 IMT",
		"32 IT","A43 IT","97 Titanium HD","80 G9","40 Titanium"
		};
		InsertProducts(0x0e79, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x1001};
		char* mids[] = {"Yopy 3000 PDA","YP3X00 PDA"};
		InsertProducts(0x0e7e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0004,0x0023,0x1806,0x1836,0x2000,0x3329,0x763e};
		char* mids[] = {"MT6227 phone","MT6227 phone","S103","Samsung SE-208AB Slim Portable DVD Writer","Samsung SE-S084 Super WriteMaster Slim External DVD writer",
		"MT65xx Preloader","Qstarz BT-Q1000XT","MT7630e Bluetooth Adapter"};
		InsertProducts(0x0e8d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0012,0x0016,0x0020,0x0021,0x0201};
		char* mids[] = {"MaxFire Blaze2","Joystick/Gamepad","4 port USB 1.1 hub UH-174","USB to PS/2 Adapter","Multimedia Keyboard Controller",
		"SmartJoy Frag Xpad/PS2 adaptor"};
		InsertProducts(0x0e8f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100};
		char* mids[] = {"Storage Adapter V1"};
		InsertProducts(0x0e90, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xc001};
		char* mids[] = {"TRUST 380 USB2 SPACEC@M"};
		InsertProducts(0x0e96, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0908};
		char* mids[] = {"Composite HID (Keyboard and Mouse)"};
		InsertProducts(0x0e97, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000};
		char* mids[] = {"Streamzap Remote Control"};
		InsertProducts(0x0e9c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2126,0x2153,0x2168,0x6803,0x6808,0x6828,0x6858};
		char* mids[] = {"7-in-1 Card Reader","SD Card Reader Key","Transcend JetFlash 2.0 / Astone USB Drive","OTI-6803 Flash Disk","OTI-6808 Flash Disk",
		"OTI-6828 Flash Disk","OTi-6858 serial adapter"};
		InsertProducts(0x0ea0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x9020,0x9021};
		char* mids[] = {"NovaTech NV-902W","RT2573"};
		InsertProducts(0x0eb0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6666,0x6668,0x7007};
		char* mids[] = {"WinFast WalkieTV TV Loader","WinFast WalkieTV TV Loader","WinFast WalkieTV WDM Capture"};
		InsertProducts(0x0eb1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2200,0xf000};
		char* mids[] = {"Ariva Scale","PS60 Scale"};
		InsertProducts(0x0eb8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"FT-IR Spectrometer"};
		InsertProducts(0x0ebb, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1008};
		char* mids[] = {"So., Show 301 Digital Camera"};
		InsertProducts(0x0ec7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1400,0xa100};
		char* mids[] = {"CD\\RW 40X","LDW-411SX DVD/CD Rewritable Drive"};
		InsertProducts(0x0ecd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6660,0x6680,0x7634};
		char* mids[] = {"Flash Disk 64M-C","Flash Disk 64M-B","MP3 Player"};
		InsertProducts(0x0ed1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xe000,0xf000,0xf201};
		char* mids[] = {"USB-inSync Device","Fiberbyte USB-inSync Device","Fiberbyte USB-inSync DAQ-2500X"};
		InsertProducts(0x0ed5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2060};
		char* mids[] = {"FID irock! 100 Series"};
		InsertProducts(0x0edf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000};
		char* mids[] = {"Image Tank 1.5"};
		InsertProducts(0x0ee3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8810};
		char* mids[] = {"Mass Storage Drive"};
		InsertProducts(0x0eee, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x7200,0xa802};
		char* mids[] = {"eGalax TouchScreen","Touchscreen Controller(Professional)","Touchscreen Controller","eGalaxTouch EXC7920"};
		InsertProducts(0x0eef, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2202,0x2366};
		char* mids[] = {"Flash Disk","Flash Disk"};
		InsertProducts(0x0ef5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Alpha 1200Sx"};
		InsertProducts(0x0f03, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0011};
		char* mids[] = {"Real Arcade Pro 3"};
		InsertProducts(0x0f0d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x1010,0x1020,0x1080,0x1081,0x1090,0x1100,0x1101,0x1200,0x2000,0x2010,0x2020,0x2030,0x2040};
		char* mids[] = {"CASSY-S","Pocket-CASSY","Mobile-CASSY","Joule and Wattmeter","Digital Multimeter P",
		"UMI P","X-Ray Apparatus","X-Ray Apparatus","VideoCom","COM3LAB",
		"Terminal Adapter","Network Analyser","Converter Control Unit","Machine Test System"};
		InsertProducts(0x0f11, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0012};
		char* mids[] = {"Vital'Act 3S"};
		InsertProducts(0x0f14, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0006,0x0007,0x000a,0x000b,0x000c,0x000d};
		char* mids[] = {"CCD","Focuser","Filter Wheel","ProLine CCD","Color Filter Wheel 4",
		"PDF2","Guider"};
		InsertProducts(0x0f18, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x001c,0x0110,0x0111,0x0208};
		char* mids[] = {"PS3 Guitar Controller Dongle","Dual Analog Rumble Pad","Colour Rumble Pad","Xbox & PC Gamepad"};
		InsertProducts(0x0f30, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0876};
		char* mids[] = {"Keyboard [87 Francium Pro]"};
		InsertProducts(0x0f39, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0112};
		char* mids[] = {"CDMA 1xEVDO PC Card, PC 5220"};
		InsertProducts(0x0f3d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xef11,0xef12,0xff11,0xff12};
		char* mids[] = {"Patriot (firmware not loaded)","Patriot","Liberty (firmware not loaded)","Liberty"};
		InsertProducts(0x0f44, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000};
		char* mids[] = {"Bluetooth Dongle"};
		InsertProducts(0x0f4d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"MP6 Stage Piano"};
		InsertProducts(0x0f54, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x9455};
		char* mids[] = {"Compact Drive"};
		InsertProducts(0x0f5d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001};
		char* mids[] = {"Targus Mini Trackball Optical Mouse"};
		InsertProducts(0x0f62, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010,0x0022,0x0500,0x0600,0x0700,0x0800,0x0900,0x0a00,0x0b00,0x0c00,0x0d00,0x0e00,0x0f00,0x1000,0x1100,0x1111,0x1300};
		char* mids[] = {"Leapster Explorer","Leap Reader","Fly Fusion","Leap Port Turbo","POGO",
		"Didj","TAGSchool","Leapster 2","Crammer","Tag Jr",
		"My Pal Scout","Tag32","Tag64","Kiwi16","Leapster L2x",
		"Fly Fusion","Didj UK/France (Leapster Advance)"};
		InsertProducts(0x0f63, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0201,0x0202,0x0300,0x0400,0x0401,0x0402,0x0403,0x0404};
		char* mids[] = {"GameBoy Color Emulator","GameBoy Advance Flash Gang Writer","GameBoy Advance Capture","Gamecube DOL Viewer","NDS Emulator",
		"NDS UIC","NDS Writer","NDS Capture","NDS Emulator (Lite)"};
		InsertProducts(0x0f6e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3012,0x3014};
		char* mids[] = {"RT2570","ZD1211B"};
		InsertProducts(0x0f88, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0301,0x0332};
		char* mids[] = {"M-Any Premium DAH-610 MP3/WMA Player","mobiBLU DAH-1200 MP3/Ogg Player"};
		InsertProducts(0x0f9c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3fc3,0x3fc4};
		char* mids[] = {"Firefly X10i I/O Board (with firmware)","Firefly X10i I/O Board (without firmware)"};
		InsertProducts(0x0fb6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"eHome Infrared Receiver"};
		InsertProducts(0x0fb8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1222};
		char* mids[] = {"I/O Development Board"};
		InsertProducts(0x0fc5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0004,0x0006,0x0008,0x8001,0x8004,0x8007,0x8010,0x8011,0x8020};
		char* mids[] = {"Blackberry Handheld","Blackberry Handheld","Blackberry Pearl","Blackberry Pearl","Blackberry Handheld",
		"Blackberry","Blackberry Handheld","Blackberry Playbook (Connect to Windows mode)","Blackberry Playbook (Connect to Mac mode)","Blackberry Playbook (CD-Rom mode)"
		};
		InsertProducts(0x0fca, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0076,0x00af,0x00d4,0x00d9,0x0112,0x015a,0x0166,0x0167,0x0169,0x0172,0x0177,0x0dde,0x1010,0x10af,0x10d4,0x2105,0x2137,0x2138,0x2149,0x3137,
		0x3138,0x3149,0x514f,0x5169,0x5177,0x518c,0x614f,0x6166,0x618c,0x715a,0x7166,0x7177,0x8004,0xadde,0xd008,0xd016,0xd017,0xd019,0xd025,0xd028,
		0xd038,0xd039,0xd041,0xd042,0xd043,0xd046,0xd065,0xd076,0xd089,0xd0a1,0xd0af,0xd0cf,0xd0d4,0xd0e1,0xd12e,0xe000,0xe039,0xe042,0xe043,0xe075,
		0xe076,0xe089,0xe090,0xe0a1,0xe0a3,0xe0af,0xe0d4,0xe0ef,0xe0f3,0xe105,0xe112,0xe12e,0xe133,0xe14f,0xe15a,0xe161,0xe166,0xe167,0xf0fa};
		char* mids[] = {"W910i (Multimedia mode)","V640i Phone [PTP Camera]","C902 [MTP]","C702 Phone","W995 Walkman Phone",
		"Xperia Pro [Media Transfer Protocol]","Xperia Mini Pro","ST15i (Xperia mini)","Xperia S","Xperia P",
		"Xperia Ion [Mass Storage]","Xperia Mini Pro Bootloader","WMC Modem","V640i Phone [PictBridge]","C902 Phone [PictBridge]",
		"W715 Phone","Xperia X10 mini (USB debug)","Xperia X10 mini pro (Debug)","Xperia X8 (debug)","Xperia X10 mini",
		"Xperia X10 mini pro","Xperia X8","Xperia arc S [Adb-Enable Mode]","Xperia S [Adb-Enable Mode]","Xperia Ion [Debug Mode]",
		"C1605 [Xperia E dual] MTD mode","Xperia X12 (debug mode)","Xperia Mini Pro","C1605 [Xperia E dual] MSC mode","Xperia Pro [Tethering]",
		"Xperia Mini Pro (Tethering mode)","Xperia Ion [Tethering]","9000 Phone [Mass Storage]","Boot loader","V800-Vodafone 802SE Phone",
		"K750i Phone","K608i Phone","VDC EGPRS Modem","520 WMC Data Modem","W800i",
		"W850i Phone","K800i (phone mode)","K510i Phone","W810i Phone","V630i Phone",
		"K610i Phone","W960i Phone (PC Suite)","W910i (Phone mode)","W580i Phone (mass storage)","K810",
		"V640i Phone","MD300 Mobile Broadband Modem","C902 Phone [Modem]","MD400 Mobile Broadband Modem","Xperia X10",
		"K810 (PictBridge mode)","K800i (msc mode)","W810i Phone","V630i Phone [Mass Storage]","K850i",
		"W910i (Mass storage)","W580i Phone","W200 Phone (Mass Storage)","K810 (Mass Storage mode)","W660i",
		"V640i Phone [Mass Storage]","C902 Phone [Mass Storage] ","C905 Phone [Mass Storage]","W595","W705",
		"W995 Phone (Mass Storage)","X10i Phone","Vivaz","Xperia Arc/X12","Xperia Pro [Mass Storage Class]",
		"Xperia Ray","Xperia Mini Pro","XPERIA mini","Liveview micro display MN800 in DFU mode"};
		InsertProducts(0x0fce, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1003,0x1004,0x1006,0x1008,0x1009};
		char* mids[] = {"ANT Development Board","ANTUSB Stick","ANT Development Board","ANTUSB2 Stick","ANTUSB-m Stick"
		};
		InsertProducts(0x0fcf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"RDS 6000"};
		InsertProducts(0x0fd2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0011,0x0018,0x0020,0x0021,0x002a,0x002c,0x0033,0x0037};
		char* mids[] = {"EyeTV Diversity","EyeTV Hybrid","EyeTV DTT Deluxe","EyeTV DTT","EyeTV Sat",
		"EyeTV DTT Deluxe v2","Video Capture","Video Capture v2"};
		InsertProducts(0x0fd9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100};
		char* mids[] = {"quanton flight control"};
		InsertProducts(0x0fda, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xca01};
		char* mids[] = {"WMRS200 weather station"};
		InsertProducts(0x0fde, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0101,0x0200};
		char* mids[] = {"Bluetooth Mouse","Bluetooth IMU","Bluetooth Keypad"};
		InsertProducts(0x0fe0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8101,0x811e,0x9700};
		char* mids[] = {"DM9601 Fast Ethernet Adapter","Parallel Adapter","DM9601 Fast Ethernet Adapter"};
		InsertProducts(0x0fe6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4020,0xdb00,0xdb01,0xdb10,0xdb11,0xdb78};
		char* mids[] = {"TViX M-6500","FusionHDTV DVB-T (MT352+LgZ201) (uninitialized)","FusionHDTV DVB-T (MT352+LgZ201) (initialized)","FusionHDTV DVB-T (MT352+Thomson7579) (uninitialized)","FusionHDTV DVB-T (MT352+Thomson7579) (initialized)",
		"FusionHDTV DVB-T Dual Digital 4 (ZL10353+xc2028/xc3028) (initialized)"};
		InsertProducts(0x0fe9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0021};
		char* mids[] = {"Nord Stage 2"};
		InsertProducts(0x0ffc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xff00};
		char* mids[] = {"OEM"};
		InsertProducts(0x0ffd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x153b};
		char* mids[] = {"TerraTec Electronic GmbH"};
		InsertProducts(0x1000, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0100};
		char* mids[] = {"SD14","SD9/SD10"};
		InsertProducts(0x1003, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1fae,0x6000,0x6005,0x6018,0x618e,0x618f,0x61c5,0x61c6,0x61cc,0x61f1,0x61f9,0x61fc,0x61fe,0x6300,0x631c,0x631d,0x631e,0x631f,0x6356,0x6800,
		0x7000,0x91c8,0xa400};
		char* mids[] = {"U8120 3G Cellphone","Various Mobile Phones","T5100","GM360/GD510/GW520/KP501","Ally/Optimus One/Vortex (debug mode)",
		"Ally/Optimus One","P880 / Charge only","Vortex (msc)","Optimus S","Optimus Android Phone [LG Software mode]",
		"Optimus (Various Models) MTP Mode","Optimus 3","Optimus Android Phone [USB tethering mode]","Optimus Android Phone","Optimus Android Phone [MTP mode]",
		"Optimus Android Phone (Camera/PTP Mode)","Optimus Android Phone [Camera/PTP mode]","Optimus Android Phone (Charge Mode)","Optimus Android Phone [Virtual CD mode]","CDMA Modem",
		"LG LDP-7024D(LD)USB","P880 / USB tethering","Renoir (KC910)"};
		InsertProducts(0x1004, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001,0x1004,0x1006,0xb113,0xb223};
		char* mids[] = {"MP3 Player","MP3 Player","MP3 Player","Handy Steno 2.0/HT203","CD-RW + 6in1 Card Reader Digital Storage / Converter"
		};
		InsertProducts(0x1005, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3001,0x3002,0x3003,0x3004};
		char* mids[] = {"iHP-100","iHP-120/140 MP3 Player","H320/H340","H340 (mtp)"};
		InsertProducts(0x1006, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000e,0x0013,0x0015,0x0016};
		char* mids[] = {"eHome Infrared Receiver","Angel MPEG Device","Lumanate Wave PAL SECAM DVBT Device","Lumanate Wave NTSC/ATSC Combo Device"};
		InsertProducts(0x1009, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2402,0x2404,0x2405,0x2406,0xa0c0};
		char* mids[] = {"MP3 Player","MP3 Player","MP3 Player","MP3 Player","MP3 Player"
		};
		InsertProducts(0x100a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3342,0x3382,0x6072,0x9031,0x9032,0xcb01};
		char* mids[] = {"Cayman 3352 DSL Modem","3380 Series Network Interface","DSL Modem","Motorola 802.11n Dualband USB Wireless Adapter","Motorola 802.11n 5G USB Wireless Adapter",
		"Cayman 3341 Ethernet DSL Router"};
		InsertProducts(0x100d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"AccFast Mp3"};
		InsertProducts(0x1011, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0c55,0x0f38};
		char* mids[] = {"Flash Reader, Desknote UCR-61S2B","Infrared Receiver"};
		InsertProducts(0x1019, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0006,0x000a,0x0106};
		char* mids[] = {"Wireless Keyboard","Wireless Optical Mouse","Wireless Optical Mouse"};
		InsertProducts(0x1020, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x005e,0x005f,0x0300,0x0350};
		char* mids[] = {"USB DVB-T device","USB DVB-T device","MP3 Player","MP3 Player"};
		InsertProducts(0x1025, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6151,0x6251};
		char* mids[] = {"Q-Cam Sangha CIF","Q-Cam VGA"};
		InsertProducts(0x102c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0068};
		char* mids[] = {"3,5'' HDD case MD-231"};
		InsertProducts(0x1033, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x1361};
		char* mids[] = {"Ideazon Zboard","Ideazon Sensei"};
		InsertProducts(0x1038, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0824,0x2140};
		char* mids[] = {"1866 802.11bg [Texas Instruments TNETW1450]","dsl+ 1100 duo"};
		InsertProducts(0x1039, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0101};
		char* mids[] = {"ScratchAmp","ScratchAmp"};
		InsertProducts(0x103d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x160f,0x4901,0x8006,0x8012};
		char* mids[] = {"Wireless Network Adapter","AV-836 Video Capture Device","Flash Disk 32-256 MB","Flash Disk 256 MB"};
		InsertProducts(0x1043, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7001,0x7002,0x7004,0x7005,0x7006,0x8001,0x8002,0x8003,0x8004,0x8005,0x8006,0x8007,0x8008,0x800a,0x800b,0x800c,0x800d};
		char* mids[] = {"Gigabyte U7000 DVB-T tuner","Gigabyte U8000 DVB-T tuner","Gigabyte U7100 DVB-T tuner","Gigabyte U7200 DVB-T tuner [AF9035]","Gigabyte U6000 DVB-T tuner [em2863]",
		"GN-54G","GN-BR402W","GN-WLBM101","GN-WLBZ101 802.11b Adapter","GN-WLBZ201 802.11b Adapter",
		"GN-WBZB-M 802.11b Adapter","GN-WBKG","GN-WB01GS","GN-WI05GS","GN-WB30N 802.11n WLAN Card",
		"GN-WB31N 802.11n USB WLAN Card","GN-WB32L 802.11n USB WLAN Card"};
		InsertProducts(0x1044, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6694,0x8901,0x9967};
		char* mids[] = {"Generic W6694 USB","Bluetooth Device","W9967CF/W9968CF Webcam IC"};
		InsertProducts(0x1046, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1003};
		char* mids[] = {"Model-52 LED Light Source Power Supply and Driver"};
		InsertProducts(0x104d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0006,0x0007,0x0008,0x0009};
		char* mids[] = {"Infinity Phoenix","Smartmouse","FunProgrammer","Infinity Unlimited","Infinity Smart",
		"Infinity Smart module","Infinity CryptoKey","RE-BL PlayStation 3 IR-to-Bluetooth converter"};
		InsertProducts(0x104f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010,0x0110,0x0111,0x0211};
		char* mids[] = {"Yubikey","Yubikey NEO OTP","Yubikey NEO OTP+CCID","Gnubby"};
		InsertProducts(0x1050, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5004,0x5005};
		char* mids[] = {"DSL 7420 Loader","DSL 7420 LAN Modem"};
		InsertProducts(0x1054, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0200,0x0400,0x0500,0x0702,0x0704,0x070a,0x071a,0x0730,0x0740,0x0741,0x0742,0x0748,0x0810,0x0900,0x0901,0x0902,0x0903,0x0910,0x1001,0x1003,
		0x1010,0x1021,0x1023,0x1048,0x10a2,0x10a8,0x1100,0x1103,0x1104,0x1105,0x1123,0x1140};
		char* mids[] = {"FireWire USB Combo","External HDD","hub","Passport External HDD","Passport External HDD",
		"My Passport Essential SE, My Passport for Mac (WDBAAB)","My Passport","My Passport Essential (WDBACY)","My Passport","My Passport Ultra",
		"My Passport Essential SE","My Passport (WDBKXH)","My Passport Ultra","MyBook Essential External HDD","My Book Essential Edition (Green Ring)",
		"My Book Pro Edition","My Book Premium Edition","MyBook Essential External HDD","Elements Desktop (WDE1U)","Elements 1000 GB",
		"Elements Portable (WDBAAR)","Elements Desktop (WDBAAU)","Elements SE","Elements Portable (WDBU6Y)","Elements SE Portable (WDBPCK)",
		"Elements Portable (WDBUZG)","My Book Essential Edition 2.0 (WDH1U)","My Book Studio","MyBook Mirror Edition External HDD","My Book Studio II",
		"My Book 3.0","My Book Essential USB3.0"};
		InsertProducts(0x1058, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000b};
		char* mids[] = {"StarSign Bio Token 3.0"};
		InsertProducts(0x1059, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1555,0x4100};
		char* mids[] = {"MC141555 Hub","SB4100 USB Cable Modem"};
		InsertProducts(0x1063, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0020,0x2136};
		char* mids[] = {"USB-DVR2 Dev Board","EasyDisk ED1064"};
		InsertProducts(0x1065, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1101,0x1102,0x1103,0x1104,0x1105,0x1106,0x1301,0x1302,0x1303,0x1304,0x1401,0x1402,0x1403,0x1501,0x1502,0x1503,0x1601,0x1602,0x1603,0x2101,
		0x2102,0x2103,0x2301,0x2302,0x2303,0x2401,0x2402,0x2403,0x2501,0x2502,0x2503,0x2601,0x2602,0x2603,0x3701,0x3702,0x3714,0x3716,0x3721,0x3b14,
		0x3eb4,0x4101,0x4102,0x4301,0x4302,0x4401,0x4402,0x4501,0x4502,0x4601,0x4602,0x5101,0x5102,0x5301,0x5302,0x5401,0x5402,0x5501,0x5502,0x5601,
		0x5602,0x7101,0x7102,0xa000,0xa001,0xc100,0xc200,0xc500,0xe200};
		char* mids[] = {"CDMA 2000 1xRTT USB modem (HX-550C)","Packet Service","Packet Service Diagnostic Serial Port (WDM)","Packet Service Diagnostic Serial Port (WDM)","Composite Device",
		"Packet Service Diagnostic Serial Port (WDM)","Composite Device","Packet Service Diagnostic Serial Port (WDM)","Packet Service","Packet Service",
		"Composite Device","Packet Service","Packet Service Diagnostic Serial Port (WDM)","Packet Service","Packet Service Diagnostic Serial Port (WDM)",
		"Packet Service","Packet Service","Packet Service Diagnostic Serial Port (WDM)","Packet Service","AudioVox 8900 Cell Phone",
		"Packet Service","Packet Service Diagnostic Serial Port (WDM)","Packet Service","Packet Service Diagnostic Serial Port (WDM)","Packet Service",
		"Packet Service Diagnostic Serial Port (WDM)","Packet Service","Packet Service Diagnostic Serial Port (WDM)","Packet Service","Packet Service Diagnostic Serial Port (WDM)",
		"Packet Service","Packet Service","Packet Service Diagnostic Serial Port (WDM)","Packet Service","Broadband Wireless modem",
		"Pantech PX-500","PANTECH USB MODEM [UM175]","UMW190 Modem","Option Beemo (GI0801) LTE surfstick","Option Beemo (GI0801) LTE surfstick",
		"Packet Service Diagnostic Serial Port (WDM)","Packet Service Diagnostic Serial Port (WDM)","Packet Service","Composite Device","Packet Service Diagnostic Serial Port (WDM)",
		"Composite Device","Packet Service","Packet Service","Packet Service Diagnostic Serial Port (WDM)","Composite Device",
		"Packet Service Diagnostic Serial Port (WDM)","Packet Service","Packet Service Diagnostic Serial Port (WDM)","Packet Service Diagnostic Serial Port (WDM)","Packet Service",
		"Packet Service","Packet Service Diagnostic Serial Port (WDM)","Packet Service Diagnostic Serial Port (WDM)","Packet Service","Packet Service Diagnostic Serial Port (WDM)",
		"Packet Service","Composite Device","Packet Service","Packet Service","Packet Service Diagnostic Serial Port (WDM)",
		"Packet Service","Packet Service","Packet Service Diagnostic Serial Port (WDM)","Packet Service"};
		InsertProducts(0x106c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0009,0x000a,0x000c};
		char* mids[] = {"CT10x Coin Transaction","CR10x Coin Recycler","Xchange"};
		InsertProducts(0x106f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0031,0x0032};
		char* mids[] = {"Bluetooth Device","Bluetooth Device"};
		InsertProducts(0x1076, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3009,0x55b2,0x55f2};
		char* mids[] = {"eHome Infrared Transceiver","WBU-110 802.11b Wireless Adapter [Intersil PRISM 3]","WGU-210 802.11g Adapter [Intersil ISL3886]"};
		InsertProducts(0x107b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x161b,0x162c};
		char* mids[] = {"DR-2010C Scanner","P-150 Scanner"};
		InsertProducts(0x1083, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x9118};
		char* mids[] = {"Medion P4013 Mobile"};
		InsertProducts(0x109b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3163,0x3164};
		char* mids[] = {"Trigem Mobile SmartDisplay84","Trigem Mobile SmartDisplay121"};
		InsertProducts(0x109f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1102,0x1104,0x6021};
		char* mids[] = {"Sky Love Actually IM-U460K","Sky Vega IM-A650S","SIRIUS alpha"};
		InsertProducts(0x10a9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1002,0x1003,0x1005,0x1006,0x10c5};
		char* mids[] = {"Bluetooth Device","BC02-EXT in DFU","Bluetooth Adptr","BC04-EXT in DFU","Sony-Ericsson / Samsung DataCable"
		};
		InsertProducts(0x10ab, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008};
		char* mids[] = {"UPS","PowerSure PSA UPS","PowerSure PST UPS","PowerSure PSP UPS","PowerSure PSI UPS",
		"UPStation GXT 2U UPS","UPStation GXT UPS","Nfinity Power Systems UPS","PowerSure Interactive UPS"};
		InsertProducts(0x10af, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x9060};
		char* mids[] = {"Test Board"};
		InsertProducts(0x10b5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0bb8,0x0bb9,0x0bc6,0x0bc7};
		char* mids[] = {"DiBcom USB DVB-T reference design (MOD300) (cold)","DiBcom USB DVB-T reference design (MOD300) (warm)","DiBcom USB2.0 DVB-T reference design (MOD3000P) (cold)","DiBcom USB2.0 DVB-T reference design (MOD3000P) (warm)"};
		InsertProducts(0x10b8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1427};
		char* mids[] = {"Ethernet"};
		InsertProducts(0x10bd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"SmartHome PowerLinc"};
		InsertProducts(0x10bf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00a4,0x00a5};
		char* mids[] = {"ULS PLS Series Laser Engraver Firmware Loader","ULS Print Support"};
		InsertProducts(0x10c3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0003,0x8030,0x8044,0x804e,0x80a9,0x80ca,0x813f,0x8149,0x814a,0x814b,0x818a,0x81e8,0x8460,0x8461,0x8477,0x8496,0x8497,0x8605,0x86bc,
		0x8789,0x87be,0x8863,0x8897,0x8918,0xea60,0xea61,0xea70,0xea80};
		char* mids[] = {"F32x USBXpress Device","CommandIR","K4JRG Ham Radio devices","USB Debug Adapter","Software Bisque Paramount ME",
		"CP210x to UART Bridge Controller","ATM2400 Sensor Device","tams EasyControl","West Mountain Radio Computerized Battery Analyzer","West Mountain Radio RIGblaster P&P",
		"West Mountain Radio RIGtalk","Silicon Labs FM Radio Reference Design","Zephyr BioHarness","Sangoma Wanpipe VoiceTime","Sangoma U100",
		"Balluff RFID Reader","SiLabs Cypress FW downloader","SiLabs Cypress EVB","dilitronics ESoLUX solar lighting controller","C8051F34x AudioDelay [AD-340]",
		"C8051F34x Extender & EDID MGR [EMX-DVI]","C8051F34x HDMI Audio Extractor [EMX-HD-AUD]","C8051F34x Bootloader","C8051F38x HDMI Splitter [UHBX]","C8051F38x HDMI Audio Extractor [VSA-HA-DP]",
		"CP210x UART Bridge / myAVR mySmartUSB light","CP210x UART Bridge","CP210x UART Bridge","CP210x UART Bridge"};
		InsertProducts(0x10c4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x819a};
		char* mids[] = {"FM Radio"};
		InsertProducts(0x10c5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1101};
		char* mids[] = {"MP3 Player"};
		InsertProducts(0x10cc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000e,0xea6a};
		char* mids[] = {"Shinko/Sinfonia CHC-S2145","MobiData EDGE USB Modem"};
		InsertProducts(0x10ce, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2011,0x5500,0x5501,0x5502,0x5503};
		char* mids[] = {"R-Engine MPEG2 encoder/decoder","8055 Experiment Interface Board (address=0)","8055 Experiment Interface Board (address=1)","8055 Experiment Interface Board (address=2)","8055 Experiment Interface Board (address=3)"
		};
		InsertProducts(0x10cf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0202,0x0301};
		char* mids[] = {"USB-Module for Spider8, CP32","CP22 - Communication Processor","CP42 - Communication Processor"};
		InsertProducts(0x10d1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004,0x5552,0x55a2};
		char* mids[] = {"PS/2 Converter","KVM Human Interface Composite Device (Keyboard/Mouse ports)","2Port KVMSwitcher"};
		InsertProducts(0x10d5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x1100,0x1101,0x2200,0x8888,0xff51,0xff61,0xff66};
		char* mids[] = {"MP3 Player","MPMan MP-Ki 128 MP3 Player/Recorder","D-Wave 2GB MP4 Player / AK1025 MP3/MP4 Player","Acer MP-120 MP3 player","ADFU Device",
		"ADFU Device","MP4 Player","Craig 2GB MP3/Video Player"};
		InsertProducts(0x10d6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0500};
		char* mids[] = {"iAPP CR-e500 Card reader"};
		InsertProducts(0x10df, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2002};
		char* mids[] = {"iNexio Touchscreen controller"};
		InsertProducts(0x10f0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1a08,0x1a1e,0x1a2a};
		char* mids[] = {"Internal Webcam","Laptop Integrated Webcam 1.3M","Laptop Integrated Webcam"};
		InsertProducts(0x10f1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0200};
		char* mids[] = {"Audio Advantage Roadie"};
		InsertProducts(0x10f5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7e50,0x804d,0x8050,0xde00};
		char* mids[] = {"FlyCam Usb 100","Typhoon Webshot II Webcam [zc0301]","FlyCAM-USB 300 XP2","WinFast WalkieTV WDM Capture Driver."};
		InsertProducts(0x10fd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000c};
		char* mids[] = {"TT-3750 BGAN-XL Radio Module"};
		InsertProducts(0x10fe, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"VTPlayer VTP-1 Braille Mouse"};
		InsertProducts(0x1100, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"FSK Electronics Super GSM Reader"};
		InsertProducts(0x1101, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1250,0x1251,0x1410,0x1450,0x1451,0x1613,0x1618,0x1653,0x1658};
		char* mids[] = {"UPort 1250 2-Port RS-232/422/485","UPort 1250I 2-Port RS-232/422/485 with Isolation","UPort 1410 4-Port RS-232","UPort 1450 4-Port RS-232/422/485","UPort 1450I 4-Port RS-232/422/485 with Isolation",
		"UPort 1610-16 16-Port RS-232","UPort 1610-8 8-Port RS-232","UPort 1650-16 16-Port RS-232/422/485","UPort 1650-8 8-Port RS-232/422/485"};
		InsertProducts(0x110a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5c01,0x6489,0x9000,0x9001,0x900f,0x9010,0x9021,0x9022,0x9023,0x9024,0x9031,0x9032};
		char* mids[] = {"Huawei MT-882 Remote NDIS Network Device","ADSL ETH/USB RTR","ADSL LAN Adapter","ADSL Loader","AT-AR215 DSL Modem",
		"AT-AR215 DSL Modem","ADSL WAN Adapter","ADSL Loader","ADSL WAN Adapter","ADSL Loader",
		"ADSL LAN Adapter","ADSL Loader"};
		InsertProducts(0x1110, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8888};
		char* mids[] = {"Evolution Device"};
		InsertProducts(0x1111, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa0a2};
		char* mids[] = {"Active Sync device"};
		InsertProducts(0x1113, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0005};
		char* mids[] = {"RedRat3 IR Transceiver","RedRat3II IR Transceiver"};
		InsertProducts(0x112a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0202,0x6604,0x660c,0x6806,0xc301,0xf211};
		char* mids[] = {"iBuddy","Rocket Launcher","MCE IR-Receiver","Foot Pedal/Thermometer","Keychain photo frame",
		"Digital Photo viewer [Wallet Pix]","TP6911 Audio Headset"};
		InsertProducts(0x1130, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001,0x1002,0x1003,0x1004};
		char* mids[] = {"KY-BT100 Bluetooth Adapter","Bluetooth Device","Bluetooth Device","Bluetooth Device"};
		InsertProducts(0x1131, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4331,0x4332,0x4333,0x4334,0x4335,0x4337,0x4338};
		char* mids[] = {"PDR-M4/M5/M70 Digital Camera","PDR-M60 Digital Camera","PDR-M2300/PDR-M700","PDR-M65","PDR-M61",
		"PDR-M11","PDR-M25"};
		InsertProducts(0x1132, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3131};
		char* mids[] = {"CTS LS515"};
		InsertProducts(0x1136, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0709};
		char* mids[] = {"Cyberview High Speed Scanner"};
		InsertProducts(0x1142, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"AirH PHONE AH-J3001V/J3002V"};
		InsertProducts(0x1145, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0110,0x0150};
		char* mids[] = {"Turbolink UB801R WLAN Adapter","Turbolink UB801RE Wireless 802.11g 54Mbps Network Adapter [RTL8187]"};
		InsertProducts(0x114b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1234};
		char* mids[] = {"Fastrack Xtend FXT001 Modem"};
		InsertProducts(0x114f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0200,0x2020};
		char* mids[] = {"Earthmate GPS (orig)","Earthmate GPS (LT-20, LT-40)","Earthmate GPS (PN-40)"};
		InsertProducts(0x1163, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0300,0x0601,0x0900,0x0bc7,0x521b,0x6601};
		char* mids[] = {"ELSAVISION 460D","Analog TV Tuner","TigerBird BMP837 USB2.0 WDM Encoder","Digital TV Tuner","MC521A mini Card ATSC Tuner",
		"Digital TV Tuner Card [RTL2832U]"};
		InsertProducts(0x1164, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005,0xc108,0xc109};
		char* mids[] = {"Flash Card Reader","Flash Card Reader","Flash Card Reader"};
		InsertProducts(0x116f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x19c7,0x4008,0x504a};
		char* mids[] = {"DigitalDream l'espion XS","ISDN TA","56k FaxModem","PJB-100 Personal Jukebox"};
		InsertProducts(0x1183, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0893};
		char* mids[] = {"EP-1427X-2 Ethernet Adapter [Acer]"};
		InsertProducts(0x1189, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010,0x0011};
		char* mids[] = {"Trifid Camera without code","Trifid Camera"};
		InsertProducts(0x1196, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0019,0x0021,0x0024,0x0110,0x0112,0x0120,0x0218,0x6467,0x6468,0x6469,0x6802,0x6803,0x6804,0x6805,0x6812,0x6820,0x6832,0x6833,0x683a,0x683c,
		0x6850,0x6851,0x6852,0x6853,0x6854,0x6856,0x6870,0x6871,0x6893,0x68a3,0x68aa,0x9000,0x9001,0x9002,0x9003,0x9004,0x9005,0x9006,0x9007,0x9008,
		0x9009,0x900a,0x9055,0x9057};
		char* mids[] = {"AC595U","AC597E","MC5727 CDMA modem","Composite Device","CDMA 1xEVDO PC Card, AirCard 580",
		"AC595U","MC5720 Wireless Modem","MP Series Network Adapter","MP Series Network Adapter","MP Series Network Adapter",
		"MC8755 Device","MC8765 Device","MC8755 Device","MC8765 Device","MC8775 Device",
		"AC875 Device","MC8780 Device","MC8781 Device","MC8785 Device","Mobile Broadband 3G/UMTS (MC8790 Device)",
		"AirCard 880 Device","AirCard 881 Device","AirCard 880E Device","AirCard 881E Device","AirCard 885 Device",
		"ATT \"USB Connect 881\"","MC8780 Device","MC8781 Device","MC8777 Device","MC8700 Modem",
		"4G LTE adapter","Gobi 2000 Wireless Modem (QDL mode)","Gobi 2000 Wireless Modem","Gobi 2000 Wireless Modem","Gobi 2000 Wireless Modem",
		"Gobi 2000 Wireless Modem","Gobi 2000 Wireless Modem","Gobi 2000 Wireless Modem","Gobi 2000 Wireless Modem","Gobi 2000 Wireless Modem",
		"Gobi 2000 Wireless Modem","Gobi 2000 Wireless Modem","Gobi 9x15 Multimode 3G/4G LTE Modem (NAT mode)","Gobi 9x15 Multimode 3G/4G LTE Modem (IP passthrough mode)"};
		InsertProducts(0x1199, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0400};
		char* mids[] = {"Infrared Keyboard V2.01"};
		InsertProducts(0x119b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xeb11};
		char* mids[] = {"CC2400EB 2.0 ZigBee Sniffer"};
		InsertProducts(0x11a0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8031,0x8032};
		char* mids[] = {"MP3 Player","MP3 Player"};
		InsertProducts(0x11a3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1518};
		char* mids[] = {"iREZ K2"};
		InsertProducts(0x11aa, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6565};
		char* mids[] = {"FuelBand"};
		InsertProducts(0x11ac, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6208};
		char* mids[] = {"PRO-28U"};
		InsertProducts(0x11b0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xf0a0};
		char* mids[] = {"Martin Maxxyz DMX"};
		InsertProducts(0x11be, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0521};
		char* mids[] = {"IMT-0521 Smartcard Reader"};
		InsertProducts(0x11c5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0207,0x0220};
		char* mids[] = {"PIN Pad VX 810","PIN Pad VX 805"};
		InsertProducts(0x11ca, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x1100};
		char* mids[] = {"PVR","PVR"};
		InsertProducts(0x11db, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0003,0x0004,0x0005,0x0008,0x0101};
		char* mids[] = {"SX1","Mobile phone USB cable","X75","SXG75/EF81","UMTS/HSDPA Data Card",
		"RCU Connect"};
		InsertProducts(0x11f5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2001};
		char* mids[] = {"Willcom WSIM"};
		InsertProducts(0x11f6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x02df};
		char* mids[] = {"Serial cable (v2) for TD-10 Mobile Phone"};
		InsertProducts(0x11f7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0140};
		char* mids[] = {"TTP-245C"};
		InsertProducts(0x1203, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001,0x1002,0x1003,0x1004,0x1005};
		char* mids[] = {"USB Hub","USB Relais","IBSecureCam-P","IBSecureCam-O","IBSecureCam-N"
		};
		InsertProducts(0x1209, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x524e,0x5260};
		char* mids[] = {"RoadMate 1475T","Triton Handheld GPS Receiver (300/400/500/1500/2000)"};
		InsertProducts(0x120f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0016,0x001b,0x001c};
		char* mids[] = {"RP500 Guitar Multi-Effects Processor","RP155 Guitar Multi-Effects Processor","RP255 Guitar Multi-Effects Processor"};
		InsertProducts(0x1210, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3403};
		char* mids[] = {"Muzio JM250 Audio Player"};
		InsertProducts(0x121e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0012,0x0015,0x584c};
		char* mids[] = {"Q18 Data Logger","TPaq21/MPaq21 Datalogger","XL2 Logger"};
		InsertProducts(0x1228, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5677};
		char* mids[] = {"FUSB200 mp3 player"};
		InsertProducts(0x1233, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x4321,0xed02};
		char* mids[] = {"Neural Impulse Actuator Prototype 1.0 [NIA]","Human Interface Device","Emotiv EPOC Developer Headset Wireless Dongle"};
		InsertProducts(0x1234, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0009,0x000a,0x000b,0x000c,0x000e,0x0010,0x0011,0x0012,0x0013,0x0014,0x0015,0x0016,
		0x0018,0x0019,0x001a,0x001b,0x4661,0x8000,0x8002,0x8006,0x8008,0x800a,0x800c,0x800e,0x8010,0x8012,0x8014};
		char* mids[] = {"ReMOTE Audio/XStation First Edition","Speedio","RemoteSL + ZeroSL","ReMOTE LE","XIOSynth [First Edition]",
		"XStation","XIOSynth","ReMOTE SL Compact","nIO","Nocturn",
		"ReMOTE SL MkII","ZeRO MkII","Launchpad","Saffire 6","Ultranova",
		"Nocturn Keyboard","VRM Box","VRM Box Audio Class (2-out)","Dicer","Ultranova",
		"Twitch","Impulse 25","Impulse 49","Impulse 61","ReMOTE25",
		"Scarlett 18i6","Scarlett 8i6","Focusrite Scarlett 2i2","Saffire 6","Scarlett 2i4",
		"Scarlett 18i20","iTrack Solo","Forte","Scarlett 6i6","Scarlett 18i8"
		};
		InsertProducts(0x1235, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0504,0x1111,0x1122,0x1155,0x1166,0x1177,0x1503,0x1603,0xf767};
		char* mids[] = {"Wireless Trackball Keyboard","Mouse","Typhoon Stream Optical Mouse USB+PS/2","PS2/USB Browser Combo Mouse","MI-2150 Trust Mouse",
		"Mouse [HT82M21A]","Keyboard","Keyboard","Keyboard"};
		InsertProducts(0x1241, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x168b,0x4017,0x4023,0x4025};
		char* mids[] = {"PRISM3 WLAN Adapter","PC-Chips 802.11b Adapter","WM168g 802.11bg Wireless Adapter [Intersil ISL3886]","IOGear GWU513 v2 802.11bg Wireless Adapter [Intersil ISL3887]"};
		InsertProducts(0x124a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4d01};
		char* mids[] = {"Airflo EX Joystick"};
		InsertProducts(0x124b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3200};
		char* mids[] = {"Stealth MXP 1GB"};
		InsertProducts(0x124c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010};
		char* mids[] = {"Alta series CCD"};
		InsertProducts(0x125c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x312a,0x312b,0xa22a,0xa91a,0xc08a,0xc81a,0xc93a,0xc96a,0xcb10};
		char* mids[] = {"Superior S102","Superior S102 Pro","DashDrive Elite HE720 500GB","Portable HDD CH91","C008 Flash Drive",
		"Flash drive","4GB Pen Drive","C906 Flash Drive","Dash Drive UV100"};
		InsertProducts(0x125f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xee22};
		char* mids[] = {"SMC2862W-G v3 EZ Connect 802.11g Adapter [Intersil ISL3887]"};
		InsertProducts(0x1260, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6302};
		char* mids[] = {"Fastweb DRG A226M ADSL Router"};
		InsertProducts(0x1266, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0103,0x0201,0x0210,0xa001,0xc002};
		char* mids[] = {"G-720 Keyboard","A4Tech SWOP-3 Mouse","LG Optical Mouse 3D-310","JP260 PC Game Pad","Wireless Optical Mouse"
		};
		InsertProducts(0x1267, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0163,0x1325,0x2168,0xa006};
		char* mids[] = {"Storage device (2gB thumb drive)","Mobile Disk","Mobile Disk III","G240 802.11bg"};
		InsertProducts(0x126f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0080};
		char* mids[] = {"WeatherFax 2000 Demodulator","SkyEye Weather Satellite Receiver"};
		InsertProducts(0x1275, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0105,0x0107,0x0109,0x0110,0x0115,0x0119,0x0135,0x0136,0x0200,0x0305,0x0307,0x0319,0x0325,0x0326,0x0507,0x0517};
		char* mids[] = {"SXV-M5","SXV-M7","SXV-M9","SXVF-H16","SXVF-H5",
		"SXV-H9","SXVF-H35","SXVF-H36","SXV interface for paraller MX cameras","SXV-M5C",
		"SXV-M7C","SXV-H9C","SXV-M25C","SXVR-M26C","Lodestar autoguider",
		"CoStar"};
		InsertProducts(0x1278, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0110,0x0111,0x0112,0x0114,0x0115,0x0116,0x0120,0x0121,0x0130,0x0150};
		char* mids[] = {"USB-RS232 Adaptor","CMS20","CMS 10","CMS 05","ARCUS digma PC-Interface",
		"SAM Axioquick recorder","SAM Axioquick recorder","emed-X","emed-AT","PDM",
		"CMS10GI (Golf)"};
		InsertProducts(0x1283, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00bc,0x1fab,0x2001,0x2006,0x8001};
		char* mids[] = {"Marvell JTAG Probe","88W8338 [Libertas] 802.11g","88W8388 802.11a/b/g WLAN","88W8362 802.11n WLAN","BLOB boot loader firmware"
		};
		InsertProducts(0x1286, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010,0x0011};
		char* mids[] = {"FDM 2xxx Flash-OFDM modem","LR7F06/LR7F14 Flash-OFDM modem"};
		InsertProducts(0x1291, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0258};
		char* mids[] = {"Creative Labs VoIP Blaster"};
		InsertProducts(0x1292, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x2101};
		char* mids[] = {"F5U002 Parallel Port [uss720]","104-key keyboard"};
		InsertProducts(0x1293, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x160b,0x160c,0x1666,0x1667,0x1828};
		char* mids[] = {"Siemens S30853-S1031-R351 802.11g Wireless Adapter [Atheros AR5523]","Siemens S30853-S1038-R351 802.11g Wireless Adapter [Atheros AR5523]","TG54USB 802.11bg","802.11bg","Gigaset USB Adapter 300"
		};
		InsertProducts(0x129b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00ff,0x0100,0x0120,0x0200,0x0210};
		char* mids[] = {"Rocksmith Guitar Adapter","RedOctane Guitar for PlayStation(R)3","RedOctane Drum Kit for PlayStation(R)3","Harmonix Guitar for PlayStation(R)3","Harmonix Drum Kit for PlayStation(R)3"
		};
		InsertProducts(0x12ba, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0006,0x0008};
		char* mids[] = {"Teleprompter Two-button Hand Control (v1)","Teleprompter Foot Control (v1)"};
		InsertProducts(0x12c4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0170};
		char* mids[] = {"Tt eSPORTS BLACK Gaming mouse"};
		InsertProducts(0x12cf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001,0x1003,0x1004,0x1009,0x1010,0x1021,0x1035,0x1037,0x1038,0x1039,0x1406,0x140b,0x140c,0x1412,0x1436,0x1446,0x1465,0x14c3,0x14c8,0x14c9,
		0x14cf,0x14d1,0x14db,0x14f1,0x14fe,0x1501,0x1505,0x1506,0x150a,0x1520,0x1521,0x155a,0x1575,0x15ca,0x1805,0x1c05,0x1c0b,0x1c20,0x1d50,0x1f01,
		0x1f16,0x380b};
		char* mids[] = {"E169/E620/E800 HSDPA Modem","E220 HSDPA Modem / E230/E270/E870 HSDPA/HSUPA Modem","E220 (bis)","U120","ETS2252+ CDMA Fixed Wireless Terminal",
		"U8520","U8120","Ideos","Ideos (debug mode)","Ideos (tethering mode)",
		"E1750","EC1260 Wireless Data Modem HSD USB Card","E180v","EC168c","E173 3G Modem (modem-mode)",
		"E1552/E1800/E173 (HSPA modem)","K3765 HSPA","K5005 Vodafone LTE/UMTS/GSM Modem/Networkcard","K5005 Vodafone LTE/UMTS/GSM MOdem/Networkcard","K3770 3G Modem",
		"K3772","K3770 3G Modem (Mass Storage Mode)","E353/E3131","Gobi 3000 HSPA+ Modem","Modem (Mass Storage Mode)",
		"Pulse","E398 LTE/UMTS/GSM Modem/Networkcard","Modem/Networkcard","E398 LTE/UMTS/GSM Modem/Networkcard","K3765 HSPA",
		"K4505 HSPA+","R205 Mobile WiFi (CD-ROM mode)","K5150 LTE modem","E3131 3G/UMTS/HSPA+ Modem (Mass Storage Mode)","AT&T Go Phone U2800A phone",
		"E173s 3G broadband stick (modem on)","E173s 3G broadband stick (modem off)","R205 Mobile WiFi (Charging)","ET302s TD-SCDMA/TD-HSDPA Mobile Broadband","E353/E3131 (Mass storage mode)",
		"K5150 LTE modem (Mass Storage Mode)","WiMAX USB modem(s)"};
		InsertProducts(0x12d1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0444,0x0888};
		char* mids[] = {"CPC-USB/ARM7","CPC-USB/M16C"};
		InsertProducts(0x12d6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Alea I True Random Number Generator"};
		InsertProducts(0x12d8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0013};
		char* mids[] = {"Blofeld"};
		InsertProducts(0x12e6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100};
		char* mids[] = {"Tapwave Handheld [Tapwave Zodiac]"};
		InsertProducts(0x12ef, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1a00,0x1e23};
		char* mids[] = {"TD Classic 003B","TravelDrive 2007 Flash Drive"};
		InsertProducts(0x12f7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001};
		char* mids[] = {"AWU2000b 802.11b Stick"};
		InsertProducts(0x12fd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"Advanced RC Servo Controller"};
		InsertProducts(0x12ff, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0163,0x0165,0x0190,0x0310,0x0330,0x0361,0x1169,0x1171};
		char* mids[] = {"256MB/512MB/1GB Flash Drive","2GB/4GB/8GB Flash Drive","Ut190 8 GB Flash Drive with MicroSD reader","SD/MicroSD CardReader [hama]","63-in-1 Multi-Card Reader/Writer",
		"CR-75: 51-in-1 Card Reader/Writer [Sakar]","TS2GJF210 JetFlash 210 2GB","Fingerprint Reader"};
		InsertProducts(0x1307, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0xc001};
		char* mids[] = {"VFD Module","eHome Infrared Transceiver"};
		InsertProducts(0x1308, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Class 1 Bluetooth Dongle"};
		InsertProducts(0x1310, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010,0x0011,0x0012,0x0110,0x0111,0x0112,0x8001,0x8012,0x8013,0x8017,0x8019,0x8020,0x8021,0x8022,0x8030,0x8070};
		char* mids[] = {"LC1 Linear Camera (Jungo)","SP1 Spectrometer (Jungo)","SP2 Spectrometer (Jungo)","LC1 Linear Camera (VISA)","SP1 Spectrometer (VISA)",
		"SP2 Spectrometer (VISA)","TXP-Series Slot (TXP5001, TXP5004)","BC106 Camera Beam Profiler","WFS10 Wavefront Sensor","BC206 Camera Beam Profiler",
		"BP2 Multi Slit Beam Profiler","PM300 Optical Power Meter","PM300E Optical Power and Energy Meter","PM320E Optical Power and Energy Meter","ER100 Extinction Ratio Meter",
		"PM100D"};
		InsertProducts(0x1313, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0155,0x0156};
		char* mids[] = {"TrackIR 3 Pro Head Tracker","TrackIR 4 Pro Head Tracker"};
		InsertProducts(0x131d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1502};
		char* mids[] = {"WiND 802.11abg / 802.11bg WLAN"};
		InsertProducts(0x132a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0001,0x0003,0x0006,0x0007,0x0008,0x000a,0x000b,0x000d,0x000f,0x0010,0x0012,0x0013,0x0015,0x0017,0x0018,0x0019,0x0021,0x0022,0x002c,
		0x2001,0x2004,0x2005,0x2029,0x2030,0x2033,0x2043,0x2045,0x2049};
		char* mids[] = {"Dimage A2 Camera","Minolta DiMAGE A2 (ptp)","Dimage Xg Camera","Dimage Z2 Camera","Minolta DiMAGE Z2 (PictBridge mode)",
		"Dimage X21 Camera","Dimage Scan Dual IV AF-3200 (2891)","Dimage Z10 Camera","Dimage X50 Camera [storage?]","Dimage X50 Camera [p2p?]",
		"Dimage G600 Camera","Dimage Scan Elite 5400 II (2892)","Dimage X31 Camera","Dimage G530 Camera","Dimage Z3 Camera",
		"Minolta DiMAGE Z3 (PictBridge mode)","Dimage A200 Camera","Dimage Z5 Camera","Minolta DiMAGE Z5 (PictBridge mode)","Dynax 5D camera",
		"Magicolor 2400w","Magicolor 5430DL","Magicolor 2430 DL","Magicolor 5440DL","PagePro 1350E(N)",
		"PagePro 1400W","Magicolor 2530DL","Magicolor 2500W","Magicolor 2490MF"};
		InsertProducts(0x132b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0200,0x0201,0x0202,0x0203,0x0204,0x0304};
		char* mids[] = {"EasiDock 200 Hub","EasiDock 200 Keyboard and Mouse Port","EasiDock 200 Serial Port","EasiDock 200 Printer Port","Ethernet",
		"EasiDock Ethernet"};
		InsertProducts(0x1342, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0004,0x0005};
		char* mids[] = {"CX / DNP DS40","CX-W / DNP DS80","CY / DNP DSRX"};
		InsertProducts(0x1343, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x001c,0x6006};
		char* mids[] = {"Xbox Controller Hub","Defender Wireless Controller"};
		InsertProducts(0x1345, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0400,0x0401,0x0402,0x0403,0x0404,0x0405,0x0406,0x0410,0x0411,0x0412,0x0413,0x0414};
		char* mids[] = {"G2CCD USB 1.1 obsolete","G2CCD-S with Sony ICX285 CCD","G2CCD2","G2/G3CCD-I KAI CCD","G2/G3/G4 CCD-F KAF CCD",
		"Gx CCD-I CCD","Gx CCD-F CCD","G1-0400 CCD","G1-0800 CCD","G1-0300 CCD",
		"G1-2000 CCD","G1-1400 CCD"};
		InsertProducts(0x1347, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004};
		char* mids[] = {"Touch Panel Controller","Touch Panel Controller","Touch Panel Controller","Touch Panel Controller"};
		InsertProducts(0x134c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0503,0x0504};
		char* mids[] = {"USB-ML-12 HCS08/HCS12 Multilink","DEMOJM"};
		InsertProducts(0x1357, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"J-Link ARM"};
		InsertProducts(0x1366, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0323,0x6828};
		char* mids[] = {"Swissmemory cirrusWHITE","Victorinox Flash Drive"};
		InsertProducts(0x1370, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0013,0x0014,0x5743,0x9022,0x9032,0x9401};
		char* mids[] = {"CNUSB-611AR Wireless Adapter-G [AT76C503]","CNUSB-611AR Wireless Adapter-G [AT76C503] (FiberLine WL-240U)","CNUSB-611 Wireless Adapter [AT76C505]","CNUSB-611 Wireless Adapter [AT76C505] (FiberLine WL-240U)","CNUSB-611 (D) Wireless Adapter [AT76C503]",
		"CWD-854 [RT2573]","CWD-854 rev F","CWD-854 Wireless 802.11g 54Mbps Network Adapter [RTL8187]"};
		InsertProducts(0x1371, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"SCAPS USC-2 Scanner Controller"};
		InsertProducts(0x137b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4250,0x4251,0x5f00,0x5f01,0x5f02,0x6e00};
		char* mids[] = {"WG111T","WG111T (no firmware)","WPN111 RangeMax(TM) Wireless USB 2.0 Adapter","WPN111 (no firmware)","WPN111 (no firmware)",
		"WPNT121 802.11g 240Mbps Wireless Adapter [Airgo AGN300]"};
		InsertProducts(0x1385, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0005,0x0007,0x0008,0x0011,0x0018,0x003c,0x003d,0x0050};
		char* mids[] = {"VFS101 Fingerprint Reader","VFS301 Fingerprint Reader","VFS451 Fingerprint Reader","VFS300 Fingerprint Reader","VFS5011 Fingerprint Reader",
		"Fingerprint scanner","VFS471 Fingerprint Reader","VFS491","Swipe Fingerprint Sensor"};
		InsertProducts(0x138a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x9000};
		char* mids[] = {"Raisonance S.A. STM32 ARM evaluation board"};
		InsertProducts(0x138e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x5454};
		char* mids[] = {"GO 520 T/GO 630/ONE XL (v9)","Blue & Me 2"};
		InsertProducts(0x1390, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000};
		char* mids[] = {"URTC-1000"};
		InsertProducts(0x1391, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3556};
		char* mids[] = {"USB Headset"};
		InsertProducts(0x1395, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00bc};
		char* mids[] = {"BCF2000"};
		InsertProducts(0x1397, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2103};
		char* mids[] = {"USB 2.0 Storage Device"};
		InsertProducts(0x1398, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x9999};
		char* mids[] = {"Card reader"};
		InsertProducts(0x13ad, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000a};
		char* mids[] = {"Alesis Photon X25 MIDI Controller"};
		InsertProducts(0x13b0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000a,0x000b,0x000c,0x000d,0x000e,0x0011,0x0014,0x0018,0x001a,0x001e,0x0020,0x0022,0x0023,0x0024,0x0026,0x0028,0x0029,0x002f,0x0031,0x0039,
		0x003a,0x003b,0x003e,0x003f,0x13b1};
		char* mids[] = {"WUSB54G v2 802.11g Adapter [Intersil ISL3887]","WUSB11 v4.0 802.11b Adapter [ALi M4301]","WUSB54AG 802.11a/g Adapter [Intersil ISL3887]","WUSB54G v4 802.11g Adapter [Ralink RT2500USB]","WUSB54GS v1 802.11g Adapter [Broadcom 4320 USB]",
		"WUSB54GP v4.0 802.11g Adapter [Ralink RT2500USB]","WUSB54GS v2 802.11g Adapter [Broadcom 4320 USB]","USB200M 10/100 Ethernet Adapter","HU200TS Wireless Adapter","WUSBF54G 802.11bg",
		"WUSB54GC v1 802.11g Adapter [Ralink RT73]","WUSB54GX4 802.11g 240Mbps Wireless Adapter [Airgo AGN300]","WUSB54GR","WUSBF54G v1.1 802.11bg","WUSB54GSC v1 802.11g Adapter [Broadcom 4320 USB]",
		"WUSB200 802.11g Adapter [Ralink RT2671]","WUSB300N 802.11bgn Wireless Adapter [Marvell 88W8362+88W8060]","AE1000 v1 802.11n [Ralink RT3572]","AM10 v1 802.11n [Ralink RT3072]","AE1200 802.11bgn Wireless Adapter [Broadcom BCM43235]",
		"AE2500 802.11abgn Wireless Adapter [Broadcom BCM43236]","AE3000 802.11abgn (3x3) Wireless Adapter [Ralink RT3573]","AE6000 802.11a/b/g/n/ac Wireless Adapter [MediaTek MT7610U]","WUSB6300 802.11a/b/g/n/ac Wireless Adapter [Realtek RTL8812AU]","WUSB200: Wireless-G Business Network Adapter with Rangebooster"
		};
		InsertProducts(0x13b1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0030};
		char* mids[] = {"Multimix 8"};
		InsertProducts(0x13b2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0017,0x0018};
		char* mids[] = {"Konig Electronic CMP-KEYPAD12 Numeric Keypad","PS/2 Keyboard+Mouse Adapter","Barcode PCP-BCG4209"};
		InsertProducts(0x13ba, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1200};
		char* mids[] = {"Olidata Wireless Multimedia Adapter"};
		InsertProducts(0x13cf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2282};
		char* mids[] = {"TechniSat DVB-PC TV Star 2"};
		InsertProducts(0x13d0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7019,0xabe6};
		char* mids[] = {"MD 82288","Wireless 802.11g 54Mbps Network Adapter [RTL8187]"};
		InsertProducts(0x13d1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0400};
		char* mids[] = {"Pocket Ethernet [klsi]"};
		InsertProducts(0x13d2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3201,0x3202,0x3203,0x3204,0x3205,0x3206,0x3207,0x3208,0x3209,0x3211,0x3212,0x3213,0x3214,0x3215,0x3216,0x3217,0x3219,0x3220,0x3223,0x3224,
		0x3226,0x3234,0x3236,0x3237,0x3239,0x3240,0x3241,0x3242,0x3243,0x3244,0x3247,0x3249,0x3262,0x3273,0x3274,0x3282,0x3284,0x3304,0x3306,0x3315,
		0x3375,0x3392,0x3394,0x5070,0x5111,0x5115,0x5116,0x5122,0x5126,0x5702,0x5710,0x5716,0x7020,0x7022};
		char* mids[] = {"VisionDTV USB-Ter/HAMA USB DVB-T device cold","VisionDTV USB-Ter/HAMA USB DVB-T device warm","DTV-DVB UDST7020BDA DVB-S Box(DVBS for MCE2005)","DTV-DVB UDST7020BDA DVB-S Box(DVBS for MCE2005)","DNTV Live! Tiny USB2 BDA (No Remote)",
		"DNTV Live! Tiny USB2 BDA (No Remote)","DTV-DVB UDST7020BDA DVB-S Box(DVBS for MCE2005)","DTV-DVB UDST7020BDA DVB-S Box(DVBS for MCE2005)","DTV-DVB UDST7022BDA DVB-S Box(Without HID)","DTV-DVB Hybrid Analog/Capture / Pinnacle PCTV 310e",
		"DTV-DVB UDTT704C - DVBT/NTSC/PAL Driver(PCM4)","DTV-DVB UDTT704D - DVBT/NTSC/PAL Driver (PCM4)","DTV-DVB UDTT704F -(MiniCard) DVBT/NTSC/PAL Driver(Without HID)","DTV-DVB UDAT7240 - ATSC/NTSC/PAL Driver(PCM4)","DTV-DVB UDTT 7047-USB 2.0 DVB-T Driver",
		"Digital-TV Receiver.","DTV-DVB UDTT7049 - DVB-T Driver(Without HID)","DTV-DVB UDTT 7047M-USB 2.0 DVB-T Driver","DNTV Live! Tiny USB2 BDA (No Remote)","DNTV Live! Tiny USB2 BDA (No Remote)",
		"DigitalNow TinyTwin DVB-T Receiver","DVB-T FTA Half Minicard [RTL2832U]","DTV-DVB UDTT 7047A-USB 2.0 DVB-T Driver","DTV-DVB UDTT 704J - dual DVB-T Driver","DTV-DVB UDTT704D - DVBT/NTSC/PAL Driver(Without HID)",
		"DTV-DVB UDXTTM6010 - A/D Driver(Without HID)","DTV-DVB UDXTTM6010 - A/D Driver(Without HID)","DTV-DVB UDAT7240LP - ATSC/NTSC/PAL Driver(Without HID)","DTV-DVB UDXTTM6010 - A/D Driver(Without HID)","DTV-DVB UDTT 7047Z-USB 2.0 DVB-T Driver",
		"802.11 n/g/b Wireless LAN Adapter","Internal Bluetooth","802.11 n/g/b Wireless LAN USB Adapter","802.11 n/g/b Wireless LAN USB Mini-Card","DVB-T Dongle [RTL2832U]",
		"DVB-T + GPS Minicard [RTL2832U]","Wireless LAN USB Mini-Card","Asus Integrated Bluetooth module [AR3011]","Mediao 802.11n WLAN [Realtek RTL8191SU]","Bluetooth module",
		"Atheros AR3012 Bluetooth 4.0 Adapter","Azurewave 43228+20702","Bluetooth","Webcam","Integrated Webcam",
		"Integrated Webcam","Integrated Webcam","2M Integrated Webcam","PC Cam","UVC VGA Webcam",
		"UVC VGA Webcam","UVC VGA Webcam","DTV-DVB UDST7020BDA DVB-S Box(DVBS for MCE2005)","DTV-DVB UDST7022BDA DVB-S Box(Without HID)"};
		InsertProducts(0x13d3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0003};
		char* mids[] = {"SL-1","TTM 57SL"};
		InsertProducts(0x13e5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"C-56 Thermal Printer"};
		InsertProducts(0x13ea, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0006};
		char* mids[] = {"HID Remote Control"};
		InsertProducts(0x13ec, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003};
		char* mids[] = {"Optical Mouse"};
		InsertProducts(0x13ee, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0840,0x0841,0x1040,0x1340,0x160f,0x1640,0x1669,0x1840,0x1e40};
		char* mids[] = {"INIC-1618L SATA","Samsung SE-T084M DVD-RW","INIC-1511L PATA Bridge","Hi-Speed USB to SATA Bridge","RocketFish SATA Bridge [INIC-1611]",
		"INIC-1610L SATA Bridge","INIC-1609PN","INIC-1608 SATA bridge","INIC-1610P SATA bridge"};
		InsertProducts(0x13fd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1a00,0x1a23,0x1d00,0x1e00,0x1e50,0x1f00,0x1f23,0x2240,0x3100,0x3123,0x3600,0x3800,0x3e00,0x5000,0x5100};
		char* mids[] = {"512MB/1GB Flash Drive","512MB Flash Drive","DataTraveler 2.0 1GB/4GB Flash Drive / Patriot Xporter 4GB Flash Drive","Flash Drive 2 GB [ICIDU 2 GB]","U3 Smart Drive",
		"Kingston DataTraveler / Patriot Xporter","PS2232 flash drive controller","microSD card reader","2/4 GB stick","Verbatim STORE N GO 4GB",
		"flash drive (4GB, EMTEC)","Rage XT Flash Drive","Flash Drive","USB flash drive (32 GB SHARKOON Accelerate)","Flash Drive"
		};
		InsertProducts(0x13fe, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Digital Photo Frame"};
		InsertProducts(0x1403, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x1485};
		char* mids[] = {"generic (firmware not loaded yet)","uEye UI1485"};
		InsertProducts(0x1409, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xb011,0xb021};
		char* mids[] = {"TCC780X-based player (USB Boot mode)","TCC77X-based players (USB Boot mode)"};
		InsertProducts(0x140e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1110,0x1120,0x1130,0x1400,0x1410,0x1430,0x1450,0x2110,0x2410,0x2420,0x4100,0x4400,0x9010,0xa001,0xa008,0xb001};
		char* mids[] = {"Merlin S620","Merlin EX720","Merlin S720","Merlin U730/U740 (Vodafone)","Merlin U740 (non-Vodafone)",
		"Merlin XU870","Merlin X950D","Ovation U720/MCD3000","Expedite EU740","Expedite EU850D/EU860D/EU870D",
		"U727","Ovation MC930D/MC950D","Expedite E362","Gobi Wireless Modem","Gobi Wireless Modem (QDL mode)",
		"Ovation MC551"};
		InsertProducts(0x1410, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0020,0x2000};
		char* mids[] = {"Sony SingStar USBMIC","Sony Wireless SingStar","Sony Playstation Eye"};
		InsertProducts(0x1415, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0605};
		char* mids[] = {"Sentech Camera"};
		InsertProducts(0x1421, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0005,0x0043};
		char* mids[] = {"Artema Hybrid","Artema Modular","medCompact"};
		InsertProducts(0x142a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x03a5};
		char* mids[] = {"933A Portable Power Sentinel"};
		InsertProducts(0x142b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0150,0x4734,0x474b};
		char* mids[] = {"wireless receiver for skylanders wii","Guitar Hero4 hub","Guitar Hero MIDI interface"};
		InsertProducts(0x1430, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0427,0x0711,0x0804,0x0826,0x0827,0x0828,0x0829};
		char* mids[] = {"UR054g 802.11g Wireless Adapter [Intersil ISL3887]","UR055G 802.11bg","AR9170+AR9104 802.11abgn Wireless Adapter","AR5523","AR5523 (no firmware)",
		"AR5523","AR5523 (no firmware)"};
		InsertProducts(0x1435, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0007};
		char* mids[] = {"Development board JTAG"};
		InsertProducts(0x1443, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6a73,0x6a78};
		char* mids[] = {"Stamps.com Model 510 5LB Scale","DYMO Endicia 75lb Digital Scale"};
		InsertProducts(0x1446, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4026};
		char* mids[] = {"26-183 Serial Cable"};
		InsertProducts(0x1453, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5117,0x5118,0x5119,0x511a,0x511b,0x511c,0x511d,0x5120,0x5121,0x5122,0x5123,0x5124};
		char* mids[] = {"OpenMoko Neo1973 kernel usbnet (g_ether, CDC Ethernet) mode","OpenMoko Neo1973 Debug board (V2+)","OpenMoko Neo1973 u-boot cdc_acm serial port","HXD8 u-boot usbtty CDC ACM Mode","SMDK2440 u-boot usbtty CDC ACM mode",
		"SMDK2443 u-boot usbtty CDC ACM mode","QT2410 u-boot usbtty CDC ACM mode","OpenMoko Neo1973 u-boot usbtty generic serial","OpenMoko Neo1973 kernel mass storage (g_storage) mode","OpenMoko Neo1973 / Neo Freerunner kernel cdc_ether USB network",
		"OpenMoko Neo1973 internal USB CSR4 module","OpenMoko Neo1973 Bluetooth Device ID service"};
		InsertProducts(0x1457, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0106,0x013d,0x013f,0x0142,0x015a,0x0161,0x0167,0x0176};
		char* mids[] = {"Trust K56 V92 USB Modem","PC Camera (SN9C201 + OV7660)","Megapixel Auto Focus Webcam","WB-6250X Webcam","WB-8300X 2MP Webcam",
		"15901 802.11bg Wireless Adapter [Realtek RTL8187L]","Widescreen 3MP Webcam","Isla Keyboard"};
		InsertProducts(0x145f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x9150};
		char* mids[] = {"eHome Infrared Transceiver"};
		InsertProducts(0x1460, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5512,0x8807};
		char* mids[] = {"MegaStick-1 Flash Stick","DIGIVOX mini III [af9015]"};
		InsertProducts(0x1462, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0007,0x0009};
		char* mids[] = {"Aolynk WUB300g [ZyDAS ZD1211]","Aolynk WUB320g"};
		InsertProducts(0x1472, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xe015,0xe016,0xe017,0xe018,0xe02c,0xe03a,0xe03c,0xe03d,0xe03e};
		char* mids[] = {"eHome Infrared Receiver","eHome Infrared Receiver","eHome Infrared Receiver","eHome Infrared Receiver","Infrared Receiver",
		"eHome Infrared Receiver","eHome Infrared Receiver","2 Channel Audio","Infrared Receiver [IR605A/Q]"};
		InsertProducts(0x147a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x1001,0x1002,0x2016,0x2020,0x3000,0x3001};
		char* mids[] = {"Biometric Touchchip/Touchstrip Fingerprint Sensor","TCS5B Fingerprint sensor","Biometric Touchchip/Touchstrip Fingerprint Sensor","Biometric Touchchip/Touchstrip Fingerprint Sensor","TouchChip Fingerprint Coprocessor (WBF advanced mode)",
		"TCS1C EIM/Cypress Fingerprint sensor","TCS1C EIM/STM32 Fingerprint sensor"};
		InsertProducts(0x147e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1005};
		char* mids[] = {"VRD PC-Interface"};
		InsertProducts(0x1482, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1746,0x7616};
		char* mids[] = {"Ecomo 19H99 Monitor","Elsa Hub"};
		InsertProducts(0x1484, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"U2E","Psion Gold Port Ethernet"};
		InsertProducts(0x1485, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x1706,0x2070,0x2570,0x2573,0x2671,0x2770,0x2870,0x3070,0x3071,0x3072,0x3370,0x3572,0x3573,0x5370,0x5372,0x5572,0x7601,0x9020,0x9021
		};
		char* mids[] = {"Motorola BC4 Bluetooth 3.0+HS Adapter","RT2500USB Wireless Adapter","RT2070 Wireless Adapter","RT2570 Wireless Adapter","RT2501/RT2573 Wireless Adapter",
		"RT2601/RT2671 Wireless Adapter","RT2770 Wireless Adapter","RT2870 Wireless Adapter","RT2870/RT3070 Wireless Adapter","RT3071 Wireless Adapter",
		"RT3072 Wireless Adapter","RT3370 Wireless Adapter","RT3572 Wireless Adapter","RT3573 Wireless Adapter","RT5370 Wireless Adapter",
		"RT5372 Wireless Adapter","RT5572 Wireless Adapter","MT7601U Wireless Adapter","RT2500USB Wireless Adapter","RT2501USB Wireless Adapter"
		};
		InsertProducts(0x148f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0020};
		char* mids[] = {"FS81 Fingerprint Scanner Module"};
		InsertProducts(0x1491, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010,0x0019,0x001a};
		char* mids[] = {"Bluebird [Ambit]","Duck [Ambit2]","Colibri [Ambit2 S]"};
		InsertProducts(0x1493, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa090};
		char* mids[] = {"DVB-T Tuner"};
		InsertProducts(0x1498, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2107};
		char* mids[] = {"DBX1 DSP core"};
		InsertProducts(0x149a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0201,0x0221,0x022b,0x0301};
		char* mids[] = {"Avermedia AverTV DVBT USB1.1 (cold)","Avermedia AverTV DVBT USB1.1 (warm)","AVermedia/Yakumo/Hama/Typhoon DVB-T USB2.0 (cold)","WT-220U DVB-T dongle","WT-220U DVB-T dongle",
		"AVermedia/Yakumo/Hama/Typhoon DVB-T USB2.0 (warm)"};
		InsertProducts(0x14aa, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3a93,0x3a95,0x3a98,0x3c02,0x3c05,0x3c06,0x3c07,0x3c09,0x3c22,0x3c23,0x3c24,0x3c25,0x3c27,0x3c28,0x3c2b,0x3c2c};
		char* mids[] = {"Topcom 802.11bg Wireless Adapter [Atheros AR5523]","Toshiba WUS-G06G-JT 802.11bg Wireless Adapter [Atheros AR5523]","Airlink101 AWLL4130 802.11bg Wireless Adapter [Atheros AR5523]","Conceptronic C54RU v2 802.11bg Wireless Adapter [Ralink RT2571]","rt2570 802.11g WLAN",
		"Conceptronic C300RU v1 802.11bgn Wireless Adapter [Ralink RT2870]","802.11n adapter","802.11n adapter","Conceptronic C54RU v3 802.11bg Wireless Adapter [Ralink RT2571W]","Airlink101 AWLL6080 802.11bgn Wireless Adapter [Ralink RT2870]",
		"NEC NP01LM 802.11abg Wireless Adapter [Ralink RT2571W]","DrayTek Vigor N61 802.11bgn Wireless Adapter [Ralink RT2870]","Airlink101 AWLL6070 802.11bgn Wireless Adapter [Ralink RT2770]","Conceptronic C300RU v2 802.11bgn Wireless Adapter [Ralink RT2770]","NEC NP02LM 802.11bgn Wireless Adapter [Ralink RT3072]",
		"Keebox W150NU 802.11bgn Wireless Adapter [Ralink RT3070]"};
		InsertProducts(0x14b2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0250,0x0350};
		char* mids[] = {"Storage Adapter V2","Storage Adapter V2"};
		InsertProducts(0x14c2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x121c,0x121f,0x123a,0x125c,0x127b,0x6116,0x6600,0x6700,0x6900,0x8123,0x8125};
		char* mids[] = {"microSD card reader","microSD CardReader SY-T18","SD/MMC/RS-MMC Card Reader","SD card reader","SDXC Reader",
		"M6116 SATA Bridge","M110E PATA bridge","Card Reader","Card Reader","SD MMC Reader",
		"SD MMC Reader"};
		InsertProducts(0x14cd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1007};
		char* mids[] = {"D2CIM-VUSB KVM connector"};
		InsertProducts(0x14dd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0501};
		char* mids[] = {"WR-G528e 'CHEETAH'"};
		InsertProducts(0x14e0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5000};
		char* mids[] = {"PenMount 5000 Touch Controller"};
		InsertProducts(0x14e1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xab10,0xab11,0xab13};
		char* mids[] = {"GW-US54GZ","GU-1000T","GW-US54Mini 802.11bg"};
		InsertProducts(0x14ea, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x29b6};
		char* mids[] = {"X2u Adapter"};
		InsertProducts(0x14ed, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0500};
		char* mids[] = {"SkyStar 2 HD CI","SkyStar 2 HD CI","CableStar Combo HD CI","AirStar TeleStick 2","DVB-PC TV Star HD"
		};
		InsertProducts(0x14f7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0a01,0x0a02,0x0a03,0x9242};
		char* mids[] = {"LI-3100 Area Meter","LI-7000 CO2/H2O Gas Analyzer","C-DiGit Blot Scanner","eHome Infrared Transceiver"};
		InsertProducts(0x1509, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0444};
		char* mids[] = {"medMobile"};
		InsertProducts(0x1513, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2003,0x2004,0x2005};
		char* mids[] = {"FlashPro3 Programmer","FlashPro3 Programmer","FlashPro3 Programmer"};
		InsertProducts(0x1514, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1603,0x8628};
		char* mids[] = {"Flash Drive","Pen Drive"};
		InsertProducts(0x1516, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"HDReye High Dynamic Range Camera","HDReye (before firmware loads)"};
		InsertProducts(0x1518, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0020};
		char* mids[] = {"HSIC Device"};
		InsertProducts(0x1519, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6680};
		char* mids[] = {"UTS 6680"};
		InsertProducts(0x1524, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0200,0x0201};
		char* mids[] = {"YAP Phone (no firmware)","YAP Phone"};
		InsertProducts(0x1527, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3100};
		char* mids[] = {"CDMA 1xRTT USB Modem (U-100/105/200/300/520)"};
		InsertProducts(0x1529, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8400,0x840d,0x841a};
		char* mids[] = {"INI DVS128","INI DAViS","INI DAViS FX3"};
		InsertProducts(0x152a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0539,0x0770,0x2329,0x2335,0x2336,0x2337,0x2338,0x2339,0x2352,0x2509};
		char* mids[] = {"JMS539 SuperSpeed SATA II 3.0G Bridge","Alienware Integrated Webcam","JM20329 SATA Bridge","ATA/ATAPI Bridge","Hard Disk Drive",
		"ATA/ATAPI Bridge","JM20337 Hi-Speed USB to SATA & PATA Combo Bridge","JM20339 SATA Bridge","ATA/ATAPI Bridge","JMS539 SuperSpeed SATA II 3.0G Bridge"
		};
		InsertProducts(0x152d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2507,0xe001};
		char* mids[] = {"PL-2507 IDE Controller","GSA-5120D DVD-RW"};
		InsertProducts(0x152e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0003,0x0007,0x0013,0x0015,0x0016,0x0017,0x001c,0x0024,0x002e,0x0036,0x0101,0x0102,0x0109,0x0113,0x0300};
		char* mids[] = {"RZ01-020300 Optical Mouse [Diamondback]","Krait Mouse","DeathAdder Mouse","Orochi mouse","Naga Mouse",
		"DeathAdder Mouse","RZ01-0035 Laser Gaming Mouse [Imperator]","RZ01-0036 Optical Gaming Mouse [Abyssus]","Razer Mamba","RZ01-0058 Gaming Mouse [Naga]",
		"RZ01-0075, Gaming Mouse [Naga Hex]","Copperhead Mouse","Tarantula Keyboard","Lycosa Keyboard","RZ07-0074 Gaming Keypad [Orbweaver]",
		"RZ06-0063 Motion Sensing Controllers [Hydra]"};
		InsertProducts(0x1532, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1181,0x1182};
		char* mids[] = {"Cinergy S2 PCIe Dual Port 1","Cinergy S2 PCIe Dual Port 2"};
		InsertProducts(0x153b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000};
		char* mids[] = {"SG-Lock[U2]"};
		InsertProducts(0x1547, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8180};
		char* mids[] = {"CARD STAR/medic2"};
		InsertProducts(0x154a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010,0x0048,0x004d,0x0057,0x007a,0x6545};
		char* mids[] = {"USB 2.0 Flash Drive","Flash Drive","8 GB Flash Drive","32GB Micro Slide Attache Flash Drive","8GB Classic Attache Flash Drive",
		"FD Device"};
		InsertProducts(0x154b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3000};
		char* mids[] = {"Marantz RC9001 Remote Control"};
		InsertProducts(0x154e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5010};
		char* mids[] = {"PV-D231U(RN)-F [PixelView PlayTV SBTVD Full-Seg]"};
		InsertProducts(0x1554, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0003,0x0a80,0x7720,0x8150};
		char* mids[] = {"model 01 WiFi interface","model 01 Bluetooth interface","Gobi Wireless Modem (QDL mode)","model 01+ Ethernet","model 01 Ethernet interface"
		};
		InsertProducts(0x1557, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3006,0x3007,0x300a,0x300b,0x300c,0x300d,0x300e,0x3012,0x3013,0x3204,0x3205,0x3206,0x3207,0x3208};
		char* mids[] = {"TEW-444UB EU [TRENDnet]","TEW-444UB EU (no firmware)","TEW-429UB 802.11bg","TEW-429UB 802.11bg","TEW-429UF A1 802.11bg Wireless Adapter [ZyDAS ZD1211B]",
		"TEW-429UB C1 802.11bg","SMC SMCWUSB-N 802.11bgn 2x2:2 Wireless Adapter [Ralink RT2870]","TEW-604UB 802.11bg Wireless Adapter [Atheros AR5523]","TEW-645UB 802.11bgn 1x2:2 Wireless Adapter [Ralink RT2770]","Allnet ALL0298 v2 802.11bg",
		"Allnet ALL0283 [AR5523]","Allnet ALL0283 [AR5523](no firmware)","TEW-509UB A1 802.11abg Wireless Adapter [ZyDAS ZD1211]","TEW-509UB 1.1R 802.11abg Wireless Adapter"};
		InsertProducts(0x157e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6003};
		char* mids[] = {"WL-430U 802.11bg"};
		InsertProducts(0x1582, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0820};
		char* mids[] = {"SmartPocket Class Device"};
		InsertProducts(0x158e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0038,0x003b,0x0042,0x004f,0x0052,0x0054,0x0061};
		char* mids[] = {"9S08JS Bootloader","USB2CAN Application for ColdFire DEMOJM board","OSBDM - Debug Port","i.MX28 SystemOnChip in RecoveryMode","i.MX50 SystemOnChip in RecoveryMode",
		"i.MX 6Dual/6Quad SystemOnChip in RecoveryMode","i.MX 6Solo/6DualLite SystemOnChip in RecoveryMode"};
		InsertProducts(0x15a2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x1001,0x1336,0x9015,0x9016};
		char* mids[] = {"AF9015/AF9035 DVB-T stick","AF9015/AF9035 DVB-T stick","SDHC/MicroSD/MMC/MS/M2/CF/XD Flash Card Reader","AF9015 DVB-T USB2.0 stick","AF9015 DVB-T USB2.0 stick"
		};
		InsertProducts(0x15a4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0004,0x0006,0x0010,0x0012};
		char* mids[] = {"SparkLAN WL-682 802.11bg Wireless Adapter [Intersil ISL3887]","WUBR-177G [Ralink RT2571W]","Wireless 11n USB Adapter","802.11n USB Wireless Card","WUBR-208N 802.11abgn Wireless Adapter [Ralink RT2870]"
		};
		InsertProducts(0x15a9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0004,0x002a,0x002b};
		char* mids[] = {"OpenOCD JTAG","OpenOCD JTAG TINY","ARM-USB-TINY-H JTAG interface","ARM-USB-OCD-H JTAG+RS232"};
		InsertProducts(0x15ba, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0009,0x000a,0x0010,0x0101};
		char* mids[] = {"2M pixel Microscope Camera","3M pixel Microscope Camera","1.3M pixel Microscope Camera (mono)","1.3M pixel Microscope Camera (colour)","3M pixel Microscope Camera (Mk 2)",
		"2M pixel Microscope Camera (with capture button)","3M pixel Microscope Camera (with capture button)","1.3M pixel Microscope Camera (colour, with capture button)","1.3M pixel Microscope Camera (colour, with capture button)","2M pixel Microscope Camera (Mk 2)",
		"1.3M pixel \"Tinycam\"","3M pixel Microscope Camera"};
		InsertProducts(0x15c0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0036,0x0038,0x0042,0xffda,0xffdc};
		char* mids[] = {"LC16M VFD Display/IR Receiver","GD01 MX LCD Display/IR Receiver","Antec Veris Multimedia Station E-Z IR Receiver","iMON PAD Remote Controller","iMON PAD Remote Controller"
		};
		InsertProducts(0x15c2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0008};
		char* mids[] = {"WL532U 802.11g Adapter"};
		InsertProducts(0x15c5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x1001,0x1002,0x1003,0x1004,0x1005,0x1100,0x1101,0x1200};
		char* mids[] = {"DigistimSP (cold)","DigistimSP (warm)","DigimapSP USB (cold)","DigimapSP USB (warm)","DigistimSP (cold)",
		"DigistimSP (warm)","Odyssee (cold)","Odyssee (warm)","Digispy"};
		InsertProducts(0x15c6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3201};
		char* mids[] = {"EVER EV-W100/EV-W250"};
		InsertProducts(0x15c8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00c3,0x0101,0x1806};
		char* mids[] = {"Mini Optical Mouse","MIDI Interface cable","MIDI Interface cable"};
		InsertProducts(0x15ca, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0a33,0x0a37,0x0a41,0x0a4c,0x0a4d,0x0a4f};
		char* mids[] = {"Optical Mouse","Mouse","MI-2540D [Optical mouse]","USB+PS/2 Optical Mouse","Optical Mouse",
		"Optical Mouse"};
		InsertProducts(0x15d9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2007};
		char* mids[] = {"RSA SecurID (R) Authenticator"};
		InsertProducts(0x15e1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0024,0x0140};
		char* mids[] = {"Mixtrack","ION VCR 2 PC / Video 2 PC"};
		InsertProducts(0x15e4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x9100,0x9110};
		char* mids[] = {"NUB100 Ethernet [pegasus]","10/100 USB Ethernet"};
		InsertProducts(0x15e8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x04ce,0x1968,0x1969};
		char* mids[] = {"MemoryFrame MF-570","MemoryFrame MF-570","Digital Frame"};
		InsertProducts(0x15e9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0025};
		char* mids[] = {"HanfTek UMT-010 USB2.0 DVB-T (cold)","HanfTek UMT-010 USB2.0 DVB-T (warm)"};
		InsertProducts(0x15f4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8000,0x8001,0x8004,0x8005,0x8006,0x8007};
		char* mids[] = {"US-428 Audio/Midi Controller (without fw)","US-428 Audio/Midi Controller","US-224 Audio/Midi Controller (without fw)","US-224 Audio/Midi Controller","US-122 Audio/Midi Interface (without fw)",
		"US-122 Audio/Midi Interface"};
		InsertProducts(0x1604, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0010,0x0030,0x0050,0x0060,0x0070,0x0130,0x0160,0x0170,0x0230,0x0350,0x1030,0x1220,0x2010,0x2020,0x2030};
		char* mids[] = {"Astra 1236U Scanner","Astra 1220U","Astra 1600U/2000U","Scanner","Astra 3400/3450",
		"Astra 4400/4450","Astra 2100U","Astra 5400U","Uniscan D50","Astra 2200/2200SU",
		"Astra 4800/4850 Scanner","Astra 4000U","Genesys Logic Scanner Controller NT5.0","AstraCam Digital Camera","AstraCam 1000",
		"AstraCam 1800 Digital Camera"};
		InsertProducts(0x1606, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x000c,0x000d,0x000e,0x000f,0x0010,0x0011,0x0012,0x0014,0x0018,0x0019,0x001a,0x0101,
		0x0105,0x0106,0x0107,0x010c,0x010d,0x0110,0x0111,0x0112,0x0114,0x0201,0x0203,0x0204,0x0205,0x0206,0x0207,0x020c,0x020d,0x020e,0x020f,0x0210,
		0x0211,0x0212,0x0214,0x0215,0x0216,0x0217,0x021a,0x021b,0x021c,0x021d,0x021e,0x021f,0x0240,0x0241,0x0242,0x0243,0x0244,0x0245,0x0301,0x0302,
		0x0303,0x0304,0x0305,0x0306,0x0307,0x0308,0x0309,0x030a,0x030b,0x030c,0x030e,0x030f,0x0310,0x0311,0x1403,0x1a17};
		char* mids[] = {"EdgePort/4 Serial Port","Edgeport/8","Rapidport/4","Edgeport/4","Edgeport/2",
		"Edgeport/4i","Edgeport/2i","Edgeport/8","Edgeport/421","Edgeport/21",
		"Edgeport/4","Edgeport/8","Edgeport/2","Edgeport/4","Edgeport/416",
		"Edgeport/8i","Edgeport/412","Edgeport/412","Edgeport/2+2i","Edgeport/4",
		"Edgeport/2","Edgeport/4i","Edgeport/2i","Edgeport/421","Edgeport/21",
		"Edgeport/2","Edgeport/4","Edgeport/416","Edgeport/8i","Edgeport/4",
		"Rapidport/4","Edgeport/4","Edgeport/2","Edgeport/4i","Edgeport/2i",
		"Edgeport/421","Edgeport/21","Edgeport/4","Edgeport/8","Edgeport/2",
		"Edgeport/4","Edgeport/416","Edgeport/8i","Edgeport/1","EPOS/44",
		"Edgeport/42","Edgeport/2+2i","Edgeport/2c","Edgeport/221c","Edgeport/22c",
		"Edgeport/21c","Edgeport/62","Edgeport/1","Edgeport/1i","Edgeport/4s",
		"Edgeport/8s","Edgeport/8","Edgeport/22c","Watchport/P","Watchport/M",
		"Watchport/W","Watchport/T","Watchport/H","Watchport/E","Watchport/L",
		"Watchport/R","Watchport/A","Watchport/D","Watchport/D","Power Management Port",
		"Power Management Port","Watchport/G","Watchport/Tc","Watchport/Hc","MultiTech Systems MT4X56 Modem",
		"Agilent Technologies (E6473)"};
		InsertProducts(0x1608, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3184};
		char* mids[] = {"VIA VNT-6656 [WiFi 802.11b/g USB Dongle]"};
		InsertProducts(0x160a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"E2USBKey"};
		InsertProducts(0x160e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0404,0x0600,0x0804};
		char* mids[] = {"WMA9109 UMTS Phone","Vodafone VDA GPS / Toschiba Protege G710","WP-S1 Phone"};
		InsertProducts(0x1614, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005,0x0011,0xff81};
		char* mids[] = {"802.11g Wireless Adapter [Intersil ISL3886]","PC Port 10 Mps Adapter","802.11b Wireless Adapter [Lucent/Agere Hermes I]"};
		InsertProducts(0x1630, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6200,0xc019};
		char* mids[] = {"GWUSB2E","RT2573"};
		InsertProducts(0x1631, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0016,0x0080,0x0081,0x0093,0x8000,0x8001,0x8002,0x8003,0x8004,0x8005,0x8080,0x8081,
		0x8093};
		char* mids[] = {"1S Serial Port","2S Serial Port","1S25 Serial Port","4S Serial Port","E45 Ethernet [klsi]",
		"Parallel Port","U1-SC25 SCSI","Ethernet","Bi-directional to Parallel Printer Converter","1 port to Serial Converter",
		"1 port to Serial Converter","1S9 Serial Port","EZ-USB","1 port to Serial","2x Serial Port",
		"1 port to Serial","2U4S serial/usb hub","Ethernet","1 port to Serial","1 port to Serial",
		"PortGear Serial Port"};
		InsertProducts(0x1645, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0102,0x0200};
		char* mids[] = {"uDART In-Circuit Debugger","SpYder USBSPYDER08"};
		InsertProducts(0x1649, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0103,0x0201,0x0203};
		char* mids[] = {"mvBlueFOX camera (no firmware)","mvBlueFOX camera","mvBlueLYNX-X intelligent camera (bootloader)","mvBlueLYNX-X intelligent camera"};
		InsertProducts(0x164c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3150};
		char* mids[] = {"SIS3150 USB2.0 to VME interface"};
		InsertProducts(0x1657, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8101,0xfad1};
		char* mids[] = {"Tranzport Control Surface","Alphatrack Control Surface"};
		InsertProducts(0x165b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"Serial Adapter"};
		InsertProducts(0x165c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0009,0x0333,0x0358,0x0405,0x0408,0x0413,0x0421,0x0441,0x0500,0x1050,0x1200,0x1441,0x2441,0x3441,0x6010,0x6097,0x6106,0x7605};
		char* mids[] = {"Gateway","Modem","InternetPhoneWizard","Gateway","Prism2.5 802.11b Adapter",
		"Gateway","Prism2.5 802.11b Adapter","IBM Integrated Bluetooth II","BTM200B BlueTooth Adapter","802UIG-1 802.11g Wireless Mini Adapter [Intersil ISL3887]",
		"802AIN Wireless N Network Adapter [Atheros AR9170+AR9101]","IBM Integrated Bluetooth II","BMDC-2 IBM Bluetooth III w.56k","IBM Integrated Bluetooth III","Gateway",
		"802.11b Wireless Adapter","802UI3(B) 802.11b Wireless Adapter [Intersil PRISM 3]","UAT1 Wireless Ethernet Adapter"};
		InsertProducts(0x1668, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001};
		char* mids[] = {"uLan2USB Converter - PS1 protocol"};
		InsertProducts(0x1669, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0201,0x0301,0x0303,0x0304,0x0305,0x0401};
		char* mids[] = {"C-Bus Multi-room Audio Matrix Switcher","C-Bus Pascal Automation Controller","C-Bus Wireless PC Interface","C-Bus interface","C-Bus Black and White Touchscreen",
		"C-Bus Spectrum Colour Touchscreen","C-Bus Architectural Dimmer"};
		InsertProducts(0x166a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0103};
		char* mids[] = {"Token"};
		InsertProducts(0x1677, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2001,0x2002};
		char* mids[] = {"Beagle Protocol Analyzer","Cheetah SPI Host Adapter"};
		InsertProducts(0x1679, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa332};
		char* mids[] = {"DVB-T Dongle [RTL2832U]"};
		InsertProducts(0x1680, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"Tuner's Dashboard","Tubachron"};
		InsertProducts(0x1681, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0200};
		char* mids[] = {"Infrared adapter"};
		InsertProducts(0x1685, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0045};
		char* mids[] = {"H4 Digital Recorder"};
		InsertProducts(0x1686, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5289,0x6211};
		char* mids[] = {"FlashDisk","FlashDisk"};
		InsertProducts(0x1687, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xfd00};
		char* mids[] = {"Onza Tournament Edition controller"};
		InsertProducts(0x1689, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"AR5523","AR5523 (no firmware)"};
		InsertProducts(0x168c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0101,0x0102,0x0103,0x0104,0x0107,0x0109,0x0203,0x0204,0x0205,0x0206,0x0208,0x0209,0x0211,0x0212,0x0213,0x0214,0x0215,0x0701,0x0710,
		0x0711,0x0712,0x0713,0x0715,0x0722,0x0726,0x0740,0x0901,0x2000,0x2001,0xfe12};
		char* mids[] = {"Arcaze Gamepad","Creative Modem Blaster DE5670","V1456 VQE-R2 Modem [conexant]","1456 VQE-R3 Modem [conexant]","HCF V90 Data Fax RTAD Modem",
		"HCF V.90 Data,Fax,RTAD Modem","MagicXpress V.90 Pocket Modem [conexant]","Voyager ADSL Modem Loader","Voyager ADSL Modem","DSL Modem",
		"GlobeSpan ADSL WAN Modem","DSL Modem","Voyager 100 ADSL Modem","Globespan Virata ADSL LAN Modem","DSL Modem",
		"HM121d DSL Modem","HM121d DSL Modem","Voyager 105 ADSL Modem","WLAN","SMCWUSBT-G",
		"SMCWUSBT-G (no firmware)","AR5523","AR5523 (no firmware)","Name: Voyager 1055 Laptop 802.11g Adapter [Broadcom 4320]","RT2573",
		"Wi-Fi Wireless LAN Adapter","802.11n Wireless LAN Card","Voyager 205 ADSL Router","naturaSign Pad Standard","naturaSign Pad Standard",
		"Bootloader"};
		InsertProducts(0x1690, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3000,0x4000,0x5000,0x5001};
		char* mids[] = {"VTG-3xxx Video Test Generator family","VTG-4xxx Video Test Generator family","VTG-5xxx Video Test Generator family","VTG-5xxx Special (update) mode of VTG-5xxx family"};
		InsertProducts(0x16a6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7801,0x7802,0x7811,0x7812};
		char* mids[] = {"AR5523","AR5523 (no firmware)","AR5523","AR5523 (no firmware)"};
		InsertProducts(0x16ab, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0801};
		char* mids[] = {"U43"};
		InsertProducts(0x16b4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"Otto driving companion"};
		InsertProducts(0x16b5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x03e8,0x03e9,0x03ea,0x03eb,0x03ec,0x03ed,0x03ee,0x03ef,0x03f0,0x03f1,0x0477,0x0478,0x0479,0x047a,0x047b,0x047c,0x047d,0x047e,0x047f,0x0480,
		0x0481,0x0482,0x0483,0x0484,0x0485,0x0486,0x0487,0x0488,0x05dc,0x05dd,0x05df,0x05e1,0x05e4,0x06b4,0x06b5,0x0762,0x076b,0x076c,0x08ac,0x08ca,
		0x08cb,0x08cc,0x08cd,0x0a32,0x27d8,0x27d9,0x27da,0x27db,0x27dc,0x27dd,0x27de,0x294a,0x294b};
		char* mids[] = {"free for internal lab use 1000","free for internal lab use 1001","free for internal lab use 1002","free for internal lab use 1003","free for internal lab use 1004",
		"free for internal lab use 1005","free for internal lab use 1006","free for internal lab use 1007","free for internal lab use 1008","free for internal lab use 1009",
		"Teensy Rebootor","Teensy Halfkay Bootloader","Teensy Debug","Teensy Serial","Teensy Serial+Debug",
		"Teensy Keyboard","Teensy Keyboard+Debug","Teensy Mouse","Teensy Mouse+Debug","Teensy RawHID",
		"Teensy RawHID+Debug","Teensyduino Keyboard+Mouse+Joystick","Teensyduino Serial","Teensyduino Disk","Teensyduino MIDI",
		"Teensyduino RawHID","Teensyduino Serial+Keyboard+Mouse+Joystick","Teensyduino Flight Sim Controls","shared ID for use with libusb","BlackcatUSB2",
		"HID device except mice, keyboards, and joysticks","Free shared USB VID/PID pair for CDC devices","Free shared USB VID/PID pair for MIDI devices","USB2LPT with 2 interfaces","USB2LPT with 3 interfaces (native, HID, printer)",
		"Osmocom SIMtrace","OpenPCD 13.56MHz RFID Reader","OpenPICC 13.56MHz RFID Simulator (native)","OpenBeacon USB stick","Alpermann+Velte Universal Display",
		"Alpermann+Velte Studio Clock","Alpermann+Velte SAM7S MT Boot Loader","Alpermann+Velte SAM7X MT Boot Loader","jbmedia Light-Manager Pro","libusb-bound devices",
		"HID device except mice, keyboards, and joysticks","Mouse","Keyboard","Joystick","CDC-ACM class devices (modems)",
		"MIDI class devices","Eye Movement Recorder [Visagraph]","Eye Movement Recorder [ReadAlyzer]"};
		InsertProducts(0x16c0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1502};
		char* mids[] = {"Bluetooth Dongle"};
		InsertProducts(0x16ca, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0498,0x0504,0x054b,0x05be,0x06f9,0x0753,0x075c,0x075d,0x080a,0x0870};
		char* mids[] = {"Braintechnology USB-LPS","RETRO Innovations ZoomFloppy","GrauTec ReelBox OLED Display (external)","EasyLogic Board","Gabotronics Xminilab",
		"Digistump DigiSpark","AB-1.x UAC1 [Audio Widget]","AB-1.x UAC2 [Audio Widget]","S2E1 Interface","Kaufmann Automotive GmbH, RKS+CAN Interface"
		};
		InsertProducts(0x16d0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0401};
		char* mids[] = {"SUP-SFR400(A) BioMini Fingerprint Reader"};
		InsertProducts(0x16d1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6202,0x6501,0x6502,0x6603};
		char* mids[] = {"CDMA/UMTS/GPRS modem","CDMA 2000 1xRTT/EV-DO Modem","CDMA/UMTS/GPRS modem","ADU-890WH modem"};
		InsertProducts(0x16d5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8000,0x8001,0x8003,0x8004,0x8005,0x8007};
		char* mids[] = {"GDP-04 desktop phone","EYE-02","GDP-04 modem","Bootloader","GDP-04i",
		"BTP-06 modem"};
		InsertProducts(0x16d6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5141,0x5533,0x5543,0x6280,0x6803,0x8001,0x8002};
		char* mids[] = {"CMOTECH CDMA Technologies modem","CCU-550 CDMA EV-DO modem","CDMA 2000 1xRTT/1xEVDO modem","CMOTECH CDMA Technologies modem","CNU-680 CDMA EV-DO modem",
		"Gobi 2000 Wireless Modem (QDL mode)","Gobi 2000 Wireless Modem"};
		InsertProducts(0x16d8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x000b,0x0010,0x0011,0x0012,0x0015};
		char* mids[] = {"CC","VM","PL512 Power Supply System","MARATON Power Supply System","MPOD Multi Channel Power Supply System",
		"CML Control, Measurement and Data Logging System"};
		InsertProducts(0x16dc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0003};
		char* mids[] = {"Speedlink Programming Interface","Airlink Wireless Programming Interface"};
		InsertProducts(0x16f0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0011};
		char* mids[] = {"MIDI-USB 1x1"};
		InsertProducts(0x170b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3020};
		char* mids[] = {"IC80 HD Camera"};
		InsertProducts(0x1711, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0115};
		char* mids[] = {"PAXcam5"};
		InsertProducts(0x1724, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x2000,0x3000};
		char* mids[] = {"wireless modem","wireless modem","wireless modem"};
		InsertProducts(0x1726, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0022,0x0024,0x0025,0x0026,0x0031,0x0032,0x0034,0x0038,0x0500,0x0501,0x0502};
		char* mids[] = {"Tablet","Tablet","Tablet","Tablet","Slim Tablet 12.1\"",
		"Slim Tablet 5.8\"","Slim Tablet 12.1\"","Genius G-Pen F509","Media Tablet 14.1\"","Media Tablet 10.6\"",
		"Sirius Battery Free Tablet"};
		InsertProducts(0x172f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"RF Wireless Optical Mouse OP-701"};
		InsertProducts(0x1733, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0039,0x0070,0x0071,0x0073,0x0075,0x0077,0x0078,0x0079};
		char* mids[] = {"USB1000 Gigabit Notebook Adapter","WUSB100 v1 RangePlus Wireless Network Adapter [Ralink RT2870]","WUSB600N v1 Dual-Band Wireless-N Network Adapter [Ralink RT2870]","WUSB54GC v2 802.11g Adapter [Realtek RTL8187B]","WUSB54GSC v2 802.11g Adapter [Broadcom 4326U]",
		"WUSB54GC v3 802.11g Adapter [Ralink RT2070L]","WUSB100 v2 RangePlus Wireless Network Adapter [Ralink RT3070]","WUSB600N v2 Dual-Band Wireless-N Network Adapter [Ralink RT3572]"};
		InsertProducts(0x1737, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"GP-K7000 keyboard"};
		InsertProducts(0x173d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0600,0x0605,0x0615,0x1000,0x2000,0x3701,0x9603,0x9701,0x9702,0x9703,0x9705,0x9706,0x9801};
		char* mids[] = {"EUB1200AC AC1200 DB Wireless Adapter [Realtek RTL8812AU]","EUB600v1 802.11abgn Wireless Adapter [Ralink RT3572]","LevelOne WUA-0605 N_Max Wireless USB Adapter","LevelOne WUA-0615 N_Max Wireless USB Adapter","NUB-350 802.11g Wireless Adapter [Intersil ISL3887]",
		"NUB-8301 802.11bg","EUB-3701 EXT 802.11g Wireless Adapter [Ralink RT2571W]","RTL8188S WLAN Adapter","EnGenius 802.11n Wireless USB Adapter","EnGenius 802.11n Wireless USB Adapter",
		"EnGenius 802.11n Wireless USB Adapter","EnGenius 802.11n Wireless USB Adapter","EUB9706 802.11n Wireless Adapter [Ralink RT3072]","EUB9801 802.11abgn Wireless Adapter [Ralink RT3572]"};
		InsertProducts(0x1740, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101};
		char* mids[] = {"Packet-Master USB12"};
		InsertProducts(0x1748, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5106,0x5136,0x55aa};
		char* mids[] = {"Transcend StoreJet 25M3","ASM1053 SATA 6Gb/s bridge","ASM1051 SATA 3Gb/s bridge"};
		InsertProducts(0x174c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1105,0x110b,0x1403,0x1404,0x5212,0x5a11,0x5a31,0x5a35,0x6a31,0x6a33,0x6a51,0x6a54,0x6d51,0x8a12,0x8a33,0xa311,0xa312,0xa821,0xaa11};
		char* mids[] = {"SM-MS/Pro-MMC-XD Card Reader","HP Webcam","Integrated Webcam","USB Camera device, 1.3 MPixel Web Cam","USB 2.0 UVC PC Camera",
		"PC Camera","Sonix USB 2.0 Camera","Sonix 1.3MPixel USB 2.0 Camera","Web Cam - Asus A8J, F3S, F5R, VX2S, V1S","Web Cam - Asus F3SA, F9J, F9S",
		"2.0MPixel Web Cam - Asus Z96J, Z96S, S96S","Web Cam","2.0Mpixel Web Cam - Eurocom D900C","Syntek 0.3MPixel USB 2.0 UVC PC Camera","Syntek USB 2.0 UVC PC Camera",
		"1.3MPixel Web Cam - Asus A3A, A6J, A6K, A6M, A6R, A6T, A6V, A7T, A7sv, A7U","1.3MPixel Web Cam","Web Cam - Packard Bell BU45, PB Easynote MX66-208W","Web Cam"};
		InsertProducts(0x174f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xc901};
		char* mids[] = {"PPC900 Pinpad Terminal"};
		InsertProducts(0x1753, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0006};
		char* mids[] = {"DiviPitch"};
		InsertProducts(0x1756, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0b05};
		char* mids[] = {"802.11n Network Adapter (wrong ID - swapped vendor and device)"};
		InsertProducts(0x1761, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x501c};
		char* mids[] = {"300K CMOS Camera"};
		InsertProducts(0x1776, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004,0x0153,0x0154,0x0313};
		char* mids[] = {"MM004V5 Photo Key Chain (Digital Photo Frame) 1.5\"","LW153 802.11n Adapter [ralink rt3070]","LW154 802.11bgn (1x1:1) Wireless Adapter [Realtek RTL8188SU]","LW313 802.11n Adapter [ralink rt2770 + rt2720]"};
		InsertProducts(0x177f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x083e,0x083f,0x0938,0x0c30,0x0c31,0x0c9f,0x1eef};
		char* mids[] = {"MetaGeek Wi-Spy","MetaGeek Wi-Spy 2.4x","Iguanaworks USB IR Transceiver","Telldus TellStick","Telldus TellStick Duo",
		"USBtiny","OpenAPC SecuKey"};
		InsertProducts(0x1781, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0004,0x0006,0x0007,0x0008,0x000a,0x0011};
		char* mids[] = {"eHome Infrared Transceiver","RF Combo Device","eHome Infrared Transceiver","eHome Infrared Transceiver","eHome Infrared Transceiver",
		"eHome Infrared Transceiver","eHome Infrared Transceiver"};
		InsertProducts(0x1784, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7051,0x8051};
		char* mids[] = {"Belkin F5D7051 802.11g Adapter v1000 [Broadcom 4320]","Belkin F5D8051 v2 802.11bgn Wireless Adapter [Marvell 88W8362]"};
		InsertProducts(0x1799, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010};
		char* mids[] = {"Internal Infrared Transceiver"};
		InsertProducts(0x179d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0100,0x0101,0x0120,0x0200,0x0201,0x0210,0x0301,0x0302,0x0303,0x0304,0x0305,0x0310};
		char* mids[] = {"C01U condenser microphone","Q1U dynamic microphone","C03U multi-pattern microphone","UB1 boundary microphone","Meteorite condenser microphone",
		"StudioDock monitors (internal hub)","StudioDock monitors (audio)","StudioGT monitors","Q2U handheld microphone with XLR","GoMic compact condenser microphone",
		"C01U Pro condenser microphone","Q2U handheld mic with XLR","GoMic compact condenser mic","Meteor condenser microphone"};
		InsertProducts(0x17a0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"Performance Monitor 3","Performance Monitor 4"};
		InsertProducts(0x17a4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0005};
		char* mids[] = {"Optical Eye/3-wire","M-Bus Master MultiPort 250D"};
		InsertProducts(0x17a8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004};
		char* mids[] = {"Linux-USB Midi Gadget"};
		InsertProducts(0x17b3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010};
		char* mids[] = {"MFT Sensor"};
		InsertProducts(0x17b5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0510,0x0511,0x0520,0x1511};
		char* mids[] = {"SAU510-USB [no firmware]","SAU510-USB and SAU510-USB plus JTAG Emulators","SAU510-USB Iso Plus JTAG Emulator","SAU510-USB Nano JTAG Emulator","Onboard Emulator on SAUModule development kit"
		};
		InsertProducts(0x17ba, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x041c,0x0808,0x0815,0x0839,0x0d8d,0x1915,0x1940,0x1969,0x1978,0x2280,0x2305,0x4711,0x4712,0xbaff};
		char* mids[] = {"Audio 2 DJ","Maschine Controller","Audio Kontrol 1","Audio 4 DJ","Guitarrig Mobile",
		"Session I/O","RigKontrol3","RigKontrol2","Audio 8 DJ","Medion MDPNA1500 in card reader mode",
		"Traktor Kontrol X1","Kore Controller","Kore Controller 2","Traktor Kontrol S4"};
		InsertProducts(0x17cc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0051,0x030b,0x0377,0x0378,0x0379,0x037a,0x037b,0x037c,0x037d,0x410a,0x430a,0x4312};
		char* mids[] = {"USB VGA Adaptor","HP T100","Plugable UD-160-A (M)","Plugable UGA-2K-A","Plugable UGA-125",
		"Plugable UGA-165","Plugable USB-VGA-165","Plugable DC-125","Plugable USB2-HDMI-165","HDMI Adapter",
		"HP Port Replicator (Composite Device)","S2340T"};
		InsertProducts(0x17e9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000,0x1003,0x1004,0x1008,0x100a,0x304b,0x3815,0x4802,0x4807,0x480c,0x480d,0x480e,0x480f,0x4810,0x4811,0x4812,0x4813,0x4814,0x4815,0x4816,
		0x481c,0x481d,0x6004,0x6007,0x6009,0x6014,0x6025,0x7203,0x7423,0x7435,0x743a,0x7497,0x7498,0x749a,0x749b};
		char* mids[] = {"Hub","Integrated Smart Card Reader","Integrated Webcam","Hub","ThinkPad Mini Dock Plus Series 3",
		"AX88179 Gigabit Ethernet [ThinkPad OneLink GigaLAN]","ChipsBnk 2GB USB Stick","Lenovo Vc0323+MI1310_SOC Camera","UVC Camera","Integrated Webcam",
		"Integrated Webcam [R5U877]","Integrated Webcam [R5U877]","Integrated Webcam [R5U877]","Integrated Webcam [R5U877]","Integrated Webcam [R5U877]",
		"Integrated Webcam [R5U877]","Integrated Webcam [R5U877]","Integrated Webcam [R5U877]","Integrated Webcam [R5U877]","Integrated Webcam",
		"Integrated Webcam","Integrated Webcam","ISD-V4 Tablet Pen","Smartcard Keyboard","ThinkPad Keyboard with TrackPoint",
		"Mini Wireless Keyboard N5901","ThinkPad Travel Mouse","Ethernet adapter [U2L 100P-Y1]","IdeaPad A1 Tablet","A789 (Mass Storage mode, with debug)",
		"A789 (Mass Storage mode)","A789 (MTP mode)","A789 (MTP mode, with debug)","A789 (PTP mode)","A789 (PTP mode, with debug)"
		};
		InsertProducts(0x17ef, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xaaaa};
		char* mids[] = {"Jazz Blood Glucose Meter"};
		InsertProducts(0x17f4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0709};
		char* mids[] = {"Model M Keyboard"};
		InsertProducts(0x17f6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4604,0x4761};
		char* mids[] = {"USB-4604","USB-4761 Portable Data Acquisition Module"};
		InsertProducts(0x1809, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3201,0x3202};
		char* mids[] = {"VisionDTV USB-Ter/HAMA USB DVB-T device cold","VisionDTV USB-Ter/HAMA USB DVB-T device warm"};
		InsertProducts(0x1822, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010};
		char* mids[] = {"VoiceKey"};
		InsertProducts(0x183d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7922};
		char* mids[] = {"Audiotrak DR.DAC2 DX [GYROCOM C&C]"};
		InsertProducts(0x1852, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3020,0x3082,0xd000,0xd001};
		char* mids[] = {"K100 Infrared Receiver","K100 Infrared Receiver v2","Compro Videomate DVB-U2000 - DVB-T USB cold","Compro Videomate DVB-U2000 - DVB-T USB warm"};
		InsertProducts(0x185b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"iNexio Touchscreen controller"};
		InsertProducts(0x1870, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0d01};
		char* mids[] = {"UVC camera (Bresser microscope)","USB2.0 Camera"};
		InsertProducts(0x1871, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xee93};
		char* mids[] = {"EasyLogger"};
		InsertProducts(0x1873, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0511,0x0600};
		char* mids[] = {"AlienFX Mobile lighting","Dual Compatible Game Pad"};
		InsertProducts(0x187c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010,0x0100,0x0200,0x0201,0x0202,0x0300,0x0301};
		char* mids[] = {"Stallar Board","Stallar Board","Nova A","Nova B","Nice",
		"Vega","VeNice"};
		InsertProducts(0x187f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5632,0x5641};
		char* mids[] = {"Atek Tote Remote","TSAM-004 Presentation Remote"};
		InsertProducts(0x1894, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"Legato2 3D Scanner"};
		InsertProducts(0x189f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Snapshell IDR"};
		InsertProducts(0x18a4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0214,0x0216,0x0218,0x0227,0x022b,0x0237,0x0302};
		char* mids[] = {"Portable Hard Drive","External Hard Drive","External Hard Drive","Pocket Hard Drive","Portable Hard Drive (Store'n'Go)",
		"Portable Harddrive (500 GB)","Flash Drive"};
		InsertProducts(0x18a5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0037};
		char* mids[] = {"Maxter Remote Control"};
		InsertProducts(0x18b1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001,0x1002,0x1689,0xfffa,0xfffb};
		char* mids[] = {"DUTV007","EC168 (v5) based USB DVB-T receiver","DUTV009","EC168 (v2) based USB DVB-T receiver","EC168 (v3) based USB DVB-T receiver"
		};
		InsertProducts(0x18b4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0008,0x0012};
		char* mids[] = {"CG-WLUSB2GO","CG-WLUSB2GNR Corega Wireless USB Adapter","CG-WLUSB10 Corega Wireless USB Adapter"};
		InsertProducts(0x18c5, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xcafe};
		char* mids[] = {"Pico iMage"};
		InsertProducts(0x18cd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0d02,0x2d00,0x2d01,0x4e11,0x4e12,0x4e13,0x4e20,0x4e21,0x4e22,0x4e24,0x4e40,0x4e41,0x4e42,0x4e43,0x4ee1,0x4ee2,0x4ee3,0x4ee4,0x7102,0xb004,
		0xd109,0xd10a};
		char* mids[] = {"Celkon A88","Android-powered device in accessory mode","Android-powered device in accessory mode with ADB support","Nexus One","Nexus One (debug)",
		"Nexus One (tether)","Nexus S (fastboot)","Nexus S","Nexus S (debug)","Nexus S (tether)",
		"Nexus 7 (fastboot)","Nexus 7 (MTP)","Nexus 7 (debug)","Nexus 7 (PTP)","Nexus 4 / 10",
		"Nexus 4 (debug)","Nexus 4 (tether)","Nexus 4 (debug + tether)","Toshiba Thrive tablet","Pandigital / B&N Novel 9\" tablet",
		"LG G2x MTP","LG G2x MTP (debug)"};
		InsertProducts(0x18d1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x01a0};
		char* mids[] = {"B-Net 91 07"};
		InsertProducts(0x18d9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000};
		char* mids[] = {"DocuPen RC800"};
		InsertProducts(0x18dd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7102,0x9101,0x9102,0x9512};
		char* mids[] = {"Multi Card Reader (Internal)","All-in-1 Card Reader","Multi Card Reader","Webcam"};
		InsertProducts(0x18e3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6144,0x6196,0x6229,0x6232};
		char* mids[] = {"LR802UA 802.11b Wireless Adapter [ALi M4301AU]","RT2573","RT2573","Wireless 802.11g 54Mbps Network Adapter [RTL8187]"};
		InsertProducts(0x18e8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0004};
		char* mids[] = {"DualHead2Go [Analog Edition]","TripleHead2Go [Digital Edition]"};
		InsertProducts(0x18ea, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3118,0x3188,0x3299,0x3366};
		char* mids[] = {"USB to IrDA adapter [ARK3116T]","ARK3188 UVC Webcam","Webcam Carrefour","Bresser Biolux NV"};
		InsertProducts(0x18ec, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1320};
		char* mids[] = {"PhotoFrame PF-15-1"};
		InsertProducts(0x1908, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x000c,0x2233,0x2234,0x2235,0x2236};
		char* mids[] = {"Wireless Desktop nRF24L01 CX-1766","Linksys WUSB11 v2.8 802.11b Adapter [Atmel AT76C505]","Linksys WUSB54G v1 OEM 802.11g Adapter [Intersil ISL3886]","Linksys WUSB54GP v1 OEM 802.11g Adapter [Intersil ISL3886]","Linksys WUSB11 v3.0 802.11b Adapter [Intersil PRISM 3]"
		};
		InsertProducts(0x1915, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"Personal SyncPoint"};
		InsertProducts(0x1923, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x0006,0x0064,0x0065,0x0066,0x0067,0x0068,0x0069,0x0071,0x0072,0x0073,0x0074,0x0075,0x0076,0x0077,0x0078,0x0079,0x007a,0x007e,0x007f,
		0x0080,0x0081,0x0082,0x0083,0x0084,0x0085,0x0086,0x0087,0x0dc2};
		char* mids[] = {"1900 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen",
		"1950 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen",
		"1950 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen",
		"1950 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen",
		"1950 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen",
		"1950 HID Touchscreen","1950 HID Touchscreen","1950 HID Touchscreen","HID Touchscreen"};
		InsertProducts(0x1926, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0416,0x0616};
		char* mids[] = {"Mouse","ADNS-5700 Optical Mouse Controller (3-button)","ADNS-5700 Optical Mouse Controller (5-button)"};
		InsertProducts(0x192f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0602,0x0702,0x5168};
		char* mids[] = {"F71610 or F71612 Consumer Infrared Receiver/Transceiver","Integrated Consumer Infrared Receiver/Transceiver","F71610A or F71612A Consumer Infrared Receiver/Transceiver"};
		InsertProducts(0x1934, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8021};
		char* mids[] = {"WH1080 Weather Station / USB Missile Launcher"};
		InsertProducts(0x1941, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2250,0x2253,0x2255,0x2257,0xa250,0xa253};
		char* mids[] = {"Model 2250 MPEG and JPEG Capture Card","Model 2253 Audio/Video Codec Card","Model 2255 4 Channel Capture Card","Model 2257 4 Channel Capture Card","Model 2250 MPEG and JPEG Capture Card (cold)",
		"Model 2253 Audio/Video Codec Card (cold)"};
		InsertProducts(0x1943, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0004,0x0006,0x0008};
		char* mids[] = {"Amazon Kindle","Amazon Kindle 3/4/Paperwhite","Kindle Fire","Amazon Kindle Fire HD 8.9\""};
		InsertProducts(0x1949, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0102,0x0103,0x0301};
		char* mids[] = {"AudioBox 22 VSL","AudioBox 44 VSL","AudioBox 1818 VSL","AudioBox"};
		InsertProducts(0x194f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0202};
		char* mids[] = {"S200 2GB Rev. 1"};
		InsertProducts(0x1953, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7002,0x7006,0x7777,0x7779};
		char* mids[] = {"Libra-Q11 IR remote","Libra-Q26 / 1.0 Remote","Scorpius wireless keyboard","Scorpius-P20MT"};
		InsertProducts(0x195d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0016};
		char* mids[] = {"HomePatrol-1"};
		InsertProducts(0x1965, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000};
		char* mids[] = {"Z Mate 16GB"};
		InsertProducts(0x1970, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6025};
		char* mids[] = {"Flash Drive 512 MB"};
		InsertProducts(0x1976, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0111};
		char* mids[] = {"TL203 MP3 Player and Voice Recorder"};
		InsertProducts(0x1977, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0222};
		char* mids[] = {"BCL 508i"};
		InsertProducts(0x197d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0210,0x0220};
		char* mids[] = {"BCS200 WiMAX Adapter","BCSM250 WiMAX Adapter"};
		InsertProducts(0x198f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3202,0x3203};
		char* mids[] = {"REC-ADPT-USB (recorder)","REC-A-ADPT-USB (recorder)"};
		InsertProducts(0x1995, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3065};
		char* mids[] = {"3DM-GX3-25 Orientation Sensor"};
		InsertProducts(0x199b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8101};
		char* mids[] = {"DFx 21BU04 Camera"};
		InsertProducts(0x199e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000};
		char* mids[] = {"ProScope HR"};
		InsertProducts(0x19ab, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6611};
		char* mids[] = {"Celestia VoIP Phone"};
		InsertProducts(0x19af, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0010,0x0011,0x0012,0x0013};
		char* mids[] = {"BX32 Batupo","BX32P Barlino","BX40 Bagero","BX48 Batego"};
		InsertProducts(0x19b2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0101};
		char* mids[] = {"SkyScout Personal Planetarium","Handheld Digital Microscope 44302"};
		InsertProducts(0x19b4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8d20};
		char* mids[] = {"Drobo Elite"};
		InsertProducts(0x19b9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6a11};
		char* mids[] = {"MDM166A Fluorescent Display"};
		InsertProducts(0x19c2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Sandio 3D HID Mouse"};
		InsertProducts(0x19ca, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0007,0x0031,0x0063,0x0064,0x0083,0x0103,0x0104,0x0146,0x0167,0x0172,0x0325,0x0326,0x1008,0x1010,0x1017,0x1018,0x1203,0x1217,
		0x1218,0x2000,0xfff2,0xfff3};
		char* mids[] = {"CDMA Wireless Modem","MF632/ONDA ET502HS/MT505UP","TU25 WiMAX Adapter [Beceem BCS200]","MF110/MF627/MF636","K3565-Z HSDPA",
		"MF627 AU","MF190","MF112","K4505-Z","MF 195E (HSPA+ Modem)",
		"MF820 4G LTE","AX226 WIMAX MODEM (After Modeswitch)","LTE4G O2 ZTE MF821D LTE/UMTS/GSM Modem/Networkcard","LTE4G O2 ZTE MF821D LTE/UMTS/GSM Modem/Networkcard","K3570-Z",
		"K3571-Z","K5006-Z vodafone LTE/UMTS/GSM Modem/Networkcard","K5006-Z vodafone LTE/UMTS/GSM Modem/Networkcard","MF691 [ T-Mobile webConnect Rocket 2.0]","MF652",
		"MF652","MF627/MF628/MF628+/MF636+ HSDPA/HSUPA","Gobi Wireless Modem (QDL mode)","Gobi Wireless Modem"};
		InsertProducts(0x19d2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x02f1};
		char* mids[] = {"NAUT324C"};
		InsertProducts(0x19db, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Podcaster"};
		InsertProducts(0x19f7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0703};
		char* mids[] = {"Steering Wheel"};
		InsertProducts(0x19fa, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0102,0x0201,0x0238};
		char* mids[] = {"1.3MP Webcam","Rocketfish Wireless 2.4G Laser Mouse","DX-WRM1401 Mouse"};
		InsertProducts(0x19ff, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xbadd};
		char* mids[] = {"USB OTG Compliance test device"};
		InsertProducts(0x1a0a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0407};
		char* mids[] = {"Mimi WiFi speakers"};
		InsertProducts(0x1a1d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0021,0x0024};
		char* mids[] = {"Keyboard","Multimedia Keyboard"};
		InsertProducts(0x1a2c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0304};
		char* mids[] = {"802.11n Wireless LAN Card"};
		InsertProducts(0x1a32, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0802};
		char* mids[] = {"Gamepad"};
		InsertProducts(0x1a34, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0201};
		char* mids[] = {"Hub","FE 2.1 7-port Hub"};
		InsertProducts(0x1a40, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Digipass 905 SmartCard Reader"};
		InsertProducts(0x1a44, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3410};
		char* mids[] = {"CoPilot System Cable"};
		InsertProducts(0x1a61, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1008};
		char* mids[] = {"E-861 PiezoWalk NEXACT Controller"};
		InsertProducts(0x1a72, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6002,0x7410};
		char* mids[] = {"Contour","Contour Next"};
		InsertProducts(0x1a79, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0068,0x0168,0x0191};
		char* mids[] = {"VerticalMouse 3","VerticalMouse 3 Wireless","VerticalMouse 4"};
		InsertProducts(0x1a7c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2203,0x2204,0x2205};
		char* mids[] = {"Laser Gaming mouse","Optical Mouse","Laser Mouse"};
		InsertProducts(0x1a81, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5512,0x5523,0x5584,0x7523,0x752d,0x7584,0xe008};
		char* mids[] = {"CH341 in EPP/MEM/I2C mode, EPP/I2C adapter","CH341 in serial mode, usb to serial port converter","CH341 in parallel mode, usb to printer port converter","HL-340 USB-Serial adapter","CH345 MIDI adapter",
		"CH340S","HID-based serial adapater"};
		InsertProducts(0x1a86, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1002,0x1009,0x100d};
		char* mids[] = {"BandLuxe 3.5G HSDPA Adapter","BandLuxe 3.5G HSPA Adapter","4G LTE adapter"};
		InsertProducts(0x1a8d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Touchscreen"};
		InsertProducts(0x1aad, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0588};
		char* mids[] = {"DS1000 SERIES"};
		InsertProducts(0x1ab1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0103};
		char* mids[] = {"AudioLink plus 4x4 2.9.28"};
		InsertProducts(0x1acc, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"KM290-HRS"};
		InsertProducts(0x1ad4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0381,0x2001,0x9003,0x9004};
		char* mids[] = {"VS-DVB-T 380U (af9015 based)","SpeedLink Snappy Mic webcam (SL-6825-SBK)","SpeedLink Vicious And Devine Laplace webcam, white (VD-1504-SWT)","SpeedLink Vicious And Devine Laplace webcam, black (VD-1504-SBK)"};
		InsertProducts(0x1ae7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"PQ Box 100"};
		InsertProducts(0x1afe, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0630,0x0940,0x0950,0x0960,0x1000,0x100a,0x100b,0x1400,0x140a,0x140b,0x140c,0x140d,0x140e,0x14ea,0x14eb,0x1604,0x1608,0x160c,0x160f,0x168f,
		0x4610,0x4650,0x4660,0x4661,0x4662,0x4663,0x4670,0x4671,0x4672,0x4673,0x4680,0x4681,0x4682,0x4683,0x6004,0x6008,0x600f,0x6014,0x6018,0x601f,
		0x6034,0x6038,0x603f,0x6044,0x6048,0x604f,0x6054,0x6058,0x605f,0x6074,0x6078,0x607f,0x6104,0x6108,0x610f,0x6114,0x6118,0x611f,0x6134,0x6138,
		0x613f,0x6144,0x6148,0x614f,0x6154,0x6158,0x615f,0x6174,0x6178,0x617f,0x6259,0x6359,0x810a,0x810b,0x820a,0x820b};
		char* mids[] = {"ME-630","ME-94","ME-95","ME-96","ME-1000",
		"ME-1000","ME-1000","ME-1400","ME-1400A","ME-1400B",
		"ME-1400C","ME-1400D","ME-1400E","ME-1400EA","ME-1400EB",
		"ME-1600/4U","ME-1600/8U","ME-1600/12U","ME-1600/16U","ME-1600/16U8I",
		"ME-4610","ME-4650","ME-4660","ME-4660I","ME-4660",
		"ME-4660I","ME-4670","ME-4670I","ME-4670S","ME-4670IS",
		"ME-4680","ME-4680I","ME-4680S","ME-4680IS","ME-6000/4",
		"ME-6000/8","ME-6000/16","ME-6000I/4","ME-6000I/8","ME-6000I/16",
		"ME-6000ISLE/4","ME-6000ISLE/8","ME-6000ISLE/16","ME-6000/4/DIO","ME-6000/8/DIO",
		"ME-6000/16/DIO","ME-6000I/4/DIO","ME-6000I/8/DIO","ME-6000I/16/DIO","ME-6000ISLE/4/DIO",
		"ME-6000ISLE/8/DIO","ME-6000ISLE/16/DIO","ME-6100/4","ME-6100/8","ME-6100/16",
		"ME-6100I/4","ME-6100I/8","ME-6100I/16","ME-6100ISLE/4","ME-6100ISLE/8",
		"ME-6100ISLE/16","ME-6100/4/DIO","ME-6100/8/DIO","ME-6100/16/DIO","ME-6100I/4/DIO",
		"ME-6100I/8/DIO","ME-6100I/16/DIO","ME-6100ISLE/4/DIO","ME-6100ISLE/8/DIO","ME-6100ISLE/16/DIO",
		"ME-6200I/9/DIO","ME-6300I/9/DIO","ME-8100A","ME-8100B","ME-8200A",
		"ME-8200B"};
		InsertProducts(0x1b04, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1078,0x1079,0x1080};
		char* mids[] = {"BLUDRIVE II CCID","BLUDRIVE II CCID","WRITECHIP II CCID"};
		InsertProducts(0x1b0e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0890,0x0a00,0x0a60,0x1a01,0x1a0a,0x1a90};
		char* mids[] = {"Flash Padlock","SP2500 Speakers","Vengeance K60 Keyboard","Flash Voyager GT","Survivor Stealth Flash Drive",
		"Flash Voyager GT"};
		InsertProducts(0x1b1c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0064};
		char* mids[] = {"Pleo robotic dinosaur"};
		InsertProducts(0x1b32, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2933,0x2935,0x2936,0x2937,0x2938,0x2939,0x2950,0x2951,0x2952,0x2953,0x2955,0x2956,0x2957,0x2958,0x2959,0x2960,0x2961,0x2962,0x2963,0x2965,
		0x2966,0x2967,0x2968,0x2969};
		char* mids[] = {"PC Camera/Webcam controller","PC Camera/Webcam controller","PC Camera/Webcam controller","PC Camera/Webcam controller","PC Camera/Webcam controller",
		"PC Camera/Webcam controller","PC Camera/Webcam controller","PC Camera/Webcam controller","PC Camera/Webcam controller","PC Camera/Webcam controller",
		"PC Camera/Webcam controller","PC Camera/Webcam controller","PC Camera/Webcam controller","PC Camera/Webcam controller","PC Camera/Webcam controller",
		"PC Camera/Webcam controller","PC Camera/Webcam controller","PC Camera/Webcam controller","PC Camera/Webcam controller","PC Camera/Webcam controller",
		"PC Camera/Webcam controller","PC Camera/Webcam controller","PC Camera/Webcam controller","PC Camera/Webcam controller"};
		InsertProducts(0x1b3b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0c52,0x2002};
		char* mids[] = {"808 Camera #9 (mass storage mode)","808 Camera #9 (web-cam mode)"};
		InsertProducts(0x1b3f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"CHUSB Duo Charger (NiMH AA/AAA USB smart charger)"};
		InsertProducts(0x1b47, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2101,0x2102,0x2103,0x4101,0x4201,0x4202,0x4203,0x4204,0x4205,0x4206,0x4301,0x4302,0x4303,0x4401,0x4501,0x4502,0x6101,0x6202,0x6203,0x8101,
		0x8102,0x8103};
		char* mids[] = {"FXMC Neural Network Controller","FXMC Neural Network Controller V2","FXMC Neural Network Controller V3","Passport Reader CLR device","Passport Reader PRM device",
		"Passport Reader PRM extension device","Passport Reader PRM DSP device","Passport Reader PRMC device","Passport Reader CSHR device","Passport Reader PRMC V2 device",
		"Passport Reader MRZ device","Passport Reader MRZ DSP device","Passport Reader CSLR device","Card Reader","Passport Reader RFID device",
		"Passport Reader RFID AIG device","Neural Network Controller","Fingerprint Reader device","Fingerprint Scanner device","Camera V1",
		"Recovery / Camera V2","Camera V3"};
		InsertProducts(0x1b52, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3002};
		char* mids[] = {"USBTV007 Video Grabber [EasyCAP]"};
		InsertProducts(0x1b71, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000};
		char* mids[] = {"xHC1 Controller"};
		InsertProducts(0x1b73, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3072,0x8171,0x8187,0x9170,0xa200};
		char* mids[] = {"AirLive WN-360USB adapter","WN-370USB 802.11bgn Wireless Adapter [Realtek RTL8188SU]","AirLive WL-1600USB 802.11g Adapter [Realtek RTL8187L]","AirLive X.USB 802.11abgn [Atheros AR9170+AR9104]","AirLive WN-200USB wireless 11b/g/n dongle"
		};
		InsertProducts(0x1b75, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xc810,0xd393,0xd396,0xd397,0xd398,0xd700,0xe297,0xe383,0xe385,0xe386,0xe399,0xe39a,0xe39b,0xe401,0xe409};
		char* mids[] = {"MC810 [af9015]","DVB-T receiver [RTL2832U]","UB396-T [RTL2832U]","DVB-T receiver [RTL2832U]","DVB-T receiver [RTL2832U]",
		"FM Radio SnapMusic Mobile 700 (FM700)","Conceptronic DVB-T CTVDIGRCU V3.0","DVB-T UB383-T [af9015]","DVB-T UB385-T [af9015]","DVB-T UB385-T [af9015]",
		"DVB-T KWorld PlusTV 399U [af9015]","DVB-T395U [af9015]","DVB-T395U [af9015]","Sveon STV22 DVB-T [af9015]","IT9137FN Dual DVB-T [KWorld UB499-2T]"
		};
		InsertProducts(0x1b80, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Duosense Transparent Electromagnetic Digitizer"};
		InsertProducts(0x1b96, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"InSight USB Link"};
		InsertProducts(0x1ba4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0003};
		char* mids[] = {"Guitar for Xbox 360","Drum Kit for Xbox 360"};
		InsertProducts(0x1bad, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"VR920 Immersive Eyewear"};
		InsertProducts(0x1bae, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x011e,0xf017};
		char* mids[] = {"Alcatel One Touch L100V / Telekom Speedstick LTE II","Alcatel One Touch L100V / Telekom Speedstick LTE II"};
		InsertProducts(0x1bbb, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0020,0x0021,0x0023,0x1003,0x1004,0x1005,0x1006,0x1010,0x1011,0x1200};
		char* mids[] = {"HE863","HE910","HE910-D ECM","UC864-E","UC864-G",
		"CC864-DUAL","CC864-SINGLE","DE910-DUAL","CE910-DUAL","LE920"
		};
		InsertProducts(0x1bc7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0007,0x053a,0x05c5,0x05cf,0x0c31,0x2885,0x2888,0x2b83};
		char* mids[] = {"Optical Mouse","Targa Silvercrest OMC807-C optische Funkmaus","SPRF2413A [2.4GHz Wireless Keyboard/Mouse Receiver]","Micro keyboard & mouse receiver","SPIF30x Serial-ATA bridge",
		"ASUS Webcam","HP Universal Camera","Laptop Integrated Webcam FHD"};
		InsertProducts(0x1bcf, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1268,0x1368,0x1568,0x1668,0x1688,0x2968,0x5968,0x6968};
		char* mids[] = {"Touch Screen","Touch Screen","Capacitive Touch Screen","IR Touch Screen","Resistive Touch Screen",
		"Touch Screen","Touch Screen","Touch Screen"};
		InsertProducts(0x1bfd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0102};
		char* mids[] = {"Plug Computer"};
		InsertProducts(0x1c0c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7241};
		char* mids[] = {"Prox'N'Roll RFID Scanner"};
		InsertProducts(0x1c34, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0533,0x0534,0x0535,0x0536};
		char* mids[] = {"TiltStick","i2c-tiny-usb interface","glcd2usb interface","Swiss ColorPAL"};
		InsertProducts(0x1c40, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0003,0x000e,0x0026,0x3000,0x3002};
		char* mids[] = {"Keyboard TRACER Gamma Ivory","HID controller","Genius KB-120 Keyboard","Keyboard","Micro USB Web Camera",
		"WebCam SiGma Micro"};
		InsertProducts(0x1c4f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa222};
		char* mids[] = {"DVD Writer Slimtype eTAU108"};
		InsertProducts(0x1c6b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x861f};
		char* mids[] = {"Anysee E30 USB 2.0 DVB-T Receiver"};
		InsertProducts(0x1c73, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0801};
		char* mids[] = {"Fingerprint Reader"};
		InsertProducts(0x1c7a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"RS150 V2"};
		InsertProducts(0x1c83, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0007,0x003c};
		char* mids[] = {"SMI Grabber (EasyCAP DC60+ clone) (no firmware) [SMI-2021CBE]","SMI Grabber (EasyCAP DC60+ clone) [SMI-2021CBE]"};
		InsertProducts(0x1c88, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6061};
		char* mids[] = {"WL-72B 3.5G MODEM"};
		InsertProducts(0x1c9e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x18ab};
		char* mids[] = {"SATA bridge"};
		InsertProducts(0x1ca1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa332,0xb288};
		char* mids[] = {"C8 Webcam","C18 Webcam"};
		InsertProducts(0x1cac, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6681};
		char* mids[] = {"IDC6681"};
		InsertProducts(0x1cb6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00fd,0x00ff,0x0166};
		char* mids[] = {"In-Circuit Debug Interface","Stellaris ROM DFU Bootloader","CANAL USB2CAN"};
		InsertProducts(0x1cbe, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0004,0x0017,0x0018,0x0019,0x001a,0x001b,0x001c,0x001d,0x0022,0x0023,0x0025,0x0027};
		char* mids[] = {"Sensor Terminal Board","Wireless Handheld Terminal","deRFusbSniffer 2.4 GHz","deRFusb24E001","deRFusb14E001",
		"deRFusb23E00","deRFusb13E00","deRFnode","deRFnode / gateway","deUSB level shifter",
		"deRFusbSniffer Sub-GHz","deRFusb23E06","deRFusb13E06"};
		InsertProducts(0x1cf1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0028};
		char* mids[] = {"iCreativ MIDI Controller"};
		InsertProducts(0x1d03, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1026};
		char* mids[] = {"HSUPA Modem FLYING-LARK46-VER0.07 [Flying Angel]"};
		InsertProducts(0x1d09, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"AXiS-49 Harmonic Table MIDI Keyboard"};
		InsertProducts(0x1d17, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1101,0x1102,0x1103,0x6105,0x8202};
		char* mids[] = {"DK DVB-T Dongle","DK mini DVB-T Dongle","DK 5217 DVB-T Dongle","Video grabber","DK DVBC/T DONGLE"
		};
		InsertProducts(0x1d19, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0004,0x0008,0x000a,0x000d,0x0013};
		char* mids[] = {"Dream Cheeky Fidget","Dream Cheeky Webmail Notifier","Dream Cheeky button","Dream Cheeky Mailbox Friends Alert","Dream Cheeky Big Red Button",
		"Dream Cheeky LED Message Board"};
		InsertProducts(0x1d34, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1d45};
		char* mids[] = {"Foxlink Optical touch sensor"};
		InsertProducts(0x1d45, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x000c,0x000e};
		char* mids[] = {"Ralink RT2770/2720 802.11b/g/n Wireless LAN Mini-USB Device","Ralink RT3070 802.11b/g/n Wireless Lan USB Device","Ralink RT3070 802.11b/g/n Wireless Lan USB Device"};
		InsertProducts(0x1d4d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5119,0x602b,0x6053};
		char* mids[] = {"GTA01/GTA02 U-Boot Bootloader","FPGALink","Darkgame Controller"};
		InsertProducts(0x1d50, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005,0x0006,0x000c,0x2400,0x32da,0x83d0,0xac01,0xad02,0xaf01};
		char* mids[] = {"Wireless Receiver (Keyboard and Mouse)","Wireless Receiver (RC Laser Pointer)","Optical Mouse","Wireless Mouse Receiver","2.4GHz Receiver (Keyboard and Mouse)",
		"Click-mouse!","Wireless Receiver (Keyboard and Mouse)","SE340D PC Remote Control","AUVIO Universal Remote Receiver for PlayStation 3"};
		InsertProducts(0x1d57, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0100,0x0101,0x0102,0x0103,0x0104,0x0105,0x0200};
		char* mids[] = {"1.1 root hub","2.0 root hub","3.0 root hub","PTP Gadget","Audio Gadget",
		"EEM Gadget","NCM (Ethernet) Gadget","Multifunction Composite Gadget","FunctionFS Gadget","Qemu Audio Device"
		};
		InsertProducts(0x1d6b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x201e};
		char* mids[] = {"PPU-700"};
		InsertProducts(0x1d90, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1101,0xc101};
		char* mids[] = {"Generic Display Device (Mass storage mode)","Generic Display Device"};
		InsertProducts(0x1de1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xf000};
		char* mids[] = {"iCON 210 UMTS Surfstick"};
		InsertProducts(0x1e0e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2004};
		char* mids[] = {"Sony 1.3MP 1/3\" ICX445 IIDC video camera [Chameleon]"};
		InsertProducts(0x1e10, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"instadose dosimeter"};
		InsertProducts(0x1e17, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0165};
		char* mids[] = {"Secure Pen drive"};
		InsertProducts(0x1e1d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0101,0x0102,0x0401,0x0402,0x0403,0x0404,0x0405,0x0406,0x0407,0x0408,0x0409,0x040a,0x040b,0x040c,0x040d,0x040e,0x0501,0x0601};
		char* mids[] = {"CPX Adapter","CPX Adapter >=HW10.09 [CP2102]","iL3-TP [AT90USB646]","FTDI232 [EasyPort]","FTDI232 [EasyPort Mini]",
		"FTDI232 [Netzteil-GL]","FTDI232 [MotorPrÃ¼fstand]","STM32F103 [EasyKit]","LPC2378 [Robotino]","LPC2378 [Robotino-Arm]",
		"LPC2378 [Robotino-Arm Bootloader]","LPC2378 [Robotino Bootloader]","LPC2378 [Robotino XT]","LPC2378 [Robotino XT Bootloader]","LPC2378 [Robotino 3]",
		"LPC2378 [Robotino 3 Bootloader]","CP2102 [CMSP]","CMMP-AS"};
		InsertProducts(0x1e29, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2093,0x4082};
		char* mids[] = {"CBM209x Flash Drive (OEM)","CBM4082 SD Card Reader"};
		InsertProducts(0x1e3d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"CS328A PC Oscilloscope"};
		InsertProducts(0x1e41, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0102};
		char* mids[] = {"WebCam","GL-UPC822 UVC WebCam"};
		InsertProducts(0x1e4e, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2030};
		char* mids[] = {"2030 USB Keyboard"};
		InsertProducts(0x1e54, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x001b,0x0050};
		char* mids[] = {"DataStation maxi g.u","DataStation maxi light"};
		InsertProducts(0x1e68, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Avatar Optical Mouse"};
		InsertProducts(0x1e71, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2211,0x2647,0x2659,0x4641,0x6511,0x6512,0x7111};
		char* mids[] = {"MP300","2 GB 2 Go Video MP3 Player [MP601-2G]","Coby 4GB Go Video MP3 Player [MP620-4G]","A8705 MP3/Video Player","MP705-8G MP3 player",
		"MP705-4G","MP957 Music and Video Player"};
		InsertProducts(0x1e74, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2c24,0x2ced,0x2cf6,0x2d50,0x2d51,0x30d4};
		char* mids[] = {"Pyra Mouse (wired)","Kone Mouse","Pyra Mouse (wireless)","Kova+ Mouse","Kone+ Mouse",
		"Arvo Keyboard"};
		InsertProducts(0x1e7d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2012,0x2210,0x2310,0x2410};
		char* mids[] = {"Air2210 54 Mbps Wireless Adapter","Air2210 54 Mbps Wireless Adapter","Air2310 150 Mbps Wireless Adapter","Air2410 300 Mbps Wireless Adapter"};
		InsertProducts(0x1eda, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xbd3b};
		char* mids[] = {"Intensity Shuttle"};
		InsertProducts(0x1edb, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0014};
		char* mids[] = {"MT833UP"};
		InsertProducts(0x1ee8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2233,0x5064,0x5523,0x5545,0x5648,0x564a};
		char* mids[] = {"Cassidian NH90 STTE","FDR Interface","Cassidian SSDC Adapter II","Cassidian SSDC Adapter III","RIU CSMU/BSD",
		"Cassidian RIU CSMU/BSD Simulator"};
		InsertProducts(0x1ef6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0020,0x0021};
		char* mids[] = {"CDMA USB Modem A600","CD INSTALLER USB Device"};
		InsertProducts(0x1f28, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xefe8};
		char* mids[] = {"V972 tablet in flashing mode"};
		InsertProducts(0x1f3a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"NM-1000 scanner"};
		InsertProducts(0x1f44, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0627,0x0628};
		char* mids[] = {"Data capturing system","Data capturing and control module"};
		InsertProducts(0x1f48, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xb803};
		char* mids[] = {"Lifeview LV5TDLX DVB-T [RTL2832U]"};
		InsertProducts(0x1f4d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0023,0x8000};
		char* mids[] = {"Jawbone Jambox","Jawbone Jambox - Updating"};
		InsertProducts(0x1f6f, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0888,0x0902};
		char* mids[] = {"IS888 SATA Storage Controller","IS902 UFD controller"};
		InsertProducts(0x1f75, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"PrecisionHD Camera"};
		InsertProducts(0x1f82, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"Multi-touch HID Controller"};
		InsertProducts(0x1f87, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0241};
		char* mids[] = {"AirView2-EXT"};
		InsertProducts(0x1f9b, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x104d};
		char* mids[] = {"ES65"};
		InsertProducts(0x1fab, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Expert Key - Data aquisition system"};
		InsertProducts(0x1fbd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x010b};
		char* mids[] = {"LPC1343","PR533"};
		InsertProducts(0x1fc9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"UART Bridge"};
		InsertProducts(0x1fde, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1000};
		char* mids[] = {"VW100 series CDMA EV-DO Rev.A modem"};
		InsertProducts(0x1fe7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0013,0x001a};
		char* mids[] = {"CVTouch Screen (HID)","Human Interface Device"};
		InsertProducts(0x1ff7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0201,0x1a00,0x1a02,0x200c,0x3200,0x3301,0x3306,0x3308,0x3309,0x330a,0x3500,0x3700,0x3701,0x3702,0x3703,0x3704,0x3705,0x3761,0x3a00,
		0x3a01,0x3a02,0x3a03,0x3a04,0x3a05,0x3a80,0x3a81,0x3a82,0x3a83,0x3b00,0x3b01,0x3c00,0x3c01,0x3c02,0x3c05,0x3c15,0x3c17,0x3c19,0x3c1a,0x3c1b,
		0x4000,0x4001,0x4002,0x4003,0x400b,0x4102,0x5100,0x5102,0x5b00,0x9414,0x9b00,0xabc1,0xf013,0xf103,0xf10d,0xf110,0xf111,0xf112,0xf116,0xf117,
		0xf118};
		char* mids[] = {"DWL-120 WIRELESS ADAPTER","DHN-120 10Mb Home Phoneline Adapter","DUB-E100 Fast Ethernet Adapter(rev.A) [ASIX AX88172]","DUB-E100 Fast Ethernet Adapter(rev.C1) [ASIX AX88772]","10/100 Ethernet",
		"DWL-120 802.11b Wireless Adapter(rev.E1) [Atmel at76c503a]","DWA-130 802.11n Wireless N Adapter(rev.C1) [Realtek RTL8192U]","DWL-G122 Wireless Adapter(rev.F1) [Realtek RTL8188SU]","DWA-121 802.11n Wireless N 150 Pico Adapter [Realtek RTL8188CUS]","DWA-135 802.11n Wireless N Adapter(rev.A1) [Realtek RTL8192CU]",
		"DWA-133 802.11n Wireless N Adapter [Realtek RTL8192CU]","Elitegroup Computer Systems WLAN card WL-162","DWL-122 802.11b [Intersil Prism 3]","DWL-G120 Spinnaker 802.11g [Intersil ISL3886]","DWL-120 802.11b Wireless Adapter(rev.F) [Intersil ISL3871]",
		"AirPlus G DWL-G122 Wireless Adapter(rev.A1) [Intersil ISL3880]","AirPlus G DWL-G122 Wireless Adapter(rev.A2) [Intersil ISL3887]","AirPlus G DWL-G120 Wireless Adapter(rev.C) [Intersil ISL3887]","IEEE 802.11g USB2.0 Wireless Network Adapter-PN","DWL-AG132 [Atheros AR5523]",
		"DWL-AG132 (no firmware) [Atheros AR5523]","DWL-G132 [Atheros AR5523]","DWL-G132 (no firmware) [Atheros AR5523]","DWL-AG122 [Atheros AR5523]","DWL-AG122 (no firmware) [Atheros AR5523]",
		"AirPlus Xtreme G DWL-G132 Wireless Adapter","predator Bootloader Download","AirPremier AG DWL-AG132 Wireless Adapter","predator Bootloader Download","AirPlus DWL-120+ Wireless Adapter [Texas Instruments ACX100USB]",
		"WLAN Boot Device","AirPlus G DWL-G122 Wireless Adapter(rev.B1) [Ralink RT2571]","AirPlus AG DWL-AG122 Wireless Adapter","AirPlus G DWL-G122 Wireless Adapter","DUB-E100 Fast Ethernet Adapter(rev.B1) [ASIX AX88772]",
		"DWA-140 RangeBooster N Adapter(rev.B3) [Ralink RT5372]","DWA-123 Wireless N 150 Adapter(rev.A1) [Ralink RT3370]","DWA-125 Wireless N 150 Adapter(rev.A3) [Ralink RT5370]","DWA-160 802.11abgn Xtreme N Dual Band Adapter(rev.B2) [Ralink RT5572]","DWA-127 Wireless N 150 High-Gain Adapter(rev.A1) [Ralink RT3070]",
		"DSB-650C Ethernet [klsi]","DSB-650TX Ethernet [pegasus]","DSB-650TX Ethernet [pegasus]","DSB-650TX-PNA Ethernet [pegasus]","10/100 Ethernet",
		"10/100 Ethernet","DSL-200 ADSL ATM Modem","DSL-200 ADSL Loader","Remote NDIS Network Device","Cable Modem",
		"Broadband Cable Modem Remote NDIS Device","DSB-650 Ethernet [pegasus]","DLink 7 port USB2.0 Hub","DUB-H7 7-port USB 2.0 hub","Accent Communications Modem",
		"DUB-AV300 A/V Capture","DBT-122 Bluetooth adapter","DUB-T210 Audio Device","Formosa 2","Formosa 3",
		"Formosa 4"};
		InsertProducts(0x2001, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x100b};
		char* mids[] = {"Play audio soundcard"};
		InsertProducts(0x200c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0245,0x0246,0x0248,0x024f};
		char* mids[] = {"PCTV 73ESE","PCTV 74E","PCTV 282E","nanoStick T2 290e"};
		InsertProducts(0x2013, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3220,0x4901,0x4903,0x4904,0x5303,0x5304,0xab01,0xab24,0xab25,0xab28,0xab29,0xab2a,0xab2b,0xab2c,0xab50,0xc002,0xc007,0xed02,0xed06,0xed10,
		0xed14,0xed16,0xed17,0xed18};
		char* mids[] = {"GW-US11S WLAN [Atmel AT76C503A]","GW-USSuper300 802.11bgn Wireless Adapter [Realtek RTL8191SU]","GW-USFang300 802.11abgn Wireless Adapter [Realtek RTL8192DU]","GW-USUltra300 802.11abgn Wireless Adapter [Realtek RTL8192DU]","GW-US54GXS 802.11bg",
		"GWUS300 802.11n","GW-US54HP","GW-US300MiniS","GW-USMini2N 802.11n Wireless Adapter [Ralink RT2870]","GW-USNano",
		"GW-USMicro300","GW-USNano2 802.11n Wireless Adapter [Realtek RTL8188CUS]","GW-USEco300 802.11bgn Wireless Adapter [Realtek RTL8192CU]","GW-USDual300 802.11abgn Wireless Adapter [Realtek RTL8192DU]","GW-US54Mini2",
		"GW-US54SG","GW-US54GZL","GW-USMM","GW-US300MiniW 802.11bgn Wireless Adapter","GW-US300Mini2",
		"GW-USMicroN","GW-USMicroN2W 802.11bgn Wireless Adapter [Realtek RTL8188SU]","GW-USValue-EZ 802.11n Wireless Adapter [Realtek RTL8188CUS]","GW-USHyper300 / GW-USH300N 802.11bgn Wireless Adapter [Realtek RTL8191SU]"};
		InsertProducts(0x2019, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0c80,0x0c90,0x1700,0x1800,0x1801,0x2000,0x2009,0x200a,0x2010,0x2011,0x2019,0x2400,0x4700,0x4902,0x4903,0x4982,0x5500,0x5510,0x5520,0x5530,
		0x5580,0x5590,0x6500,0x6502,0x6503,0x6513,0x7050,0x7060,0x7070,0x7240,0x8400,0x9300,0x9301,0x9941,0x9950,0xb910,0xb980,0xb990,0xc000,0xc010
		};
		char* mids[] = {"Windham","Windham","CataMount","Okemo A","Okemo B",
		"Tiger Minicard","Tiger Minicard R2","Tiger Minicard","Tiger Minicard","WinTV MiniCard [Dell Digital TV Receiver]",
		"Tiger Minicard","WinTV PVR USB2 (Model 24019)","WinTV Nova-S-USB2","HD PVR","HS PVR",
		"HD PVR","Windham","Windham","Windham","Windham",
		"Windham","Windham","WinTV HVR-900","WinTV HVR-900","WinTV HVR-930",
		"WinTV HVR-980","Nova-T Stick","Nova-T Stick 2","Nova-T Stick 3","WinTV HVR-850",
		"WinTV Nova-T-500","WinTV NOVA-T USB2 (cold)","WinTV NOVA-T USB2 (warm)","WinTV Nova-T-500","WinTV Nova-T-500",
		"Windham","Windham","Windham","Windham","Windham"
		};
		InsertProducts(0x2040, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0200,0x0855,0x0964};
		char* mids[] = {"MSP430 USB HID Bootstrap Loader","Invensense Embedded MotionApp HID Sensor","Inventio Software MSP430"};
		InsertProducts(0x2047, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0003,0x0004};
		char* mids[] = {"nook","NOOKcolor","NOOK Simple Touch","NOOK Tablet"};
		InsertProducts(0x2080, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0a01,0x0a02,0x0b03};
		char* mids[] = {"Multi Touch Panel","Multi Touch Panel","Multi Touch Panel"};
		InsertProducts(0x2087, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4123,0x414a,0x415a,0x415b,0x415c};
		char* mids[] = {"IKALOGIC SCANALOGIC 2","MDE SPI Interface","OpenPilot","CopterControl","PipXtreme"
		};
		InsertProducts(0x20a0, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x10ad,0xf7d1};
		char* mids[] = {"XUSB Loader","XTAG2 - JTAG Adapter"};
		InsertProducts(0x20b1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0a18};
		char* mids[] = {"10.1 Touch screen overlay"};
		InsertProducts(0x20b3, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0713,0x1540,0x1db5,0x1db6,0xc25b,0xcb72};
		char* mids[] = {"Milkymist JTAG/serial","ben-wpan, AT86RF230-based","IDBG in DFU mode","IDBG in normal mode","C2 Dongle",
		"ben-wpan, cntr"};
		InsertProducts(0x20b7, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Entropy Key [UDEKEY01]"};
		InsertProducts(0x20df, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x648b};
		char* mids[] = {"TEW-648UBM 802.11n 150Mbps Micro Wireless N Adapter [Realtek RTL8188CUS]"};
		InsertProducts(0x20f4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0201};
		char* mids[] = {"SIIG 4-to-2 Printer Switch"};
		InsertProducts(0x2101, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x211b,0x2703};
		char* mids[] = {"Touchscreen Controller","TS58xxA/TC56xxA [CoolTouch]"};
		InsertProducts(0x2149, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2031,0x500c,0x8001};
		char* mids[] = {"Network Blaster Wireless Adapter","DE5771 Modem Blaster","Broadxent BritePort DSL Bridge 8010U"};
		InsertProducts(0x2162, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0005,0x0006,0x0011};
		char* mids[] = {"GDS-3000 Oscilloscope","GDS-3000 Oscilloscope","AFG Function Generator (CDC)"};
		InsertProducts(0x2184, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"EPOC Consumer Headset Wireless Dongle"};
		InsertProducts(0x21a1, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002};
		char* mids[] = {"Seismic recorder [Tellus]"};
		InsertProducts(0x21d6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004,0x2520,0x4050};
		char* mids[] = {"iWebKey Keyboard","Mini Tablet","AirStick joystick"};
		InsertProducts(0x2222, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3105};
		char* mids[] = {"SKYDATA SKD-U100"};
		InsertProducts(0x2227, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1005,0x1028,0x1029,0x1037};
		char* mids[] = {"WebCam SCB-0385N","WebCam SC-03FFL11939N","WebCam SC-13HDL11939N","WebCam SC-03FFM12339N"};
		InsertProducts(0x2232, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6323};
		char* mids[] = {"USB Electronic Scale"};
		InsertProducts(0x2233, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4161};
		char* mids[] = {"eReader White"};
		InsertProducts(0x2237, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Terminal Bike Key Reader"};
		InsertProducts(0x228d, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xffff};
		char* mids[] = {"PieKey \"beta\" 4GB model 4E4F41482E4F5247 (SM3251Q BB)"};
		InsertProducts(0x22a6, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002,0x0005,0x0830,0x0833,0x0850,0x1001,0x1002,0x1005,0x1101,0x1801,0x2035,0x2805,0x2821,0x2822,0x2823,0x2a01,0x2a02,0x2a03,0x2a21,
		0x2a22,0x2a23,0x2a41,0x2a42,0x2a43,0x2a61,0x2a62,0x2a63,0x2a81,0x2a83,0x2ac1,0x2ac3,0x2d78,0x3001,0x3002,0x3801,0x3802,0x3803,0x4001,0x4002,
		0x4003,0x4008,0x41d6,0x41d9,0x41db,0x41de,0x4204,0x4214,0x4224,0x4234,0x4244,0x4285,0x4801,0x4803,0x4810,0x4901,0x4902,0x4903,0x4a01,0x4a03,
		0x4a32,0x5801,0x5803,0x5901,0x5903,0x6001,0x6003,0x6004,0x6006,0x6008,0x6009,0x600a,0x600b,0x600c,0x6021,0x6023,0x6026,0x6027,0x604c,0x6101,
		0x6401,0x6403,0x6415,0x6604,0x6631,0x7001,0xfe01};
		char* mids[] = {"Wally 2.2 chipset","Wally 2.4 chipset","V.60c/V.60i GSM Phone","2386C-HT820","2386C-HT820 [Flash Mode]",
		"Bluetooth Device","Patriot 1.0 (GSM) chipset","Patriot 2.0 chipset","T280e GSM/GPRS Phone","Patriot 1.0 (TDMA) chipset",
		"Rainbow chipset flash","Bluetooth Device","GSM Modem","T720 GSM Phone","V.120e GSM Phone",
		"Flash Interface","MSM6050 chipset","CDMA modem","MSM6050 chipset flash","V710 GSM Phone (P2K)",
		"V710 GSM Phone (AT)","MSM6100 chipset flash","MSM6300 chipset","Usb Modem","MSM6300 chipset flash",
		"E815 GSM Phone (P2K)","E815 GSM Phone (AT)","MSM6500 chipset flash","MSM6025 chipset","MSM6025 chipset flash",
		"MSM6100 chipset","MSM6100 chipset flash","XT300[SPICE]","A835/E1000 GSM Phone (P2K)","A835/E1000 GSM Phone (AT)",
		"C350L/C450 (P2K)","C330/C350L/C450/EZX GSM Phone (AT)","Neptune LT chipset flash","OMAP 1.0 chipset","A920/A925 UMTS Phone",
		"OMAP 1.0 chipset flash","OMAP 1.0 chipset RDL","Droid X (Windows media mode)","Droid/Milestone","Droid/Milestone (Debug mode)",
		"Droid X (PC mode)","MPx200 Smartphone","MPc GSM","MPx220 Smartphone","MPc CDMA",
		"MPx100 Smartphone","Droid X (Mass storage)","Neptune LTS chipset","Neptune LTS chipset flash","Triplet GSM Phone (storage)",
		"Triplet GSM Phone (P2K)","Triplet GSM Phone (AT)","Neptune LTE chipset flash","Neptune LTX chipset","Neptune LTX chipset flash",
		"L6-imode Phone","Neptune ULS chipset","Neptune ULS chipset flash","Neptune VLT chipset","Neptune VLT chipset flash",
		"Dalhart EZX","Dalhart flash","EZX GSM Phone (CDC Net)","MOTOROKR E6","Dalhart RDL",
		"EZX GSM Phone (P2K)","Dalhart EZX config 17","Dalhart EZX config 18","EZX GSM Phone (USBLAN)","JUIX chipset",
		"JUIX chipset flash","Flash RAM Downloader/miniOS","USBLAN","EZX GSM Phone (Storage)","Talon integrated chipset",
		"Argon chipset","Argon chipset flash","ROKR Z6 (MTP mode)","Washington CDMA Phone","CDC Modem",
		"Q Smartphone","StarTAC III MS900"};
		InsertProducts(0x22b8, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0006};
		char* mids[] = {"Touch Screen"};
		InsertProducts(0x22b9, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0109,0x0110,0x0111,0x0112,0x0201,0x0204,0x0205,0x0206,0x0207,0x0208,0x020e,0x020f,0x0210,0x0212,0x0213,0x0214,0x0216,0x0219,0x021a,0x021b,
		0x021d,0x021e,0x021f,0x0222,0x0223,0x0225,0x0226,0x0227,0x0228,0x0229,0x022a,0x022b,0x0232,0x0236,0x0237,0x023a,0x023b,0x023d,0x023e,0x0300,
		0x0301,0x0302,0x0419,0x061d,0x061e};
		char* mids[] = {"Studio PCTV USB (SECAM)","Studio PCTV USB (PAL)","Miro PCTV USB","Studio PCTV USB (NTSC) with FM radio","Systems MovieBox Device",
		"MovieBox USB_B","DVC 150B","Systems MovieBox Deluxe Device","Dazzle DVC90 Video Device","Studio PCTV USB2",
		"PCTV 200e","PCTV 400e BDA Device","Studio PCTV USB (PAL) with FM radio","Studio PCTV USB (NTSC)","500-USB Device",
		"Studio PCTV USB (PAL) with FM radio","PCTV 60e","PCTV 260e","Dazzle DVC100 Audio Device","Dazzle DVC130/DVC170",
		"Dazzle DVC130","Dazzle DVC170","PCTV Sat HDTV Pro BDA Device","PCTV Sat Pro BDA Device","DazzleTV Sat BDA Device",
		"Remote Kit Infrared Transceiver","PCTV 330e","PCTV for Mac, HD Stick","PCTV DVB-T Flash Stick","PCTV Dual DVB-T 2001e",
		"PCTV 160e","PCTV 71e [Afatech AF9015]","PCTV 170e","PCTV 72e [DiBcom DiB7000PC]","PCTV 73e [DiBcom DiB7000PC]",
		"PCTV 801e","PCTV 801e SE","PCTV 340e","PCTV 340e SE","Studio Linx Video input cable (NTSC)",
		"Studio Linx Video input cable (PAL)","Dazzle DVC120","PCTV Bungee USB (PAL) with FM radio","PCTV Deluxe (NTSC) Device","PCTV Deluxe (PAL) Device"
		};
		InsertProducts(0x2304, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0011};
		char* mids[] = {"CitiDISK Jr. IDE Enclosure"};
		InsertProducts(0x2318, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0010,0x003b,0x003f,0x0042,0x0043,0x0044,0x0045,0x8036};
		char* mids[] = {"Uno (CDC ACM)","Mega 2560 (CDC ACM)","Serial Adapter (CDC ACM)","Mega ADK (CDC ACM)","Mega 2560 R3 (CDC ACM)",
		"Uno R3 (CDC ACM)","Mega ADK R3 (CDC ACM)","Serial R3 (CDC ACM)","Leonardo (CDC ACM, HID)"};
		InsertProducts(0x2341, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"5 MegaPixel Digital Still Camera [DSC5M]"};
		InsertProducts(0x2373, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Digital Audio Player"};
		InsertProducts(0x2375, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6688};
		char* mids[] = {"PD7X Portable Storage"};
		InsertProducts(0x2406, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x00dc};
		char* mids[] = {"aes220 FPGA Mini-Module"};
		InsertProducts(0x2443, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2008};
		char* mids[] = {"U209-000-R Serial Port"};
		InsertProducts(0x2478, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3209};
		char* mids[] = {"7-in-1 Card Reader"};
		InsertProducts(0x2632, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1101,0x1201,0x1202,0x1203,0x1204,0x1205,0x1206,0x1207,0x1208,0x1209,0x1210,0x1211,0x1212,0x1213};
		char* mids[] = {"TNT DVB-T/DAB/DAB+/FM","FM Transmitter/Receiver","MediaTV Analog/FM/DVB-T","MediaTV Analog/FM/DVB-T MiniPCIe","MediaTV Analog/FM/ATSC",
		"SkyTV Ultimate V","MediaTV DVB-T MiniPCIe","Sundtek HD Capture","Sundtek SkyTV Ultimate III","MediaTV Analog/FM/ATSC MiniPCIe",
		"MediaTV Pro III (EU)","MediaTV Pro III (US)","MediaTV Pro III MiniPCIe (EU)","MediaTV Pro III MiniPCIe (US)"};
		InsertProducts(0x2659, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x200f};
		char* mids[] = {"CT-S310 Label printer"};
		InsertProducts(0x2730, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0003,0x1001,0x1002,0x1003,0x1004,0x1005,0x1006,0x1007,0x1008,0x1009,0x100a,0x100b,0x100c,0x100d,0x100e,0x100f,0x1012,0x1013,0x1014,0x1016,
		0x1017,0x1018,0x1019,0x101a,0x101b,0x102b,0x102c,0x103f,0x1040,0x1041,0x1042,0x1043,0x1044};
		char* mids[] = {"MPIO HS100","MPIO FY200","MPIO FL100","MPIO FD100","MPIO HD200",
		"MPIO HD300","MPIO FG100","MPIO FG130","MPIO FY300","MPIO FY400",
		"MPIO FL300","MPIO HS200","MPIO FL350","MPIO FY500","MPIO FY500",
		"MPIO FY600","MPIO FL400","MPIO HD400","MPIO HD400","MPIO FY700",
		"MPIO FY700","MPIO FY800","MPIO FY800","MPIO FY900","MPIO FY900",
		"MPIO FL500","MPIO FL500","MPIO FY570","MPIO FY570","MPIO FY670",
		"MPIO FY670","HCT HMD-180A","HCT HMD-180A"};
		InsertProducts(0x2735, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0a01,0x905c,0x9060,0x9120,0x9130,0x913c,0x9150,0x9153,0x915d,0x930b,0x930c};
		char* mids[] = {"ScanJet 4600 series","Che-Ez Snap SNAP-U/Digigr8/Soundstar TDC-35","A130","Che-ez! Snap / iClick Tiny VGA Digital Camera","TCG 501",
		"Argus DC-1730","Mini Cam","iClick 5X","Cyberpix S-210S / Little Tikes My Real Digital Camera","CCD Webcam(PC370R)",
		"CCD Webcam(PC370R)"};
		InsertProducts(0x2770, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0161,0x160f,0x3300};
		char* mids[] = {"WL-161 802.11b Wireless Adapter [SiS 162U]","WL-160g 802.11g Wireless Adapter [Envara WiND512]","WL-140 / Hawking HWU36D 802.11b Wireless Adapter [Intersil PRISM 3]"};
		InsertProducts(0x2821, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x012c};
		char* mids[] = {"Camera Device"};
		InsertProducts(0x2899, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x14ea};
		char* mids[] = {"GW-US11H WLAN"};
		InsertProducts(0x2c02, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000};
		char* mids[] = {"Wireless Optical Mouse"};
		InsertProducts(0x2c1a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"TrackerPod Camera Stand"};
		InsertProducts(0x3125, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4fb1};
		char* mids[] = {"MonsterTV P2H"};
		InsertProducts(0x3275, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1701};
		char* mids[] = {"Fast Ethernet"};
		InsertProducts(0x3334, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x043a,0x0e3a,0xa0a3};
		char* mids[] = {"Mio A701 DigiWalker PPCPhone","Pocket PC 300 GPS SL / Typhoon MyGuide 3500","deltaX 5 BT (D) PDA"};
		InsertProducts(0x3340, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xf110};
		char* mids[] = {"Security Key"};
		InsertProducts(0x3504, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0015,0x0022,0x0042,0x0054};
		char* mids[] = {"Travel Flash","Mass Storge Device","Hi-Speed Mass Storage Device","Cool Drive U339 Flash Disk","Flash Drive (2GB)"
		};
		InsertProducts(0x3538, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6901};
		char* mids[] = {"Media Reader"};
		InsertProducts(0x3579, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"5-in-1 Card Reader"};
		InsertProducts(0x3838, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x12c0,0x12d0,0x12e0,0x12f0,0x1750,0x17b0,0x1820,0x1830,0x1f00,0x1f10,0x1f20,0x1f30,0x1f40,0x1f50,0x2f80,0x2f90,0x702b,0x703c,0x709b,0x7254,
		0x729e};
		char* mids[] = {"DAQPad-6020E","DAQPad-6507","NI 4350","NI 5102","DAQPad-6508",
		"USB-ISA-Bridge","DAQPad-6020E (68 pin I/O)","DAQPad-6020E (BNC)","DAQPad-6024E","DAQPad-6024E",
		"DAQPad-6025E","DAQPad-6025E","DAQPad-6036E","DAQPad-6036E","DAQPad-6052E",
		"DAQPad-6052E","GPIB-USB-B","USB-485 RS485 Cable","GPIB-USB-HS","NI MIO (data acquisition card) firmware updater",
		"USB-6251 (OEM) data acquisition card"};
		InsertProducts(0x3923, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0a09};
		char* mids[] = {"USB2.0-SCSI Bridge USB2-SC"};
		InsertProducts(0x40bb, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1301};
		char* mids[] = {"IR-2510 usb phone"};
		InsertProducts(0x4101, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001,0x1003,0x1005,0x1007,0x1008,0x100a,0x1014,0x1019,0x1034,0x1040,0x1041,0x1101,0x1103,0x1105,0x1113,0x1117,0x1119,0x1141,0x2002,0x2101,
		0x2102,0x2105};
		char* mids[] = {"iFP-100 series mp3 player","iFP-300 series mp3 player","iFP-500 series mp3 player","iFP-700 series mp3/ogg vorbis player","iFP-800 series mp3/ogg vorbis player",
		"iFP-1000 series mp3/ogg vorbis player","T20 series mp3/ogg vorbis player (ums firmware)","T30","T60","M1Player",
		"E100 (ums)","iFP-100 series mp3 player (ums firmware)","iFP-300 series mp3 player (ums firmware)","iFP-500 series mp3 player (ums firmware)","T10 (alternate)",
		"T10","T30 series mp3/ogg/wma player","E100 (mtp)","H10 6GB","H10 20GB (mtp)",
		"H10 5GB (mtp)","H10 5/6GB (mtp)"};
		InsertProducts(0x4102, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0000,0x0001,0x0058,0x1001,0x1002,0x1003,0x1005,0x2001,0x2002,0x2003,0x2005,0x2010,0x2011,0x2100,0x2101,0x2105,0x2106,0x2500,0x2513,0x3010,
		0x3012,0x3016,0x3200,0x4001,0x4002,0x4003,0x4004,0x4005,0x4006,0x4007,0x4008,0x4009,0x4011,0x5103,0x5105,0x5107,0x5109,0x5110,0x5111,0x5112,
		0x5113,0x5114,0x5115,0x5116,0x5117,0x5118,0x5124,0x5128,0x5200,0x5202,0x5203,0x5210,0x5211,0x5220,0x5225,0x5226,0x5300,0x5400,0x5401,0x5513,
		0x5601,0x5602,0x5631,0x5905,0x8000,0x8010,0x8100,0x8102,0x8103,0x8104,0x8105,0x8106,0x8110,0x8111,0x8114,0x8115,0x8116,0x8117,0x8118,0x8120,
		0x8121,0x8122,0x8123,0x8124,0x8126,0x8127,0x8128,0x8129,0x8131,0x8133,0x8134,0x8135,0x8136,0x8137,0x8138,0x8140,0x8142,0x8147,0x8156,0x8157,
		0x8158,0x8160,0x8161,0x8162,0x8171,0x8172,0x8183,0x8184,0x8185,0x8186,0x8187,0x8501,0x9500,0xa001,0xa005,0xa700};
		char* mids[] = {"DRAC 5 Virtual Keyboard and Mouse","DRAC 5 Virtual Media","Port Replicator","Keyboard Hub","Keyboard Hub",
		"Keyboard Hub","Multimedia Pro Keyboard Hub","Keyboard HID Support","SK-8125 Keyboard","Keyboard",
		"RT7D50 Keyboard","Keyboard","Multimedia Pro Keyboard","SK-3106 Keyboard","SmartCard Reader Keyboard",
		"Model L100 Keyboard","Dell QuietKey Keyboard","DRAC4 Remote Access Card","internal USB Hub of E-Port Replicator","Optical Wheel Mouse",
		"Optical Wheel Mouse","Optical 5-Button Wheel Mouse","Mouse","Axim X5","Axim X3",
		"Axim X30","Axim Sync","Axim Sync","Axim Sync","Axim Sync",
		"Axim Sync","Axim Sync","Axim X51v","AIO Printer A940","AIO Printer A920",
		"AIO Printer A960","Photo AIO Printer 922","Photo AIO Printer 962","Photo AIO Printer 942","Photo AIO Printer 924",
		"Photo AIO Printer 944","Photo AIO Printer 964","Photo AIO Printer 926","AIO Printer 946","Photo AIO Printer 966",
		"AIO 810","Laser MFP 1815","Photo AIO 928","Laser Printer","Printing Support",
		"Printing Support","Printing Support","1110 Laser Printer","Laser MFP 1600n","Printing Support",
		"Printing Support","Laser Printer","Laser Printer","Laser Printer","WLA3310 Wireless Adapter [Intersil ISL3887]",
		"Laser Printer 3100cn","Laser Printer 3000cn","Laser Printer 5100cn","Printing Support","BC02 Bluetooth Adapter",
		"TrueMobile Bluetooth Module in","TrueMobile 1180 802.11b Adapter [Intersil PRISM 3]","TrueMobile 1300 802.11g Wireless Adapter [Intersil ISL3880]","Wireless 350 Bluetooth","Wireless 1450 Dual-band (802.11a/b/g) Adapter [Intersil ISL3887]",
		"U2 in HID - Driver","Wireless 350 Bluetooth Internal Card in","Wireless 3xx Bluetooth Internal Card","Wireless 3xx Bluetooth Internal Card in","Wireless 5700 Mobile Broadband (CDMA EV-DO) Minicard Modem",
		"Wireless 5500 Mobile Broadband (3G HSDPA) Minicard Modem","Wireless 5505 Mobile Broadband (3G HSDPA) Minicard Modem","Wireless 5700 Mobile Broadband (CDMA EV-DO) Expresscard Modem","Wireless 5510 Mobile Broadband (3G HSDPA) Expresscard Status Port","Bluetooth adapter",
		"Eastfold in HID","Eastfold in DFU","eHome Infrared Receiver","eHome Infrared Receiver","Wireless 355 Bluetooth",
		"Wireless 355 Module with Bluetooth 2.0 + EDR Technology.","Wireless 5700-Sprint Mobile Broadband (CDMA EV-DO) Mini-Card Status Port","Wireless 5700-Telus Mobile Broadband (CDMA EV-DO) Mini-Card Status Port","Wireless 360 Bluetooth 2.0 + EDR module.","Wireless 5720 VZW Mobile Broadband (EVDO Rev-A) Minicard GPS Port",
		"Wireless 5720 Sprint Mobile Broadband (EVDO Rev-A) Minicard Status Port","Wireless 5720 TELUS Mobile Broadband (EVDO Rev-A) Minicard Diagnostics Port","Wireless 5520 Cingular Mobile Broadband (3G HSDPA) Minicard Diagnostics Port","Wireless 5520 Voda L Mobile Broadband (3G HSDPA) Minicard Status Port","Wireless 5520 Voda I Mobile Broadband (3G HSDPA) Minicard EAP-SIM Port",
		"Wireless 360 Bluetooth","Mobile 360 in DFU","F3507g Mobile Broadband Module","Wireless 370 Bluetooth Mini-card","Integrated Keyboard",
		"Integrated Touchpad / Trackstick","Wireless 365 Bluetooth","Integrated Keyboard","Integrated Touchpad [Synaptics]","Gobi Wireless Modem (QDL mode)",
		"Gobi Wireless Modem","F3607gw Mobile Broadband Module","F3607gw v2 Mobile Broadband Module","Gobi 2000 Wireless Modem (QDL mode)","Gobi 2000 Wireless Modem",
		"DW375 Bluetooth Module","Bluetooth Adapter","USB CP210x UART Bridge Controller [DW700]","Hub","Internal 2.0 Hub",
		"Hub (in 1905FP LCD Monitor)"};
		InsertProducts(0x413c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x9281,0xba01};
		char* mids[] = {"Iomega Micro Mini 128MB Flash Drive","Intuix Flash Drive"};
		InsertProducts(0x4146, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4201,0x4220};
		char* mids[] = {"Buttons and Lights HID device","Echo 1 Camera"};
		InsertProducts(0x4242, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0700,0x0701,0x0711,0x0720};
		char* mids[] = {"U.S. Robotics USR5426 802.11g Adapter","U.S. Robotics USR5425 Wireless MAXg Adapter","Belkin F5D7051 v3000 802.11g","Dynex DX-BUSB"};
		InsertProducts(0x4317, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5523,0x5537,0x5584};
		char* mids[] = {"USB->RS 232 adapter with Prolifec PL 2303 chipset","13.56Mhz RFID Card Reader and Writer","CH34x printer adapter cable"};
		InsertProducts(0x4348, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4572};
		char* mids[] = {"Shuttle PN31 Remote"};
		InsertProducts(0x4572, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1026};
		char* mids[] = {"Crystal Bar Flash Drive"};
		InsertProducts(0x4586, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x9394};
		char* mids[] = {"Game Cube USB Memory Adaptor 64M"};
		InsertProducts(0x4670, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0011};
		char* mids[] = {"Midistart-2"};
		InsertProducts(0x4752, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2009,0x2010};
		char* mids[] = {"PEL-2000 Series Electronic Load (CDC)","PEL-2000 Series Electronic Load (CDC)"};
		InsertProducts(0x4757, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"MEZ1000 RDA"};
		InsertProducts(0x4766, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7288};
		char* mids[] = {"Ultra Traveldrive 160G 2.5\" HDD"};
		InsertProducts(0x4855, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xcb01,0xce17};
		char* mids[] = {"SP-U25/120G","1TB SimpleDrive II USB External Hard Drive"};
		InsertProducts(0x4971, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0002};
		char* mids[] = {"V-Link","V-DAC II"};
		InsertProducts(0x4d46, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0bb8,0x0bb9,0x0fa0,0x0fa1};
		char* mids[] = {"Grandtec USB1.1 DVB-T (cold)","Grandtec USB1.1 DVB-T (warm)","Grandtec USB1.1 DVB-T (cold)","Grandtec USB1.1 DVB-T (warm)"};
		InsertProducts(0x5032, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2234,0x2235};
		char* mids[] = {"WUSB54G v1 802.11g Adapter [Intersil ISL3886]","WUSB54GP v1 802.11g Adapter [Intersil ISL3886]"};
		InsertProducts(0x5041, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4013};
		char* mids[] = {"WLAN Adapter"};
		InsertProducts(0x50c2, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1809};
		char* mids[] = {"ZD1211"};
		InsertProducts(0x5173, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1001};
		char* mids[] = {"Cetus CDC Device"};
		InsertProducts(0x5219, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1234};
		char* mids[] = {"PDS6062T Oscilloscope"};
		InsertProducts(0x5345, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0003,0x0004,0x0005,0x0041,0x0042,0x0064};
		char* mids[] = {"SuperPen WP3325U Tablet","Tablet WP4030U","Tablet WP5540U","Tablet WP8060U","Genius PenSketch 6x8 Tablet",
		"Tablet PF1209","Aiptek HyperPen 10000U"};
		InsertProducts(0x5543, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1110,0x1120,0x2222,0x3333,0x3337,0x3340,0x3344,0x3411,0x3422};
		char* mids[] = {"VGA2USB","KVM2USB","DVI2USB","VGA2USB Pro","KVM2USB Pro",
		"VGA2USB LR","KVM2USB LR","DVI2USB Solo","DVI2USB Duo"};
		InsertProducts(0x5555, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0015,0x0102,0x0103,0x0201,0x1234,0xa103,0xb000,0xb004,0xb00b,0xb00c,0xb012,0xb200,0xb204,0xb207};
		char* mids[] = {"Hard Drive","SuperDisk","IDE Hard Drive","DDI to Reader-19","ATAPI Bridge",
		"Sandisk SDDR-55 SmartMedia Card Reader","USB to CompactFlash Card Reader","OnSpec MMC/SD Reader/Writer","USB to Memory Stick Card Reader","USB to SmartMedia Card Reader",
		"Mitsumi FA402M 8-in-2 Card Reader","Compact Flash Reader","MMC/ SD Reader","Memory Stick Reader"};
		InsertProducts(0x55aa, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0832};
		char* mids[] = {"UT2000/UT3000 Digital Storage Oscilloscope"};
		InsertProducts(0x5656, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Touchscreen"};
		InsertProducts(0x595a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100,0x0101,0x0102,0x01a6,0x01a7,0x01a9,0x0200,0x0203,0x0241,0x02d0,0x03d0};
		char* mids[] = {"Orbicam","USB2.0 Camera","Crystal Eye Webcam","Lenovo Integrated Webcam","Lenovo Integrated Webcam",
		"Lenovo Integrated Webcam","OrbiCam","BisonCam NB Pro 1300","BisonCam, NB Pro","Lenovo Integrated Webcam [R5U877]",
		"Lenovo Integrated Webcam [R5U877]"};
		InsertProducts(0x5986, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0260,0x0280,0x0282,0x0283,0x0284,0x0290,0x5257};
		char* mids[] = {"RT2570","802.11a/b/g/n USB Wireless LAN Card","802.11b/g/n USB Wireless LAN Card","802.11b/g/n USB Wireless LAN Card","802.11a/b/g/n USB Wireless LAN Card",
		"ZW-N290 802.11n [Realtek RTL8192SU]","Metronic 495257 wifi 802.11ng"};
		InsertProducts(0x5a57, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xdec0,0xdec1};
		char* mids[] = {"TV Wander","TV Voyage"};
		InsertProducts(0x6000, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4740};
		char* mids[] = {"XBurst Jz4740 boot mode"};
		InsertProducts(0x601a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x182d,0x2068};
		char* mids[] = {"USB 2.0 Ethernet","USB to serial cable (v2)"};
		InsertProducts(0x6189, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0100};
		char* mids[] = {"Ir reciver f. remote control"};
		InsertProducts(0x6253, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x01c8};
		char* mids[] = {"PlayStation Portable [Mass Storage]"};
		InsertProducts(0x6472, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0232};
		char* mids[] = {"ARK3116 Serial"};
		InsertProducts(0x6547, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001};
		char* mids[] = {"Touchscreen"};
		InsertProducts(0x6615, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0667,0x2667,0x8802,0x8804};
		char* mids[] = {"WiseGroup Smart Joy PSX, PS-PC Smart JoyPad","JCOP BlueZ Smartcard reader","SmartJoy Dual Plus PS2 converter","WiseGroup SuperJoy Box 5"};
		InsertProducts(0x6666, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8802,0x8811};
		char* mids[] = {"SmartJoy Dual Plus PS2 converter","Deluxe Dance Mat"};
		InsertProducts(0x6677, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xa727};
		char* mids[] = {"3CRUSB10075 802.11bg [ZyDAS ZD1211]"};
		InsertProducts(0x6891, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3829};
		char* mids[] = {"Opera1 DVB-S (warm state)"};
		InsertProducts(0x695c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xb001};
		char* mids[] = {"VoIP Phone"};
		InsertProducts(0x6993, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2202};
		char* mids[] = {"UF5/UF6/UF7/UF8 MIDI Master Keyboard"};
		InsertProducts(0x7104, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2149};
		char* mids[] = {"EntropyKing Random Number Generator"};
		InsertProducts(0x726c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x5920,0x5928};
		char* mids[] = {"Q-Box II DVB-S2 HD","Q-Box II DVB-S2 HD"};
		InsertProducts(0x734c, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7711,0x7717,0x7718,0x7722,0x7811};
		char* mids[] = {"EW-7711UTn nLite Wireless Adapter [Ralink RT2870]","EW-7717UN 802.11n Wireless Adapter [Ralink RT2870]","EW-7718UN 802.11n Wireless Adapter [Ralink RT2870]","EW-7722UTn 802.11n Wireless Adapter [Ralink RT307x]","EW-7811Un 802.11n Wireless Adapter [Realtek RTL8188CUS]"
		};
		InsertProducts(0x7392, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0001,0x0044,0x0046,0x0100,0x0101,0x0110,0x0120,0x0180,0x0181,0x0182,0x0186,0x0188,0x0200,0x0431,0x0510,0x0630,0x0780,0x07d3,0x0dad,0x1010,
		0x110a,0x110b,0x1110,0x1111,0x1134,0x1139,0x1234,0x1403,0x1405,0x1406,0x2448,0x3100,0x3101,0x3240,0x3241,0x8602,0x9303,0x9500,0x9890,0xbeef,
		0xc013,0xf001,0xf1a5};
		char* mids[] = {"AnyPoint (TM) Home Network 1.6 Mbps Wireless Adapter","CPU DRAM Controller","HD Graphics","Personal Audio Player 3000","Personal Audio Player 3000",
		"Easy PC Camera","PC Camera CS120","WiMAX Connection 2400m","WiMAX Connection 2400m","WiMAX Connection 2400m",
		"WiMAX Connection 2400m","WiMAX Connection 2400m","AnyPoint(TM) Wireless II Network 11Mbps Adapter [Atmel AT76C503A]","Intel Pro Video PC Camera","Digital Movie Creator",
		"Pocket PC Camera","CS780 Microphone Input","BLOB boot loader firmware","Cherry MiniatureCard Keyboard","AnyPoint(TM) Home Network 10 Mbps Phoneline Adapter",
		"Bluetooth Controller from (Ericsson P4A)","Bluetooth Controller from (Intel/CSR)","PRO/Wireless LAN Module","PRO/Wireless 2011B 802.11b Adapter [Intersil PRISM 2.5]","Hollister Mobile Monitor",
		"In-Target Probe (ITP)","Prototype Reader/Writer","WiMAX Connection 2400m","WiMAX Connection 2400m","WiMAX Connection 2400m",
		"82801 PCI Bridge","PRO/DSL 3220 Modem - WAN","PRO/DSL 3220 Modem","AnyPointÂ® 3240 Modem - WAN","AnyPointÂ® 3240 Modem",
		"Miniature Card Slot","Intel 8x930Hx Hub","CE 9500 DVB-T","82930 Test Board","SCM Miniature Card Reader/Writer",
		"Wireless HID Station","XScale PXA27x Bulverde flash","Z-U130 [Value Solid State Drive]"};
		InsertProducts(0x8086, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0020,0x0024};
		char* mids[] = {"Integrated Rate Matching Hub","Integrated Rate Matching Hub"};
		InsertProducts(0x8087, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0021};
		char* mids[] = {"USB Tablet"};
		InsertProducts(0x80ee, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x3201,0x3301};
		char* mids[] = {"Retro Adapter","Retro Adapter Mouse"};
		InsertProducts(0x8282, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2000};
		char* mids[] = {"Flashdisk"};
		InsertProducts(0x8341, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x182d};
		char* mids[] = {"WL-022 802.11b Adapter"};
		InsertProducts(0x9016, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xd630,0xd650,0xd660};
		char* mids[] = {"DVB-S S630","DVB-S2 S650","DVB-S2 S660"};
		InsertProducts(0x9022, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0004};
		char* mids[] = {"R3 Compatible Device"};
		InsertProducts(0x9148, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x7703,0x7705,0x7715,0x7717,0x7720,0x7730,0x7780,0x7830,0x7832,0x7840};
		char* mids[] = {"MCS7703 Serial Port Adapter","MCS7705 Parallel port adapter","MCS7715 Parallel and serial port adapter","MCS7717 3-port hub with serial and parallel adapter","MCS7720 Dual serial port adapter",
		"MCS7730 10/100 Mbps Ethernet adapter","MCS7780 4Mbps Fast IrDA Adapter","MCS7830 10/100 Mbps Ethernet adapter","MCS7832 10/100 Mbps Ethernet adapter","MCS7820/MCS7840 2/4 port serial adapter"
		};
		InsertProducts(0x9710, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x8988};
		char* mids[] = {"V.cap Camera Device"};
		InsertProducts(0x99fa, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x4b8f};
		char* mids[] = {"ProxMark-3 RFID Instrument"};
		InsertProducts(0x9ac4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0610,0x0611,0x0612,0x0613,0x0614,0x0615,0x0616,0x0617,0x0618};
		char* mids[] = {"Dino-Lite Digital Microscope (SN9C201 + HV7131R)","Dino-Lite Digital Microscope (SN9C201 + HV7131R)","Dino-Lite Digital Microscope (SN9C120 + HV7131R)","Dino-Lite Digital Microscope (SN9C201 + HV7131R)","Dino-Lite Digital Microscope (SN9C201 + MI1310/MT9M111)",
		"Dino-Lite Digital Microscope (SN9C201 + MI1310/MT9M111)","Dino-Lite Digital Microscope (SN9C120 + HV7131R)","Dino-Lite Digital Microscope (SN9C201 + MI1310/MT9M111)","Dino-Lite Digital Microscope (SN9C201 + HV7131R)"};
		InsertProducts(0xa128, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0610,0x0611,0x0613,0x0614,0x0615,0x0617,0x0618};
		char* mids[] = {"Dino-Lite Digital Microscope","Dino-Lite Digital Microscope","Dino-Lite Digital Microscope","Dino-Lite Pro Digital Microscope","Dino-Lite Pro Digital Microscope",
		"Dino-Lite Pro Digital Microscope","Dino-Lite Digital Microscope"};
		InsertProducts(0xa168, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xe110};
		char* mids[] = {"OK1ZIA Davac 4.x"};
		InsertProducts(0xa600, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6893,0x6895,0x6897};
		char* mids[] = {"3CRUSB20075 OfficeConnect Wireless 108Mbps 11g Adapter [Atheros AR5523]","AR5523","AR5523"};
		InsertProducts(0xa727, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0xcdee};
		char* mids[] = {"Petcam"};
		InsertProducts(0xabcd, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x2710};
		char* mids[] = {"ULink"};
		InsertProducts(0xc251, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0002,0x0300};
		char* mids[] = {"AirPCAP Classic 802.11 packet capture adapter","AirPcap NX [Atheros AR9001U-(2)NG]"};
		InsertProducts(0xcace, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0301,0x0501};
		char* mids[] = {"I-PAC Arcade Control Interface","Ultra-Stik Ultimarc Ultra-Stik Player 1"};
		InsertProducts(0xd209, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x1130,0x1131,0x1132,0x1140,0x1141,0x1142,0x1150,0x1151,0x1152,0x1160,0x1161,0x1162};
		char* mids[] = {"Astribank series","Astribank series","Astribank series","Astribank series","Astribank series",
		"Astribank series","Astribank series","Astribank series","Astribank series","Astribank 2 series",
		"Astribank 2 series","Astribank 2 series"};
		InsertProducts(0xe4e4, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x0920};
		char* mids[] = {"Make Controller Kit"};
		InsertProducts(0xeb03, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x17de,0x17df,0x2571,0x2710,0x2750,0x2761,0x2776,0x2800,0x2801,0x2863,0x2870,0x2881,0x50a3,0x50a6,0xe355};
		char* mids[] = {"KWorld V-Stream XPERT DTV - DVB-T USB cold","KWorld V-Stream XPERT DTV - DVB-T USB warm","M035 Compact Web Cam","SilverCrest Webcam","ECS Elitegroup G220 integrated Webcam",
		"EeePC 701 integrated Webcam","Combined audio and video input device","Terratec Cinergy 200","GrabBeeX+ Video Encoder","Video Grabber",
		"Pinnacle PCTV Stick","EM2881 Video Controller","Gadmei UTV380 TV Box","Gadmei UTV330 TV Box","KWorld DVB-T 355U Digital TV Dongle"
		};
		InsertProducts(0xeb1a, mid, mids, ARRAYSIZE(mid));
	}
	{
		DWORD mid[] = {0x6002};
		char* mids[] = {"PhotoSmart C500"};
		InsertProducts(0xf003, mid, mids, ARRAYSIZE(mid));
	}
	}

	void RCSGUsbIds::InsertVendors( DWORD *mid, char** mids, unsigned int size )
	{
		for(unsigned int i=0; i<size; i++)
		{
			mh.insert(mid[i], QString::fromUtf8(mids[i]));
		}
	}

	void RCSGUsbIds::InsertProducts( DWORD vendorId, DWORD *mid, char** mids, unsigned int size )
	{
		QHash<WORD, QString> h;
		for(unsigned int i=0; i<size; i++)
		{
			h.insert(mid[i], QString::fromUtf8(mids[i]));
		}
		mph.insert(vendorId, h);
	}

