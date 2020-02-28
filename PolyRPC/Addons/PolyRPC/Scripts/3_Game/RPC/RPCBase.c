/*
* @author GravityWolf
* @version 0.1
* @since 0.1
*/

class RPCBase
{
	protected int type;

	int GetRPCType()
	{
		return type;
	}

	void SetRPCType(int t)
	{
		type = t;
	}

	bool IsValid(PlayerIdentity sender)
	{
		return false;
	}

	void ExecuteRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx, Class instance = null);
}