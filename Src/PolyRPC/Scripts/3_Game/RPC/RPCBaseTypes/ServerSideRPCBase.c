/*
* @author GravityWolf
* @version 0.1
* @since 0.1
*/

class ServerSideRPCBase : RPCBase
{
	override void ExecuteRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx, Class instance = null)
	{
		Print("[RPC Sent from Client]:: Player Name: " + sender.GetName() + ", Player ID: " + sender.GetPlainId());
	}
	
	override bool IsValid(PlayerIdentity sender)
	{
		return (sender == null || GetGame().IsClient());
	}
}