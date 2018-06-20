#!/usr/bin/perl -w


# @filename           :  easy_and_medium_link.pl
# @author             :  Copyright (C) drunkwater
# @date               :  Mon Jan 15 12:43:38 HKT 2018
# @function           :  create file README.md within links.
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


sub filter_title
{
	my $s = shift;

	$s =~ s/[~!@#\$%\^&\*\;\,\?]+//g;

	return $s;
}



my $lc_site = "https://leetcode.com";
my $easy_c_folder = 'https://github.com/drunkwater/leetcode/tree/master/easy_c/';
my $easy_cpp_folder = 'https://github.com/drunkwater/leetcode/tree/master/easy_cpp/';
my $medium_c_folder = 'https://github.com/drunkwater/leetcode/tree/master/medium_c/';
my $medium_cpp_folder = 'https://github.com/drunkwater/leetcode/tree/master/medium_cpp/';
my $hard_c_folder = 'https://github.com/drunkwater/leetcode/tree/master/hard_c/';
my $hard_cpp_folder = 'https://github.com/drunkwater/leetcode/tree/master/hard_cpp/';

my $blank_line = "| blank | blank | blank | blank | blank |\n";

use HTML::TreeBuilder;


sub add_easy_table
{
	my $fn0="./easy_tbody.html";
	my $fn0Ref=open_filehandle_for_input($fn0);

	my $fn1="./easy.list";
	my $fn1Ref=open_filehandle_for_output($fn1);


	my $fn2Ref = $_[0];

	my $tree = new HTML::TreeBuilder();
	binmode $fn0Ref, ":utf8";
	$tree->parse_file($fn0Ref);

	#$tree->dump;
	my $sequence = 0;
	my $easyIndex = 0;
	my $fname = '';


	foreach my $div ( $tree->find_by_tag_name("div") )
	{
		my $a = $div->find_by_tag_name('a');
		my $href = $a->attr('href');

		my $title = $a->as_text;

		$title =~ s/New$//g;
		$title = trim($title);
		$title =~ s/\s/_/g;
		$title = filter_title($title);

		my $offset = 0;
		foreach my $cell ( $div->parent->parent->content_list )
		{
			if (1 eq $offset)
			{
				$sequence = $cell->as_text;

				$easyIndex = sprintf("%04d", $easyIndex);
				$fname = "c" . $easyIndex . "_" . $sequence . "_" . $title;
				print $fn1Ref $fname . "\n";
			}

			$offset++;
		}

		my $line = '|' . $sequence . '|[' . $title . '](' . $lc_site . $href . q{)|[C](} . $easy_c_folder . $fname . q{)|[C++](} . $easy_cpp_folder . $fname . ")|Easy|\n";
		print $fn2Ref $line;

		$easyIndex++;
	}

	$tree->delete;

	print $fn2Ref $blank_line;

	close($fn0Ref);
	close($fn1Ref);



	return 0;
}


sub add_medium_table
{
	my $fn0="./medium_tbody.html";
	my $fn0Ref=open_filehandle_for_input($fn0);

	my $fn1="./medium.list";
	my $fn1Ref=open_filehandle_for_output($fn1);


	my $fn2Ref=$_[0];

	my $tree = new HTML::TreeBuilder();
	binmode $fn0Ref, ":utf8";
	$tree->parse_file($fn0Ref);

	#$tree->dump;
	my $sequence = 0;
	my $easyIndex = 0;
	my $fname = '';


	foreach my $div ( $tree->find_by_tag_name("div") )
	{
		my $a = $div->find_by_tag_name('a');
		my $href = $a->attr('href');

		my $title = $a->as_text;

		$title =~ s/New$//g;
		$title = trim($title);
		$title =~ s/\s/_/g;
		$title = filter_title($title);

		my $offset = 0;
		foreach my $cell ( $div->parent->parent->content_list )
		{
			if (1 eq $offset)
			{
				$sequence = $cell->as_text;

				$easyIndex = sprintf("%04d", $easyIndex);
				$fname = "c" . $easyIndex . "_" . $sequence . "_" . $title;
				print $fn1Ref $fname . "\n";
			}

			$offset++;
		}

		my $line = '|' . $sequence . '|[' . $title . '](' . $lc_site . $href . q{)|[C](} . $medium_c_folder . $fname . q{)|[C++](} . $medium_cpp_folder . $fname . ")|Medium|\n";
		print $fn2Ref $line;

		$easyIndex++;
	}

	$tree->delete;

	print $fn2Ref $blank_line;

	close($fn0Ref);
	close($fn1Ref);



	return 0;
}



sub add_hard_table
{
	my $fn0="./hard_tbody.html";
	my $fn0Ref=open_filehandle_for_input($fn0);

	my $fn1="./hard.list";
	my $fn1Ref=open_filehandle_for_output($fn1);


	my $fn2Ref=$_[0];

	my $tree = new HTML::TreeBuilder();
	binmode $fn0Ref, ":utf8";
	$tree->parse_file($fn0Ref);

	#$tree->dump;
	my $sequence = 0;
	my $easyIndex = 0;
	my $fname = '';


	foreach my $div ( $tree->find_by_tag_name("div") )
	{
		my $a = $div->find_by_tag_name('a');
		my $href = $a->attr('href');

		my $title = $a->as_text;

		$title =~ s/New$//g;
		$title = trim($title);
		$title =~ s/\s/_/g;
		$title = filter_title($title);

		my $offset = 0;
		foreach my $cell ( $div->parent->parent->content_list )
		{
			if (1 eq $offset)
			{
				$sequence = $cell->as_text;

				$easyIndex = sprintf("%04d", $easyIndex);
				$fname = "c" . $easyIndex . "_" . $sequence . "_" . $title;
				print $fn1Ref $fname . "\n";
			}

			$offset++;
		}

		my $line = '|' . $sequence . '|[' . $title . '](' . $lc_site . $href . q{)|[C](} . $hard_c_folder . $fname . q{)|[C++](} . $hard_cpp_folder . $fname . ")|Hard|\n";
		print $fn2Ref $line;

		$easyIndex++;
	}

	$tree->delete;

	print $fn2Ref $blank_line;

	close($fn0Ref);
	close($fn1Ref);



	return 0;
}


sub main
{
	# ../../README.md
	my $fn2="../../README.md";
	my $fn2Ref=open_filehandle_for_output($fn2);


	while (<DATA>)
	{
		print $fn2Ref $_;
	}
	print $fn2Ref "\n" x 4;


	print $fn2Ref "# Date";
	print $fn2Ref "\n" x 2;
	my $dateString = `date`;
	print $fn2Ref $dateString;
	print $fn2Ref "\n" x 4;


	print $fn2Ref "# Solutions Table";
	print $fn2Ref "\n" x 4;

	print $fn2Ref "|  #  | leetcode Title | c | c++ | Difficulty |\n";
	print $fn2Ref "|-----| -------------- | - | --- | ---------- |\n";


	add_easy_table($fn2Ref);
	add_medium_table($fn2Ref);
	add_hard_table($fn2Ref);


	close($fn2Ref);


	return 0;
}



################################################################################
my $date = &getCurrentTime();
$OS_DATE = $date->{date};
chomp($OS_DATE);

main();

exit 0;
################################################################################





__DATA__

# drunkwater


```bash
# @filename           :  c100
# @author             :  Copyright (C) drunkwater
# @date               :  Tue Jan 16 12:59:51 HKT 2018
# @function           :  
# @see                :  
# @require            :  
```


```c
/*
# @filename           :  c100
# @author             :  Copyright (C) drunkwater
# @date               :  Tue Jan 16 12:59:51 HKT 2018
# @function           :  
# @see                :  
# @require            :  
*/
```




# clone my codes


`git clone https://github.com/drunkwater/leetcode.git --depth=1`




# C and C++ on leetcode


[https://leetcode.com/](https://leetcode.com/)
