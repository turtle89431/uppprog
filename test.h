#ifndef _test_test_h
#define _test_test_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <test/test.lay>
#include <CtrlCore/lay.h>
#include <Core/Core.h>
#include <Core/SSL/SSL.h>
class test : public WithtestLayout<TopWindow> {
public:
	typedef test CLASSNAME;
	test();
	String DumpSpecial(String s)
{
	String out;
	for(const char *p = s.Begin(), *e = s.End(); p < e; p++)
		if((byte)*p >= ' ' && *p != '\xFF')
			out.Cat(*p);
		else {
			switch(*p) {
				case '\a': out.Cat("[\\a]"); break;
				case '\b': out.Cat("[\\b]"); break;
				case '\f': out.Cat("[\\f]"); break;
				case '\v': out.Cat("[\\v]"); break;
				case '\t': out.Cat("[\\t]"); break;
				case '\r': out.Cat("[\\r]"); break;
				case '\n': out.Cat("[\\n]\n"); break;
				default:   out.Cat(NFormat("[\\x%02x", (byte)*p)); break;
			}
		}
	return out;
}
	String gethttpdata(String url){
		String proxy;
		HttpRequest request(url);
		request.Proxy(proxy);
		String content = request.Execute();
		return DumpSpecial(content);
	}
	void btnclick(){
		rtBox.SetData(gethttpdata("https://www.google.com"));
	}
};

#endif
