// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/stringize.hpp>

# if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#    define BOOST_PP_STRINGIZEU8(text) BOOST_PP_STRINGIZEU8_A((text))
#    define BOOST_PP_STRINGIZEU8_A(arg) BOOST_PP_STRINGIZEU8_I arg
#	define BOOST_PP_STRINGIZEU8_I(text) u8#text
# else
#    define BOOST_PP_STRINGIZEU8(text) BOOST_PP_STRINGIZEU8_I(text)
#	define BOOST_PP_STRINGIZEU8_I(text) BOOST_PP_CAT(u8,#text)
# endif
#

#ifdef DCompiler_MSVC
#	define DMibStringizeUTF8 BOOST_PP_STRINGIZEU8
#else
#	define DMibStringizeUTF8 BOOST_PP_STRINGIZE
#endif

#define DMibStringize BOOST_PP_STRINGIZE
//DMibStringizeHelper(_Tokens)
#define DMibStringizeHelper(_Tokens) #_Tokens

#define DMibConcatenate BOOST_PP_CAT
//DMibConcatenateHelper1( _Left, _Right )
#define DMibConcatenateHelper1( _Left, _Right ) DMibConcatenateHelper2(_Left,_Right)
#define DMibConcatenateHelper2( _Left, _Right ) _Left##_Right
