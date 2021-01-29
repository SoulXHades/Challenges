package runtime;

/**
 * The runtime module implicitly imported by every PL/3007 module is automatically generated from
 * this Java class. Thus, your test programs can use any public static method declared in this
 * class, and you can add your own if you like.
 */
public final class Runtime {
	public static void println(String str) {
		System.out.println(str);
	}
	
	public static void printint(int i) {
		System.out.println(i);
	}
}
