modded class PlayerBase
{
	private ref map<int, ref RPCBase> rpcs;

	void PlayerBase()
	{
		rpcs = new map<int, ref RPCBase>;

		InitRPCs();
	}

	void InitRPCs()
	{
		rpcs.Insert(RPCTypeEnum.RPCTest, new TestRPC(RPCTypeEnum.RPCTest));
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{	
		autoptr RPCBase rpc = rpcs.Get(rpc_type);

		if(rpc != null)
		{
			rpc.ExecuteRPC(sender, this, ctx);
			return;
		}

		super.OnRPC(sender, rpc_type, ctx);
	}
}