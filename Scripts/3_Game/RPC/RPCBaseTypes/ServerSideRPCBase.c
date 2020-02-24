class ServerSideRPCBase : RPCBase
{
	override void ExecuteRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx)
	{
		//Check if is on the valid side, and actually from a player.//
		if(sender == null || GetGame().IsClient())
		{
			SetIsValidSide(false);
			return;
		}

		Print("[RPC Sent from Client]:: Player Name: " + sender.GetName() + ", Player ID: " + sender.GetPlainId() + ", RPC Type: " + GetRPCType());
	}
}