// Studio Reborne 2024

using UnrealBuildTool;
using System.IO; // Add this if not already included

public class SimpleNoiseGenerators : ModuleRules
{
    public SimpleNoiseGenerators(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
                Path.Combine(ModuleDirectory, "Public")
            }
        );

        PrivateIncludePaths.AddRange(
            new string[] {
                Path.Combine(ModuleDirectory, "Private")
            }
        );

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                // Add other public dependencies that you statically link with here
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                // Add private dependencies that you statically link with here  
            }
        );

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
                // Add any modules that your module loads dynamically here
            }
        );
    }
}
