/*
* @author GravityWolf
* @version 0.1
* @since 0.1
*/

class RPCBase : IRPCExecutable
{
	override bool IsValid(PlayerIdentity sender)
	{
		return false;
	}

	override void ExecuteRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx, Class instance = null){}
}