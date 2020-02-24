class RPCBase
{
	private int type;
	private bool isValidSide;

	void RPCBase()
	{
		isValidSide = true;
	}
	
	int GetRPCType()
	{
		return type;
	}

	void SetRPCType(int t)
	{
		type = t;
	}

	bool IsValidSide()
	{
		return isValidSide;
	}

	void SetIsValidSide(bool side)
	{
		isValidSide = side;
	}

	void ExecuteRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx);
}