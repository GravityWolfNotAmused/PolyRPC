class RPCBase
{
	private int type;

	void RPCBase(int type)
	{
		this.type = type;
	}

	int GetRPCType()
	{
		return type;
	}

	void ExecuteRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx);
}