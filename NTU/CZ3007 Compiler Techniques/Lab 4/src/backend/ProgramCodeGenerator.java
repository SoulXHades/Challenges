package backend;

import java.lang.reflect.Modifier;
import java.util.HashMap;

import soot.Scene;
import soot.SootClass;
import ast.Module;
import ast.Program;

/**
 * This class is in charge of generating Jimple code for an entire program. In particular,
 * it maintains the mapping from modules to Soot classes. 
 */
public class ProgramCodeGenerator {
	private HashMap<Module, SootClass> module2class = new HashMap<Module, SootClass>();
	
	/**
	 * Looks up the Soot class for the given module; creates a new one if no class exists
	 * for this module yet.
	 */
	public SootClass getSootClass(Module module) {
		SootClass klass = module2class.get(module);
		if(klass == null) {
			klass = new SootClass(module.getQualifiedName(), Modifier.PUBLIC | Modifier.FINAL);
			klass.setSuperclass(Scene.v().getSootClass("java.lang.Object"));
			module2class.put(module, klass);
		}
		return klass;
	}

	/**
	 * Generates Soot classes for all the modules in the program.
	 */
	public SootClass[] generate(Program program) {
		Scene.v().loadClassAndSupport("java.lang.Object");
		
		SootClass[] klasses = new SootClass[program.getNumModule()];
		for(int i=0;i<program.getNumModule();++i)
			klasses[i] = new ModuleCodeGenerator(this).generate(program.getModule(i));
		
		return klasses;
	}
}
