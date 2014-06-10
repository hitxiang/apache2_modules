http://www.codeproject.com/Articles/491909/Apache-2-x-Modules-In-Cplusplus-Part-1
http://www.codeproject.com/Articles/492398/Apache-x-Modules-In-Cplusplus-Part

In you ssh shell change directory to where Netbeans built your module. On my server it’s here:-

    ~/NetBeansProjects/mod_foo/dist/Debug/GNU-Linux-x86/

And in there you should see a file mod_foo.so which we can install into Apache. Note, if your ssh shell is not root you will need root permissions to do this:-

    # apxs –n foo –I mod_foo.so

The Apache apxs tool should been installed as part of your Apache installation. For a standard 64bit server this installs mod_foo.so to /usr/lib64/httpd/modules/

Now that that module is in place we need to activate it. In /etc/httpd/conf.d create a new file called foo.conf and in it place:-
Collapse | Copy Code

LoadModule foo_module modules/mod_foo.so
<Location /foo>
    SetHandler foo
</Location>

And finally to run Apache in single process/non-thread mode invoke with httpd –X which will cause Apache to run until you kill it with Ctrl-C and then point your favourite Firefox at <a href="http://localhost/foo">http://localhost/foo</a> and if it all worked you should see your "Hello World from FOO" printed.
Debugging

Before we move on to coding some nice OOPs stuff it’s worth mentioning at this point how one can use the integrated gdb debugger in Netbeans. Clearly doing httpd –X invoked it from the command line. We are not going to try and build all of Apache in Netbeans and run it from there (although you could).

The easiest way is to use Netbeans "Attach to process" under the Debug menu. In the popup dialog filter enter "httpd –X" and you will see your process you start from the command line. Select it and attach. You can then set a breakpoint in the foo_handler() function. When you refresh Firefox it’ll break at that point.

However, on every code change you make you will need to recompile/build, Ctrl-C the httpd –X, re-install mod_foo.so with apxs, restart httpd –X and re-attach. It does sound a lot, however you’ll soon get use to it and it only takes a few seconds to get each iteration going. 
