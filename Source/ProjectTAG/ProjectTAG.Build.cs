// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProjectTAG : ModuleRules
{
	public ProjectTAG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore",
            "AIModule",
            "GameplayTasks",
            "SlateCore",
            "HeadMountedDisplay", 
			"EnhancedInput" 
		});

        PublicIncludePaths.Add(ModuleDirectory);

    }
}
