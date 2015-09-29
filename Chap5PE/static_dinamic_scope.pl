#!/usr/bin/perl

$x = 42;

sub add1 {
    return $x + 1;
}

sub static_scope {
    my $x = 99;
    return add1();
}

sub dynamic_scope{
    local $x = 99;
    return add1();
}
print "Using static scope:\n";
print static_scope();       
# 100 or 43? 43 porque al usar MY add1 va a utilizar su scope donde x vale 42
print "\nUsing dynamic scope\n";
print dynamic_scope();      
# 100 or 43? 100 porque al usar LOCAL add1 va a usar el scope de donde es llamada y en el scope de dynamic, x vale 99
print "\n";