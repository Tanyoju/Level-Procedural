// Copyright Epic Games, Inc. All Rights Reserved.
// Studio Reborne 2024

#include "SimpleNoiseGeneratorsBPLibrary.h"
#include "SimpleNoiseGenerators.h"
#include "Math/UnrealMathUtility.h"
#include "Math/RandomStream.h"
#include "Engine/Texture2D.h"
#include "ImageUtils.h"

USimpleNoiseGeneratorsBPLibrary::USimpleNoiseGeneratorsBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}
//Worley Noise

//1D Perlin Noise
//Simple Perlin Noise 1D
float USimpleNoiseGeneratorsBPLibrary::SimplePerlinNoise1D(float X, float Scale)
{
    // Ensure Scale is not zero to avoid division by zero error
    if (Scale <= 0.f)
    {
        Scale = 0.01f; // Default to a very small scale if zero or negative value is provided
    }

    // Adjust coordinate based on scale
    float AdjustedX = X / Scale;

    // Generate Perlin noise value using Unreal's built-in FMath function for 1D
    // Since Unreal Engine doesn't provide a 1D Perlin noise function directly,
    // we'll use the 2D function with a constant Y value.
    float NoiseValue = FMath::PerlinNoise2D(FVector2D(AdjustedX, 0.0f));

    return NoiseValue;
}

//Perlin Noise 1D
float USimpleNoiseGeneratorsBPLibrary::PerlinNoise1D(float X, float Scale, float CellSize, float Attenuation, int32 Seed)
{
    if (Scale <= 0.f) Scale = 0.01f;
    if (CellSize <= 0.f) CellSize = 0.01f;
    if (X == 0.f) X = 0.01f;

    // Generate pseudo-random offsets from the seed
    FRandomStream RandomStream(Seed);
    float OffsetX = RandomStream.FRandRange(-100000.f, 100000.f);

    // Adjust coordinates based on scale and apply the offsets
    float AdjustedX = ((X / CellSize) / Scale) + OffsetX;

    // Generate Perlin noise value
    float NoiseValue = FMath::PerlinNoise2D(FVector2D(AdjustedX, 1.0f)) * 2;

    //Calculate attentuation
    float Distance = FMath::Sqrt(X * X); // Calculate distance from origin
    float AttenuatedAmplitude = (1.0f - FMath::Exp(-Distance / Attenuation));

    // Apply the attenuation to the noise value
    //NoiseValue *= AttenuatedAmplitude;

    return NoiseValue;
}

//2D Perlin Noise
//Simple Perlin Noise 2D
float USimpleNoiseGeneratorsBPLibrary::SimplePerlinNoise2D(float X, float Y, float Scale)
{
    // Ensure Scale is not zero to avoid division by zero error
    if (Scale <= 0.f)
    {
        Scale = 1.0f; // Default to a very small scale if zero or negative value is provided
    }


    // Adjust coordinates based on scale
    float AdjustedX = X / Scale;
    float AdjustedY = Y / Scale;

    // Generate Perlin noise value using Unreal's built-in FMath function
    float NoiseValue = (FMath::PerlinNoise2D(FVector2D(AdjustedX, AdjustedY)));

    return NoiseValue;
}

//Perlin Noise 2D
float USimpleNoiseGeneratorsBPLibrary::PerlinNoise2D(float X, float Y, float Scale, float CellSize, float Attenuation, int32 Seed)
{
    // Ensure non-zero values
    if (Scale <= 0.f) Scale = 0.01f;
    if (CellSize <= 0.f) CellSize = 0.01f;
    if (X == 0.f) X = 0.01f;
    if (Y == 0.f) Y = 0.01f;
    if (Attenuation == 0.f) Attenuation = 0.01f;

    // Generate pseudo-random offsets from the seed
    FRandomStream RandomStream(Seed);
    float OffsetX = RandomStream.FRandRange(-100000.f, 100000.f);
    float OffsetY = RandomStream.FRandRange(-100000.f, 100000.f);

    // Adjust coordinates based on scale and apply the offsets
    float AdjustedX = ((X / CellSize) / Scale) + OffsetX;
    float AdjustedY = ((Y / CellSize) / Scale) + OffsetY;

    // Generate Perlin noise value
    float NoiseValue = FMath::PerlinNoise2D(FVector2D(AdjustedX, AdjustedY));

    //Calculate attentuation
    float Distance = FMath::Sqrt(X * X + Y * Y); // Calculate distance from origin
    float AttenuatedAmplitude = (1.0f - FMath::Exp(-Distance/Attenuation));

    // Apply the attenuation
    NoiseValue *= AttenuatedAmplitude;

    return NoiseValue;
}

//3D Perlin Noise
//Simple Perlin Noise 3D
float USimpleNoiseGeneratorsBPLibrary::SimplePerlinNoise3D(float X, float Y, float Z, float Scale)
{
    // Ensure Scale is not zero to avoid division by zero error
    if (Scale <= 0.f)
    {
        Scale = 0.01f; // Default to a very small scale if zero or negative value is provided
    }

    // Adjust coordinates based on scale
    float AdjustedX = X / Scale;
    float AdjustedY = Y / Scale;
    float AdjustedZ = Z / Scale;

    // Generate Perlin noise value using Unreal's built-in FMath function for 3D
    float NoiseValue = FMath::PerlinNoise3D(FVector(AdjustedX, AdjustedY, AdjustedZ));

    return NoiseValue;
}

//Perlin Noise 3D
float USimpleNoiseGeneratorsBPLibrary::PerlinNoise3D(float X, float Y, float Z, float Scale, float CellSize, float Attenuation, int32 Seed)
{
    // Ensure Scale and CellSize are not zero to avoid division by zero error
    if (Scale <= 0.f) Scale = 0.01f;
    if (CellSize <= 0.f) CellSize = 0.01f;
    if (X == 0.f) X = 0.01f;

    // Generate pseudo-random offsets from the seed
    FRandomStream RandomStream(Seed);
    float OffsetX = RandomStream.FRandRange(-100000.f, 100000.f);
    float OffsetY = RandomStream.FRandRange(-100000.f, 100000.f);
    float OffsetZ = RandomStream.FRandRange(-100000.f, 100000.f);

    // Adjust coordinates based on scale and apply the offsets
    float AdjustedX = ((X / CellSize) / Scale) + OffsetX;
    float AdjustedY = ((Y / CellSize) / Scale) + OffsetY;
    float AdjustedZ = ((Z / CellSize) / Scale) + OffsetZ;

    // Generate Perlin noise value using Unreal's built-in FMath function for 3D
    float NoiseValue = FMath::PerlinNoise3D(FVector(AdjustedX, AdjustedY, AdjustedZ));

    //Calculate attentuation
    float Distance = FMath::Sqrt(X * X + Y * Y + Z * Z); // Calculate distance from origin
    float AttenuatedAmplitude = (1.0f - FMath::Exp(-Distance / Attenuation));

    // Apply the attenuation to the noise value
    NoiseValue *= AttenuatedAmplitude;

    return NoiseValue;
}

//4D perlin Noise
//Simple Perlin Noise 4D
float USimpleNoiseGeneratorsBPLibrary::SimplePerlinNoise4D(float X, float Y, float Z, float W, float Scale)
{
    // Ensure Scale is not zero to avoid division by zero error
    if (Scale <= 0.f)
    {
        Scale = 0.01f;
    }

    // Adjust coordinates based on scale
    float AdjustedX = X / Scale;
    float AdjustedY = Y / Scale;
    float AdjustedZ = Z / Scale;
    float AdjustedW = W / Scale;

    // Example approach: Combine two 3D noise values, using W as a phase shift for one
    float NoiseValue1 = FMath::PerlinNoise3D(FVector(AdjustedX, AdjustedY, AdjustedZ));
    float NoiseValue2 = FMath::PerlinNoise3D(FVector(AdjustedX + AdjustedW, AdjustedY + AdjustedW, AdjustedZ + AdjustedW));

    // Blend the two noise values (simple average)
    float NoiseValue = (NoiseValue1 + NoiseValue2);

    return FMath::Clamp(NoiseValue, -1.0f, 1.0f);
}

//Perlin Noise 4D
float USimpleNoiseGeneratorsBPLibrary::PerlinNoise4D(float X, float Y, float Z, float W, float Scale, float CellSize, float Attenuation, int32 Seed)
{
    if (Scale <= 0.f) Scale = 0.01f;
    if (CellSize <= 0.f) CellSize = 0.01f;
    if (X == 0.f) X = 0.01f;

    // Generate pseudo-random offsets from the seed
    FRandomStream RandomStream(Seed);
    float OffsetX = RandomStream.FRandRange(-100000.f, 100000.f);
    float OffsetY = RandomStream.FRandRange(-100000.f, 100000.f);
    float OffsetZ = RandomStream.FRandRange(-100000.f, 100000.f);
    float OffsetW = RandomStream.FRandRange(-100000.f, 100000.f);

    // Adjust coordinates based on scale and apply the offsets
    float AdjustedX = ((X / CellSize) / Scale) + OffsetX;
    float AdjustedY = ((Y / CellSize) / Scale) + OffsetY;
    float AdjustedZ = ((Z / CellSize) / Scale) + OffsetZ;
    float AdjustedW = ((W / CellSize) / Scale) + OffsetW;

    // Use W as a phase shift for one of the noise values
    float NoiseValue1 = FMath::PerlinNoise3D(FVector(AdjustedX, AdjustedY, AdjustedZ));
    float NoiseValue2 = FMath::PerlinNoise3D(FVector(AdjustedX + AdjustedW, AdjustedY + AdjustedW, AdjustedZ + AdjustedW));

    //Calculate attentuation
    float Distance = FMath::Sqrt(X * X + Y * Y + Z * Z + W * W); // Calculate distance from origin
    float AttenuatedAmplitude = (1.0f - FMath::Exp(-Distance / Attenuation));

    // Blend and normalize
    float NoiseValue = (NoiseValue1 + NoiseValue2) * AttenuatedAmplitude;

    return FMath::Clamp(NoiseValue, -1.0f, 1.0f);
}



//Worley Noise

//Worley Noise 1D
float USimpleNoiseGeneratorsBPLibrary::WorleyNoise1D(float X, int Seed, float CellSize, float Attenuation)
{
    FRandomStream RandomStream(Seed);
    float MinDistance = MAX_flt;

    // Determine cell index based on CellSize
    int CellX = FMath::FloorToInt(X / CellSize);

    // Inspect the current cell and the two adjacent cells
    for (int offsetX = -1; offsetX <= 1; offsetX++)
    {
        // Unique seed for each cell based on its coordinate and the global seed
        int CellSeed = (CellX + offsetX) * 73856093 ^ Seed;
        RandomStream.Initialize(CellSeed);

        // Random point within this cell
        float PointX = (CellX + offsetX) * CellSize + RandomStream.FRand() * CellSize;

        // Update minimum distance
        float Distance = FMath::Abs(PointX - X);
        MinDistance = FMath::Min(MinDistance, Distance);
    }

    float NoiseValue = ((MinDistance / CellSize) * 2) - 1;

    //Calculate attentuation
    float Distance = FMath::Sqrt(X * X); // Calculate distance from origin
    float AttenuatedAmplitude = (1.0f - FMath::Exp(-Distance / Attenuation));

    NoiseValue *= AttenuatedAmplitude;

    // Normalize distance
    return FMath::Clamp(NoiseValue, -1.0f, 1.0f);
}

//Worley Noise 2D
float USimpleNoiseGeneratorsBPLibrary::WorleyNoise2D(float X, float Y, int Seed, float CellSize, float Attenuation)
{
    FRandomStream RandomStream(Seed);
    float MinDistance = MAX_flt;

    // Determine cell indices based on CellSize
    int CellX = FMath::FloorToInt(X / CellSize);
    int CellY = FMath::FloorToInt(Y / CellSize);

    // Inspect surrounding cells
    for (int offsetY = -1; offsetY <= 1; offsetY++)
    {
        for (int offsetX = -1; offsetX <= 1; offsetX++)
        {
            // Unique seed for each cell based on its coordinates and the global seed
            int CellSeed = (CellX + offsetX) * 73856093 ^ (CellY + offsetY) * 19349663 ^ Seed;
            RandomStream.Initialize(CellSeed);

            // Random point within this cell
            float PointX = (CellX + offsetX) * CellSize + RandomStream.FRand() * CellSize;
            float PointY = (CellY + offsetY) * CellSize + RandomStream.FRand() * CellSize;

            // Update minimum distance
            float Distance = FMath::Sqrt(FMath::Pow(PointX - X, 2) + FMath::Pow(PointY - Y, 2));
            MinDistance = FMath::Min(MinDistance, Distance);
        }
    }

    float NoiseValue = ((MinDistance / CellSize)*2)-1;

    //Calculate attentuation
    float Distance = FMath::Sqrt(X * X + Y * Y); // Calculate distance from origin
    float AttenuatedAmplitude = (1.0f - FMath::Exp(-Distance / Attenuation));

    NoiseValue *= AttenuatedAmplitude;

    // Normalize distance
    return FMath::Clamp(NoiseValue, -1.0f, 1.0f);
}

//Worley Noise 3D
float USimpleNoiseGeneratorsBPLibrary::WorleyNoise3D(float X, float Y, float Z, int Seed, float CellSize, float Attenuation)
{
    FRandomStream RandomStream(Seed);
    float MinDistance = MAX_flt;

    // Determine cell indices based on CellSize
    int CellX = FMath::FloorToInt(X / CellSize);
    int CellY = FMath::FloorToInt(Y / CellSize);
    int CellZ = FMath::FloorToInt(Z / CellSize);

    // Inspect surrounding cells in 3D
    for (int offsetZ = -1; offsetZ <= 1; offsetZ++)
    {
        for (int offsetY = -1; offsetY <= 1; offsetY++)
        {
            for (int offsetX = -1; offsetX <= 1; offsetX++)
            {
                // Unique seed for each cell based on its coordinates and the global seed
                int CellSeed = (CellX + offsetX) * 73856093 ^ (CellY + offsetY) * 19349663 ^ (CellZ + offsetZ) * 83492791 ^ Seed;
                RandomStream.Initialize(CellSeed);

                // Random point within this cell
                float PointX = (CellX + offsetX) * CellSize + RandomStream.FRand() * CellSize;
                float PointY = (CellY + offsetY) * CellSize + RandomStream.FRand() * CellSize;
                float PointZ = (CellZ + offsetZ) * CellSize + RandomStream.FRand() * CellSize;

                // Update minimum distance
                float Distance = FMath::Sqrt(FMath::Pow(PointX - X, 2) + FMath::Pow(PointY - Y, 2) + FMath::Pow(PointZ - Z, 2));
                MinDistance = FMath::Min(MinDistance, Distance);
            }
        }
    }

    float NoiseValue = ((MinDistance / CellSize) * 2) - 1;

    //Calculate attentuation
    float Distance = FMath::Sqrt(X * X + Y * Y + Z * Z); // Calculate distance from origin
    float AttenuatedAmplitude = (1.0f - FMath::Exp(-Distance / Attenuation));

    NoiseValue *= AttenuatedAmplitude;

    // Normalize distance
    return FMath::Clamp(NoiseValue, -1.0f, 1.0f);
}

//Worley Noise 4D
float USimpleNoiseGeneratorsBPLibrary::WorleyNoise4D(float X, float Y, float Z, float W, int Seed, float CellSize, float Attenuation)
{
    FRandomStream RandomStream(Seed);
    float MinDistance = MAX_flt;

    // Determine cell indices based on CellSize
    int CellX = FMath::FloorToInt(X / CellSize);
    int CellY = FMath::FloorToInt(Y / CellSize);
    int CellZ = FMath::FloorToInt(Z / CellSize);
    int CellW = FMath::FloorToInt(W / CellSize);

    // Inspect surrounding cells in 4D
    for (int offsetW = -1; offsetW <= 1; offsetW++)
    {
        for (int offsetZ = -1; offsetZ <= 1; offsetZ++)
        {
            for (int offsetY = -1; offsetY <= 1; offsetY++)
            {
                for (int offsetX = -1; offsetX <= 1; offsetX++)
                {
                    // Unique seed for each cell based on its coordinates and the global seed
                    int CellSeed = (CellX + offsetX) * 73856093 ^ (CellY + offsetY) * 19349663 ^ (CellZ + offsetZ) * 83492791 ^ (CellW + offsetW) * 286293355 ^ Seed;
                    RandomStream.Initialize(CellSeed);

                    // Random point within this 4D cell
                    float PointX = (CellX + offsetX) * CellSize + RandomStream.FRand() * CellSize;
                    float PointY = (CellY + offsetY) * CellSize + RandomStream.FRand() * CellSize;
                    float PointZ = (CellZ + offsetZ) * CellSize + RandomStream.FRand() * CellSize;
                    float PointW = (CellW + offsetW) * CellSize + RandomStream.FRand() * CellSize;

                    // Update minimum distance considering 4D space
                    float Distance = FMath::Sqrt(FMath::Pow(PointX - X, 2) + FMath::Pow(PointY - Y, 2) + FMath::Pow(PointZ - Z, 2) + FMath::Pow(PointW - W, 2));
                    MinDistance = FMath::Min(MinDistance, Distance);
                }
            }
        }
    }

    float NoiseValue = ((MinDistance / CellSize) * 2) - 1;

    //Calculate attentuation
    float Distance = FMath::Sqrt(X * X + Y * Y + Z * Z + W * W); // Calculate distance from origin
    float AttenuatedAmplitude = (1.0f - FMath::Exp(-Distance / Attenuation));

    NoiseValue *= AttenuatedAmplitude;

    // Normalize distance
    return FMath::Clamp(NoiseValue, -1.0f, 1.0f);
}



//Voroni Noise

//Voroni Noise 2D
float USimpleNoiseGeneratorsBPLibrary::VoronoiNoise2D(float X, float Y, float CellSize, int Seed, float Attenuation)
{
    // Ensure CellSize and Attenuation are positive to avoid division by zero or negative attenuation
    if (CellSize <= 0.0f)
    {
        CellSize = 1.0f;
    }
    if (Attenuation <= 0.0f)
    {
        Attenuation = 1.0f; // Default Attenuation to avoid potential errors
    }

    FRandomStream RandomStream(Seed);
    float MinDistance = MAX_flt;

    int CellX = FMath::FloorToInt(X / CellSize);
    int CellY = FMath::FloorToInt(Y / CellSize);

    for (int offsetY = -1; offsetY <= 1; offsetY++)
    {
        for (int offsetX = -1; offsetX <= 1; offsetX++)
        {
            // Adjust seed for each cell based on its coordinates, global seed, and offsets
            RandomStream.Initialize(Seed + (CellX + offsetX) * 73856093 ^ (CellY + offsetY) * 19349663);

            float PointX = (CellX + offsetX) * CellSize + RandomStream.FRand() * CellSize;
            float PointY = (CellY + offsetY) * CellSize + RandomStream.FRand() * CellSize;

            float Distance = FVector2D::Distance(FVector2D(X, Y), FVector2D(PointX, PointY));

            // Update minimum distance
            MinDistance = FMath::Min(MinDistance, Distance);
        }
    }

    float NoiseValue = ((MinDistance / CellSize) * 2) - 1;

    //Calculate attentuation
    float Distance = FMath::Sqrt(X * X + Y * Y); // Calculate distance from origin
    float AttenuatedAmplitude = (1.0f - FMath::Exp(-Distance / Attenuation));

    NoiseValue *= AttenuatedAmplitude;

    // Normalize distance
    return FMath::Clamp(NoiseValue, -1.0f, 1.0f);
}

//Voroni Noise 3D
float USimpleNoiseGeneratorsBPLibrary::VoronoiNoise3D(float X, float Y, float Z, float CellSize, int Seed, float Attenuation)
{
    if (CellSize <= 0.0f) CellSize = 1.0f;
    if (Attenuation <= 0.0f) Attenuation = 1.0f;

    FRandomStream RandomStream(Seed);
    float MinDistance = MAX_flt;

    int CellX = FMath::FloorToInt(X / CellSize);
    int CellY = FMath::FloorToInt(Y / CellSize);
    int CellZ = FMath::FloorToInt(Z / CellSize);

    for (int offsetZ = -1; offsetZ <= 1; offsetZ++)
    {
        for (int offsetY = -1; offsetY <= 1; offsetY++)
        {
            for (int offsetX = -1; offsetX <= 1; offsetX++)
            {
                // Seed adjustment to ensure variability across cells
                RandomStream.Initialize(Seed + (CellX + offsetX) * 73856093 ^ (CellY + offsetY) * 19349663 ^ (CellZ + offsetZ) * 83492791);

                float PointX = (CellX + offsetX) * CellSize + RandomStream.FRand() * CellSize;
                float PointY = (CellY + offsetY) * CellSize + RandomStream.FRand() * CellSize;
                float PointZ = (CellZ + offsetZ) * CellSize + RandomStream.FRand() * CellSize;

                float Distance = FVector::Dist(FVector(X, Y, Z), FVector(PointX, PointY, PointZ));

                MinDistance = FMath::Min(MinDistance, Distance);
            }
        }
    }

    float NoiseValue = ((MinDistance / CellSize) * 2) - 1;

    //Calculate attentuation
    float Distance = FMath::Sqrt(X * X + Y * Y + Z * Z); // Calculate distance from origin
    float AttenuatedAmplitude = (1.0f - FMath::Exp(-Distance / Attenuation));

    NoiseValue *= AttenuatedAmplitude;

    // Normalize distance
    return FMath::Clamp(NoiseValue, -1.0f, 1.0f);
}

//Voronoi Noise 4D
float USimpleNoiseGeneratorsBPLibrary::VoronoiNoise4D(float X, float Y, float Z, float W, float CellSize, int Seed, float Attenuation)
{
    if (CellSize <= 0.0f) CellSize = 1.0f;
    if (Attenuation <= 0.0f) Attenuation = 1.0f;

    FRandomStream RandomStream(Seed);
    float MinDistance = MAX_flt;

    // Compute the cell indices for the 4D position
    int CellX = FMath::FloorToInt(X / CellSize);
    int CellY = FMath::FloorToInt(Y / CellSize);
    int CellZ = FMath::FloorToInt(Z / CellSize);
    int CellW = FMath::FloorToInt(W / CellSize);

    // Inspect surrounding cells in 4D
    for (int offsetW = -1; offsetW <= 1; offsetW++)
    {
        for (int offsetZ = -1; offsetZ <= 1; offsetZ++)
        {
            for (int offsetY = -1; offsetY <= 1; offsetY++)
            {
                for (int offsetX = -1; offsetX <= 1; offsetX++)
                {
                    // Adjust the seed for each cell to ensure unique randomness
                    RandomStream.Initialize(Seed + (CellX + offsetX) * 73856093 ^ (CellY + offsetY) * 19349663 ^ (CellZ + offsetZ) * 83492791 ^ (CellW + offsetW) * 286293355);

                    // Generate a random point within this 4D cell
                    float PointX = (CellX + offsetX) * CellSize + RandomStream.FRand() * CellSize;
                    float PointY = (CellY + offsetY) * CellSize + RandomStream.FRand() * CellSize;
                    float PointZ = (CellZ + offsetZ) * CellSize + RandomStream.FRand() * CellSize;
                    float PointW = (CellW + offsetW) * CellSize + RandomStream.FRand() * CellSize;

                    // Calculate the 4D distance
                    float Distance = FMath::Sqrt(FMath::Pow(PointX - X, 2) + FMath::Pow(PointY - Y, 2) + FMath::Pow(PointZ - Z, 2) + FMath::Pow(PointW - W, 2));

                    // Update the minimum distance
                    MinDistance = FMath::Min(MinDistance, Distance);
                }
            }
        }
    }

    float NoiseValue = ((MinDistance / CellSize) * 2) - 1;

    //Calculate attentuation
    float Distance = FMath::Sqrt(X * X + Y * Y + Z * Z + W * W); // Calculate distance from origin
    float AttenuatedAmplitude = (1.0f - FMath::Exp(-Distance / Attenuation));

    NoiseValue *= AttenuatedAmplitude;

    // Normalize distance
    return FMath::Clamp(NoiseValue, -1.0f, 1.0f);
}
