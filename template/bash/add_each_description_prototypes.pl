#!/usr/bin/perl -w


# @filename           :  add_description_prototypes.pl
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

# https://metacpan.org/pod/File::Copy
use File::Copy;


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

sub open_filehandle_for_write
{
	my $filename = $_[0];
	my $overWriteFilename = ">" . $filename;
	local *FH;

	open (FH, $overWriteFilename) || die "Could not open $filename";

	return *FH;
}

sub open_filehandle_for_read
{
	my $filename = $_[0];
	local *FH;

	open (FH, $filename) || die "Could not open $filename";

	return *FH;
}


sub filter_title
{
	my $s = shift;

	$s =~ s/[~!@#\$%\^&\*\;\,\?]+-//g;

	return $s;
}

my $whereAmI="";
sub get_abs_path
{
	# best code, get file true path.
	use File::Spec;
	my $path_curf = File::Spec->rel2abs(__FILE__);
	#print ("file in PATH = ",$path_curf,"\n");
	my ($vol, $dirs, $file) = File::Spec->splitpath($path_curf);
	#print ("file in Dir = ", $dirs,"\n");

	return $dirs;
}


my %language_hash=(
"C++" => "cpp",
"Java" => "java",
"Python" => "python",
"Python3" => "python3",
"C" => "c",
"C#" => "csharp",
"JavaScript" => "javascript",
"Ruby" => "ruby",
"Swift" => "swift",
"Go" => "golang",
"Scala" => "scala",
"Kotlin" => "kotlin"
);

my %filename_extension=(
"cpp" => ".cpp",
"java" => ".java",
"python" => ".py",
"python3" => ".py",
"c" => ".c",
"csharp" => ".cs",
"javascript" => ".js",
"ruby" => ".rb",
"swift" => ".swift",
"golang" => ".go",
"scala" => ".scala",
"kotlin" => ".kt"
);

my %comment_strings=(
"cpp" => "//",
"java" => "//",
"python" => "#",
"python3" => "#",
"c" => "//",
"csharp" => "//",
"javascript" => "//",
"ruby" => "#",
"swift" => "//",
"golang" => "//",
"scala" => "//",
"kotlin" => "//"
);

sub get_filename_extension
{
	my $language = shift;
	foreach my $key ( sort keys %filename_extension )
	{
		if ($language eq $key)
		{
			return $filename_extension{$key};
		}
	}
}

sub get_comment_strings
{
	my $language = shift;
	foreach my $key ( sort keys %comment_strings )
	{
		if ($language eq $key)
		{
			return $comment_strings{$key};
		}
	}
}

sub add_description_prototypes
{
	my $difficulty = shift;
	my $language = shift;

	my $fnDirs = $whereAmI . "../win32/leetcode_all_" . $difficulty . ".dirs";
	my $fnDirsRef = open_filehandle_for_read($fnDirs);
	binmode $fnDirsRef, ":encoding(UTF-8)";


	my $HtmlDir = $whereAmI . "../win32/html_good/" . $difficulty . '/';
	my $SourceCodeDir = $whereAmI . "../../" . $difficulty . '/';


	my $fnDescriptionHtml = "";
	my $fnDescriptionHtmlRef;
	my $fnCodeDefinitionLanguageHtml = "";
	my $fnCodeDefinitionLanguageHtmlRef;


	my $srcDirName = "";
	my $templateFileName = "";
	my $templateFileNameRef;
	#my $language = "";
	my $counter = 0;
	my $dirIndex = 0;
	my $prefix = "";
	my $filename = "";
	my $filenameRef;
	foreach (<$fnDirsRef>)
	{
		$dirIndex++;
		my @darray = split(' ', $_);
		$srcDirName = $darray[0];
		if ("Locked" eq $darray[1])
		{
			print "$darray[0], $darray[1], $darray[2]\n";
			next;
		}
		$counter++;

		$_ =~ /^(c\d+)\_(\d+)\_(.*)$/;
		my $title = (split(' ', $3))[0];
		$title =~ s/[\r\n]//g;
		$prefix = $counter . '_' . $title;


		#foreach my $key ( sort keys %language_hash )
		{
			#$language = $language_hash{$key};
			my $srcFullDirName = $SourceCodeDir . '/' . $language . '/' . $srcDirName . '/';
			$templateFileName = $srcFullDirName . '00_leetcode_' . sprintf("%04d", $dirIndex-1) . get_filename_extension($language);
			$templateFileNameRef = open_filehandle_for_read($templateFileName);
			binmode $templateFileNameRef, ":encoding(UTF-8)";
			# my little girl
			my @tc = <$templateFileNameRef>;
			my $lineNumber = 0;
			close($templateFileNameRef);


			my $comment_strings = get_comment_strings($language);
			$fnDescriptionHtml = $HtmlDir . $prefix . '_description.html';
			if (! -r $fnDescriptionHtml)
			{
				print("$fnDescriptionHtml not exist!\n");
				next;
			}
			$fnDescriptionHtmlRef = open_filehandle_for_read($fnDescriptionHtml);
			binmode $fnDescriptionHtmlRef, ":encoding(UTF-8)";

			$fnCodeDefinitionLanguageHtml = $HtmlDir . $prefix . '_' . $language . '_language.html';
			if (! -r $fnCodeDefinitionLanguageHtml)
			{
				print("$fnCodeDefinitionLanguageHtml not exist!\n");
				close($fnDescriptionHtmlRef);
				next;
			}
			$fnCodeDefinitionLanguageHtmlRef = open_filehandle_for_read($fnCodeDefinitionLanguageHtml);
			binmode $fnCodeDefinitionLanguageHtmlRef, ":encoding(UTF-8)";


			$templateFileNameRef = open_filehandle_for_write($templateFileName);
			binmode $templateFileNameRef, ":utf8";
			foreach (@tc)
			{
				$lineNumber++;
				if (4 eq $lineNumber)
				{
					foreach (<$fnDescriptionHtmlRef>)
					{
						$_ =~ s/[\r\n]+//g;
						print $templateFileNameRef $comment_strings . $_ . "\n" if $_;
					}
					close($fnDescriptionHtmlRef);

					foreach (<$fnCodeDefinitionLanguageHtmlRef>)
					{
						$_ =~ s/[\r\n]+//g;
						$_ =~ s/^[\s\d]+$//g;
						print $templateFileNameRef $comment_strings . $_ . "\n" if $_;
					}
					close($fnCodeDefinitionLanguageHtmlRef);
					print $templateFileNameRef "\n";
				}
				print $templateFileNameRef $_;
			}
			close($templateFileNameRef);

			copy($HtmlDir . $prefix . '_solution.html', $srcFullDirName . $prefix . '_solution.html');
		}
	}

	close($fnDirsRef);

	return 0;
}


my $date = &getCurrentTime();
$OS_DATE = $date->{date};
chomp($OS_DATE);


sub main
{
	die "$0 difficulty language" unless @ARGV==2;
	#print($OS_DATE . "\n");

	$whereAmI=get_abs_path();

	my ($difficulty, $language) = @ARGV[0,1];
	add_description_prototypes($difficulty, $language);

	return 0;
}

################################################################################
main();
exit 0;
################################################################################