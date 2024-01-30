// Licensed under the MIT License.

#ifndef EXCEPTION_f152f59488c248f48b77fc64f8dd0fc6
#define EXCEPTION_f152f59488c248f48b77fc64f8dd0fc6

/** Specifies an error that occurs at runtime. */
enum Exception
{
    /** There is not enough memory to continue the program. */
    EXCEPTION_OUT_OF_MEMORY = -1,

    /** */
    EXCEPTION_FORMAT = -2
};

/** Specifies an error that occurs at runtime. */
typedef enum Exception Exception;

#endif
