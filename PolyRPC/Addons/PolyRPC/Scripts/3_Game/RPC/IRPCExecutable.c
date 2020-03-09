class IRPCExecutable
{
	bool IsValid(PlayerIdentity sender);
	void ExecuteRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx, Class instance = null);
}