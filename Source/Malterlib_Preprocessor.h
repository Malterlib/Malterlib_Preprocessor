// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#ifdef DCompiler_MSVC
#	define DMibConcatenate_Helper1(d_Left, d_Right) DMibConcatenate_Helper2(~, d_Left ## d_Right)
#	define DMibConcatenate_Helper2(d_Dummy, d_Result) d_Result
#else
#	define DMibConcatenate_Helper1(d_Left, d_Right) d_Left ## d_Right
#endif

#define DMibConcatenate(d_Left, d_Right) DMibConcatenate_Helper1(d_Left, d_Right)

#define DMibStringize_Helper1(...) #__VA_ARGS__

#ifdef DCompiler_MSVC
#	define DMibStringize(d_ToStringize) DMibStringize_Helper2((d_ToStringize))
#	define DMibStringize_Helper2(d_Result) p. d_Result
#else
#	define DMibStringize(d_ToStringize) DMibStringize_Helper1(d_ToStringize)
#endif

#ifdef DCompiler_MSVC
#	define DMibStringizeUTF8(d_ToStringize) DMibStringizeUTF8_Helper2((d_ToStringize))
#	define DMibStringizeUTF8_Helper2(d_Result) DMibStringizeUTF8_Helper1 d_Result
#	define DMibStringizeUTF8_Helper1(d_ToStringize) u8#d_ToStringize
#else
#	define DMibStringizeUTF8 DMibStringize
#endif
