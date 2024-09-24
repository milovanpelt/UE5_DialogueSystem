// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5_DialogueSystem : ModuleRules
{
	public UE5_DialogueSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });

        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore"});
    }
}
