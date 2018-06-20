#!/usr/bin/perl -w


# @filename           :  array.pl
# @author             :  Copyright (C) drunkwater
# @date               :  Mon Jan 15 12:43:38 HKT 2018
# @function           :  create file within C style's string array.
# @see                :  
# @require            :  



# require here
#require v5.6.1;


# use standard library/use warnings
use strict;
use warnings;

#use File::Copy;


# use other library/perl modules, writed by drunkwater

my $OS_DATE;

sub getCurrentTime
{
	my $time = time();
	my ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime($time);

	$sec  = ($sec<10)?"0$sec":$sec;
	$min  = ($min<10)?"0$min":$min;
	$hour = ($hour<10)?"0$hour":$hour;
	$mday = ($mday<10)?"0$mday":$mday;
	$mon  = ($mon<9)?"0".($mon+1):$mon;
	$year+=1900;
	my $weekday = ('Sun','Mon','Tue','Wed','Thu','Fri','Sat')[$wday];
	return { 'second' => $sec,
			'minute' => $min,
			'hour'   => $hour,
			'day'    => $mday,
			'month'  => $mon,
			'year'   => $year,
			'weekNo' => $wday,
			'wday'   => $weekday,
			'yday'   => $yday,
			'date'   => "$year$mon$mday"
			};
}

sub ltrim { my $s = shift; $s =~ s/^\s+//;       return $s };
sub rtrim { my $s = shift; $s =~ s/\s+$//;       return $s };
sub  trim { my $s = shift; $s =~ s/^\s+|\s+$//g; return $s };

sub open_filehandle_for_output
{
    my $filename = $_[0];
    my $overWriteFilename = ">" . $filename;
    local *FH;

    open (FH, $overWriteFilename) || die "Could not open $filename";

    return *FH;
}

sub open_filehandle_for_input
{
    my $filename = $_[0];
    local *FH;

    open (FH, $filename) || die "Could not open $filename";

    return *FH;
}


#       C program '\X' escapes are noted.
#
#       Oct   Dec   Hex   Char                        Oct   Dec   Hex   Char
#       ------------------------------------------------------------------------
#       000   0     00    NUL '\0'                    100   64    40    @
#       001   1     01    SOH (start of heading)      101   65    41    A
#       002   2     02    STX (start of text)         102   66    42    B
#       003   3     03    ETX (end of text)           103   67    43    C
#       004   4     04    EOT (end of transmission)   104   68    44    D
#       005   5     05    ENQ (enquiry)               105   69    45    E
#       006   6     06    ACK (acknowledge)           106   70    46    F
#       007   7     07    BEL '\a' (bell)             107   71    47    G
#       010   8     08    BS  '\b' (backspace)        110   72    48    H
#       011   9     09    HT  '\t' (horizontal tab)   111   73    49    I
#       012   10    0A    LF  '\n' (new line)         112   74    4A    J
#       013   11    0B    VT  '\v' (vertical tab)     113   75    4B    K
#       014   12    0C    FF  '\f' (form feed)        114   76    4C    L
#       015   13    0D    CR  '\r' (carriage ret)     115   77    4D    M
#       016   14    0E    SO  (shift out)             116   78    4E    N
#       017   15    0F    SI  (shift in)              117   79    4F    O
#       020   16    10    DLE (data link escape)      120   80    50    P
#       021   17    11    DC1 (device control 1)      121   81    51    Q
#       022   18    12    DC2 (device control 2)      122   82    52    R
#       023   19    13    DC3 (device control 3)      123   83    53    S
#       024   20    14    DC4 (device control 4)      124   84    54    T
#       025   21    15    NAK (negative ack.)         125   85    55    U
#       026   22    16    SYN (synchronous idle)      126   86    56    V
#       027   23    17    ETB (end of trans. blk)     127   87    57    W
#       030   24    18    CAN (cancel)                130   88    58    X
#       031   25    19    EM  (end of medium)         131   89    59    Y
#       032   26    1A    SUB (substitute)            132   90    5A    Z
#       033   27    1B    ESC (escape)                133   91    5B    [
#       034   28    1C    FS  (file separator)        134   92    5C    \  '\\'
#       035   29    1D    GS  (group separator)       135   93    5D    ]
#       036   30    1E    RS  (record separator)      136   94    5E    ^
#       037   31    1F    US  (unit separator)        137   95    5F    _
#       040   32    20    SPACE                       140   96    60    `
#       041   33    21    !                           141   97    61    a
#       042   34    22    "                           142   98    62    b
#       043   35    23    #                           143   99    63    c
#       044   36    24    $                           144   100   64    d
#       045   37    25    %                           145   101   65    e
#       046   38    26    &                           146   102   66    f
#       047   39    27    ´                           147   103   67    g
#       050   40    28    (                           150   104   68    h
#       051   41    29    )                           151   105   69    i
#       052   42    2A    *                           152   106   6A    j
#       053   43    2B    +                           153   107   6B    k
#       054   44    2C    ,                           154   108   6C    l
#       055   45    2D    -                           155   109   6D    m
#       056   46    2E    .                           156   110   6E    n
#       057   47    2F    /                           157   111   6F    o
#
#       060   48    30    0                           160   112   70    p
#       061   49    31    1                           161   113   71    q
#       062   50    32    2                           162   114   72    r
#       063   51    33    3                           163   115   73    s
#       064   52    34    4                           164   116   74    t
#       065   53    35    5                           165   117   75    u
#       066   54    36    6                           166   118   76    v
#       067   55    37    7                           167   119   77    w
#       070   56    38    8                           170   120   78    x
#       071   57    39    9                           171   121   79    y
#       072   58    3A    :                           172   122   7A    z
#       073   59    3B    ;                           173   123   7B    {
#       074   60    3C    <                           174   124   7C    |
#       075   61    3D    =                           175   125   7D    }
#       076   62    3E    >                           176   126   7E    ~
#       077   63    3F    ?                           177   127   7F    DEL




# https://en.wikipedia.org/wiki/Digraphs_and_trigraphs#C


# Some characters from the C and C++ character set are not available in all environments.
# You can enter these characters into a C or C++ source program using a sequence of three characters called a trigraph.
# The trigraph sequences are:
# 
# Trigraph	Single character	Description
# ??=		#					pound sign
# ??(		[					left bracket
# ??)		]					right bracket
# ??<		{					left brace
# ??>		}					right brace
# ??/		\					backslash
# ??'		^					caret
# ??!		|					vertical bar
# ??-		~					tilde
# The preprocessor replaces trigraph sequences with the corresponding single-character representation. For example,
# some_array??(i??) = n;
# Represents:
# some_array[i] = n;




sub random_nonspace_string
{
	my $maxSize = 65_536;
	my $fn1Ref = $_[0];

	srand;
	# ASCII: 32~126
	print $fn1Ref "static char *random_nonspace_string_array_". $maxSize. "[]={\n";
	my $offset = 0;
	do{
		if (0 eq $offset%16)
		{
			print $fn1Ref "\n";
		}

		my $len = 0;
		do{
			$len = int(rand(32));
		}while($len<=0 or $len>32);

		my $str = "";
		my $s = 0;
		do{
				my $d = 0;
				do{
					$d = int(rand(127));
				}while($d<32);
				# escaped and length
				my $c = (92==$d or 34==$d or 63==$d)?"\\":"";
				$c .= chr($d);
				$str .= $c;
				$s++;
		}while($s<=$len);
		print $fn1Ref  '"' . $str . '", ';

		$offset++;
	}while($offset<$maxSize);

	print $fn1Ref "\n};\n\n";

	return 0;
}



sub random_letter_string
{
	my $maxSize = 65_536;
	my $fn1Ref = $_[0];

	srand;
	# ASCII: 32~126

	print $fn1Ref "static char *random_letter_string_array_". $maxSize. "[]={\n";
	my $offset = 0;
	do{
		if (0 eq $offset%16)
		{
			print $fn1Ref "\n";
		}

		my $len = 0;
		do{
			$len = int(rand(32));
		}while($len<=0 or $len>32);

		my $str = "";
		my $s = 0;
		do{
				my $d = 0;
				do{
					$d = int(rand(123));
				}while($d<97);
				$str .= chr($d);
				$s++;
		}while($s<=$len);
		print $fn1Ref  '"' . $str . '", ';

		$offset++;
	}while($offset<$maxSize);

	print $fn1Ref "\n};\n\n";


	return 0;
}



sub random_reverse_letter_string
{
	my $maxSize = 65_536;
	my $fn1Ref = $_[0];

	srand;
	# ASCII: 32~126

	print $fn1Ref "static char *random_reverse_letter_string_array_" . $maxSize . "_2_[]={\n";
	my $offset = 0;
	do{
		if (0 eq $offset%16)
		{
			print $fn1Ref "\n";
		}

		my $len = 0;
		do{
			$len = int(rand(32));
		}while($len<=0 or $len>32);

		my $str = "";
		my $s = 0;
		do{
				my $d = 0;
				do{
					$d = int(rand(123));
				}while($d<97);
				$str .= chr($d);
				$s++;
		}while($s<=$len);
		print $fn1Ref  '"' . $str . '", ';
		my $rs = join("", reverse(split(//,$str)));
		print $fn1Ref  '"' . $rs . '", ';

		$offset++;
	}while($offset<$maxSize);

	print $fn1Ref "\n};\n\n";


	return 0;
}


sub random_KuoHao_string
{
	my $maxSize = 65_536;
	my $fn1Ref = $_[0];

	srand;
	# ASCII: 32~126

	print $fn1Ref "static char *random_KuoHao_string_array_". $maxSize. "[]={\n";
	my $offset = 0;
	do{
		if (0 eq $offset%16)
		{
			print $fn1Ref "\n";
		}

		my $len = 0;
		do{
			$len = int(rand(32));
		}while($len<=0 or $len>32);

		my $str = "";
		my $s = 0;
		do{
				my $d = 0;
				do{
					$d = int(rand(123));
				}while(!($d==40 or $d==41 or $d==91 or $d==93 or $d==123 or $d==125));
				$str .= chr($d);
				$s++;
		}while($s<=$len);
		print $fn1Ref  '"' . $str . '", ';

		$offset++;
	}while($offset<$maxSize);

	print $fn1Ref "\n};\n\n";


	return 0;
}





sub random_fake_english_words_string
{
	my $maxSize = 65_536;
	my $fn1Ref = $_[0];

	srand;
	# ASCII: 32~126

	print $fn1Ref "static char *random_fake_english_words_string_". $maxSize. "[]={\n";
	my $offset = 0;
	do{
		if (0 eq $offset%16)
		{
			print $fn1Ref "\n";
		}

		my $len = 0;
		do{
			$len = int(rand(128));
		}while($len<=0 or $len>32);

		my $str = "";
		my $s = 0;
		do{
				my $d = 0;
				do{
					$d = int(rand(123));
				}while(!($d==32 or $d>=97));
				$str .= chr($d);
				$s++;
		}while($s<=$len);
		print $fn1Ref  '"' . $str . '", ';

		$offset++;
	}while($offset<$maxSize);

	print $fn1Ref "\n};\n\n";


	return 0;
}


sub main
{
	my $fn1="./random_strings_array.c";
	my $fn1Ref=open_filehandle_for_output($fn1);


	random_nonspace_string($fn1Ref);
	random_letter_string($fn1Ref);

	random_reverse_letter_string($fn1Ref);
	random_KuoHao_string($fn1Ref);

	random_fake_english_words_string($fn1Ref);




	close($fn1Ref);


	return 0;
}
################################################################################
my $date = &getCurrentTime();
$OS_DATE = $date->{date};
chomp($OS_DATE);

main();

exit 0;
################################################################################

