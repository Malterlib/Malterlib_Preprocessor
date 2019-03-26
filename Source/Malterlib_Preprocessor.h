// Copyright © 2015 Hansoft AB 
// Distributed under the MIT license, see license text in LICENSE.Malterlib

#pragma once

#ifdef BOOST_PP_VARIADICS
	#undef BOOST_PP_VARIADICS
#endif // BOOST_PP_VARIADICS	
#define BOOST_PP_VARIADICS 1

#include <boost/preprocessor/if.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/enum.hpp>
#include <boost/preprocessor/repeat.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/enum_params.hpp>
#include <boost/preprocessor/comparison.hpp>


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


#define DMibPreIterateHelper1(_NumIterations) DMibConcatenate(Malterlib/Preprocessor/Source/Private/Iterate_,_NumIterations)
#define DMibPreIterateHelper(_NumIterations) DMibConcatenate(DMibPreIterateHelper1(_NumIterations), ".h")
#define DMibPreIterate(_NumIterations) DMibStringize(DMibPreIterateHelper1(_NumIterations).h)

#define DMibPreIterate_OnLast() (DMibPreIterate_i + 1 == DMibPre_NumIter)


#define DMibPreComma() ,

#define DMibPreEmpty() 


#define DMibPreIfInternal(_Condition, _ResultTrue, _ResultFalse) DMibPreIfInternalHelper( (_Condition, _ResultTrue, _ResultFalse) )
#define DMibPreIfInternalHelper(_x) DMibPreIfInternalHelper2 ## _x

#define DMibPreIfInternalHelper2(_Condition, _ResultTrue, _ResultFalse) DMibPreIfInternalHelper2_2(DMibPreIfInternalHelper ## _Condition(_ResultTrue, _ResultFalse))
#define DMibPreIfInternalHelper2_2(x) x

#define DMibPreIfInternalHelper0(_ResultTrue, _ResultFalse) _ResultFalse
#define DMibPreIfInternalHelper1(_ResultTrue, _ResultFalse) _ResultTrue

//#define DMibPreIf(_Condition, _ResultTrue, _ResultFalse) DMibPreIfHelper(_Condition, _ResultTrue, _ResultFalse)
//#define DMibPreIfHelper(_Condition, _ResultTrue, _ResultFalse) DMibPreIfInternal(DMibPreBoolean(_Condition), _ResultTrue, _ResultFalse)
#define DMibPreLess BOOST_PP_LESS
#define DMibPreIf BOOST_PP_IF
#define DMibPreCommaIfHelper(x) BOOST_PP_COMMA_IF(x)
#define DMibPreCommaIf(x) DMibPreCommaIfHelper(x)

//#define BOOST_PP_ENUM_PARAMS(count, param) BOOST_PP_ENUM_PARAMS_I(count, param)
//#define BOOST_PP_ENUM_PARAMS_I(count, param) BOOST_PP_REPEAT(count, BOOST_PP_ENUM_PARAMS_M, param)
//#define BOOST_PP_ENUM_PARAMS_M(z, n, param) BOOST_PP_COMMA_IF(n) param ## n


#define DMibPreRepeat BOOST_PP_REPEAT

//#define DMibPreRepeat(_Count, _Function, _FunctionParam) DMibPreRepeatHelper(_Count, _Function, _FunctionParam)
#define DMibPreRepeatHelper(_Count, _Function, _FunctionParam) DMibPreRepeatHelper ## _Count(_Function, _FunctionParam, 0)

#define DMibPreRepeatHelper0(_Function, _FunctionParam) 
#define DMibPreRepeatHelper1(_Function, _FunctionParam) _Function(0, _FunctionParam)
#define DMibPreRepeatHelper2(_Function, _FunctionParam) DMibPreRepeatHelper1(_Function, _FunctionParam) _Function(1, _FunctionParam)

#define DMibPreGenerateParams BOOST_PP_ENUM_PARAMS

#define DMibPreGenerateParamsFunc(count, param) DMibPreRepeat(count, DMibPreGenerateParamsFunc_M, param)
#define DMibPreGenerateParamsFunc_M(z, n, param) DMibPreCommaIf(n) param(n)


//#define DMibPreGenerateParams(_Count, _Prefix) DMibPreGenerateParamsHelper(_Count, _Prefix)
#define DMibPreGenerateParamsHelper(_Count, _Prefix) DMibPreRepeat(_Count, DMibPreGenerateParamsHelperImp, _Prefix)
#define DMibPreGenerateParamsHelperImp(_Index, _Prefix) DMibPreCommaIf(_Index) _Prefix ## _Index

#define DMibPreBoolean(_Integer_0_255) DMibPreBooleanHelper((_Integer_0_255))
#define DMibPreBooleanHelper(_Integer_0_255) DMibPreBooleanHelper_ ## _Integer_0_255

#define DMibPreBooleanHelper_(x) DMibPreBooleanHelper_ ## x

#define DMibPreBooleanHelper_0 0
#define DMibPreBooleanHelper_1 1
#define DMibPreBooleanHelper_2 1
#define DMibPreBooleanHelper_3 1
#define DMibPreBooleanHelper_4 1
#define DMibPreBooleanHelper_5 1
#define DMibPreBooleanHelper_6 1
#define DMibPreBooleanHelper_7 1
#define DMibPreBooleanHelper_8 1
#define DMibPreBooleanHelper_9 1
#define DMibPreBooleanHelper_10 1
#define DMibPreBooleanHelper_11 1
#define DMibPreBooleanHelper_12 1
#define DMibPreBooleanHelper_13 1
#define DMibPreBooleanHelper_14 1
#define DMibPreBooleanHelper_15 1
#define DMibPreBooleanHelper_16 1
#define DMibPreBooleanHelper_17 1
#define DMibPreBooleanHelper_18 1
#define DMibPreBooleanHelper_19 1
#define DMibPreBooleanHelper_20 1
#define DMibPreBooleanHelper_21 1
#define DMibPreBooleanHelper_22 1
#define DMibPreBooleanHelper_23 1
#define DMibPreBooleanHelper_24 1
#define DMibPreBooleanHelper_25 1
#define DMibPreBooleanHelper_26 1
#define DMibPreBooleanHelper_27 1
#define DMibPreBooleanHelper_28 1
#define DMibPreBooleanHelper_29 1
#define DMibPreBooleanHelper_30 1
#define DMibPreBooleanHelper_31 1
#define DMibPreBooleanHelper_32 1
#define DMibPreBooleanHelper_33 1
#define DMibPreBooleanHelper_34 1
#define DMibPreBooleanHelper_35 1
#define DMibPreBooleanHelper_36 1
#define DMibPreBooleanHelper_37 1
#define DMibPreBooleanHelper_38 1
#define DMibPreBooleanHelper_39 1
#define DMibPreBooleanHelper_40 1
#define DMibPreBooleanHelper_41 1
#define DMibPreBooleanHelper_42 1
#define DMibPreBooleanHelper_43 1
#define DMibPreBooleanHelper_44 1
#define DMibPreBooleanHelper_45 1
#define DMibPreBooleanHelper_46 1
#define DMibPreBooleanHelper_47 1
#define DMibPreBooleanHelper_48 1
#define DMibPreBooleanHelper_49 1
#define DMibPreBooleanHelper_50 1
#define DMibPreBooleanHelper_51 1
#define DMibPreBooleanHelper_52 1
#define DMibPreBooleanHelper_53 1
#define DMibPreBooleanHelper_54 1
#define DMibPreBooleanHelper_55 1
#define DMibPreBooleanHelper_56 1
#define DMibPreBooleanHelper_57 1
#define DMibPreBooleanHelper_58 1
#define DMibPreBooleanHelper_59 1
#define DMibPreBooleanHelper_60 1
#define DMibPreBooleanHelper_61 1
#define DMibPreBooleanHelper_62 1
#define DMibPreBooleanHelper_63 1
#define DMibPreBooleanHelper_64 1
#define DMibPreBooleanHelper_65 1
#define DMibPreBooleanHelper_66 1
#define DMibPreBooleanHelper_67 1
#define DMibPreBooleanHelper_68 1
#define DMibPreBooleanHelper_69 1
#define DMibPreBooleanHelper_70 1
#define DMibPreBooleanHelper_71 1
#define DMibPreBooleanHelper_72 1
#define DMibPreBooleanHelper_73 1
#define DMibPreBooleanHelper_74 1
#define DMibPreBooleanHelper_75 1
#define DMibPreBooleanHelper_76 1
#define DMibPreBooleanHelper_77 1
#define DMibPreBooleanHelper_78 1
#define DMibPreBooleanHelper_79 1
#define DMibPreBooleanHelper_80 1
#define DMibPreBooleanHelper_81 1
#define DMibPreBooleanHelper_82 1
#define DMibPreBooleanHelper_83 1
#define DMibPreBooleanHelper_84 1
#define DMibPreBooleanHelper_85 1
#define DMibPreBooleanHelper_86 1
#define DMibPreBooleanHelper_87 1
#define DMibPreBooleanHelper_88 1
#define DMibPreBooleanHelper_89 1
#define DMibPreBooleanHelper_90 1
#define DMibPreBooleanHelper_91 1
#define DMibPreBooleanHelper_92 1
#define DMibPreBooleanHelper_93 1
#define DMibPreBooleanHelper_94 1
#define DMibPreBooleanHelper_95 1
#define DMibPreBooleanHelper_96 1
#define DMibPreBooleanHelper_97 1
#define DMibPreBooleanHelper_98 1
#define DMibPreBooleanHelper_99 1
#define DMibPreBooleanHelper_100 1
#define DMibPreBooleanHelper_101 1
#define DMibPreBooleanHelper_102 1
#define DMibPreBooleanHelper_103 1
#define DMibPreBooleanHelper_104 1
#define DMibPreBooleanHelper_105 1
#define DMibPreBooleanHelper_106 1
#define DMibPreBooleanHelper_107 1
#define DMibPreBooleanHelper_108 1
#define DMibPreBooleanHelper_109 1
#define DMibPreBooleanHelper_110 1
#define DMibPreBooleanHelper_111 1
#define DMibPreBooleanHelper_112 1
#define DMibPreBooleanHelper_113 1
#define DMibPreBooleanHelper_114 1
#define DMibPreBooleanHelper_115 1
#define DMibPreBooleanHelper_116 1
#define DMibPreBooleanHelper_117 1
#define DMibPreBooleanHelper_118 1
#define DMibPreBooleanHelper_119 1
#define DMibPreBooleanHelper_120 1
#define DMibPreBooleanHelper_121 1
#define DMibPreBooleanHelper_122 1
#define DMibPreBooleanHelper_123 1
#define DMibPreBooleanHelper_124 1
#define DMibPreBooleanHelper_125 1
#define DMibPreBooleanHelper_126 1
#define DMibPreBooleanHelper_127 1
#define DMibPreBooleanHelper_128 1
#define DMibPreBooleanHelper_129 1
#define DMibPreBooleanHelper_130 1
#define DMibPreBooleanHelper_131 1
#define DMibPreBooleanHelper_132 1
#define DMibPreBooleanHelper_133 1
#define DMibPreBooleanHelper_134 1
#define DMibPreBooleanHelper_135 1
#define DMibPreBooleanHelper_136 1
#define DMibPreBooleanHelper_137 1
#define DMibPreBooleanHelper_138 1
#define DMibPreBooleanHelper_139 1
#define DMibPreBooleanHelper_140 1
#define DMibPreBooleanHelper_141 1
#define DMibPreBooleanHelper_142 1
#define DMibPreBooleanHelper_143 1
#define DMibPreBooleanHelper_144 1
#define DMibPreBooleanHelper_145 1
#define DMibPreBooleanHelper_146 1
#define DMibPreBooleanHelper_147 1
#define DMibPreBooleanHelper_148 1
#define DMibPreBooleanHelper_149 1
#define DMibPreBooleanHelper_150 1
#define DMibPreBooleanHelper_151 1
#define DMibPreBooleanHelper_152 1
#define DMibPreBooleanHelper_153 1
#define DMibPreBooleanHelper_154 1
#define DMibPreBooleanHelper_155 1
#define DMibPreBooleanHelper_156 1
#define DMibPreBooleanHelper_157 1
#define DMibPreBooleanHelper_158 1
#define DMibPreBooleanHelper_159 1
#define DMibPreBooleanHelper_160 1
#define DMibPreBooleanHelper_161 1
#define DMibPreBooleanHelper_162 1
#define DMibPreBooleanHelper_163 1
#define DMibPreBooleanHelper_164 1
#define DMibPreBooleanHelper_165 1
#define DMibPreBooleanHelper_166 1
#define DMibPreBooleanHelper_167 1
#define DMibPreBooleanHelper_168 1
#define DMibPreBooleanHelper_169 1
#define DMibPreBooleanHelper_170 1
#define DMibPreBooleanHelper_171 1
#define DMibPreBooleanHelper_172 1
#define DMibPreBooleanHelper_173 1
#define DMibPreBooleanHelper_174 1
#define DMibPreBooleanHelper_175 1
#define DMibPreBooleanHelper_176 1
#define DMibPreBooleanHelper_177 1
#define DMibPreBooleanHelper_178 1
#define DMibPreBooleanHelper_179 1
#define DMibPreBooleanHelper_180 1
#define DMibPreBooleanHelper_181 1
#define DMibPreBooleanHelper_182 1
#define DMibPreBooleanHelper_183 1
#define DMibPreBooleanHelper_184 1
#define DMibPreBooleanHelper_185 1
#define DMibPreBooleanHelper_186 1
#define DMibPreBooleanHelper_187 1
#define DMibPreBooleanHelper_188 1
#define DMibPreBooleanHelper_189 1
#define DMibPreBooleanHelper_190 1
#define DMibPreBooleanHelper_191 1
#define DMibPreBooleanHelper_192 1
#define DMibPreBooleanHelper_193 1
#define DMibPreBooleanHelper_194 1
#define DMibPreBooleanHelper_195 1
#define DMibPreBooleanHelper_196 1
#define DMibPreBooleanHelper_197 1
#define DMibPreBooleanHelper_198 1
#define DMibPreBooleanHelper_199 1
#define DMibPreBooleanHelper_200 1
#define DMibPreBooleanHelper_201 1
#define DMibPreBooleanHelper_202 1
#define DMibPreBooleanHelper_203 1
#define DMibPreBooleanHelper_204 1
#define DMibPreBooleanHelper_205 1
#define DMibPreBooleanHelper_206 1
#define DMibPreBooleanHelper_207 1
#define DMibPreBooleanHelper_208 1
#define DMibPreBooleanHelper_209 1
#define DMibPreBooleanHelper_210 1
#define DMibPreBooleanHelper_211 1
#define DMibPreBooleanHelper_212 1
#define DMibPreBooleanHelper_213 1
#define DMibPreBooleanHelper_214 1
#define DMibPreBooleanHelper_215 1
#define DMibPreBooleanHelper_216 1
#define DMibPreBooleanHelper_217 1
#define DMibPreBooleanHelper_218 1
#define DMibPreBooleanHelper_219 1
#define DMibPreBooleanHelper_220 1
#define DMibPreBooleanHelper_221 1
#define DMibPreBooleanHelper_222 1
#define DMibPreBooleanHelper_223 1
#define DMibPreBooleanHelper_224 1
#define DMibPreBooleanHelper_225 1
#define DMibPreBooleanHelper_226 1
#define DMibPreBooleanHelper_227 1
#define DMibPreBooleanHelper_228 1
#define DMibPreBooleanHelper_229 1
#define DMibPreBooleanHelper_230 1
#define DMibPreBooleanHelper_231 1
#define DMibPreBooleanHelper_232 1
#define DMibPreBooleanHelper_233 1
#define DMibPreBooleanHelper_234 1
#define DMibPreBooleanHelper_235 1
#define DMibPreBooleanHelper_236 1
#define DMibPreBooleanHelper_237 1
#define DMibPreBooleanHelper_238 1
#define DMibPreBooleanHelper_239 1
#define DMibPreBooleanHelper_240 1
#define DMibPreBooleanHelper_241 1
#define DMibPreBooleanHelper_242 1
#define DMibPreBooleanHelper_243 1
#define DMibPreBooleanHelper_244 1
#define DMibPreBooleanHelper_245 1
#define DMibPreBooleanHelper_246 1
#define DMibPreBooleanHelper_247 1
#define DMibPreBooleanHelper_248 1
#define DMibPreBooleanHelper_249 1
#define DMibPreBooleanHelper_250 1
#define DMibPreBooleanHelper_251 1
#define DMibPreBooleanHelper_252 1
#define DMibPreBooleanHelper_253 1
#define DMibPreBooleanHelper_254 1
#define DMibPreBooleanHelper_255 1
#define DMibPreBooleanHelper_256 1

