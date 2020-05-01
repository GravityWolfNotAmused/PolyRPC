/*
* @author GravityWolf
* @version 0.1
* @since 0.1
*/

class ClientSideRPCBase : RPCBase
{
	override void ExecuteRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx, Class instance = null)
	{
		Print("[RPC Sent from Server]:: Classname: " + ClassName());
	}

	override bool IsValid(PlayerIdentity sender)
	{
		return (sender == null && GetGame().IsClient());
	}
}