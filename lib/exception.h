// Licensed under the MIT License.

#ifndef EXCEPTION_f152f59488c248f48b77fc64f8dd0fc6
#define EXCEPTION_f152f59488c248f48b77fc64f8dd0fc6

/** Specifies an error that occurs at runtime. */
enum Exception
{
    /** There is not enough memory to continue the program. */
    EXCEPTION_OUT_OF_MEMORY = -1,

    /** A composite format string is not well formed. */
    EXCEPTION_FORMAT = -2,

    /** The value of an argument is outside the allowable range. */
    EXCEPTION_ARGUMENT_OUT_OF_RANGE = -3
};

/** Specifies an error that occurs at runtime. */
typedef enum Exception Exception;

#endif
