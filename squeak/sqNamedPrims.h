/* This is an automatically generated table of all builtin modules in the VM */

extern sqExport vm_exports[];
extern sqExport os_exports[];
extern sqExport B2DPlugin_exports[];
extern sqExport BitBltPlugin_exports[];
extern sqExport FilePlugin_exports[];
extern sqExport FloatArrayPlugin_exports[];
extern sqExport LargeIntegers_exports[];
extern sqExport Matrix2x3Plugin_exports[];
extern sqExport MiscPrimitivePlugin_exports[];
extern sqExport SecurityPlugin_exports[];

sqExport *pluginExports[] = {
	vm_exports,
	os_exports,
	B2DPlugin_exports,
	BitBltPlugin_exports,
	FilePlugin_exports,
	FloatArrayPlugin_exports,
	LargeIntegers_exports,
	Matrix2x3Plugin_exports,
	MiscPrimitivePlugin_exports,
	SecurityPlugin_exports,
	NULL
};
