/*
* @author GravityWolf
* @version 0.1
* @since 0.1
*/

modded class PluginManager
{
	void PluginManager()
	{
		//GetDayZGame().Event_OnRPC.Insert( OnRPC );
	}

	override void Init()
	{
		super.Init();

		RegisterPlugin("PolyUIManager", true, false);
	}

	void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		if((sender == null && GetGame().IsClient()) || (sender == null && GetGame().IsClient()))
		{
			if(rpc_type > 97)
			{		
				foreach(typename type, PluginBase plugin : m_PluginsPtrs)
				{
					//plugin.OnRPC(sender, rpc_type, ctx);
				}
			}
		}
	}
}

class PolyUIManager : PluginBase
{
	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		/*
		if(GetGame().IsClient())
		{
			UIManager manager = GetGame().GetUIManager();
			UIScriptedMenu menu = manager.GetMenu();
			PolyUIScriptedMenu polyMenu = PolyUIScriptedMenu.Cast(menu);

			while (menu)
			{				
				if(polyMenu)
				{
					polyMenu.OnRPC(sender, rpc_type, ctx);
				}

				menu = menu.GetParentMenu();
				polyMenu = PolyUIScriptedMenu.Cast(menu);
			}
		}
		*/
	}
}
