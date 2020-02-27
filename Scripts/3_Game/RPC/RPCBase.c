/*
* @author GravityWolf
* @version 0.1
* @since 0.1
*/

class RPCBase
{
	private int type;
	private bool isValid;

	void RPCBase()
	{
		isValid = true;
	}

	int GetRPCType()
	{
		return type;
	}

	void SetRPCType(int t)
	{
		type = t;
	}

	bool IsValid()
	{
		return isValid;
	}

	void SetIsValid(bool valid)
	{
		isValid = valid;
	}

	void ExecuteRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx, Class instance = null);
}