class TestRPC : ClientSideRPCBase
{
	override void ExecuteRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx)
	{
		super.ExecuteRPC(sender, target, ctx);
		
		Print("I got a message from the server");

		string msg;

		if(ctx.Read(msg))
			Print(msg);

		ScriptRPC rpc = new ScriptRPC();
		rpc.Write("This is response from client: " + msg);
		rpc.Send(null, RPCTypeEnum.RPCServerTest, true, null);

		//You may use the Param version of RPCs as well as ScriptRPCs.
	}
}