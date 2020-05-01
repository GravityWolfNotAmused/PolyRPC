modded class MissionServer
{
	[NonSerialized()]
	private ref map<int, ref IRPCExecutable> rpcs;

	void MissionServer()
	{
		GetDayZGame().Event_OnRPC.Insert( OnRPC );
		rpcs = new map<int, ref IRPCExecutable>;

		InitRPCs();
	}

	void ~MissionServer()
	{
		delete rpcs;
	}

	void InitRPCs()
	{
	}

	void AddRPC(typename type, int id)
	{
		ref IRPCExecutable rpc = type.Spawn();

		if(rpc != null)
		{
			rpcs.Insert(id, rpc);
		}
	}

	void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx)
	{
		if(target == null)
		{
			autoptr IRPCExecutable rpc = rpcs.Get(rpc_type);

			if(rpc != null)
			{
				if(rpc.IsValid(sender))
					rpc.ExecuteRPC(sender, null, ctx, this);
			}
		}
	}
}
