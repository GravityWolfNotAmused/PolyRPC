class TestPluginThing : PluginBase
{
	override void InitRPCs()
	{
		AddRPC(TestServerRPC, RPCTypeEnum.RPCServerTest);
	}
}