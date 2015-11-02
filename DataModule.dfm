object DM: TDM
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  OnDestroy = DataModuleDestroy
  Height = 512
  Width = 784
  object ADOConnection: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=MSDASQL.1;Password=root;Persist Security Info=True;User' +
      ' ID=root;Data Source=MySQL;Mode=ReadWrite;Initial Catalog=hochsc' +
      'hule'
    LoginPrompt = False
    Mode = cmReadWrite
    Left = 40
    Top = 8
  end
  object domain: TADOTable
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    TableName = 'domain'
    Left = 40
    Top = 72
    object domainid: TIntegerField
      DisplayLabel = #1050#1086#1076' '#1075#1072#1083#1091#1079#1110
      FieldName = 'id'
    end
    object domainname: TWideStringField
      DisplayLabel = #1053#1072#1079#1074#1072' '#1075#1072#1083#1091#1079#1110
      FieldName = 'name'
      Size = 100
    end
  end
  object eduLevel: TADOTable
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    TableName = 'edu_level'
    Left = 144
    Top = 72
    object eduLevelid: TIntegerField
      DisplayLabel = #1050#1086#1076' '#1054#1050#1056
      FieldName = 'id'
    end
    object eduLevelname: TWideStringField
      DisplayLabel = #1054#1050#1056
      FieldName = 'name'
      Size = 50
    end
  end
  object hochAndLevel: TADOTable
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    TableName = 'hoch_and_level'
    Left = 264
    Top = 72
    object hochAndLevellevel_id: TIntegerField
      DisplayLabel = #1056#1110#1074#1077#1085#1100' '#1072#1082#1088#1077#1076#1080#1090#1072#1094#1110#1111
      FieldName = 'level_id'
    end
    object hochAndLevelhochschule_lookup: TStringField
      DisplayLabel = #1042#1053#1047
      FieldKind = fkLookup
      FieldName = 'hochschule_lookup'
      LookupDataSet = hochschule
      LookupKeyFields = 'id'
      LookupResultField = 'name'
      KeyFields = 'hochschule_id'
      Size = 255
      Lookup = True
    end
    object hochAndLevelhochschule_id: TIntegerField
      FieldName = 'hochschule_id'
      Visible = False
    end
  end
  object hochType: TADOTable
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    TableName = 'hoch_type'
    Left = 384
    Top = 72
    object hochTypeid: TAutoIncField
      DisplayLabel = #1050#1086#1076' '#1090#1080#1087#1091' '#1042#1053#1047
      FieldName = 'id'
      ReadOnly = True
    end
    object hochTypetype: TWideStringField
      DisplayLabel = #1058#1080#1087' '#1042#1053#1047
      FieldName = 'type'
      Size = 120
    end
  end
  object hochschule: TADOTable
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    AfterScroll = hochschuleAfterScroll
    TableName = 'hochschule'
    Left = 504
    Top = 72
    object hochschulehoch_type_id: TIntegerField
      FieldName = 'hoch_type_id'
      Visible = False
    end
    object hochschuleid: TAutoIncField
      DisplayLabel = #1050#1086#1076
      FieldName = 'id'
      ReadOnly = True
    end
    object hochschulename: TWideStringField
      DisplayLabel = #1053#1072#1079#1074#1072
      FieldName = 'name'
      Size = 255
    end
    object hochschulehoch_type_lookup: TStringField
      DisplayLabel = #1058#1080#1087
      FieldKind = fkLookup
      FieldName = 'hoch_type_lookup'
      LookupDataSet = hochType
      LookupKeyFields = 'id'
      LookupResultField = 'type'
      KeyFields = 'hoch_type_id'
      Size = 120
      Lookup = True
    end
    object hochschuleregion_lookup: TWideStringField
      DisplayLabel = #1054#1073#1083#1072#1089#1090#1100
      FieldKind = fkLookup
      FieldName = 'region'
      LookupDataSet = place
      LookupKeyFields = 'id'
      LookupResultField = 'region_lookup'
      KeyFields = 'place_id'
      Size = 50
      Lookup = True
    end
    object hochschulesettlement: TWideStringField
      DisplayLabel = #1053#1072#1089#1077#1083#1077#1085#1080#1081' '#1087#1091#1085#1082#1090
      FieldKind = fkLookup
      FieldName = 'settlement'
      LookupDataSet = place
      LookupKeyFields = 'id'
      LookupResultField = 'settlement_lookup'
      KeyFields = 'place_id'
      Size = 50
      Lookup = True
    end
    object hochschulestreet: TWideStringField
      DisplayLabel = #1042#1091#1083#1080#1094#1103
      FieldName = 'street'
      Size = 100
    end
    object hochschuleplace_id: TIntegerField
      FieldName = 'place_id'
    end
    object hochschuleemail: TWideStringField
      FieldName = 'email'
      Size = 70
    end
    object hochschulephone: TWideStringField
      DisplayLabel = #1058#1077#1083#1077#1092#1086#1085
      FieldName = 'phone'
      Size = 50
    end
    object hochschuleregion_id: TIntegerField
      FieldKind = fkLookup
      FieldName = 'region_id'
      LookupDataSet = place
      LookupKeyFields = 'id'
      LookupResultField = 'region_id'
      KeyFields = 'place_id'
      Lookup = True
    end
    object hochschulesettlement_id: TIntegerField
      FieldKind = fkLookup
      FieldName = 'settlement_id'
      LookupDataSet = place
      LookupKeyFields = 'id'
      LookupResultField = 'settlement_id'
      KeyFields = 'place_id'
      Lookup = True
    end
    object hochschuleaccr_level_low: TIntegerField
      FieldName = 'accr_level_low'
    end
    object hochschuleaccr_level_high: TIntegerField
      FieldName = 'accr_level_high'
    end
  end
  object place: TADOTable
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    TableName = 'place'
    Left = 608
    Top = 72
    object placeid: TAutoIncField
      DisplayLabel = #1050#1086#1076
      FieldName = 'id'
      ReadOnly = True
    end
    object placesettlement_id: TIntegerField
      FieldName = 'settlement_id'
      Visible = False
    end
    object placeregion_id: TIntegerField
      FieldName = 'region_id'
      Visible = False
    end
    object placesettlement_lookup: TWideStringField
      DisplayLabel = #1053#1072#1089#1077#1083#1077#1085#1080#1081' '#1087#1091#1085#1082#1090
      FieldKind = fkLookup
      FieldName = 'settlement_lookup'
      LookupDataSet = settlement
      LookupKeyFields = 'id'
      LookupResultField = 'name'
      KeyFields = 'settlement_id'
      Size = 50
      Lookup = True
    end
    object placeregion_lookup: TWideStringField
      DisplayLabel = #1054#1073#1083#1072#1089#1090#1100
      FieldKind = fkLookup
      FieldName = 'region_lookup'
      LookupDataSet = region
      LookupKeyFields = 'id'
      LookupResultField = 'name'
      KeyFields = 'region_id'
      Size = 50
      Lookup = True
    end
  end
  object region: TADOTable
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    TableName = 'region'
    Left = 712
    Top = 72
    object regionid: TAutoIncField
      DisplayLabel = #1050#1086#1076' '#1086#1073#1083#1072#1089#1090#1110
      FieldName = 'id'
      ReadOnly = True
    end
    object regionname: TWideStringField
      DisplayLabel = #1054#1073#1083#1072#1089#1090#1100
      FieldName = 'name'
      Size = 50
    end
  end
  object settlement: TADOTable
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    TableName = 'settlement'
    Left = 40
    Top = 192
    object settlementid: TAutoIncField
      DisplayLabel = #1050#1086#1076' '#1053#1055
      FieldName = 'id'
      ReadOnly = True
    end
    object settlementname: TWideStringField
      DisplayLabel = #1053#1072#1089#1077#1083#1077#1085#1080#1081' '#1087#1091#1085#1082#1090
      FieldName = 'name'
      Size = 50
    end
  end
  object speciality: TADOTable
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    TableName = 'speciality'
    Left = 160
    Top = 192
    object specialityid: TAutoIncField
      DisplayLabel = #1050#1086#1076
      FieldName = 'id'
      ReadOnly = True
    end
    object specialityedu_level_lookup: TWideStringField
      DisplayLabel = #1054#1050#1056
      FieldKind = fkLookup
      FieldName = 'edu_level_lookup'
      LookupDataSet = eduLevel
      LookupKeyFields = 'id'
      LookupResultField = 'name'
      KeyFields = 'edu_level_id'
      Size = 50
      Lookup = True
    end
    object specialitydomain_lookup: TWideStringField
      DisplayLabel = #1043#1072#1083#1091#1079#1100
      FieldKind = fkLookup
      FieldName = 'domain_lookup'
      LookupDataSet = domain
      LookupKeyFields = 'id'
      LookupResultField = 'name'
      KeyFields = 'domain_id'
      Size = 100
      Lookup = True
    end
    object specialityname: TWideStringField
      DisplayLabel = #1053#1072#1087#1088#1103#1084
      FieldName = 'name'
      Size = 255
    end
    object specialityedu_level_id: TIntegerField
      DisplayLabel = #1050#1086#1076' '#1054#1050#1056
      FieldName = 'edu_level_id'
    end
    object specialitydomain_id: TIntegerField
      DisplayLabel = #1050#1086#1076' '#1075#1072#1083#1091#1079#1110
      FieldName = 'domain_id'
    end
    object specialitycourse_code: TIntegerField
      DisplayLabel = #1050#1086#1076' '#1085#1072#1087#1088#1103#1084#1091
      FieldName = 'course_code'
    end
  end
  object structUnitSpec: TADOTable
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    AfterScroll = structUnitSpecAfterScroll
    TableName = 'struct_unit_spec'
    Left = 264
    Top = 192
    object structUnitSpecid: TAutoIncField
      FieldName = 'id'
      ReadOnly = True
    end
    object structUnitSpecstructural_unit_id: TIntegerField
      FieldName = 'structural_unit_id'
    end
    object structUnitSpecspeciality_id: TIntegerField
      FieldName = 'speciality_id'
    end
    object structUnitSpecedu_level_lookup: TWideStringField
      FieldKind = fkLookup
      FieldName = 'edu_level_lookup'
      LookupDataSet = speciality
      LookupKeyFields = 'id'
      LookupResultField = 'edu_level_lookup'
      KeyFields = 'speciality_id'
      Size = 50
      Lookup = True
    end
    object structUnitSpecdomain_lookup: TWideStringField
      FieldKind = fkLookup
      FieldName = 'domain_lookup'
      LookupDataSet = speciality
      LookupKeyFields = 'id'
      LookupResultField = 'domain_lookup'
      KeyFields = 'speciality_id'
      Size = 100
      Lookup = True
    end
    object structUnitSpeccourse_name: TWideStringField
      FieldKind = fkLookup
      FieldName = 'course_name'
      LookupDataSet = speciality
      LookupKeyFields = 'id'
      LookupResultField = 'name'
      KeyFields = 'speciality_id'
      Size = 255
      Lookup = True
    end
    object structUnitSpechochschule_lookup: TWideStringField
      FieldKind = fkLookup
      FieldName = 'hochschule_lookup'
      LookupDataSet = structUnit
      LookupKeyFields = 'id'
      LookupResultField = 'hochschule_lookup'
      KeyFields = 'structural_unit_id'
      Size = 255
      Lookup = True
    end
    object structUnitSpecstruct_unit_type_lookup: TWideStringField
      FieldKind = fkLookup
      FieldName = 'struct_unit_type_lookup'
      LookupDataSet = structUnit
      LookupKeyFields = 'id'
      LookupResultField = 'struct_unit_type_lookup'
      KeyFields = 'structural_unit_id'
      Lookup = True
    end
    object structUnitSpecstruct_unit_name: TWideStringField
      FieldKind = fkLookup
      FieldName = 'struct_unit_name'
      LookupDataSet = structUnit
      LookupKeyFields = 'id'
      LookupResultField = 'name'
      KeyFields = 'structural_unit_id'
      Size = 255
      Lookup = True
    end
    object structUnitSpecedu_level_id_f: TIntegerField
      FieldKind = fkLookup
      FieldName = 'edu_level_id_f'
      LookupDataSet = speciality
      LookupKeyFields = 'id'
      LookupResultField = 'edu_level_id'
      KeyFields = 'speciality_id'
      Lookup = True
    end
    object structUnitSpecdomain_id_f: TIntegerField
      FieldKind = fkLookup
      FieldName = 'domain_id_f'
      LookupDataSet = speciality
      LookupKeyFields = 'id'
      LookupResultField = 'domain_id'
      KeyFields = 'speciality_id'
      Lookup = True
    end
    object structUnitSpeccourse_coude_f: TIntegerField
      FieldKind = fkLookup
      FieldName = 'course_coude_f'
      LookupDataSet = speciality
      LookupKeyFields = 'id'
      LookupResultField = 'course_code'
      KeyFields = 'speciality_id'
      Lookup = True
    end
    object structUnitSpechochschule_id_f: TIntegerField
      FieldKind = fkLookup
      FieldName = 'hochschule_id_f'
      LookupDataSet = structUnit
      LookupKeyFields = 'id'
      LookupResultField = 'hochschule_id'
      KeyFields = 'structural_unit_id'
      Lookup = True
    end
    object structUnitSpecstructural_unit_type_id_f: TIntegerField
      FieldKind = fkLookup
      FieldName = 'structural_unit_type_id_f'
      LookupDataSet = structUnit
      LookupKeyFields = 'id'
      LookupResultField = 'structural_unit_type_id'
      KeyFields = 'structural_unit_id'
      Lookup = True
    end
  end
  object structUnitSpecStud: TADOTable
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    TableName = 'struct_unit_spec_stud_type'
    Left = 392
    Top = 192
  end
  object structUnitType: TADOTable
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    TableName = 'struct_unit_type'
    Left = 504
    Top = 192
  end
  object structUnit: TADOTable
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    TableName = 'structural_unit'
    Left = 608
    Top = 192
    object structUnitid: TAutoIncField
      FieldName = 'id'
      ReadOnly = True
    end
    object structUnithochschule_id: TIntegerField
      FieldName = 'hochschule_id'
    end
    object structUnitstructural_unit_type_id: TIntegerField
      FieldName = 'structural_unit_type_id'
    end
    object structUnitname: TWideStringField
      FieldName = 'name'
      Size = 255
    end
    object structUnithochschule_lookup: TWideStringField
      FieldKind = fkLookup
      FieldName = 'hochschule_lookup'
      LookupDataSet = hochschule
      LookupKeyFields = 'id'
      LookupResultField = 'name'
      KeyFields = 'hochschule_id'
      Size = 255
      Lookup = True
    end
    object structUnitstruct_unit_type_lookup: TWideStringField
      FieldKind = fkLookup
      FieldName = 'struct_unit_type_lookup'
      LookupDataSet = structUnitType
      LookupKeyFields = 'id'
      LookupResultField = 'type'
      KeyFields = 'structural_unit_type_id'
      Lookup = True
    end
  end
  object studyingType: TADOTable
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    TableName = 'studying_type'
    Left = 712
    Top = 192
  end
  object domainSource: TDataSource
    DataSet = domain
    Left = 40
    Top = 128
  end
  object eduLevelSource: TDataSource
    DataSet = eduLevel
    Left = 144
    Top = 128
  end
  object hochAndLevelSource: TDataSource
    DataSet = hochAndLevel
    Left = 264
    Top = 128
  end
  object hochTypeSource: TDataSource
    DataSet = hochType
    Left = 384
    Top = 128
  end
  object hochschuleSource: TDataSource
    DataSet = hochschule
    Left = 504
    Top = 128
  end
  object placeSource: TDataSource
    DataSet = place
    Left = 608
    Top = 128
  end
  object regionSource: TDataSource
    DataSet = region
    Left = 712
    Top = 128
  end
  object settlementSource: TDataSource
    DataSet = settlement
    Left = 40
    Top = 248
  end
  object specialitySource: TDataSource
    DataSet = speciality
    Left = 160
    Top = 248
  end
  object structUnitSpecSource: TDataSource
    DataSet = structUnitSpec
    Left = 264
    Top = 264
  end
  object structUnitSpecStudSource: TDataSource
    DataSet = structUnitSpecStud
    Left = 392
    Top = 248
  end
  object structUnitTypeSource: TDataSource
    DataSet = structUnitType
    Left = 504
    Top = 264
  end
  object structUnitSource: TDataSource
    DataSet = structUnit
    Left = 608
    Top = 248
  end
  object studyingTypeSource: TDataSource
    DataSet = studyingType
    Left = 704
    Top = 264
  end
  object Query: TADOQuery
    Connection = ADOConnection
    CursorType = ctStatic
    DataSource = structUnitSpecSource
    Parameters = <>
    Prepared = True
    Left = 32
    Top = 312
  end
  object courseNameQ: TADOQuery
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'edu_level'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 2
        Precision = 255
        Size = 255
        Value = Null
      end
      item
        Name = 'domain'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 2
        Precision = 255
        Size = 255
        Value = Null
      end>
    Prepared = True
    SQL.Strings = (
      
        'SELECT speciality.name FROM speciality JOIN (domain, edu_level) ' +
        'ON (domain.id=domain_id and edu_level_id = edu_level.id) WHERE (' +
        'edu_level.name=:edu_level AND domain.name=:domain) ORDER BY name')
    Left = 128
    Top = 336
  end
  object structUnitNameQ: TADOQuery
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'hoch'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 2
        Precision = 255
        Size = 255
        Value = Null
      end
      item
        Name = 'type'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 2
        Precision = 255
        Size = 255
        Value = Null
      end>
    Prepared = True
    SQL.Strings = (
      
        'SELECT structural_unit.name FROM structural_unit JOIN (hochschul' +
        'e, struct_unit_type) ON (hochschule.id=hochschule_id and structu' +
        'ral_unit_type_id = struct_unit_type.id) WHERE (hochschule.name=:' +
        'hoch AND struct_unit_type.type=:type) ORDER BY structural_unit.n' +
        'ame')
    Left = 224
    Top = 336
  end
  object specialityQ: TADOQuery
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'edu_level'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 2
        Precision = 255
        Size = 255
        Value = Null
      end
      item
        Name = 'domain'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 2
        Precision = 255
        Size = 255
        Value = Null
      end
      item
        Name = 'speciality'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 2
        Precision = 255
        Size = 255
        Value = Null
      end>
    Prepared = True
    SQL.Strings = (
      
        'select speciality.id from speciality join (domain, edu_level) on' +
        ' (domain.id=domain_id and edu_level.id=edu_level_id) where (edu_' +
        'level.name=:edu_level and domain.name=:domain and speciality.nam' +
        'e=:speciality)')
    Left = 312
    Top = 344
  end
  object structUnitQ: TADOQuery
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'hoch'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 2
        Precision = 255
        Size = 255
        Value = Null
      end
      item
        Name = 'type'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 2
        Precision = 255
        Size = 255
        Value = Null
      end
      item
        Name = 'structUnitName'
        Attributes = [paNullable]
        DataType = ftWideString
        NumericScale = 2
        Precision = 255
        Size = 255
        Value = Null
      end>
    Prepared = True
    SQL.Strings = (
      
        'select structural_unit.id from structural_unit join (hochschule,' +
        ' struct_unit_type) on (hochschule.id=hochschule_id and struct_un' +
        'it_type.id=structural_unit_type_id) where (hochschule.name=:hoch' +
        ' and struct_unit_type.type=:type and structural_unit.name=:struc' +
        'tUnitName)')
    Left = 408
    Top = 344
  end
  object hochschuleQ: TADOQuery
    Active = True
    Connection = ADOConnection
    CursorType = ctStatic
    Parameters = <>
    Prepared = True
    SQL.Strings = (
      'SELECT'
      '    p.id AS place_id,'
      '    p.region_id,'
      '    p.settlement_id,'
      '    h.id,'
      '    h.name,'
      '    t.id AS type_id,'
      '    l.level_id AS level,'
      '    r.name AS region,'
      '    s.name AS settlement,'
      '    h.street,'
      '    h.email,'
      '    h.phone'
      'FROM'
      '    hochschule AS h'
      '        JOIN'
      
        '    (place AS p, region AS r, settlement AS s, hoch_type AS t, h' +
        'och_and_level AS l) ON (p.id = place_id AND r.id = region_id'
      '        AND s.id = settlement_id'
      '        AND t.id = hoch_type_id'
      '        AND l.hochschule_id = h.id)'
      'ORDER BY id;')
    Left = 496
    Top = 344
    object hochschuleQtype_id: TIntegerField
      FieldName = 'type_id'
      Visible = False
    end
    object hochschuleQid: TIntegerField
      FieldName = 'id'
    end
    object hochschuleQname: TWideStringField
      FieldName = 'name'
      Size = 255
    end
    object hochschuleQlevel: TIntegerField
      FieldName = 'level'
    end
    object hochschuleQtype_lookup: TWideStringField
      FieldKind = fkLookup
      FieldName = 'type_lookup'
      LookupDataSet = hochType
      LookupKeyFields = 'id'
      LookupResultField = 'type'
      KeyFields = 'type_id'
      Size = 120
      Lookup = True
    end
    object hochschuleQregion: TWideStringField
      FieldName = 'region'
      Size = 50
    end
    object hochschuleQsettlement: TWideStringField
      FieldName = 'settlement'
      Size = 50
    end
    object hochschuleQplace_id: TIntegerField
      FieldName = 'place_id'
    end
    object hochschuleQstreet: TWideStringField
      FieldName = 'street'
      Size = 100
    end
    object hochschuleQemail: TWideStringField
      FieldName = 'email'
      Size = 255
    end
    object hochschuleQphone: TWideStringField
      FieldName = 'phone'
      Size = 50
    end
  end
end
