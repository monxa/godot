/**************************************************************************/
/*  resource_duplication_remap.cpp                                        */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include "resource_duplication_remap.h"

#include "core/io/resource.h"
#include "core/object/ref_counted.h"
#include "core/templates/hash_map.h"

struct ResourceDuplicationRemap::Data {
	HashMap<Ref<Resource>, Ref<Resource>> remap;
};

ResourceDuplicationRemap::ResourceDuplicationRemap() {
	data = memnew(Data);
}

ResourceDuplicationRemap::~ResourceDuplicationRemap() {
	memdelete(data);
}

bool ResourceDuplicationRemap::has(const Ref<Resource> &p_key) const {
	return data->remap.has(p_key);
}
Ref<Resource> ResourceDuplicationRemap::get(const Ref<Resource> &p_key) const {
	return data->remap.get(p_key);
}

void ResourceDuplicationRemap::insert(const Ref<Resource> &p_key, const Ref<Resource> &p_value) {
	data->remap.insert(p_key, p_value);
}
