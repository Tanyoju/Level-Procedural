// Copyright Epic Games, Inc. All Rights Reserved.
// Studio Reborne 2024

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/Texture2D.h"
#include "SimpleNoiseGeneratorsBPLibrary.generated.h"

UCLASS()
class USimpleNoiseGeneratorsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	//Perlin Noise

	//1D Perlin Noise
	//Simple Perlin Noise 1D
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "SimplePerlinNoise1D", Keywords = "Perlin Noise, 1D, Generate"), Category = "Perlin Noise Generation")
	static float SimplePerlinNoise1D(float X, float Scale);

	// Generate Complex Perlin Noise 1D with Cell Size and Attenuation
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "PerlinNoise1D", Keywords = "Perlin Noise, 1D, Generate, Cell Size, Attenuation"), Category = "Perlin Noise Generation")
	static float PerlinNoise1D(float X, float Scale, float CellSize, float Attenuation, int32 Seed);

	//2D Perlin Noise
	//Generate Simple Perlin Noise 2D
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "SimplePerlinNoise2D", Keywords = "Perlin Noise, 2D, Generate"), Category = "Perlin Noise Generation")
	static float SimplePerlinNoise2D(float X, float Y, float Scale);

	//Generate Perlin Noise 2D
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "PerlinNoise2D", Keywords = "Perlin Noise, 2D, Generate, Cell Size"), Category = "Perlin Noise Generation")
	static float PerlinNoise2D(float X, float Y, float Scale, float CellSize, float Attenuation, int32 Seed);

	//3D Perlin Noise
	//Generate Simple Perlin Noise 3D
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "SimplePerlinNoise3D", Keywords = "Perlin Noise, 3D, Generate"), Category = "Perlin Noise Generation")
	static float SimplePerlinNoise3D(float X, float Y, float Z, float Scale);

	//Generate Perlin Noise 3D
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "PerlinNoise3D", Keywords = "Perlin Noise, 3D, Generate, Cell Size, Attenuation"), Category = "Perlin Noise Generation")
	static float PerlinNoise3D(float X, float Y, float Z, float Scale, float CellSize, float Attenuation, int32 Seed);

	//4D Perlin Noise
	//Generate Simple Perlin Noise 4D
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "SimplePerlinNoise4D", Keywords = "Perlin Noise, 4D, Generate"), Category = "Perlin Noise Generation")
	static float SimplePerlinNoise4D(float X, float Y, float Z, float W, float Scale);

	//Generate Perlin Noise 4D
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "PerlinNoise4D", Keywords = "Perlin Noise, 4D, Generate, Cell Size, Attenuation"), Category = "Perlin Noise Generation")
	static float PerlinNoise4D(float X, float Y, float Z, float W, float Scale, float CellSize, float Attenuation, int32 Seed);



	//Worley Noise

	// Generate Worley Noise 1D
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "WorleyNoise1D", Keywords = "Worley Noise, Cellular Noise, 1D, Generate"), Category = "Worley Noise Generation")
	static float WorleyNoise1D(float X, int Seed, float CellSize, float Attenuation);

	// Generate Worley Noise 2D
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "WorleyNoise2D", Keywords = "Worley Noise, Cellular Noise, 2D, Generate, Cell Size, Seed, Attenuation"), Category = "Worley Noise Generation")
	static float WorleyNoise2D(float X, float Y, int Seed, float CellSize, float Attenuation);

	// Generate Worley Noise 3D
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "WorleyNoise3D", Keywords = "Worley Noise, Cellular Noise, 3D, Generate"), Category = "Worley Noise Generation")
	static float WorleyNoise3D(float X, float Y, float Z, int Seed, float CellSize, float Attenuation);

	// Generate Worley Noise 4D
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "WorleyNoise4D", Keywords = "Worley Noise, Cellular Noise, 4D, Generate"), Category = "Worley Noise Generation")
	static float WorleyNoise4D(float X, float Y, float Z, float W, int Seed, float CellSize, float Attenuation);



	//Voronoi Noise

	//Voronoi Noise 2D
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "VoronoiNoise2D", Keywords = "Voronoi Noise, 2D, Generate, Seed, Attenuation"), Category = "Voronoi Noise Generation")
	static float VoronoiNoise2D(float X, float Y, float CellSize, int Seed, float Attenuation);

	//Voronoi Noise 3D
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "VoronoiNoise3D", Keywords = "Voronoi Noise, 3D, Generate, Seed, Attenuation"), Category = "Voronoi Noise Generation")
	static float VoronoiNoise3D(float X, float Y, float Z, float CellSize, int Seed, float Attenuation);

	//Voronoi Noise 4D
	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "VoronoiNoise4D", Keywords = "Voronoi Noise, 4D, Generate, Seed, Attenuation"), Category = "Voronoi Noise Generation")
	static float VoronoiNoise4D(float X, float Y, float Z, float W, float CellSize, int Seed, float Attenuation);
};