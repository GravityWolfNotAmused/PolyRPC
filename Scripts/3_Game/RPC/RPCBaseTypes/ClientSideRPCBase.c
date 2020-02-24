class ClientSideRPCBase : RPCBase
{
	override void ExecuteRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx)
	{
		if(sender != null || GetGame().IsServer())
		{
			SetIsValidSide(false);
			return;
		}

		Print("[RPC Sent from Server]:: RPC Type: " + GetRPCType());
	}
}