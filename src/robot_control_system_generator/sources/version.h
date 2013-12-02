#define RCSGXTEXT(X) #X
#define RCSGTEXT(X) RCSGXTEXT(X)

#define VERSION_MAJOR               1
#define VERSION_MINOR               0
#define VERSION_REVISION            0
#define VERSION_BUILD               0

#define VER_FILE_DESCRIPTION_STR    "Robot Control System Generator"
#define VER_FILE_VERSION            VERSION_MAJOR, VERSION_MINOR, VERSION_REVISION, VERSION_BUILD
#define VER_FILE_VERSION_STR        RCSGTEXT(VERSION_MAJOR)    \
								"." RCSGTEXT(VERSION_MINOR)    \
								"." RCSGTEXT(VERSION_REVISION) \
								"." RCSGTEXT(VERSION_BUILD)    \

#define VER_COMPANY_NAME_STR	    "www.robotics.by and/or its subsidiary(-ies)"
#define VER_PRODUCTNAME_STR         "Robot Control System Generator"
#define VER_PRODUCT_VERSION         VER_FILE_VERSION
#define VER_PRODUCT_VERSION_STR     VER_FILE_VERSION_STR
#define VER_ORIGINAL_FILENAME_STR   VER_PRODUCTNAME_STR ".exe"
#define VER_INTERNAL_NAME_STR       "Robot Control System Generator"
#define VER_COPYRIGHT_STR           "Copyright (C) 2013 www.robotics.by and/or its subsidiary(-ies)."
