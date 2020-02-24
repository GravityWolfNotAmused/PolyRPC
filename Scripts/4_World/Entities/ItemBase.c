modded class ItemBase
{
	protected map<int, ref RPCBase> rpcs;

	void ItemBase()
	{
		rpcs = new map<int, ref RPCBase>;

		InitRPCs();
	}

	void InitRPCs()
	{

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