use warnings;

use Time::HiRes qw( time );
use List::Util qw(first);

srand( time() ^ ($$ + ($$ << 15)) );
my @alphabet = qw ( a b c d e f g h i j k l m n o p q r s t u v w x y z );
my %hash;  
my @list;
my $name;
sub hash {
    for (my $i = 0; $i < 10000; $i++) {
        my $age = rand(90);
        my $name = '';
        $name .= $alphabet[int(rand(26))] for 1 .. 3;
        if(! $hash{$name}){
            $hash{$name} = $age;
        }
    }   
    print(%hash);
}
sub nohash{
    for (my $i = 0; $i < 10000; $i++) {
        my $age = rand(90);
        my $name .= $alphabet[int(rand(26))] for 1 .. 3;
        push(@list, $age);
    }   
    #print(@list);
}

my $start_hash = time();
hash();
my $end_hash = time();

printf("With hash it took: %.2f seconds\n", $end_hash - $start_hash);


my $start_no_hash = time();
nohash();
my $end_no_hash = time();
printf("Without hash it took: %.2f seconds\n", $end_no_hash - $start_no_hash);

# El programa con hash toma mas tiempo que el que no lo utiliza
# With hash it took: 0.15 seconds
# Without hash it took: 0.01 seconds
