class TestServerRPC : ServerSideRPCBase
{
	override void ExecuteRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx, Class instance = null)
	{
		super.ExecuteRPC(sender, target, ctx, instance);

		Print("I got a message from the client");

		string msg;

		if(ctx.Read(msg))
			Print(msg);
	}
}