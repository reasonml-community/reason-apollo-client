module ApolloCache = ApolloClient__Cache_Core_Cache.ApolloCache;
module ApolloError = ApolloClient__Errors_ApolloError;
module ApolloLink = ApolloClient__Link_Core_ApolloLink;
module ApolloQueryResult = ApolloClient__Core_Types.ApolloQueryResult;
module DataProxy = ApolloClient__Cache_Core_Types.DataProxy;
module ErrorPolicy = ApolloClient__Core_WatchQueryOptions.ErrorPolicy;
module FetchPolicy = ApolloClient__Core_WatchQueryOptions.FetchPolicy;
module FetchPolicy__noCacheExtracted = ApolloClient__Core_WatchQueryOptions.FetchPolicy__noCacheExtracted;
module FetchResult = ApolloClient__Link_Core_Types.FetchResult;
module FragmentMatcher = ApolloClient__Core_LocalState.FragmentMatcher;
module Graphql = ApolloClient__Graphql;
module MutationOptions = ApolloClient__Core_WatchQueryOptions.MutationOptions;
module MutationQueryReducersMap = ApolloClient__Core_WatchQueryOptions.MutationQueryReducersMap;
module MutationUpdaterFn = ApolloClient__Core_WatchQueryOptions.MutationUpdaterFn;
module ObservableQuery = ApolloClient__Core_ObservableQuery.ObservableQuery;
module QueryOptions = ApolloClient__Core_WatchQueryOptions.QueryOptions;
module PureQueryOptions = ApolloClient__Core_Types.PureQueryOptions;
module RefetchQueryDescription = ApolloClient__Core_WatchQueryOptions.RefetchQueryDescription;
module Resolvers = ApolloClient__Core_Types.Resolvers;
module UriFunction = ApolloClient__Link_Http_SelectHttpOptionsAndBody.UriFunction;
module Types = ApolloClient__Types;
module Utils = ApolloClient__Utils;
module WatchQueryFetchPolicy = ApolloClient__Core_WatchQueryOptions.WatchQueryFetchPolicy;
module WatchQueryOptions = ApolloClient__Core_WatchQueryOptions.WatchQueryOptions;

module type Fragment = Types.Fragment;
module type Operation = Types.Operation;
module type OperationNoRequiredVars = Types.OperationNoRequiredVars;

module DefaultWatchQueryOptions = {
  module Js_ = {
    // Partial<QueryOptions>;
    type t = {
      fetchPolicy: option(WatchQueryFetchPolicy.Js_.t),
      // query: GraphQL.Language.documentNode,
      // variables: option('jsVariables),
      errorPolicy: option(ErrorPolicy.Js_.t),
      context: option(Js.Json.t),
    };
  };

  type t = {
    fetchPolicy: option(WatchQueryFetchPolicy.t),
    errorPolicy: option(ErrorPolicy.t),
    context: option(Js.Json.t),
  };

  let toJs: t => Js_.t =
    t => {
      fetchPolicy: t.fetchPolicy->Belt.Option.map(WatchQueryFetchPolicy.toJs),
      errorPolicy: t.errorPolicy->Belt.Option.map(ErrorPolicy.toJs),
      context: t.context,
    };

  let make = (~fetchPolicy=?, ~errorPolicy=?, ~context=?, ()) => {
    fetchPolicy,
    errorPolicy,
    context,
  };
};

module DefaultQueryOptions = {
  module Js_ = {
    // Partial<QueryOptions>;
    type t = {
      fetchPolicy: option(FetchPolicy.Js_.t),
      // query: GraphQL.Language.documentNode,
      // variables: option('jsVariables),
      errorPolicy: option(ErrorPolicy.Js_.t),
      context: option(Js.Json.t),
    };
  };

  type t = {
    fetchPolicy: option(FetchPolicy.t),
    errorPolicy: option(ErrorPolicy.t),
    context: option(Js.Json.t),
  };

  let toJs: t => Js_.t =
    t => {
      fetchPolicy: t.fetchPolicy->Belt.Option.map(FetchPolicy.toJs),
      errorPolicy: t.errorPolicy->Belt.Option.map(ErrorPolicy.toJs),
      context: t.context,
    };

  let make = (~fetchPolicy=?, ~errorPolicy=?, ~context=?, ()) => {
    fetchPolicy,
    errorPolicy,
    context,
  };
};

module DefaultMutateOptions = {
  module Js_ = {
    // Partial<MutationOptions>;
    type t = {
      context: option(Js.Json.t),
      fetchPolicy: option(FetchPolicy__noCacheExtracted.Js_.t),
      awaitRefetchQueries: option(bool),
      errorPolicy: option(ErrorPolicy.Js_.t),
      // optimisticResponse: option('jsVariables => 'jsData),
      // update: option(MutationUpdaterFn.Js_.t('jsData)),
      // updateQueries: option(MutationQueryReducersMap.Js_.t('jsData)),
      refetchQueries: option(RefetchQueryDescription.Js_.t),
      // variables: option('jsVariables),
    };
  };

  type t = {
    context: option(Js.Json.t),
    fetchPolicy: option(FetchPolicy__noCacheExtracted.t),
    awaitRefetchQueries: option(bool),
    errorPolicy: option(ErrorPolicy.t),
    refetchQueries: option(RefetchQueryDescription.t),
  };

  let toJs: t => Js_.t =
    t => {
      context: t.context,
      fetchPolicy:
        t.fetchPolicy->Belt.Option.map(FetchPolicy__noCacheExtracted.toJs),
      awaitRefetchQueries: t.awaitRefetchQueries,
      errorPolicy: t.errorPolicy->Belt.Option.map(ErrorPolicy.toJs),
      refetchQueries:
        t.refetchQueries->Belt.Option.map(RefetchQueryDescription.toJs),
    };

  let make =
      (
        ~context=?,
        ~fetchPolicy=?,
        ~awaitRefetchQueries=?,
        ~errorPolicy=?,
        ~refetchQueries=?,
        (),
      ) => {
    context,
    fetchPolicy,
    awaitRefetchQueries,
    errorPolicy,
    refetchQueries,
  };
};

module DefaultOptions = {
  module Js_ = {
    // export interface DefaultOptions {
    //     watchQuery?: Partial<WatchQueryOptions>;
    //     query?: Partial<QueryOptions>;
    //     mutate?: Partial<MutationOptions>;
    // }
    type t = {
      watchQuery: option(DefaultWatchQueryOptions.Js_.t),
      query: option(DefaultQueryOptions.Js_.t),
      mutate: option(DefaultMutateOptions.Js_.t),
    };
  };

  type t = {
    watchQuery: option(DefaultWatchQueryOptions.t),
    query: option(DefaultQueryOptions.t),
    mutate: option(DefaultMutateOptions.t),
  };

  let toJs: t => Js_.t =
    t => {
      watchQuery:
        t.watchQuery->Belt.Option.map(DefaultWatchQueryOptions.toJs),
      query: t.query->Belt.Option.map(DefaultQueryOptions.toJs),
      mutate: t.mutate->Belt.Option.map(DefaultMutateOptions.toJs),
    };

  let make:
    (
      ~mutate: DefaultMutateOptions.t=?,
      ~query: DefaultQueryOptions.t=?,
      ~watchQuery: DefaultWatchQueryOptions.t=?,
      unit
    ) =>
    t =
    (~mutate=?, ~query=?, ~watchQuery=?, ()) => {watchQuery, query, mutate};
};

module ApolloClientOptions = {
  module Js_ = {
    // export declare type ApolloClientOptions<TCacheShape> = {
    //     uri?: string | UriFunction;
    //     credentials?: string;
    //     headers?: Record<string, string>;
    //     link?: ApolloLink;
    //     cache: ApolloCache<TCacheShape>;
    //     ssrForceFetchDelay?: number;
    //     ssrMode?: boolean;
    //     connectToDevTools?: boolean;
    //     queryDeduplication?: boolean;
    //     defaultOptions?: DefaultOptions;
    //     assumeImmutableResults?: boolean;
    //     resolvers?: Resolvers | Resolvers[];
    //     typeDefs?: string | string[] | DocumentNode | DocumentNode[];
    //     fragmentMatcher?: FragmentMatcher;
    //     name?: string;
    //     version?: string;
    // };
    type t = {
      uri: option(UriFunction.Js_.t),
      credentials: option(string),
      headers: option(Js.Dict.t(string)),
      link: option(ApolloLink.Js_.t),
      cache: ApolloCache.t(Js.Json.t), // Non-Js_ ApolloCache is correct here
      ssrForceFetchDelay: option(int),
      ssrMode: option(bool),
      connectToDevTools: option(bool),
      queryDeduplication: option(bool),
      defaultOptions: option(DefaultOptions.Js_.t),
      assumeImmutableResults: option(bool),
      resolvers: option(array(Resolvers.Js_.t)),
      typeDefs: option(array(Graphql.documentNode)),
      fragmentMatcher: option(FragmentMatcher.Js_.t),
      name: option(string),
      version: option(string),
    };
  };

  type t = {
    uri: option(UriFunction.t),
    credentials: option(string),
    headers: option(Js.Dict.t(string)),
    link: option(ApolloLink.t),
    cache: ApolloCache.t(Js.Json.t),
    ssrForceFetchDelay: option(int),
    ssrMode: option(bool),
    connectToDevTools: option(bool),
    queryDeduplication: option(bool),
    defaultOptions: option(DefaultOptions.t),
    assumeImmutableResults: option(bool),
    resolvers: option(array(Resolvers.t)),
    typeDefs: option(array(Graphql.documentNode)),
    fragmentMatcher: option(FragmentMatcher.t),
    name: option(string),
    version: option(string),
  };

  let toJs: t => Js_.t =
    t => {
      uri: t.uri,
      credentials: t.credentials,
      headers: t.headers,
      link: t.link,
      cache: t.cache,
      ssrForceFetchDelay: t.ssrForceFetchDelay,
      ssrMode: t.ssrMode,
      connectToDevTools: t.connectToDevTools,
      queryDeduplication: t.queryDeduplication,
      defaultOptions: t.defaultOptions->Belt.Option.map(DefaultOptions.toJs),
      assumeImmutableResults: t.assumeImmutableResults,
      resolvers: t.resolvers,
      typeDefs: t.typeDefs,
      fragmentMatcher: t.fragmentMatcher,
      name: t.name,
      version: t.version,
    };
};

module Js_ = {
  module Cast = {
    external asReasonCache: ApolloCache.Js_.t('a) => ApolloCache.t('a) =
      "%identity";
    type jsCb = unit => Js.Promise.t(unit);
    type cb = unit => Promise.t(unit);
    external castCb: cb => jsCb = "%identity";
  };

  // export declare class ApolloClient<TCacheShape> implements DataProxy {
  //     link: ApolloLink;
  //     cache: ApolloCache<TCacheShape>;
  //     disableNetworkFetches: boolean;
  //     version: string;
  //     queryDeduplication: boolean;
  //     defaultOptions: DefaultOptions;
  //     readonly typeDefs: ApolloClientOptions<TCacheShape>['typeDefs'];
  //     private queryManager;
  //     private devToolsHookCb;
  //     private resetStoreCallbacks;
  //     private clearStoreCallbacks;
  //     private localState;
  //     constructor(options: ApolloClientOptions<TCacheShape>);
  //     stop(): void;
  //     watchQuery<T = any, TVariables = OperationVariables>(options: WatchQueryOptions<TVariables>): ObservableQuery<T, TVariables>;
  //     query<T = any, TVariables = OperationVariables>(options: QueryOptions<TVariables>): Promise<ApolloQueryResult<T>>;
  //     mutate<T = any, TVariables = OperationVariables>(options: MutationOptions<T, TVariables>): Promise<FetchResult<T>>;
  //     subscribe<T = any, TVariables = OperationVariables>(options: SubscriptionOptions<TVariables>): Observable<FetchResult<T>>;
  //     readQuery<T = any, TVariables = OperationVariables>(options: DataProxy.Query<TVariables>, optimistic?: boolean): T | null;
  //     readFragment<T = any, TVariables = OperationVariables>(options: DataProxy.Fragment<TVariables>, optimistic?: boolean): T | null;
  //     writeQuery<TData = any, TVariables = OperationVariables>(options: DataProxy.WriteQueryOptions<TData, TVariables>): void;
  //     writeFragment<TData = any, TVariables = OperationVariables>(options: DataProxy.WriteFragmentOptions<TData, TVariables>): void;
  //     __actionHookForDevTools(cb: () => any): void;
  //     __requestRaw(payload: GraphQLRequest): Observable<ExecutionResult>;
  //     resetStore(): Promise<ApolloQueryResult<any>[] | null>;
  //     clearStore(): Promise<any[]>;
  //     onResetStore(cb: () => Promise<any>): () => void;
  //     onClearStore(cb: () => Promise<any>): () => void;
  //     reFetchObservableQueries(includeStandby?: boolean): Promise<ApolloQueryResult<any>[]>;
  //     extract(optimistic?: boolean): TCacheShape;
  //     restore(serializedState: TCacheShape): ApolloCache<TCacheShape>;
  //     addResolvers(resolvers: Resolvers | Resolvers[]): void;
  //     setResolvers(resolvers: Resolvers | Resolvers[]): void;
  //     getResolvers(): Resolvers;
  //     setLocalStateFragmentMatcher(fragmentMatcher: FragmentMatcher): void;
  //     setLink(newLink: ApolloLink): void;
  // }
  type t;

  // clearStore(): Promise<any[]>;
  [@bs.send]
  external clearStore: t => Js.Promise.t(array(Js.Json.t)) = "clearStore";

  // mutate<T = any, TVariables = OperationVariables>(options: MutationOptions<T, TVariables>): Promise<FetchResult<T>>;
  [@bs.send]
  external mutate:
    (t, ~options: MutationOptions.Js_.t('jsData, 'jsVariables)) =>
    Js.Promise.t(FetchResult.Js_.t('jsData)) =
    "mutate";

  // onClearStore(cb: () => Promise<any>): () => void;
  [@bs.send]
  external onClearStore: (t, ~cb: unit => Js.Promise.t(unit), unit) => unit =
    "onClearStore";

  // onResetStore(cb: () => Promise<any>): () => void;
  [@bs.send]
  external onResetStore: (t, ~cb: unit => Js.Promise.t(unit), unit) => unit =
    "onResetStore";

  // query<T = any, TVariables = OperationVariables>(options: QueryOptions<TVariables>): Promise<ApolloQueryResult<T>>;
  [@bs.send]
  external query:
    (t, ~options: QueryOptions.Js_.t('jsVariables)) =>
    Js.Promise.t(ApolloQueryResult.Js_.t('jsData)) =
    "query";

  // readQuery<T = any, TVariables = OperationVariables>(options: DataProxy.Query<TVariables>, optimistic?: boolean): T | null;
  [@bs.send]
  external readQuery:
    (
      t,
      ~options: DataProxy.Query.Js_.t('jsVariables),
      ~optimistic: option(bool)
    ) =>
    Js.nullable('jsData) =
    "readQuery";

  // resetStore(): Promise<ApolloQueryResult<any>[] | null>;
  [@bs.send]
  external resetStore:
    t =>
    Js.Promise.t(Js.nullable(array(ApolloQueryResult.Js_.t(Js.Json.t)))) =
    "resetStore";

  // restore(serializedState: TCacheShape): ApolloCache<TCacheShape>;
  [@bs.send]
  external restore: (t, Js.Json.t) => ApolloCache.Js_.t(Js.Json.t) =
    "restore";

  // setLink(newLink: ApolloLink): void;
  [@bs.send] external setLink: (t, ApolloLink.Js_.t) => unit = "setLink";

  // <T = any, TVariables = OperationVariables>(options: WatchQueryOptions<TVariables>): ObservableQuery<T, TVariables>;
  [@bs.send]
  external watchQuery:
    (t, ~options: WatchQueryOptions.Js_.t('jsVariables)) =>
    ObservableQuery.Js_.t('jsData) =
    "watchQuery";

  // writeFragment<TData = any, TVariables = OperationVariables>(options: DataProxy.WriteFragmentOptions<TData, TVariables>): void;
  [@bs.send]
  external writeFragment:
    (
      t,
      ~options: DataProxy.WriteFragmentOptions.Js_.t('jsData, 'jsVariables)
    ) =>
    unit =
    "writeFragment";

  // writeQuery<TData = any, TVariables = OperationVariables>(options: DataProxy.WriteQueryOptions<TData, TVariables>): void;
  [@bs.send]
  external writeQuery:
    (t, ~options: DataProxy.WriteQueryOptions.Js_.t('jsData, 'jsVariables)) =>
    unit =
    "writeQuery";

  [@bs.module "@apollo/client"] [@bs.new]
  external make: ApolloClientOptions.Js_.t => t = "ApolloClient";
};

type t = {
  [@bs.as "reason_clearStore"]
  clearStore: unit => Promise.t(Belt.Result.t(array(Js.Json.t), Js.Exn.t)),
  [@bs.as "reason_mutate"]
  mutate:
    'data 'variables 'jsVariables.
    (
      ~mutation: (module Operation with
                    type t = 'data and
                    type t_variables = 'variables and
                    type Raw.t_variables = 'jsVariables),
      ~awaitRefetchQueries: bool=?,
      ~context: Js.Json.t=?,
      ~errorPolicy: ErrorPolicy.t=?,
      ~fetchPolicy: FetchPolicy__noCacheExtracted.t=?,
      ~mapJsVariables: 'jsVariables => 'jsVariables=?,
      ~optimisticResponse: 'jsVariables => 'data=?,
      ~refetchQueries: RefetchQueryDescription.t=?,
      ~updateQueries: MutationQueryReducersMap.t('data)=?,
      ~update: MutationUpdaterFn.t('data)=?,
      'variables
    ) =>
    Promise.t(Belt.Result.t(FetchResult.t__ok('data), ApolloError.t)),

  [@bs.as "reason_onClearStore"]
  onClearStore: (~cb: unit => Promise.t(unit), unit) => unit,
  [@bs.as "reason_onResetStore"]
  onResetStore: (~cb: unit => Promise.t(unit), unit) => unit,
  [@bs.as "reason_query"]
  query:
    'data 'jsData 'variables 'jsVariables.
    (
      ~query: (module Operation with
                 type t = 'data and
                 type t_variables = 'variables and
                 type Raw.t = 'jsData and
                 type Raw.t_variables = 'jsVariables),
      ~context: Js.Json.t=?,
      ~errorPolicy: ErrorPolicy.t=?,
      ~fetchPolicy: FetchPolicy.t=?,
      ~mapJsVariables: 'jsVariables => 'jsVariables=?,
      'variables
    ) =>
    Promise.t(Belt.Result.t(ApolloQueryResult.t__ok('data), ApolloError.t)),

  [@bs.as "reason_readQuery"]
  readQuery:
    'data 'variables 'jsVariables.
    (
      ~query: (module Operation with
                 type t = 'data and
                 type t_variables = 'variables and
                 type Raw.t_variables = 'jsVariables),
      ~id: string=?,
      ~mapJsVariables: 'jsVariables => 'jsVariables=?,
      ~optimistic: bool=?,
      'variables
    ) =>
    option('data),

  [@bs.as "reason_resetStore"]
  resetStore:
    unit =>
    Promise.t(
      Belt.Result.t(
        option(array(ApolloQueryResult.Js_.t(Js.Json.t))),
        Js.Exn.t,
      ),
    ),
  [@bs.as "reason_restore"]
  restore: (~serializedState: Js.Json.t) => ApolloCache.t(Js.Json.t),
  [@bs.as "reason_setLink"]
  setLink: ApolloLink.t => unit,
  [@bs.as "reason_watchQuery"]
  watchQuery:
    'data 'variables 'jsVariables.
    (
      ~query: (module Operation with
                 type t = 'data and
                 type t_variables = 'variables and
                 type Raw.t_variables = 'jsVariables),
      ~context: Js.Json.t=?,
      ~errorPolicy: ErrorPolicy.t=?,
      ~fetchPolicy: WatchQueryFetchPolicy.t=?,
      ~mapJsVariables: 'jsVariables => 'jsVariables=?,
      'variables
    ) =>
    ObservableQuery.t('data),

  [@bs.as "reason_writeFragment"]
  writeFragment:
    'data 'jsVariables.
    (
      ~fragment: (module Fragment with type t = 'data),
      ~data: 'data,
      ~broadcast: bool=?,
      ~id: string,
      ~fragmentName: string=?,
      unit
    ) =>
    unit,

  [@bs.as "reason_writeQuery"]
  writeQuery:
    'data 'variables 'jsVariables.
    (
      ~query: (module Operation with
                 type t = 'data and
                 type t_variables = 'variables and
                 type Raw.t_variables = 'jsVariables),
      ~broadcast: bool=?,
      ~data: 'data,
      ~id: string=?,
      ~mapJsVariables: 'jsVariables => 'jsVariables=?,
      'variables
    ) =>
    unit,

};

let preserveJsPropsAndContext: (Js_.t, t) => t = [%bs.raw
  {|
    function (js, t) {
      return Object.assign(js, t)
    }
  |}
];

let make:
  (
    ~uri: UriFunction.t=?,
    ~credentials: string=?,
    ~headers: Js.Dict.t(string)=?,
    ~link: ApolloLink.t=?,
    ~cache: ApolloCache.t(Js.Json.t),
    ~ssrForceFetchDelay: int=?,
    ~ssrMode: bool=?,
    ~connectToDevTools: bool=?,
    ~queryDeduplication: bool=?,
    ~defaultOptions: DefaultOptions.t=?,
    ~assumeImmutableResults: bool=?,
    ~resolvers: array(Resolvers.t)=?,
    ~typeDefs: array(Graphql.documentNode)=?,
    ~fragmentMatcher: FragmentMatcher.t=?,
    ~name: string=?,
    ~version: string=?,
    unit
  ) =>
  t =
  (
    ~uri=?,
    ~credentials=?,
    ~headers=?,
    ~link=?,
    ~cache,
    ~ssrForceFetchDelay=?,
    ~ssrMode=?,
    ~connectToDevTools=?,
    ~queryDeduplication=?,
    ~defaultOptions=?,
    ~assumeImmutableResults=?,
    ~resolvers=?,
    ~typeDefs=?,
    ~fragmentMatcher=?,
    ~name=?,
    ~version=?,
    (),
  ) => {
    let jsClient =
      Js_.make(
        ApolloClientOptions.toJs({
          uri,
          credentials,
          headers,
          link,
          cache,
          ssrForceFetchDelay,
          ssrMode,
          connectToDevTools,
          queryDeduplication,
          defaultOptions,
          assumeImmutableResults,
          resolvers,
          typeDefs,
          fragmentMatcher,
          name,
          version,
        }),
      );

    let clearStore = () =>
      jsClient
      ->Js_.clearStore
      ->Promise.Js.fromBsPromise
      ->Promise.Js.toResult
      ->Promise.mapError(e => Utils.ensureError(Any(e)));

    let mutate =
        (
          type data,
          type variables,
          type jsVariables,
          ~mutation as
            module Operation:
              Operation with
                type t = data and
                type t_variables = variables and
                type Raw.t_variables = jsVariables,
          ~awaitRefetchQueries=?,
          ~context=?,
          ~errorPolicy=?,
          ~fetchPolicy=?,
          ~mapJsVariables=Utils.identity,
          ~optimisticResponse=?,
          ~refetchQueries=?,
          ~updateQueries=?,
          ~update=?,
          variables,
        ) => {
      let safeParse = Utils.safeParse(Operation.parse);

      Js_.mutate(
        jsClient,
        ~options=
          MutationOptions.toJs(
            {
              awaitRefetchQueries,
              context,
              errorPolicy,
              fetchPolicy,
              mutation: Operation.query,
              optimisticResponse,
              updateQueries,
              refetchQueries,
              update,
              variables,
            },
            ~mapJsVariables,
            ~safeParse,
            ~serialize=Operation.serialize,
            ~serializeVariables=Operation.serializeVariables,
          ),
      )
      ->Promise.Js.fromBsPromise
      ->Promise.Js.toResult
      ->Promise.map(result => {
          switch (result) {
          | Ok(jsFetchResult) =>
            jsFetchResult->FetchResult.fromJs(~safeParse)
          | Error(error) =>
            FetchResult.fromError(
              ApolloError.make(
                ~networkError=FetchFailure(Utils.(ensureError(Any(error)))),
                (),
              ),
            )
          }
        })
      ->Promise.map(FetchResult.toResult);
    };

    let onClearStore = (~cb) =>
      jsClient->Js_.onClearStore(~cb=Js_.Cast.castCb(cb));

    let onResetStore = (~cb) =>
      jsClient->Js_.onResetStore(~cb=Js_.Cast.castCb(cb));

    let query =
        (
          type data,
          type jsData,
          type variables,
          type jsVariables,
          ~query as
            module Operation:
              Operation with
                type t = data and
                type t_variables = variables and
                type Raw.t = jsData and
                type Raw.t_variables = jsVariables,
          ~context=?,
          ~errorPolicy=?,
          ~fetchPolicy=?,
          ~mapJsVariables=Utils.identity,
          variables,
        ) => {
      let safeParse = Utils.safeParse(Operation.parse);

      Js_.query(
        jsClient,
        ~options=
          QueryOptions.toJs(
            {
              fetchPolicy,
              query: Operation.query,
              variables,
              errorPolicy,
              context,
            },
            ~mapJsVariables,
            ~serializeVariables=Operation.serializeVariables,
          ),
      )
      ->Promise.Js.fromBsPromise
      ->Promise.Js.toResult
      ->Promise.map(result => {
          switch (result) {
          | Ok(jsApolloQueryResult) =>
            jsApolloQueryResult->ApolloQueryResult.fromJs(~safeParse)
          | Error(error) =>
            ApolloQueryResult.fromError(
              ApolloError.make(
                ~networkError=FetchFailure(Utils.(ensureError(Any(error)))),
                (),
              ),
            )
          }
        })
      ->Promise.map(ApolloQueryResult.toResult);
    };

    let readQuery =
        (
          type data,
          type variables,
          type jsVariables,
          ~query as
            module Operation:
              Operation with
                type t = data and
                type t_variables = variables and
                type Raw.t_variables = jsVariables,
          ~id=?,
          ~mapJsVariables=Utils.identity,
          ~optimistic=?,
          variables,
        ) => {
      Js_.readQuery(
        jsClient,
        ~options=
          DataProxy.Query.toJs(
            {id, query: Operation.query, variables},
            ~mapJsVariables,
            ~serializeVariables=Operation.serializeVariables,
          ),
        ~optimistic,
      )
      ->Js.toOption
      ->Belt.Option.map(Operation.parse);
    };

    let resetStore:
      unit =>
      Promise.t(
        Belt.Result.t(
          option(array(ApolloQueryResult.Js_.t(Js.Json.t))),
          Js.Exn.t,
        ),
      ) =
      () =>
        jsClient
        ->Js_.resetStore
        ->Promise.Js.fromBsPromise
        ->Promise.Js.toResult
        ->Promise.mapOk(Js.toOption)
        ->Promise.mapError(e => Utils.ensureError(Any(e)));

    let restore = (~serializedState) =>
      jsClient->Js_.restore(serializedState)->Js_.Cast.asReasonCache;

    let setLink = link => jsClient->Js_.setLink(link);

    let watchQuery =
        (
          type data,
          type variables,
          type jsVariables,
          ~query as
            module Operation:
              Operation with
                type t = data and
                type t_variables = variables and
                type Raw.t_variables = jsVariables,
          ~context=?,
          ~errorPolicy=?,
          ~fetchPolicy=?,
          ~mapJsVariables=Utils.identity,
          variables,
        ) => {
      let safeParse = Utils.safeParse(Operation.parse);

      jsClient
      ->Js_.watchQuery(
          ~options=
            WatchQueryOptions.toJs(
              {
                fetchPolicy,
                query: Operation.query,
                variables,
                errorPolicy,
                context,
              },
              ~mapJsVariables,
              ~serializeVariables=Operation.serializeVariables,
            ),
        )
      ->ObservableQuery.fromJs(~safeParse);
    };

    let writeFragment =
        (
          type data,
          ~fragment as module Fragment: Fragment with type t = data,
          ~data: data,
          ~broadcast=?,
          ~id,
          ~fragmentName=?,
          (),
        ) => {
      jsClient->Js_.writeFragment(
        ~options=
          DataProxy.WriteFragmentOptions.toJs(
            {broadcast, data, id, fragment: Fragment.query, fragmentName},
            ~serialize=Fragment.serialize,
          ),
      );
    };

    let writeQuery =
        (
          type data,
          type variables,
          type jsVariables,
          ~query as
            module Operation:
              Operation with
                type t = data and
                type t_variables = variables and
                type Raw.t_variables = jsVariables,
          ~broadcast=?,
          ~data,
          ~id=?,
          ~mapJsVariables=Utils.identity,
          variables,
        ) => {
      jsClient->Js_.writeQuery(
        ~options=
          DataProxy.WriteQueryOptions.toJs(
            {broadcast, data, id, query: Operation.query, variables},
            ~mapJsVariables,
            ~serialize=Operation.serialize,
            ~serializeVariables=Operation.serializeVariables,
          ),
      );
    };

    preserveJsPropsAndContext(
      jsClient,
      {
        clearStore,
        mutate,
        onClearStore,
        onResetStore,
        query,
        readQuery,
        resetStore,
        restore,
        setLink,
        watchQuery,
        writeFragment,
        writeQuery,
      },
    );
  };
