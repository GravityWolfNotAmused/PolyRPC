/*
* @author GravityWolf
* @version 0.1
* @since 0.1
*/

class ServerSideRPCBase : RPCBase
{
	override void ExecuteRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx, Class instance = null)
	{
		//Check if is on the valid side, and actually from a player.//
		if(sender == null || GetGame().IsClient())
		{
			SetIsValid(false);
			return;
		}

		Print("[RPC Sent from Client]:: Player Name: " + sender.GetName() + ", Player ID: " + sender.GetPlainId() + ", RPC Type: " + GetRPCType());
	}
}