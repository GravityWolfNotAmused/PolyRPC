class RPCBase
{
	private int type;

	int GetRPCType()
	{
		return type;
	}

	void SetRPCType(int t)
	{
		type = t;
	}

	void ExecuteRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx);
}