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
		AddRPC(TestRPC, RPCTypeEnum.RPCTest);
	}

	void AddRPC(typename type, int id)
	{
		ref RPCBase rpc = type.Spawn();

		if(rpc != null)
		{
			rpc.SetRPCType(id);
			rpcs.Insert(id, rpc);
		}
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
