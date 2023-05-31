// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DialogueEditorModule : ModuleRules
{
	public DialogueEditorModule(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "DialogueEditorModule" });

        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore"});
    }
}
