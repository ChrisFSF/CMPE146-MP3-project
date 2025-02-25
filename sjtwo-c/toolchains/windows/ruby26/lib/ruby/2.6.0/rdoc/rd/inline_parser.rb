# frozen_string_literal: true
#
# DO NOT MODIFY!!!!
# This file is automatically generated by Racc 1.4.14
# from Racc grammer file "".
#

require 'racc/parser.rb'

require 'strscan'

class RDoc::RD

##
# RD format parser for inline markup such as emphasis, links, footnotes, etc.

class InlineParser < Racc::Parser


# :stopdoc:

EM_OPEN = '((*'
EM_OPEN_RE = /\A#{Regexp.quote(EM_OPEN)}/
EM_CLOSE = '*))'
EM_CLOSE_RE = /\A#{Regexp.quote(EM_CLOSE)}/
CODE_OPEN = '(({'
CODE_OPEN_RE = /\A#{Regexp.quote(CODE_OPEN)}/
CODE_CLOSE = '}))'
CODE_CLOSE_RE = /\A#{Regexp.quote(CODE_CLOSE)}/
VAR_OPEN = '((|'
VAR_OPEN_RE = /\A#{Regexp.quote(VAR_OPEN)}/
VAR_CLOSE = '|))'
VAR_CLOSE_RE = /\A#{Regexp.quote(VAR_CLOSE)}/
KBD_OPEN = '((%'
KBD_OPEN_RE = /\A#{Regexp.quote(KBD_OPEN)}/
KBD_CLOSE = '%))'
KBD_CLOSE_RE = /\A#{Regexp.quote(KBD_CLOSE)}/
INDEX_OPEN = '((:'
INDEX_OPEN_RE = /\A#{Regexp.quote(INDEX_OPEN)}/
INDEX_CLOSE = ':))'
INDEX_CLOSE_RE = /\A#{Regexp.quote(INDEX_CLOSE)}/
REF_OPEN = '((<'
REF_OPEN_RE = /\A#{Regexp.quote(REF_OPEN)}/
REF_CLOSE = '>))'
REF_CLOSE_RE = /\A#{Regexp.quote(REF_CLOSE)}/
FOOTNOTE_OPEN = '((-'
FOOTNOTE_OPEN_RE = /\A#{Regexp.quote(FOOTNOTE_OPEN)}/
FOOTNOTE_CLOSE = '-))'
FOOTNOTE_CLOSE_RE = /\A#{Regexp.quote(FOOTNOTE_CLOSE)}/
VERB_OPEN = "(('"
VERB_OPEN_RE = /\A#{Regexp.quote(VERB_OPEN)}/
VERB_CLOSE = "'))"
VERB_CLOSE_RE = /\A#{Regexp.quote(VERB_CLOSE)}/

BAR = "|"
BAR_RE = /\A#{Regexp.quote(BAR)}/
QUOTE = '"'
QUOTE_RE = /\A#{Regexp.quote(QUOTE)}/
SLASH = "/"
SLASH_RE = /\A#{Regexp.quote(SLASH)}/
BACK_SLASH = "\\"
BACK_SLASH_RE = /\A#{Regexp.quote(BACK_SLASH)}/
URL = "URL:"
URL_RE = /\A#{Regexp.quote(URL)}/

other_re_mode = Regexp::EXTENDED
other_re_mode |= Regexp::MULTILINE

OTHER_RE = Regexp.new(
  "\\A.+?(?=#{Regexp.quote(EM_OPEN)}|#{Regexp.quote(EM_CLOSE)}|
              #{Regexp.quote(CODE_OPEN)}|#{Regexp.quote(CODE_CLOSE)}|
              #{Regexp.quote(VAR_OPEN)}|#{Regexp.quote(VAR_CLOSE)}|
              #{Regexp.quote(KBD_OPEN)}|#{Regexp.quote(KBD_CLOSE)}|
              #{Regexp.quote(INDEX_OPEN)}|#{Regexp.quote(INDEX_CLOSE)}|
              #{Regexp.quote(REF_OPEN)}|#{Regexp.quote(REF_CLOSE)}|
            #{Regexp.quote(FOOTNOTE_OPEN)}|#{Regexp.quote(FOOTNOTE_CLOSE)}|
              #{Regexp.quote(VERB_OPEN)}|#{Regexp.quote(VERB_CLOSE)}|
              #{Regexp.quote(BAR)}|
              #{Regexp.quote(QUOTE)}|
              #{Regexp.quote(SLASH)}|
              #{Regexp.quote(BACK_SLASH)}|
              #{Regexp.quote(URL)})", other_re_mode)

# :startdoc:

##
# Creates a new parser for inline markup in the rd format.  The +block_parser+
# is used to for footnotes and labels in the inline text.

def initialize block_parser
  @block_parser = block_parser
end

##
# Parses the +inline+ text from RD format into RDoc format.

def parse inline
  @inline = inline
  @src = StringScanner.new inline
  @pre = "".dup
  @yydebug = true
  do_parse.to_s
end

##
# Returns the next token from the inline text

def next_token
  return [false, false] if @src.eos?
#  p @src.rest if @yydebug
  if ret = @src.scan(EM_OPEN_RE)
    @pre << ret
    [:EM_OPEN, ret]
  elsif ret = @src.scan(EM_CLOSE_RE)
    @pre << ret
    [:EM_CLOSE, ret]
  elsif ret = @src.scan(CODE_OPEN_RE)
    @pre << ret
    [:CODE_OPEN, ret]
  elsif ret = @src.scan(CODE_CLOSE_RE)
    @pre << ret
    [:CODE_CLOSE, ret]
  elsif ret = @src.scan(VAR_OPEN_RE)
    @pre << ret
    [:VAR_OPEN, ret]
  elsif ret = @src.scan(VAR_CLOSE_RE)
    @pre << ret
    [:VAR_CLOSE, ret]
  elsif ret = @src.scan(KBD_OPEN_RE)
    @pre << ret
    [:KBD_OPEN, ret]
  elsif ret = @src.scan(KBD_CLOSE_RE)
    @pre << ret
    [:KBD_CLOSE, ret]
  elsif ret = @src.scan(INDEX_OPEN_RE)
    @pre << ret
    [:INDEX_OPEN, ret]
  elsif ret = @src.scan(INDEX_CLOSE_RE)
    @pre << ret
    [:INDEX_CLOSE, ret]
  elsif ret = @src.scan(REF_OPEN_RE)
    @pre << ret
    [:REF_OPEN, ret]
  elsif ret = @src.scan(REF_CLOSE_RE)
    @pre << ret
    [:REF_CLOSE, ret]
  elsif ret = @src.scan(FOOTNOTE_OPEN_RE)
    @pre << ret
    [:FOOTNOTE_OPEN, ret]
  elsif ret = @src.scan(FOOTNOTE_CLOSE_RE)
    @pre << ret
    [:FOOTNOTE_CLOSE, ret]
  elsif ret = @src.scan(VERB_OPEN_RE)
    @pre << ret
    [:VERB_OPEN, ret]
  elsif ret = @src.scan(VERB_CLOSE_RE)
    @pre << ret
    [:VERB_CLOSE, ret]
  elsif ret = @src.scan(BAR_RE)
    @pre << ret
    [:BAR, ret]
  elsif ret = @src.scan(QUOTE_RE)
    @pre << ret
    [:QUOTE, ret]
  elsif ret = @src.scan(SLASH_RE)
    @pre << ret
    [:SLASH, ret]
  elsif ret = @src.scan(BACK_SLASH_RE)
    @pre << ret
    [:BACK_SLASH, ret]
  elsif ret = @src.scan(URL_RE)
    @pre << ret
    [:URL, ret]
  elsif ret = @src.scan(OTHER_RE)
    @pre << ret
    [:OTHER, ret]
  else
    ret = @src.rest
    @pre << ret
    @src.terminate
    [:OTHER, ret]
  end
end

##
# Raises a ParseError when invalid formatting is found

def on_error(et, ev, values)
  lines_of_rest = @src.rest.lines.to_a.length
  prev_words = prev_words_on_error(ev)
  at = 4 + prev_words.length

  message = <<-MSG
RD syntax error: line #{@block_parser.line_index - lines_of_rest}:
...#{prev_words} #{(ev||'')} #{next_words_on_error()} ...
  MSG

  message << " " * at + "^" * (ev ? ev.length : 0) + "\n"
  raise ParseError, message
end

##
# Returns words before the error

def prev_words_on_error(ev)
  pre = @pre
  if ev and /#{Regexp.quote(ev)}$/ =~ pre
    pre = $`
  end
  last_line(pre)
end

##
# Returns the last line of +src+

def last_line(src)
  if n = src.rindex("\n")
    src[(n+1) .. -1]
  else
    src
  end
end
private :last_line

##
# Returns words following an error

def next_words_on_error
  if n = @src.rest.index("\n")
    @src.rest[0 .. (n-1)]
  else
    @src.rest
  end
end

##
# Creates a new RDoc::RD::Inline for the +rdoc+ markup and the raw +reference+

def inline rdoc, reference = rdoc
  RDoc::RD::Inline.new rdoc, reference
end

# :stopdoc:
##### State transition tables begin ###

racc_action_table = [
   104,   103,   102,   100,   101,    99,   115,   116,   117,    29,
   105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
    84,   118,   119,    63,    64,    65,    61,    81,    62,    76,
    78,    79,    85,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    77,    80,   149,    63,    64,    65,   153,
    81,    62,    76,    78,    79,    86,    66,    67,    68,    69,
    70,    71,    72,    73,    74,    75,    77,    80,   152,   104,
   103,   102,   100,   101,    99,   115,   116,   117,    87,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,    88,
   118,   119,   104,   103,   102,   100,   101,    99,   115,   116,
   117,    89,   105,   106,   107,   108,   109,   110,   111,   112,
   113,   114,    96,   118,   119,   104,   103,   102,   100,   101,
    99,   115,   116,   117,   124,   105,   106,   107,   108,   109,
   110,   111,   112,   113,   114,   137,   118,   119,    22,    23,
    24,    25,    26,    21,    18,    19,   176,   177,    13,   148,
    14,   154,    15,   137,    16,   161,    17,   164,   173,    20,
    22,    23,    24,    25,    26,    21,    18,    19,   175,   177,
    13,   nil,    14,   nil,    15,   nil,    16,   nil,    17,   nil,
   nil,    20,    22,    23,    24,    25,    26,    21,    18,    19,
   nil,   nil,    13,   nil,    14,   nil,    15,   nil,    16,   nil,
    17,   nil,   nil,    20,    22,    23,    24,    25,    26,    21,
    18,    19,   nil,   nil,    13,   nil,    14,   nil,    15,   nil,
    16,   nil,    17,   nil,   nil,    20,    22,    23,    24,    25,
    26,    21,    18,    19,   nil,   nil,    13,   nil,    14,   nil,
    15,   nil,    16,   nil,    17,   nil,   nil,    20,    22,    23,
    24,    25,    26,    21,    18,    19,   nil,   nil,    13,   nil,
    14,   nil,    15,   nil,    16,   nil,    17,   nil,   nil,    20,
    22,    23,    24,    25,    26,    21,    18,    19,   nil,   nil,
    13,   nil,    14,   nil,    15,   nil,    16,   nil,    17,    42,
   nil,    20,    54,    38,    53,    55,    56,    57,   nil,    13,
   nil,    14,   nil,    15,   nil,    16,   nil,    17,   nil,   nil,
    20,    22,    23,    24,    25,    26,    21,    18,    19,   nil,
   nil,    13,   nil,    14,   nil,    15,   nil,    16,   nil,    17,
   nil,   nil,    20,    63,    64,    65,    61,    81,    62,    76,
    78,    79,   nil,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    77,    80,   122,   nil,   nil,    54,   nil,
    53,    55,    56,    57,   nil,    13,   nil,    14,   nil,    15,
   nil,    16,   nil,    17,   145,   nil,    20,    54,   133,    53,
    55,    56,    57,   nil,    13,   nil,    14,   nil,    15,   nil,
    16,   nil,    17,   145,   nil,    20,    54,   133,    53,    55,
    56,    57,   nil,    13,   nil,    14,   nil,    15,   nil,    16,
   nil,    17,   145,   nil,    20,    54,   133,    53,    55,    56,
    57,   nil,    13,   nil,    14,   nil,    15,   nil,    16,   nil,
    17,   145,   nil,    20,    54,   133,    53,    55,    56,    57,
   nil,    13,   nil,    14,   nil,    15,   nil,    16,   nil,    17,
   nil,   nil,    20,   135,   136,    54,   133,    53,    55,    56,
    57,   nil,    13,   nil,    14,   nil,    15,   nil,    16,   nil,
    17,   nil,   nil,    20,   135,   136,    54,   133,    53,    55,
    56,    57,   nil,    13,   nil,    14,   nil,    15,   nil,    16,
   nil,    17,   nil,   nil,    20,   135,   136,    54,   133,    53,
    55,    56,    57,   nil,    13,   nil,    14,   nil,    15,   nil,
    16,   nil,    17,    95,   nil,    20,    54,    91,    53,    55,
    56,    57,   145,   nil,   nil,    54,   133,    53,    55,    56,
    57,   158,   nil,   nil,    54,   nil,    53,    55,    56,    57,
   165,   135,   136,    54,   133,    53,    55,    56,    57,   145,
   nil,   nil,    54,   133,    53,    55,    56,    57,   172,   135,
   136,    54,   133,    53,    55,    56,    57,   174,   135,   136,
    54,   133,    53,    55,    56,    57,   178,   135,   136,    54,
   133,    53,    55,    56,    57,   135,   136,    54,   133,    53,
    55,    56,    57,   135,   136,    54,   133,    53,    55,    56,
    57,   135,   136,    54,   133,    53,    55,    56,    57,    22,
    23,    24,    25,    26,    21 ]

racc_action_check = [
    38,    38,    38,    38,    38,    38,    38,    38,    38,     1,
    38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
    29,    38,    38,    59,    59,    59,    59,    59,    59,    59,
    59,    59,    31,    59,    59,    59,    59,    59,    59,    59,
    59,    59,    59,    59,    59,    59,    61,    61,    61,    61,
    61,    61,    61,    61,    61,    32,    61,    61,    61,    61,
    61,    61,    61,    61,    61,    61,    61,    61,    61,    91,
    91,    91,    91,    91,    91,    91,    91,    91,    33,    91,
    91,    91,    91,    91,    91,    91,    91,    91,    91,    34,
    91,    91,    97,    97,    97,    97,    97,    97,    97,    97,
    97,    35,    97,    97,    97,    97,    97,    97,    97,    97,
    97,    97,    37,    97,    97,   155,   155,   155,   155,   155,
   155,   155,   155,   155,    41,   155,   155,   155,   155,   155,
   155,   155,   155,   155,   155,    43,   155,   155,     0,     0,
     0,     0,     0,     0,     0,     0,   165,   165,     0,    58,
     0,    90,     0,    94,     0,   100,     0,   125,   162,     0,
     2,     2,     2,     2,     2,     2,     2,     2,   164,   172,
     2,   nil,     2,   nil,     2,   nil,     2,   nil,     2,   nil,
   nil,     2,    13,    13,    13,    13,    13,    13,    13,    13,
   nil,   nil,    13,   nil,    13,   nil,    13,   nil,    13,   nil,
    13,   nil,   nil,    13,    14,    14,    14,    14,    14,    14,
    14,    14,   nil,   nil,    14,   nil,    14,   nil,    14,   nil,
    14,   nil,    14,   nil,   nil,    14,    15,    15,    15,    15,
    15,    15,    15,    15,   nil,   nil,    15,   nil,    15,   nil,
    15,   nil,    15,   nil,    15,   nil,   nil,    15,    16,    16,
    16,    16,    16,    16,    16,    16,   nil,   nil,    16,   nil,
    16,   nil,    16,   nil,    16,   nil,    16,   nil,   nil,    16,
    17,    17,    17,    17,    17,    17,    17,    17,   nil,   nil,
    17,   nil,    17,   nil,    17,   nil,    17,   nil,    17,    18,
   nil,    17,    18,    18,    18,    18,    18,    18,   nil,    18,
   nil,    18,   nil,    18,   nil,    18,   nil,    18,   nil,   nil,
    18,    19,    19,    19,    19,    19,    19,    19,    19,   nil,
   nil,    19,   nil,    19,   nil,    19,   nil,    19,   nil,    19,
   nil,   nil,    19,    20,    20,    20,    20,    20,    20,    20,
    20,    20,   nil,    20,    20,    20,    20,    20,    20,    20,
    20,    20,    20,    20,    20,    39,   nil,   nil,    39,   nil,
    39,    39,    39,    39,   nil,    39,   nil,    39,   nil,    39,
   nil,    39,   nil,    39,    44,   nil,    39,    44,    44,    44,
    44,    44,    44,   nil,    44,   nil,    44,   nil,    44,   nil,
    44,   nil,    44,    45,   nil,    44,    45,    45,    45,    45,
    45,    45,   nil,    45,   nil,    45,   nil,    45,   nil,    45,
   nil,    45,   138,   nil,    45,   138,   138,   138,   138,   138,
   138,   nil,   138,   nil,   138,   nil,   138,   nil,   138,   nil,
   138,   146,   nil,   138,   146,   146,   146,   146,   146,   146,
   nil,   146,   nil,   146,   nil,   146,   nil,   146,   nil,   146,
   nil,   nil,   146,    42,    42,    42,    42,    42,    42,    42,
    42,   nil,    42,   nil,    42,   nil,    42,   nil,    42,   nil,
    42,   nil,   nil,    42,   122,   122,   122,   122,   122,   122,
   122,   122,   nil,   122,   nil,   122,   nil,   122,   nil,   122,
   nil,   122,   nil,   nil,   122,   127,   127,   127,   127,   127,
   127,   127,   127,   nil,   127,   nil,   127,   nil,   127,   nil,
   127,   nil,   127,    36,   nil,   127,    36,    36,    36,    36,
    36,    36,    52,   nil,   nil,    52,    52,    52,    52,    52,
    52,    92,   nil,   nil,    92,   nil,    92,    92,    92,    92,
   126,   126,   126,   126,   126,   126,   126,   126,   126,   142,
   nil,   nil,   142,   142,   142,   142,   142,   142,   159,   159,
   159,   159,   159,   159,   159,   159,   159,   163,   163,   163,
   163,   163,   163,   163,   163,   163,   171,   171,   171,   171,
   171,   171,   171,   171,   171,    95,    95,    95,    95,    95,
    95,    95,    95,   158,   158,   158,   158,   158,   158,   158,
   158,   168,   168,   168,   168,   168,   168,   168,   168,    27,
    27,    27,    27,    27,    27 ]

racc_action_pointer = [
   135,     9,   157,   nil,   nil,   nil,   nil,   nil,   nil,   nil,
   nil,   nil,   nil,   179,   201,   223,   245,   267,   286,   308,
   330,   nil,   nil,   nil,   nil,   nil,   nil,   606,   nil,    20,
   nil,    18,    39,    60,    69,    79,   510,    89,    -3,   352,
   nil,   120,   449,   130,   371,   390,   nil,   nil,   nil,   nil,
   nil,   nil,   519,   nil,   nil,   nil,   nil,   nil,   138,    20,
   nil,    43,   nil,   nil,   nil,   nil,   nil,   nil,   nil,   nil,
   nil,   nil,   nil,   nil,   nil,   nil,   nil,   nil,   nil,   nil,
   nil,   nil,   nil,   nil,   nil,   nil,   nil,   nil,   nil,   nil,
   128,    66,   528,   nil,   148,   581,   nil,    89,   nil,   nil,
   149,   nil,   nil,   nil,   nil,   nil,   nil,   nil,   nil,   nil,
   nil,   nil,   nil,   nil,   nil,   nil,   nil,   nil,   nil,   nil,
   nil,   nil,   470,   nil,   nil,   154,   537,   491,   nil,   nil,
   nil,   nil,   nil,   nil,   nil,   nil,   nil,   nil,   409,   nil,
   nil,   nil,   546,   nil,   nil,   nil,   428,   nil,   nil,   nil,
   nil,   nil,   nil,   nil,   nil,   112,   nil,   nil,   589,   555,
   nil,   nil,   155,   564,   164,   142,   nil,   nil,   597,   nil,
   nil,   573,   164,   nil,   nil,   nil,   nil,   nil,   nil ]

racc_action_default = [
  -138,  -138,    -1,    -3,    -4,    -5,    -6,    -7,    -8,    -9,
   -10,   -11,   -12,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
  -138,  -103,  -104,  -105,  -106,  -107,  -108,  -111,  -110,  -138,
    -2,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,   -27,
   -26,   -35,  -138,   -58,   -41,   -40,   -47,   -48,   -49,   -50,
   -51,   -52,   -63,   -66,   -67,   -68,   -69,   -70,  -138,  -138,
  -112,  -138,  -116,  -117,  -118,  -119,  -120,  -121,  -122,  -123,
  -124,  -125,  -126,  -127,  -128,  -129,  -130,  -131,  -132,  -133,
  -134,  -135,  -137,  -109,   179,   -13,   -14,   -15,   -16,   -17,
  -138,  -138,   -23,   -22,   -33,  -138,   -19,   -24,   -79,   -80,
  -138,   -82,   -83,   -84,   -85,   -86,   -87,   -88,   -89,   -90,
   -91,   -92,   -93,   -94,   -95,   -96,   -97,   -98,   -99,  -100,
   -25,   -35,  -138,   -58,   -28,  -138,   -59,   -42,   -46,   -55,
   -56,   -65,   -71,   -72,   -75,   -76,   -77,   -31,   -38,   -44,
   -53,   -54,   -57,   -61,   -73,   -74,   -39,   -62,  -101,  -102,
  -136,  -113,  -114,  -115,   -18,   -20,   -21,   -33,  -138,  -138,
   -78,   -81,  -138,   -59,   -36,   -37,   -64,   -45,   -59,   -43,
   -60,  -138,   -34,   -36,   -37,   -29,   -30,   -32,   -34 ]

racc_goto_table = [
   126,    44,   125,    43,   144,   144,   160,    93,    97,    52,
   166,    82,   144,    40,    41,    39,   138,   146,   169,    30,
    36,    94,    44,     1,   123,   129,   169,    52,    90,    37,
    52,   167,   147,    92,   120,   121,    31,    32,    33,    34,
    35,   170,    58,   166,    59,    83,   170,   166,   151,   nil,
   150,   nil,   166,   159,     4,   166,     4,   nil,   nil,   nil,
   nil,   155,   nil,   156,   160,   nil,   nil,     4,     4,     4,
     4,     4,   nil,     4,     5,   nil,     5,   157,   nil,   nil,
   163,   nil,   162,    52,   nil,   168,   nil,     5,     5,     5,
     5,     5,   nil,     5,   nil,   nil,   nil,   nil,   144,   nil,
   nil,   nil,   144,   nil,   nil,   129,   144,   144,   nil,     6,
   129,     6,   nil,   nil,   nil,   nil,   171,     7,   nil,     7,
   nil,   nil,     6,     6,     6,     6,     6,     8,     6,     8,
     7,     7,     7,     7,     7,    11,     7,    11,   nil,   nil,
     8,     8,     8,     8,     8,   nil,     8,   nil,    11,    11,
    11,    11,    11,   nil,    11 ]

racc_goto_check = [
    22,    24,    21,    23,    36,    36,    37,    18,    16,    34,
    35,    41,    36,    19,    20,    17,    25,    25,    28,     3,
    13,    23,    24,     1,    23,    24,    28,    34,    14,    15,
    34,    29,    32,    17,    19,    20,     1,     1,     1,     1,
     1,    33,     1,    35,    38,    39,    33,    35,    42,   nil,
    41,   nil,    35,    22,     4,    35,     4,   nil,   nil,   nil,
   nil,    16,   nil,    18,    37,   nil,   nil,     4,     4,     4,
     4,     4,   nil,     4,     5,   nil,     5,    23,   nil,   nil,
    22,   nil,    21,    34,   nil,    22,   nil,     5,     5,     5,
     5,     5,   nil,     5,   nil,   nil,   nil,   nil,    36,   nil,
   nil,   nil,    36,   nil,   nil,    24,    36,    36,   nil,     6,
    24,     6,   nil,   nil,   nil,   nil,    22,     7,   nil,     7,
   nil,   nil,     6,     6,     6,     6,     6,     8,     6,     8,
     7,     7,     7,     7,     7,    11,     7,    11,   nil,   nil,
     8,     8,     8,     8,     8,   nil,     8,   nil,    11,    11,
    11,    11,    11,   nil,    11 ]

racc_goto_pointer = [
   nil,    23,   nil,    17,    54,    74,   109,   117,   127,   nil,
   nil,   135,   nil,     2,    -8,    11,   -30,    -3,   -29,    -5,
    -4,   -40,   -42,   -15,   -17,   -28,   nil,   nil,  -120,   -96,
   nil,   nil,   -20,  -101,    -9,  -116,   -40,   -91,    24,    18,
   nil,    -9,   -13 ]

racc_goto_default = [
   nil,   nil,     2,     3,    46,    47,    48,    49,    50,     9,
    10,    51,    12,   nil,   nil,   nil,   nil,   nil,   nil,   nil,
   nil,   nil,   nil,   nil,   140,   nil,    45,   127,   139,   128,
   141,   130,   142,   143,   132,   131,   134,    98,   nil,    28,
    27,   nil,    60 ]

racc_reduce_table = [
  0, 0, :racc_error,
  1, 27, :_reduce_none,
  2, 28, :_reduce_2,
  1, 28, :_reduce_3,
  1, 29, :_reduce_none,
  1, 29, :_reduce_none,
  1, 29, :_reduce_none,
  1, 29, :_reduce_none,
  1, 29, :_reduce_none,
  1, 29, :_reduce_none,
  1, 29, :_reduce_none,
  1, 29, :_reduce_none,
  1, 29, :_reduce_none,
  3, 30, :_reduce_13,
  3, 31, :_reduce_14,
  3, 32, :_reduce_15,
  3, 33, :_reduce_16,
  3, 34, :_reduce_17,
  4, 35, :_reduce_18,
  3, 35, :_reduce_19,
  2, 40, :_reduce_20,
  2, 40, :_reduce_21,
  1, 40, :_reduce_22,
  1, 40, :_reduce_23,
  2, 41, :_reduce_24,
  2, 41, :_reduce_25,
  1, 41, :_reduce_26,
  1, 41, :_reduce_27,
  2, 39, :_reduce_none,
  4, 39, :_reduce_29,
  4, 39, :_reduce_30,
  2, 43, :_reduce_31,
  4, 43, :_reduce_32,
  1, 44, :_reduce_33,
  3, 44, :_reduce_34,
  1, 45, :_reduce_none,
  3, 45, :_reduce_36,
  3, 45, :_reduce_37,
  2, 46, :_reduce_38,
  2, 46, :_reduce_39,
  1, 46, :_reduce_40,
  1, 46, :_reduce_41,
  1, 47, :_reduce_none,
  2, 51, :_reduce_43,
  1, 51, :_reduce_44,
  2, 53, :_reduce_45,
  1, 53, :_reduce_46,
  1, 50, :_reduce_none,
  1, 50, :_reduce_none,
  1, 50, :_reduce_none,
  1, 50, :_reduce_none,
  1, 50, :_reduce_none,
  1, 50, :_reduce_none,
  1, 54, :_reduce_none,
  1, 54, :_reduce_none,
  1, 55, :_reduce_none,
  1, 55, :_reduce_none,
  1, 56, :_reduce_57,
  1, 52, :_reduce_58,
  1, 57, :_reduce_59,
  2, 58, :_reduce_60,
  1, 58, :_reduce_none,
  2, 49, :_reduce_62,
  1, 49, :_reduce_none,
  2, 48, :_reduce_64,
  1, 48, :_reduce_none,
  1, 60, :_reduce_none,
  1, 60, :_reduce_none,
  1, 60, :_reduce_none,
  1, 60, :_reduce_none,
  1, 60, :_reduce_none,
  1, 62, :_reduce_none,
  1, 62, :_reduce_none,
  1, 59, :_reduce_none,
  1, 59, :_reduce_none,
  1, 61, :_reduce_none,
  1, 61, :_reduce_none,
  1, 61, :_reduce_none,
  2, 42, :_reduce_78,
  1, 42, :_reduce_none,
  1, 63, :_reduce_none,
  2, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  1, 63, :_reduce_none,
  3, 36, :_reduce_101,
  3, 37, :_reduce_102,
  1, 65, :_reduce_none,
  1, 65, :_reduce_none,
  1, 65, :_reduce_none,
  1, 65, :_reduce_none,
  1, 65, :_reduce_none,
  1, 65, :_reduce_none,
  2, 66, :_reduce_109,
  1, 66, :_reduce_none,
  1, 38, :_reduce_111,
  1, 67, :_reduce_none,
  2, 67, :_reduce_113,
  2, 67, :_reduce_114,
  2, 67, :_reduce_115,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  1, 68, :_reduce_none,
  2, 64, :_reduce_136,
  1, 64, :_reduce_none ]

racc_reduce_n = 138

racc_shift_n = 179

racc_token_table = {
  false => 0,
  :error => 1,
  :EX_LOW => 2,
  :QUOTE => 3,
  :BAR => 4,
  :SLASH => 5,
  :BACK_SLASH => 6,
  :URL => 7,
  :OTHER => 8,
  :REF_OPEN => 9,
  :FOOTNOTE_OPEN => 10,
  :FOOTNOTE_CLOSE => 11,
  :EX_HIGH => 12,
  :EM_OPEN => 13,
  :EM_CLOSE => 14,
  :CODE_OPEN => 15,
  :CODE_CLOSE => 16,
  :VAR_OPEN => 17,
  :VAR_CLOSE => 18,
  :KBD_OPEN => 19,
  :KBD_CLOSE => 20,
  :INDEX_OPEN => 21,
  :INDEX_CLOSE => 22,
  :REF_CLOSE => 23,
  :VERB_OPEN => 24,
  :VERB_CLOSE => 25 }

racc_nt_base = 26

racc_use_result_var = true

Racc_arg = [
  racc_action_table,
  racc_action_check,
  racc_action_default,
  racc_action_pointer,
  racc_goto_table,
  racc_goto_check,
  racc_goto_default,
  racc_goto_pointer,
  racc_nt_base,
  racc_reduce_table,
  racc_token_table,
  racc_shift_n,
  racc_reduce_n,
  racc_use_result_var ]

Racc_token_to_s_table = [
  "$end",
  "error",
  "EX_LOW",
  "QUOTE",
  "BAR",
  "SLASH",
  "BACK_SLASH",
  "URL",
  "OTHER",
  "REF_OPEN",
  "FOOTNOTE_OPEN",
  "FOOTNOTE_CLOSE",
  "EX_HIGH",
  "EM_OPEN",
  "EM_CLOSE",
  "CODE_OPEN",
  "CODE_CLOSE",
  "VAR_OPEN",
  "VAR_CLOSE",
  "KBD_OPEN",
  "KBD_CLOSE",
  "INDEX_OPEN",
  "INDEX_CLOSE",
  "REF_CLOSE",
  "VERB_OPEN",
  "VERB_CLOSE",
  "$start",
  "content",
  "elements",
  "element",
  "emphasis",
  "code",
  "var",
  "keyboard",
  "index",
  "reference",
  "footnote",
  "verb",
  "normal_str_ele",
  "substitute",
  "ref_label",
  "ref_label2",
  "ref_url_strings",
  "filename",
  "element_label",
  "element_label2",
  "ref_subst_content",
  "ref_subst_content_q",
  "ref_subst_strings_q",
  "ref_subst_strings_first",
  "ref_subst_ele2",
  "ref_subst_eles",
  "ref_subst_str_ele_first",
  "ref_subst_eles_q",
  "ref_subst_ele",
  "ref_subst_ele_q",
  "ref_subst_str_ele",
  "ref_subst_str_ele_q",
  "ref_subst_strings",
  "ref_subst_string3",
  "ref_subst_string",
  "ref_subst_string_q",
  "ref_subst_string2",
  "ref_url_string",
  "verb_strings",
  "normal_string",
  "normal_strings",
  "verb_string",
  "verb_normal_string" ]

Racc_debug_parser = false

##### State transition tables end #####

# reduce 0 omitted

# reduce 1 omitted

def _reduce_2(val, _values, result)
 result.append val[1]
    result
end

def _reduce_3(val, _values, result)
 result = val[0]
    result
end

# reduce 4 omitted

# reduce 5 omitted

# reduce 6 omitted

# reduce 7 omitted

# reduce 8 omitted

# reduce 9 omitted

# reduce 10 omitted

# reduce 11 omitted

# reduce 12 omitted

def _reduce_13(val, _values, result)
      content = val[1]
      result = inline "<em>#{content}</em>", content

    result
end

def _reduce_14(val, _values, result)
      content = val[1]
      result = inline "<code>#{content}</code>", content

    result
end

def _reduce_15(val, _values, result)
      content = val[1]
      result = inline "+#{content}+", content

    result
end

def _reduce_16(val, _values, result)
      content = val[1]
      result = inline "<tt>#{content}</tt>", content

    result
end

def _reduce_17(val, _values, result)
      label = val[1]
      @block_parser.add_label label.reference
      result = "<span id=\"label-#{label}\">#{label}</span>"

    result
end

def _reduce_18(val, _values, result)
      result = "{#{val[1]}}[#{val[2].join}]"

    result
end

def _reduce_19(val, _values, result)
      scheme, inline = val[1]

      result = "{#{inline}}[#{scheme}#{inline.reference}]"

    result
end

def _reduce_20(val, _values, result)
      result = [nil, inline(val[1])]

    result
end

def _reduce_21(val, _values, result)
      result = [
        'rdoc-label:',
        inline("#{val[0].reference}/#{val[1].reference}")
      ]

    result
end

def _reduce_22(val, _values, result)
      result = ['rdoc-label:', val[0].reference]

    result
end

def _reduce_23(val, _values, result)
      result = ['rdoc-label:', "#{val[0].reference}/"]

    result
end

def _reduce_24(val, _values, result)
      result = [nil, inline(val[1])]

    result
end

def _reduce_25(val, _values, result)
      result = [
        'rdoc-label:',
        inline("#{val[0].reference}/#{val[1].reference}")
      ]

    result
end

def _reduce_26(val, _values, result)
      result = ['rdoc-label:', val[0]]

    result
end

def _reduce_27(val, _values, result)
      ref = val[0].reference
      result = ['rdoc-label:', inline(ref, "#{ref}/")]

    result
end

# reduce 28 omitted

def _reduce_29(val, _values, result)
 result = val[1]
    result
end

def _reduce_30(val, _values, result)
 result = val[1]
    result
end

def _reduce_31(val, _values, result)
      result = inline val[0]

    result
end

def _reduce_32(val, _values, result)
      result = inline "\"#{val[1]}\""

    result
end

def _reduce_33(val, _values, result)
      result = inline val[0]

    result
end

def _reduce_34(val, _values, result)
      result = inline "\"#{val[1]}\""

    result
end

# reduce 35 omitted

def _reduce_36(val, _values, result)
 result = val[1]
    result
end

def _reduce_37(val, _values, result)
 result = inline val[1]
    result
end

def _reduce_38(val, _values, result)
      result = val[0].append val[1]

    result
end

def _reduce_39(val, _values, result)
      result = val[0].append val[1]

    result
end

def _reduce_40(val, _values, result)
      result = val[0]

    result
end

def _reduce_41(val, _values, result)
      result = inline val[0]

    result
end

# reduce 42 omitted

def _reduce_43(val, _values, result)
      result = val[0].append val[1]

    result
end

def _reduce_44(val, _values, result)
      result = inline val[0]

    result
end

def _reduce_45(val, _values, result)
      result = val[0].append val[1]

    result
end

def _reduce_46(val, _values, result)
      result = val[0]

    result
end

# reduce 47 omitted

# reduce 48 omitted

# reduce 49 omitted

# reduce 50 omitted

# reduce 51 omitted

# reduce 52 omitted

# reduce 53 omitted

# reduce 54 omitted

# reduce 55 omitted

# reduce 56 omitted

def _reduce_57(val, _values, result)
      result = val[0]

    result
end

def _reduce_58(val, _values, result)
      result = inline val[0]

    result
end

def _reduce_59(val, _values, result)
      result = inline val[0]

    result
end

def _reduce_60(val, _values, result)
 result << val[1]
    result
end

# reduce 61 omitted

def _reduce_62(val, _values, result)
      result << val[1]

    result
end

# reduce 63 omitted

def _reduce_64(val, _values, result)
      result << val[1]

    result
end

# reduce 65 omitted

# reduce 66 omitted

# reduce 67 omitted

# reduce 68 omitted

# reduce 69 omitted

# reduce 70 omitted

# reduce 71 omitted

# reduce 72 omitted

# reduce 73 omitted

# reduce 74 omitted

# reduce 75 omitted

# reduce 76 omitted

# reduce 77 omitted

def _reduce_78(val, _values, result)
 result << val[1]
    result
end

# reduce 79 omitted

# reduce 80 omitted

# reduce 81 omitted

# reduce 82 omitted

# reduce 83 omitted

# reduce 84 omitted

# reduce 85 omitted

# reduce 86 omitted

# reduce 87 omitted

# reduce 88 omitted

# reduce 89 omitted

# reduce 90 omitted

# reduce 91 omitted

# reduce 92 omitted

# reduce 93 omitted

# reduce 94 omitted

# reduce 95 omitted

# reduce 96 omitted

# reduce 97 omitted

# reduce 98 omitted

# reduce 99 omitted

# reduce 100 omitted

def _reduce_101(val, _values, result)
      index = @block_parser.add_footnote val[1].rdoc
      result = "{*#{index}}[rdoc-label:foottext-#{index}:footmark-#{index}]"

    result
end

def _reduce_102(val, _values, result)
      result = inline "<tt>#{val[1]}</tt>", val[1]

    result
end

# reduce 103 omitted

# reduce 104 omitted

# reduce 105 omitted

# reduce 106 omitted

# reduce 107 omitted

# reduce 108 omitted

def _reduce_109(val, _values, result)
 result << val[1]
    result
end

# reduce 110 omitted

def _reduce_111(val, _values, result)
      result = inline val[0]

    result
end

# reduce 112 omitted

def _reduce_113(val, _values, result)
 result = val[1]
    result
end

def _reduce_114(val, _values, result)
 result = val[1]
    result
end

def _reduce_115(val, _values, result)
 result = val[1]
    result
end

# reduce 116 omitted

# reduce 117 omitted

# reduce 118 omitted

# reduce 119 omitted

# reduce 120 omitted

# reduce 121 omitted

# reduce 122 omitted

# reduce 123 omitted

# reduce 124 omitted

# reduce 125 omitted

# reduce 126 omitted

# reduce 127 omitted

# reduce 128 omitted

# reduce 129 omitted

# reduce 130 omitted

# reduce 131 omitted

# reduce 132 omitted

# reduce 133 omitted

# reduce 134 omitted

# reduce 135 omitted

def _reduce_136(val, _values, result)
 result << val[1]
    result
end

# reduce 137 omitted

def _reduce_none(val, _values, result)
  val[0]
end

end   # class InlineParser

end
