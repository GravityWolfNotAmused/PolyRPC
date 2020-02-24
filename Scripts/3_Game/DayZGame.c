modded class DayZGame
{
	private ref map<int, ref RPCBase> rpcs;

	void DayZGame()
	{
		rpcs = new map<int, ref RPCBase>;

		InitRPCs();
	}

	void InitRPCs()
	{
		rpcs.Insert(RPCTypeEnum.RPCTest, new TestRPC(RPCTypeEnum.RPCTest));
	}

	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		if(target == null)
		{
			autoptr RPCBase rpc = rpcs.Get(rpc_type);

			if(rpc != null)
			{
				rpc.ExecuteRPC(sender, null, ctx);
				return;
			}
		}

		super.OnRPC(sender, target, rpc_type, ctx);
	}
}
