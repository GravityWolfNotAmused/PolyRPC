/*
* @author GravityWolf
* @version 0.1
* @since 0.1
*/

modded class PluginManager
{
	void PluginManager()
	{
		GetDayZGame().Event_OnRPC.Insert( OnRPC );
	}

	void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		foreach(typename type, PluginBase plugin : m_PluginsPtrs)
		{
			plugin.OnRPC(sender, rpc_type, ctx);
		}
	}
}