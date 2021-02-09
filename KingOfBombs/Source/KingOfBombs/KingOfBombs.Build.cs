// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class KingOfBombs : ModuleRules
{
	public KingOfBombs(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
