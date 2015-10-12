#include <stdlib.h>
#include <stdio.h>
#import <Foundation/Foundation.h>
#import <CoreText/CoreText.h>

#import "markdown_peg.h"

enum markdown_extensions {
	EXT_NONE             = 0x00,
	EXT_SMART            = 0x01,
	EXT_NOTES            = 0x02,
	EXT_FILTER_HTML      = 0x04,
	EXT_FILTER_STYLES    = 0x08,
	EXT_ALL              = 0xFF
};

enum markdown_formats {
    HTML_FORMAT,
    LATEX_FORMAT,
    GROFF_MM_FORMAT
};

struct Element* markdown_to_element(NSString *text, int extensions);
NSMutableAttributedString* element_to_attr_string(struct Element* result, int extensions, NSDictionary* attributes, NSDictionary* defaultAttrs);

NSMutableAttributedString* markdown_to_attr_string(NSString *text, int extensions, NSDictionary* attributes, NSDictionary* defaultAttrs);

NSMutableString * markdown_to_nsstring(NSString *text, int extensions, int output_format);
const char * markdown_to_string(NSString *text, int extensions, int output_format);

@interface NSMutableString (Sugar)
- (void)appendCharacter:(unichar)ch;
@end

@interface NSString (Sugar)
- (const char *)defaultCString;
@end

/* vim: set ts=4 sw=4 : */
