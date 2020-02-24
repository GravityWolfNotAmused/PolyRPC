/*
class TestServerRPC : ServerSideRPCBase
{
	override void ExecuteRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx)
	{
		super.ExecuteRPC(sender, target, ctx);

		if(!IsValidSide()) return;

		Print("I got a message from the client");

		string msg;

		if(ctx.Read(msg))
			Print(msg);
	}
}
*/