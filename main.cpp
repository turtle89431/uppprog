#include "test.h"
#include <Core/Core.h>



using namespace Upp;

test::test()
{
	CtrlLayout(*this, "Window title");
	goBtn<<THISBACK(btnclick);
}



GUI_APP_MAIN
{
	test().Run();
}
