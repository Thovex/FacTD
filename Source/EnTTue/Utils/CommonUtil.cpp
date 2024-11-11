#include "EnTTue/Utils/CommonUtil.h"

#include "Internationalization/Regex.h"

namespace CommonUtil {
	FName ComponentTypeInfoToName(const entt::type_info& Info) {
		const FRegexPattern Pattern(TEXT("F(.+?_)?(.+?)(Component|Tag)?>\\(void\\) noexcept"));
		FRegexMatcher Matcher(Pattern, Info.name().data());

		if (Matcher.FindNext()) {
			FString ModuleName = Matcher.GetCaptureGroup(1).Replace(TEXT("_"), TEXT(""));
			FString ComponentName = Matcher.GetCaptureGroup(2);
			FString Suffix = Matcher.GetCaptureGroup(3); // This will capture either "Component" or "Tag"

			// Remove "Component" from the end if it exists, keep "Tag"
			if (Suffix.Equals(TEXT("Component"))) {
				ComponentName.RemoveFromEnd(TEXT("Component"));
			}

			// Insert spaces before uppercase letters
			FString FormattedName;
			for (int32 i = 0; i < ComponentName.Len(); ++i)
			{
				if (i > 0 && FChar::IsUpper(ComponentName[i]))
				{
					FormattedName.AppendChar(' ');
				}
				FormattedName.AppendChar(ComponentName[i]);
			}

			// If "Tag", append it back
			if (Suffix.Equals(TEXT("Tag"))) {
				FormattedName += " Tag";
			}

			// If ModuleName exists, wrap it with brackets
			if (!ModuleName.IsEmpty()) {
				FormattedName = FString::Printf(TEXT("[%s] %s"), *ModuleName, *FormattedName);
			}

			return FName(*FormattedName);
		}

		return NAME_None;
	}
}
