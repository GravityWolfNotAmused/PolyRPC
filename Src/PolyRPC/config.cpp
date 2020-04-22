class CfgPatches
{
	class PolyRPCFramework
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class PolyRPC
	{
		dir="PolyRPC";
		hideName=0;
		hidePicture=0;
		name="PolyRPC";
		credits="GravityWolf";
		creditsJson="PolyRPC/Data/Credits.json";
		author="DaOne & GravityWolf";
		authorID="420420";
		version="Version 0.1";
		extra=0;
		type="mod";
		tooltip="Somedays....I miss Eugen. o7";
		overview="A DayZ Workshop Addon which aims to solve the clutter of RPC work by introducing multiple base classes with polymorphic functions in the RPC event chain, allowing new RPCs to be seperated from their the classes they are used in. No extreme overhead, No unneeded logger, No extra content packaged. Just Polymorphic RPCs.";
		action="https://discord.gg/bkf3u7M";
		dependencies[]=
		{
			"Game",
			"World"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"PolyRPC/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"PolyRPC/Scripts/4_World"
				};
			};
		};
	};
};
