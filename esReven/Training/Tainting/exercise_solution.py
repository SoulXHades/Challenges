import reven2  # noqa: F401
import reven2.preview.taint as tainting
from reven2.address import LinearAddress, LogicalAddress, LogicalAddressSegmentIndex, PhysicalAddress  # noqa: F401
from reven2.arch import x64 as regs  # noqa: F401
from reven2.preview.project_manager import ProjectManager

# Let's connect first.
pm = ProjectManager("http://reven:8880")
server = pm.get_server_by(name="hj_taint")
trace = server.trace

# See the cookbook and the above suggestions.
tainter = tainting.Tainter(server.trace)
taint = tainter.simple_taint("rdx", to_context=trace.context_before(6911057), is_forward=False) # Reverse tainting. 6911057 is the trace ID which I used it as we are interested in the context of trace ID 6911048.

last_symbol = None
last_process = None
for access in taint.accesses().all():
    ctx_after = access.transition.context_after()
    new_process = ctx_after.ossi.process()
    new_symbol = ctx_after.ossi.location().symbol
    if new_symbol is None:
        if last_symbol is not None:
            print(f"{new_process}: ???")
        last_symbol = None
        last_process = new_process
        continue
    if (last_symbol is not None and last_process is not None
        and new_symbol == last_symbol
        and new_process.pid == last_process.pid
       ):
        continue

    last_symbol = new_symbol
    last_process = new_process

    if "_" != new_symbol.name[0] and "ntdll" != new_symbol.binary.name: # Follow pointer 3 to skip NTDLL functions and msvcrt.dll funciton that starts with "_".
        print(f"{new_process}: {new_symbol} - {access.transition}")


'''
Example of the printed result:
taint_playground.exe (3004): taint_playground!simple_case - #6911053 mov edx, eax
taint_playground.exe (3004): taint_playground!main - #6911046 mov ecx, eax
taint_playground.exe (3004): taint_playground!get_global - #6911041 mov eax, dword ptr ds:[rip+0xaa3e]
taint_playground.exe (3004): taint_playground!init - #6911033 mov dword ptr ds:[rip+0xaa76], eax
taint_playground.exe (3004): msvcrt!rand - #6911030 mov eax, ecx
taint_playground.exe (3004): msvcrt!srand - #6910924 mov dword ptr ds:[rax+0x1c], ebx
taint_playground.exe (3004): msvcrt!srand - #6910829 mov ebx, ecx
taint_playground.exe (3004): taint_playground!init - #6910824 mov ecx, eax
taint_playground.exe (3004): kernelbase!GetSystemTimeAsFileTime - #6910803 mov dword ptr ds:[rcx+0x4], eax
taint_playground.exe (3004): ntoskrnl!KiUpdateTime - #6869173 mov qword ptr ds:[0xfffff78000000014], rax
taint_playground.exe (3004): ntoskrnl!HalpHpetQueryCounter - #6869083 mov eax, dword ptr ds:[rax+0xf0]
taint_playground.exe (3004): ntoskrnl!KiUpdateTime - #6869061 mov rbx, qword ptr ds:[rdi+0xc8]
MsMpEng.exe (1892): ntoskrnl!KiUpdateTime - #6838333 mov qword ptr ds:[0xfffff78000000348], rax
MsMpEng.exe (1892): ntoskrnl!HalpHpetQueryCounter - #6838239 mov eax, dword ptr ds:[rax+0xf0]
MsMpEng.exe (1892): ntoskrnl!KiUpdateTime - #6838217 mov rbx, qword ptr ds:[rdi+0xc8]
MsMpEng.exe (1892): ntoskrnl!HalpHpetQueryCounter - #6767549 mov eax, dword ptr ds:[rax+0xf0]
MsMpEng.exe (1892): ntoskrnl!KiUpdateTime - #6767527 mov rbx, qword ptr ds:[rdi+0xc8]
MsMpEng.exe (1892): ntoskrnl!HalpHpetQueryCounter - #6743458 mov eax, dword ptr ds:[rax+0xf0]
MsMpEng.exe (1892): ntoskrnl!KiUpdateTime - #6743436 mov rbx, qword ptr ds:[rdi+0xc8]
SearchApp.exe (2224): ntoskrnl!KiUpdateTime - #4041409 mov qword ptr ds:[0xfffff78000000348], rax
SearchApp.exe (2224): ntoskrnl!HalpHpetQueryCounter - #4041312 mov eax, dword ptr ds:[rax+0xf0]
SearchApp.exe (2224): ntoskrnl!KiUpdateTime - #4041290 mov rbx, qword ptr ds:[rdi+0xc8]
System (4): ntoskrnl!KiUpdateTime - #480418 mov qword ptr ds:[0xfffff78000000348], rax
System (4): ntoskrnl!HalpHpetQueryCounter - #480324 mov eax, dword ptr ds:[rax+0xf0]
System (4): ntoskrnl!KiUpdateTime - #480302 mov rbx, qword ptr ds:[rdi+0xc8]
MsMpEng.exe (1892): ntoskrnl!KiUpdateTime - #24182 mov qword ptr ds:[0xfffff78000000348], rax
MsMpEng.exe (1892): ntoskrnl!HalpHpetQueryCounter - #24088 mov eax, dword ptr ds:[rax+0xf0]
MsMpEng.exe (1892): ntoskrnl!KiUpdateTime - #24066 mov rbx, qword ptr ds:[rdi+0xc8]
taint_playground.exe (3004): ntoskrnl!KiUpdateTime - #7438 mov qword ptr ds:[0xfffff78000000348], rax
taint_playground.exe (3004): ntoskrnl!HalpHpetQueryCounter - #7341 mov eax, dword ptr ds:[rax+0xf0]
taint_playground.exe (3004): ntoskrnl!KiUpdateTime - #7319 mov rbx, qword ptr ds:[rdi+0xc8]
'''