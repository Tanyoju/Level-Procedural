// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SimpleNoiseGeneratorsBPLibrary.h"

#ifdef SIMPLENOISEGENERATORS_SimpleNoiseGeneratorsBPLibrary_generated_h
#error "SimpleNoiseGeneratorsBPLibrary.generated.h already included, missing '#pragma once' in SimpleNoiseGeneratorsBPLibrary.h"
#endif
#define SIMPLENOISEGENERATORS_SimpleNoiseGeneratorsBPLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class USimpleNoiseGeneratorsBPLibrary ******************************************
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_SimpleNoiseGenerators_Source_SimpleNoiseGenerators_Public_SimpleNoiseGeneratorsBPLibrary_h_14_RPC_WRAPPERS \
	DECLARE_FUNCTION(execVoronoiNoise4D); \
	DECLARE_FUNCTION(execVoronoiNoise3D); \
	DECLARE_FUNCTION(execVoronoiNoise2D); \
	DECLARE_FUNCTION(execWorleyNoise4D); \
	DECLARE_FUNCTION(execWorleyNoise3D); \
	DECLARE_FUNCTION(execWorleyNoise2D); \
	DECLARE_FUNCTION(execWorleyNoise1D); \
	DECLARE_FUNCTION(execPerlinNoise4D); \
	DECLARE_FUNCTION(execSimplePerlinNoise4D); \
	DECLARE_FUNCTION(execPerlinNoise3D); \
	DECLARE_FUNCTION(execSimplePerlinNoise3D); \
	DECLARE_FUNCTION(execPerlinNoise2D); \
	DECLARE_FUNCTION(execSimplePerlinNoise2D); \
	DECLARE_FUNCTION(execPerlinNoise1D); \
	DECLARE_FUNCTION(execSimplePerlinNoise1D);


SIMPLENOISEGENERATORS_API UClass* Z_Construct_UClass_USimpleNoiseGeneratorsBPLibrary_NoRegister();

#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_SimpleNoiseGenerators_Source_SimpleNoiseGenerators_Public_SimpleNoiseGeneratorsBPLibrary_h_14_INCLASS \
private: \
	static void StaticRegisterNativesUSimpleNoiseGeneratorsBPLibrary(); \
	friend struct Z_Construct_UClass_USimpleNoiseGeneratorsBPLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SIMPLENOISEGENERATORS_API UClass* Z_Construct_UClass_USimpleNoiseGeneratorsBPLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(USimpleNoiseGeneratorsBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SimpleNoiseGenerators"), Z_Construct_UClass_USimpleNoiseGeneratorsBPLibrary_NoRegister) \
	DECLARE_SERIALIZER(USimpleNoiseGeneratorsBPLibrary)


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_SimpleNoiseGenerators_Source_SimpleNoiseGenerators_Public_SimpleNoiseGeneratorsBPLibrary_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USimpleNoiseGeneratorsBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USimpleNoiseGeneratorsBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USimpleNoiseGeneratorsBPLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USimpleNoiseGeneratorsBPLibrary); \
	/** Deleted move- and copy-constructors, should never be used */ \
	USimpleNoiseGeneratorsBPLibrary(USimpleNoiseGeneratorsBPLibrary&&) = delete; \
	USimpleNoiseGeneratorsBPLibrary(const USimpleNoiseGeneratorsBPLibrary&) = delete; \
	NO_API virtual ~USimpleNoiseGeneratorsBPLibrary();


#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_SimpleNoiseGenerators_Source_SimpleNoiseGenerators_Public_SimpleNoiseGeneratorsBPLibrary_h_11_PROLOG
#define FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_SimpleNoiseGenerators_Source_SimpleNoiseGenerators_Public_SimpleNoiseGeneratorsBPLibrary_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_SimpleNoiseGenerators_Source_SimpleNoiseGenerators_Public_SimpleNoiseGeneratorsBPLibrary_h_14_RPC_WRAPPERS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_SimpleNoiseGenerators_Source_SimpleNoiseGenerators_Public_SimpleNoiseGeneratorsBPLibrary_h_14_INCLASS \
	FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_SimpleNoiseGenerators_Source_SimpleNoiseGenerators_Public_SimpleNoiseGeneratorsBPLibrary_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class USimpleNoiseGeneratorsBPLibrary;

// ********** End Class USimpleNoiseGeneratorsBPLibrary ********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_build_U5M_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_SimpleNoiseGenerators_Source_SimpleNoiseGenerators_Public_SimpleNoiseGeneratorsBPLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
